/**
 * @file UART_INTERFACE.h
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __UART_INTERFACE_H__
#define __UART_INTERFACE_H__

#include "UART_PRIVATE.h" /** @todo To be removed. */

/*
----------------------------------------------------------------------
- Macros
----------------------------------------------------------------------
*/

/*
----------------------------------------------------------------------
- Data types
----------------------------------------------------------------------
*/



/*
----------------------------------------------------------------------
- Public functions declaration
----------------------------------------------------------------------
*/

extern UART_ErrorStatus_t
MUART1_tUartInit(void);

extern UART_ErrorStatus_t
MUART1_tUartTransmit_Sync(void);

extern UART_ErrorStatus_t
MUART1_tUartReceive_Sync(void);

#endif /* __UART_INTERFACE_H__ */
