/**
 * @file UART_CONFIG.h
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __UART_CONFIG_H__
#define __UART_CONFIG_H__

/*
----------------------------------------------------------------------
- Configuration Parameters
----------------------------------------------------------------------
*/


/**
 * @defgroup UART1 Configuration Parameters
 *
 */

/**
 * @brief Uart peripheral general state.
 *
 * @def Uart1 State
 *      @arg UART1_STATE_ENABLE
 *      @arg UART1_STATE_DISABLE
 */
#define UART1_STATE         (UART1_STATE_ENABLE)
/**
 * @brief Uart data word length.
 *
 * @def Uart1 data word config params
 *      @arg UART1_DATAWORD_5b
 *      @arg UART1_DATAWORD_6b
 *      @arg UART1_DATAWORD_7b
 *      @arg UART1_DATAWORD_8b
 *      @arg UART1_DATAWORD_9b
 */
#define UART1_DATAWORD      (UART1_DATAWORD_8b)
/**
 * @brief Uart parity bit config.
 *
 * @def Uart1 parity bit config params
 *      @arg UART1_PARITY_NONE
 *      @arg UART1_PARITY_EVEN
 *      @arg UART1_PARITY_ODD
 */
#define UART1_PARITY        (UART1_PARITY_NONE)
/**
 * @brief Uart stop bits.
 *
 * @def Uart1 stop bits config params
 *      @arg UART1_STOPBITS_1b
 *      @arg UART1_STOPBITS_2b
 */
#define UART1_STOPBITS      (UART1_STOPBITS_1b)
/**
 * @brief Uart mode.
 *
 * @def Uart1 stop bits config params
 *      @arg UART1_MODE_RECEIVER
 *      @arg UART1_MODE_TRANSMITER
 *      @arg UART1_MODE_TRANSCEIVER
 */
#define UART1_MODE          (UART1_MODE_TRANSCEIVER)
/**
 * @brief Uart clocking mode.
 *
 * @def Uart1 stop bits config params
 *      @arg UART1_CLK_DIV_16
 *      @arg UART1_CLK_DIV_8
 */
#define UART1_CLK           (UART1_CLK_DIV_8)
/**
 * @brief Uart baudrate value
 *
 * @def Uart1 baudrate params
 *      @arg UART1_BRVAL_CUSTOM
 *      @arg UART1_BRVAL_9600
 *      @arg UART1_BRVAL_57200
 *      @arg UART1_BRVAL_115200
 *      @arg UART1_BRVAL_
 */
#define UART1_BRVAL





/**
 * @defgroup UART2 Configuration Parameters
 *
 */

#endif /* __UART_CONFIG_H__ */
