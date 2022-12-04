/**
 * @file UART_PRIVATE.h
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __UART_PRIVATE_H__
#define __UART_PRIVATE_H__

/*
----------------------------------------------------------------------
- Registers file
----------------------------------------------------------------------
*/

#define UART1_BASE_ADDRESS    ( (u32) (0x4000C000) )
#define UART2_BASE_ADDRESS    ( (u32) (0x4000D000) )
#define UART3_BASE_ADDRESS    ( (u32) (0x4000E000) )
#define UART4_BASE_ADDRESS    ( (u32) (0x4000F000) )
#define UART5_BASE_ADDRESS    ( (u32) (0x4001D000) )
#define UART6_BASE_ADDRESS    ( (u32) (0x4001D100) )
#define UART7_BASE_ADDRESS    ( (u32) (0x4001D200) )

/**
 * @brief Register map for UART
 */
typedef struct
{
    Reg_t DR;
    union
    {
      Reg_t ECR_UART_ALT;
      Reg_t RSR;
    };
    Reg_t
    Reg_t RESERVED[4];
    Reg_t FR;
    Reg_t RESERVED1;
    Reg_t ILPR;
    Reg_t IBRD;
    Reg_t FBRD;
    Reg_t LCRH;
    Reg_t CTL;
    Reg_t IFLS;
    Reg_t IM;
    Reg_t RIS;
    Reg_t MIS;
    Reg_t ICR;
    Reg_t DMACTL;
    Reg_t RESERVED2[22];
    Reg_t _9BITADDR;
    Reg_t _9BITAMASK;
    Reg_t RESERVED3[965];
    Reg_t PP;
    Reg_t RESERVED4;
    Reg_t CC;
}ST_UARTRegisters_t;

#define UART1 ( (ST_UARTRegisters_t volatile * const) (UART1_BASE_ADDRESS) )
#define UART2 ( (ST_UARTRegisters_t volatile * const) (UART2_BASE_ADDRESS) )
#define UART3 ( (ST_UARTRegisters_t volatile * const) (UART3_BASE_ADDRESS) )
#define UART4 ( (ST_UARTRegisters_t volatile * const) (UART4_BASE_ADDRESS) )
#define UART5 ( (ST_UARTRegisters_t volatile * const) (UART5_BASE_ADDRESS) )
#define UART6 ( (ST_UARTRegisters_t volatile * const) (UART6_BASE_ADDRESS) )
#define UART7 ( (ST_UARTRegisters_t volatile * const) (UART7_BASE_ADDRESS) )
#define UART8 ( (ST_UARTRegisters_t volatile * const) (UART8_BASE_ADDRESS) )

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

typedef u8 UART_ErrorStatus_t;

/*
----------------------------------------------------------------------
- Private functions declaration
----------------------------------------------------------------------
*/


#endif /* __UART_PRIVATE_H__ */
