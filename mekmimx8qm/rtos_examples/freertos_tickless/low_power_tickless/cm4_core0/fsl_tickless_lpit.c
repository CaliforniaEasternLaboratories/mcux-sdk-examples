/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* Compiler includes. */
#if defined(__ICCARM__)
#include <intrinsics.h>
#endif

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

#if configUSE_TICKLESS_IDLE == 2
#include "fsl_lpit.h"
#else
#include "fsl_device_registers.h"
#endif

#include "fsl_tickless_lpit.h"

extern uint32_t SystemCoreClock; /* in Kinetis SDK, this contains the system core clock speed */

/*
 * LPIT timer base address and interrupt number
 */

#if configUSE_TICKLESS_IDLE == 2
extern LPIT_Type *vPortGetLpitBase(void);
extern IRQn_Type vPortGetLpitIrqn(void);
#endif /* configUSE_TICKLESS_IDLE */

/*-----------------------------------------------------------*/

/*
 * The number of SysTick increments that make up one tick period.
 */
#if configUSE_TICKLESS_IDLE == 2
static uint32_t ulTimerCountsForOneTick = 0;
#endif /* configUSE_TICKLESS_IDLE */

/*
 * The maximum number of tick periods that can be suppressed is limited by the
 * 24 bit resolution of the SysTick timer.
 */
#if configUSE_TICKLESS_IDLE == 2
static uint32_t xMaximumPossibleSuppressedTicks = 0;
#endif /* configUSE_TICKLESS_IDLE */

/*
 * The number of LPIT increments that make up one tick period.
 */
#if configUSE_TICKLESS_IDLE == 2
static uint32_t ulLPTimerCountsForOneTick = 0;
#endif /* configUSE_TICKLESS_IDLE */

/*
 * The flag of LPIT is occurs or not.
 */
#if configUSE_TICKLESS_IDLE == 2
static volatile bool ulLPTimerInterruptFired = false;
#endif /* configUSE_TICKLESS_IDLE */

#if configUSE_TICKLESS_IDLE == 2
void vPortLpitIsr(void)
{
    ulLPTimerInterruptFired = true;
    LPIT_ClearStatusFlags(vPortGetLpitBase(), kLPIT_Channel0TimerFlag);
}

