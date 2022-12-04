/**
 * @file UART_PROGRAM.c
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief
 * @copyright Copyrights (c) 2022 Wx
 *
 */
/*
----------------------------------------------------------------------
- Headers Included
----------------------------------------------------------------------
*/

/** @defgroup public library */
#include "../../00_LIB/LIB_MVP/STD_TYPES.h"
#include "../../00_LIB/LIB_MVP/BIT_MATH.h"
#include "../../00_LIB/LIB_MVP/DEFAULT_HANDLER.h"

/** @defgroup private library */
#include "UART_PRIVATE.h"
#include "UART_CONFIG.h"
#include "UART_INTERFACE.h"

/*
----------------------------------------------------------------------
- Global data types
----------------------------------------------------------------------
*/


/*
----------------------------------------------------------------------
- Public functions implementation
----------------------------------------------------------------------
*/

#if (UART1_STATE == UART1_STATE_ENABLE)

UART_ErrorStatus_t
MUART1_tUartInit(void)
{
    /* Set the data word */
    UART1->LCRH &= (~(0x02UL << 0x05U));
    UART1->LCRH |= ((UART1_DATAWORD) << 0x05U);

    /* Set the parity */
#if (UART1_PARITY == UART1_PARITY_NONE)
    BIT_CLR(UART1->LCRH, 0x01U);
#else
    BIT_SET(UART1->LCRH, 0x01U);
    BIT_WRT(UART1->LCRH, 0x02U, UART1_PARITY);
#endif

    /* Set the stop bits */
    BIT_WRT(UART1->LCRH, 0x03U, UART1_STOPBITS);

    /* Set the mode */
#if     (UART1_MODE == UART1_MODE_TRANSMITER)
    BIT_SET(UART1->CTL, 0x08);
#elif   (UART1_MODE == UART1_MODE_RECEIVER)
    BIT_SET(UART1->CTL, 0x09);
#elif   (UART1_MODE == UART1_MODE_TRANSCEIVER)
    BIT_SET(UART1->CTL, 0x08);
    BIT_SET(UART1->CTL, 0x09);
#endif

    /* Set baudrate configs */
#if     (UART1_BRVAL == UART1_BRVAL_9600)

#elif   (UART1_BRVAL == UART1_BRVAL_57200)

#elif   (UART1_BRVAL == UART1_BRVAL_115200)

#elif   (UART1_BRVAL == UART1_BRVAL_500000)

#else
    /* If customizable */
#endif

    /* Set the uart clock mode */
    BIT_WRT(UART1->CTL, 0x05U, UART1_CLK);

    /* Enable Uart 1 */
    BIT_SET(UART1->CTL, 0x00U);
}

#endif

/*
----------------------------------------------------------------------
- Private functions implementation
----------------------------------------------------------------------
*/
