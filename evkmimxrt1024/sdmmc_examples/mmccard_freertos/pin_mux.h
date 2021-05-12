/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/* Define the flexspi macro. Note that it can't be modified here */
#define IOMUXC_GPIO_AD_B1_00_FLEXSPI_A_DATA03 0x401F80FCU, 0x1U, 0x401F8374U, 0x1U, 0x401F8270U
#define IOMUXC_GPIO_AD_B1_01_FLEXSPI_A_SCLK 0x401F8100U, 0x1U, 0x401F8378U, 0x1U, 0x401F8274U
#define IOMUXC_GPIO_AD_B1_02_FLEXSPI_A_DATA00 0x401F8104U, 0x1U, 0x401F8368U, 0x1U, 0x401F8278U
#define IOMUXC_GPIO_AD_B1_03_FLEXSPI_A_DATA02 0x401F8108U, 0x1U, 0x401F8370U, 0x1U, 0x401F827CU
#define IOMUXC_GPIO_AD_B1_04_FLEXSPI_A_DATA01 0x401F810CU, 0x1U, 0x401F836CU, 0x1U, 0x401F8280U
#define IOMUXC_GPIO_AD_B1_05_FLEXSPI_A_SS0_B 0x401F8110U, 0x1U, 0, 0, 0x401F8284U

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* GPIO_AD_B0_07 (number 101), UART1_RXD/J17[8] */
#define BOARD_INITPINS_UART1_RXD_PERIPHERAL                              LPUART1   /*!< Device name: LPUART1 */
#define BOARD_INITPINS_UART1_RXD_SIGNAL                                       RX   /*!< LPUART1 signal: RX */

/* GPIO_AD_B0_06 (number 105), UART1_TXD/J17[12] */
#define BOARD_INITPINS_UART1_TXD_PERIPHERAL                              LPUART1   /*!< Device name: LPUART1 */
#define BOARD_INITPINS_UART1_TXD_SIGNAL                                       TX   /*!< LPUART1 signal: TX */

/* GPIO_SD_B0_06 (number 41), SD_CD_SW/J15[9] */
#define BOARD_INITPINS_SD_CD_SW_GPIO                                       GPIO3   /*!< GPIO device name: GPIO3 */
#define BOARD_INITPINS_SD_CD_SW_PORT                                       GPIO3   /*!< PORT device name: GPIO3 */
#define BOARD_INITPINS_SD_CD_SW_PIN                                          19U   /*!< GPIO3 pin index: 19 */

/* GPIO_SD_B0_00 (number 48), SD1_D2/J15[1] */
#define BOARD_INITPINS_SD1_D2_PERIPHERAL                                  USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD1_D2_SIGNAL                                  usdhc_data   /*!< USDHC1 signal: usdhc_data */
#define BOARD_INITPINS_SD1_D2_CHANNEL                                         2U   /*!< USDHC1 usdhc_data channel: 2 */

/* GPIO_SD_B0_01 (number 47), SD1_D3/J15[2] */
#define BOARD_INITPINS_SD1_D3_PERIPHERAL                                  USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD1_D3_SIGNAL                                  usdhc_data   /*!< USDHC1 signal: usdhc_data */
#define BOARD_INITPINS_SD1_D3_CHANNEL                                         3U   /*!< USDHC1 usdhc_data channel: 3 */

/* GPIO_SD_B0_02 (number 46), SD1_CMD/J15[3] */
#define BOARD_INITPINS_SD1_CMD_PERIPHERAL                                 USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD1_CMD_SIGNAL                                  usdhc_cmd   /*!< USDHC1 signal: usdhc_cmd */

/* GPIO_SD_B0_03 (number 45), SD1_CLK/J15[5] */
#define BOARD_INITPINS_SD1_CLK_PERIPHERAL                                 USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD1_CLK_SIGNAL                                  usdhc_clk   /*!< USDHC1 signal: usdhc_clk */

/* GPIO_SD_B0_04 (number 43), SD1_D0/J15[7] */
#define BOARD_INITPINS_SD1_D0_PERIPHERAL                                  USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD1_D0_SIGNAL                                  usdhc_data   /*!< USDHC1 signal: usdhc_data */
#define BOARD_INITPINS_SD1_D0_CHANNEL                                         0U   /*!< USDHC1 usdhc_data channel: 0 */

/* GPIO_SD_B0_05 (number 42), SD1_D1/J15[8] */
#define BOARD_INITPINS_SD1_D1_PERIPHERAL                                  USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD1_D1_SIGNAL                                  usdhc_data   /*!< USDHC1 signal: usdhc_data */
#define BOARD_INITPINS_SD1_D1_CHANNEL                                         1U   /*!< USDHC1 usdhc_data channel: 1 */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