void vPortSuppressTicksAndSleep(TickType_t xExpectedIdleTime)
{
    uint32_t ulReloadValue, ulCompleteTickPeriods;
    TickType_t xModifiableIdleTime;
    LPIT_Type *pxLpitBase;

    pxLpitBase = vPortGetLpitBase();
    if (pxLpitBase == 0)
        return;
    /* Make sure the SysTick reload value does not overflow the counter. */
    if (xExpectedIdleTime > xMaximumPossibleSuppressedTicks)
    {
        xExpectedIdleTime = xMaximumPossibleSuppressedTicks;
    }
    if (xExpectedIdleTime == 0)
        return;

    /* Calculate the reload value required to wait xExpectedIdleTime
    tick periods.  -1 is used because this code will execute part way
    through one of the tick periods. */
    ulReloadValue = (ulLPTimerCountsForOneTick * (xExpectedIdleTime - 1UL));

    /* Stop the LPIT and systick momentarily.  The time the LPIT and systick is stopped for
    is accounted for as best it can be, but using the tickless mode will
    inevitably result in some tiny drift of the time maintained by the
    kernel with respect to calendar time. */
    LPIT_StopTimer(pxLpitBase, kLPIT_Chnl_0);
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

    /* Enter a critical section but don't use the taskENTER_CRITICAL()
    method as that will mask interrupts that should exit sleep mode. */
    __disable_irq();
    __DSB();
    __ISB();

    /* If a context switch is pending or a task is waiting for the scheduler
    to be unsuspended then abandon the low power entry. */
    if (eTaskConfirmSleepModeStatus() == eAbortSleep)
    {
        /* Restart from whatever is left in the count register to complete
        this tick period. */
        SysTick->LOAD = SysTick->VAL;

        /* Restart SysTick. */
        SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

        /* Reset the reload register to the value required for normal tick
        periods. */
        SysTick->LOAD = ulTimerCountsForOneTick - 1UL;

        /* Re-enable interrupts - see comments above __disable_irq()
        call above. */
        __enable_irq();
    }
    else
    {
        /* Set the new reload value. */
        LPIT_SetTimerPeriod(pxLpitBase, kLPIT_Chnl_0, ulReloadValue);

        /* Enable LPIT. */
        LPIT_StartTimer(pxLpitBase, kLPIT_Chnl_0);

        /* Sleep until something happens.  configPRE_SLEEP_PROCESSING() can
        set its parameter to 0 to indicate that its implementation contains
        its own wait for interrupt or wait for event instruction, and so wfi
        should not be executed again.  However, the original expected idle
        time variable must remain unmodified, so a copy is taken. */
        xModifiableIdleTime = xExpectedIdleTime;
        configPRE_SLEEP_PROCESSING(xModifiableIdleTime);
        if (xModifiableIdleTime > 0)
        {
            __DSB();
            __WFI();
            __ISB();
        }
        configPOST_SLEEP_PROCESSING(xExpectedIdleTime);

        ulLPTimerInterruptFired = false;

        /* Re-enable interrupts - see comments above __disable_irq()
        call above. */
        __enable_irq();
        __NOP();
        if (ulLPTimerInterruptFired)
        {
            /* The tick interrupt handler will already have pended the tick
            processing in the kernel.  As the pending tick will be
            processed as soon as this function exits, the tick value
            maintained by the tick is stepped forward by one less than the
            time spent waiting. */
            ulCompleteTickPeriods   = xExpectedIdleTime - 1UL;
            ulLPTimerInterruptFired = false;
        }
        else
        {
            /* Something other than the tick interrupt ended the sleep.
            Work out how long the sleep lasted rounded to complete tick
            periods (not the ulReload value which accounted for part
            ticks). */
            ulCompleteTickPeriods = (LPIT_GetCurrentTimerCount(pxLpitBase, kLPIT_Chnl_0)) / ulLPTimerCountsForOneTick;
        }

        /* Stop LPIT when CPU waked up then set SysTick->LOAD back to its standard
        value.  The critical section is used to ensure the tick interrupt
        can only execute once in the case that the reload register is near
        zero. */
        LPIT_StopTimer(pxLpitBase, kLPIT_Chnl_0);
        portENTER_CRITICAL();
        {
            SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
            vTaskStepTick(ulCompleteTickPeriods);
            SysTick->LOAD = ulTimerCountsForOneTick - 1UL;
        }
        portEXIT_CRITICAL();
    }
}
#endif /* #if configUSE_TICKLESS_IDLE */

/*
 * Setup the systick timer to generate the tick interrupts at the required
 * frequency.
 */
void vPortSetupTimerInterrupt(void)
{
/* Calculate the constants required to configure the tick interrupt. */
#if configUSE_TICKLESS_IDLE == 2
    ulTimerCountsForOneTick   = (configCPU_CLOCK_HZ / configTICK_RATE_HZ);
    ulLPTimerCountsForOneTick = (configLPIT_CLOCK_HZ / configTICK_RATE_HZ);
    if (ulLPTimerCountsForOneTick != 0)
    {
        xMaximumPossibleSuppressedTicks = portMAX_32_BIT_NUMBER / ulLPTimerCountsForOneTick;
    }
    else
    {
        /* ulLPTimerCountsForOneTick is zero, not allowed state */
        while (1)
            ;
    }
    NVIC_EnableIRQ(vPortGetLpitIrqn());
#endif /* configUSE_TICKLESS_IDLE */

    /* Configure SysTick to interrupt at the requested rate. */
    SysTick->LOAD = (configCPU_CLOCK_HZ / configTICK_RATE_HZ) - 1UL;
    SysTick->VAL  = 0UL;
    SysTick->CTRL = (SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk);
}
