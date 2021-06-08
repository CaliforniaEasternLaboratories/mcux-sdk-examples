/*
 * Copyright 2020 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v8.0
processor: MCIMX7U5xxxxx
package_id: MCIMX7U5DVP07
mcu_data: ksdk2_0
processor_version: 8.0.1
board: MCIMX7ULP-EVK-REV-B
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: cm4}
- pin_list:
  - {pin_num: AG20, peripheral: PTA, signal: 'port, 25', pin_signal: PTA25, OBE: OBE_1_Enabled}
  - {pin_num: AB19, peripheral: LPUART0, signal: lpuart_rx, pin_signal: PTA19, PE: PE_1_pull_enabled, PS: PS_1_pull_up}
  - {pin_num: AC19, peripheral: LPUART0, signal: lpuart_tx, pin_signal: PTA18, PE: PE_1_pull_enabled, PS: PS_1_pull_up}
  - {pin_num: AD15, peripheral: I2S0, signal: i2s_mclk, pin_signal: PTA4, OBE: OBE_1_Enabled, DSE: DSE_1_Hi_Drive}
  - {pin_num: AG14, peripheral: I2S0, signal: 'i2s_rxd, 0', pin_signal: PTA2}
  - {pin_num: AC15, peripheral: I2S0, signal: i2s_tx_bclk, pin_signal: PTA5, DSE: DSE_1_Hi_Drive}
  - {pin_num: AB15, peripheral: I2S0, signal: i2s_tx_fs, pin_signal: PTA6, DSE: DSE_1_Hi_Drive}
  - {pin_num: AD14, peripheral: I2S0, signal: 'i2s_txd, 0', pin_signal: PTA7, DSE: DSE_1_Hi_Drive}
  - {pin_num: AF14, peripheral: PTA, signal: 'port, 3', pin_signal: PTA3, IBE: IBE_1_Enabled}
  - {pin_num: AF16, peripheral: PTA, signal: 'port, 13', pin_signal: PTA13, IBE: IBE_1_Enabled}
  - {pin_num: AF17, peripheral: PTA, signal: 'port, 14', pin_signal: PTA14, OBE: OBE_1_Enabled}
  - {pin_num: AF18, peripheral: PTA, signal: 'port, 15', pin_signal: PTA15, OBE: OBE_1_Enabled}
  - {pin_num: AF24, peripheral: PTA, signal: 'port, 31', pin_signal: PTA31, IBE: IBE_1_Enabled, PE: PE_1_pull_enabled, PS: PS_1_pull_up}
  - {pin_num: AF5, peripheral: PTB, signal: 'port, 6', pin_signal: PTB6, OBE: OBE_1_Enabled}
  - {pin_num: AF6, peripheral: PTB, signal: 'port, 7', pin_signal: PTB7, IBE: IBE_1_Enabled, PE: PE_1_pull_enabled, PS: PS_1_pull_up}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {                                /*!< Function assigned for the core: Cortex-M4[cm4] */
    IOMUXC_SetPinMux(BOARD_VOL_DOWN_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_VOL_DOWN_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_IBE_MASK);
    IOMUXC_SetPinMux(BOARD_WL_REG_ON_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_WL_REG_ON_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_OBE_MASK);
    IOMUXC_SetPinMux(BOARD_BT_REG_ON_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_BT_REG_ON_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_OBE_MASK);
    IOMUXC_SetPinMux(BOARD_UART0_TX_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_UART0_TX_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_PE_MASK |
                        IOMUXC0_SW_MUX_CTL_PAD_PS_MASK);
    IOMUXC_SetPinMux(BOARD_UART0_RX_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_UART0_RX_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_PE_MASK |
                        IOMUXC0_SW_MUX_CTL_PAD_PS_MASK);
    IOMUXC_SetPinMux(BOARD_I2S0_RXD0_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinMux(BOARD_A7_POW_EN_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_A7_POW_EN_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_OBE_MASK);
    IOMUXC_SetPinMux(BOARD_VOL_UP_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_VOL_UP_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_IBE_MASK);
    IOMUXC_SetPinMux(BOARD_WL_HOST_WAKE_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_WL_HOST_WAKE_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_IBE_MASK |
                        IOMUXC0_SW_MUX_CTL_PAD_PE_MASK |
                        IOMUXC0_SW_MUX_CTL_PAD_PS_MASK);
    IOMUXC_SetPinMux(BOARD_I2S0_MCLK_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_I2S0_MCLK_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_OBE_MASK |
                        IOMUXC0_SW_MUX_CTL_PAD_DSE_MASK);
    IOMUXC_SetPinMux(BOARD_I2S0_TX_BCLK_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_I2S0_TX_BCLK_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_DSE_MASK);
    IOMUXC_SetPinMux(BOARD_I2S0_TX_FS_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_I2S0_TX_FS_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_DSE_MASK);
    IOMUXC_SetPinMux(BOARD_I2S0_TXD0_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_I2S0_TXD0_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_DSE_MASK);
    IOMUXC_SetPinMux(BOARD_DDR_SW_EN_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_DDR_SW_EN_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_OBE_MASK);
    IOMUXC_SetPinMux(BOARD_BT_HOST_WAKE_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_BT_HOST_WAKE_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_IBE_MASK |
                        IOMUXC0_SW_MUX_CTL_PAD_PE_MASK |
                        IOMUXC0_SW_MUX_CTL_PAD_PS_MASK);
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_I2C_ConfigurePins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: cm4}
- pin_list:
  - {pin_num: AG18, peripheral: LPI2C0, signal: lpi2c_scl, pin_signal: PTA16, ODE: ODE_1_Open_drain}
  - {pin_num: AD19, peripheral: LPI2C0, signal: lpi2c_sda, pin_signal: PTA17, ODE: ODE_1_Open_drain}
  - {pin_num: AC8, peripheral: LPI2C3, signal: lpi2c_scl, pin_signal: PTB12, ODE: ODE_1_Open_drain}
  - {pin_num: AD8, peripheral: LPI2C3, signal: lpi2c_sda, pin_signal: PTB13, ODE: ODE_1_Open_drain}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_I2C_ConfigurePins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_I2C_ConfigurePins(void) {                       /*!< Function assigned for the core: Cortex-M4[cm4] */
    IOMUXC_SetPinMux(BOARD_I2C0_SCL_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_I2C0_SCL_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_ODE_MASK);
    IOMUXC_SetPinMux(BOARD_I2C0_SDA_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_I2C0_SDA_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_ODE_MASK);
    IOMUXC_SetPinMux(BOARD_I2C3_SCL_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_I2C3_SCL_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_ODE_MASK);
    IOMUXC_SetPinMux(BOARD_I2C3_SDA_PIN_FUNCTION_ID, 0U);
    IOMUXC_SetPinConfig(BOARD_I2C3_SDA_PIN_FUNCTION_ID,
                        IOMUXC0_SW_MUX_CTL_PAD_ODE_MASK);
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
