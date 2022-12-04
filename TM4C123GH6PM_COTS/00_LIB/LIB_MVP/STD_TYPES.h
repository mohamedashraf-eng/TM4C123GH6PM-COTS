/**
 * @file STD_TYPES.h
 * @author Ahmed Osama, Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Osama, Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__

/*
----------------------------------------------------------------------
- Standard macros
----------------------------------------------------------------------
*/

#define NULL        ( (void *) (0U) )

/*
----------------------------------------------------------------------
- Standard base types
----------------------------------------------------------------------
*/
/** @defgroup Custom Data type Enums */

/** @defgroup unsigned integers types */
typedef unsigned char       u8;
typedef unsigned short int  u16;
typedef unsigned long int   u32;
/** @defgroup signed integers types */
typedef signed char         s8;
typedef signed short int    s16;
typedef signed long int     s32;
/** @defgroup floating types */
typedef float               f32;
typedef double              f64;
typedef long double         f128;

/** @defgroup Custom Data Types */
typedef u8 bool_t;

/** @defgroup Microcontroller Specific Enums */
/**
 * @brief Microcontroller [TM4C123GH6PM] Peripherals.
 */
typedef const u8 uC_PeriphID_t;
typedef const u8 uC_PeriphNum_t;
/**
 * @brief Microcontroller [TM4C123GH6PM] Buses.
 */
typedef const u8 uC_BusID_t;
/**
 * @brief Microcontroller [TM4C123GH6PM] Ports.
 */
typedef const u8 uC_PortID_t;
/**
 * @brief Microcontroller [TM4C123GH6PM] Ports Specific Pins.
 */
typedef const u8 uC_PinID_t;


/**
 * @brief Standard types for backend develop
 */
typedef u32 volatile Reg_t;

/*
----------------------------------------------------------------------
- Standard enum types
----------------------------------------------------------------------
*/

/** @defgroup Custom Data type Enums */
#define bool_false          ( (u8) (0x00U) )
#define bool_true           ( (u8) (0x01U) )

#endif /* __STD_TYPES_H__ */
