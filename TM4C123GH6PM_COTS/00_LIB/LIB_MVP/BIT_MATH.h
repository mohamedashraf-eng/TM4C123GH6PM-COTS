/**
 * @file BIT_MATH.h
 * @author Ahmed Osama, Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard bit math
 * @copyright Copyrights (c) 2022 Osama, Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __BIT_MATH_H__
#define __BIT_MATH_H__

/*
----------------------------------------------------------------------
- Function like macros
----------------------------------------------------------------------
*/

/** @defgroup Bit Level Manipulations */
/**
 * @brief Function like macro to turn bit to 'VAL'.
 *
 */
#define BIT_WRT(_REG, _BIT, _VAL) ( (_REG) = (( (_REG) & (~(1<<(_BIT))) ) | ((_VAL) << (_BIT))) )
/**
 * @brief Function like macro to turn bit to '1'.
 *
 */
#define BIT_SET(_REG, _BIT) ( (_REG) |= (1U << (_BIT)) )
/**
 * @brief Function like macro to turn bit to '0'.
 *
 */
#define BIT_CLR(_REG, _BIT) ( (_REG) &= (~(1U << (_BIT))) )
/**
 * @brief Function like macro to turn bit to '~bit'.
 *
 */
#define BIT_TOG(_REG, _BIT) ( (_REG) ^= (1U << (_BIT)) )
/**
 * @brief Function like macro to get the bit value.
 *
 */
#define BIT_GET(_REG, _BIT) ( (_REG) & (1U << (_BIT)) )

/** @defgroup Register Level Manipulations */
/**
 * @brief Function like macro to turn register to '1'
 *
 */
#define REG_SET(_REG) ( (_REG) |= (~(0x00U)) )
/**
 * @brief Function like macro to turn register to '0'
 *
 */
#define REG_CLR(_REG) ( (_REG) &= (~(_REG)) )
/**
 * @brief Function like macro to turn register to '~REG'
 *
 */
#define REG_TOG(_REG) ( (_REG) ^= (_REG) )
/**
 * @brief Function like macro to get the register value.
 *
 */
#define REG_GET(_REG) ( (_REG) )
/**
 * @brief Function like macro to get the register value.
 *
 */
#define REG_WRT(_REG, _VAL) ( (_REG) = (_VAL) )


/* TODO: Create the bit math as inline functions */

#endif /* __BIT_MATH_H__ */
