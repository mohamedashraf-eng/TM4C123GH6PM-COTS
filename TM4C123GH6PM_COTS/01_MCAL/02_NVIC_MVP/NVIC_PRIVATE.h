/**
 * @file NVIC_PRIVATE.h
 * @author Ahmed Osama, Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Osama, Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __NVIC_PRIVATE_H__
#define __NVIC_PRIVATE_H__

/*
----------------------------------------------------------------------
- Registers file
----------------------------------------------------------------------
*/

#define NVIC_BASE_ADDRESS  ( (u32) (0xE000E100U) )

typedef struct
{
    Reg_t EN[5];
    Reg_t DIS[5];
    Reg_t PEND[5];
    Reg_t UNPEND[5];
    Reg_t ACTIVE[5];
    Reg_t PRI[35];
    Reg_t SWTRIG;
}ST_NVICxRegisters_t;

#define NVIC ( (ST_NVICxRegisters_t volatile * const) (NVIC_BASE_ADDRESS) )

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

typedef u8 NVIC_ErrorStatus_t;

typedef u8 uC_NvicInt_t;

/*
----------------------------------------------------------------------
- Private functions declaration
----------------------------------------------------------------------
*/


#endif /* __NVIC_PRIVATE_H__ */
