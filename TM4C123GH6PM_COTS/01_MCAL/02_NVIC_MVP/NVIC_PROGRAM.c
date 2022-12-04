/**
 * @file NVIC_PROGRAM.c
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief
 * @copyright Copyrights (c) 2022 Osama, Wx
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
#include "NVIC_PRIVATE.h"
#include "NVIC_INTERFACE.h"

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

/**
 * @brief The clever code explaination
 *
 * Suppose: User called MNVIC_tEnablePeriphInt(NVIC_GPIOF);
 * NVIC_GPIOF: HEX 0x06 - BIN 00000110 - DEC 6
 * L_u8RegisterIndex = (DEC 6 >> DEC 5): BIN 00000110 >> DEC 5 = BIN00000000 = DEC 0
 * So it is in the group 0 of the NVIC->EN[L_u8RegisterIndex]
 *
 * To activate the eqv bit inside the register.
 * We shift 1 by the Copy_tPeriphID. Then assign it to the register.
 *
 * @note NVIC->EN Accessibility: Writing 1 has effect / Writing 0 has no effect.
 */
NVIC_ErrorStatus_t
MNVIC_tSetPeriphInt(uC_PeriphID_t Copy_tPeriphID)
{
    /** @brief To avoid unused warning */
    (void) Copy_tPeriphID;

    /* Function data types */
    NVIC_ErrorStatus_t L_tThisFuncStatus = NVIC_SET_PERIPH_INT_FAILED;

    /* Check if the passed peripheral is valid */
    if( (Copy_tPeriphID >= NVIC_MIN_INT_PERIPH_ID) &&
        (Copy_tPeriphID <= NVIC_MAX_INT_PERIPH_ID) )
    {
        /* Get the register index for the passed peripheral */
        /**
         * @brief The clever code used is to shift the peripheral number by 5 (divide by 2 x5)
         *        So that every 32 group will contain the passed 'Copy_tPeriphID'.
         */
        u8 L_u8RegisterIndex = (u8) (Copy_tPeriphID >> 0x05U);

        /**
         * @brief The clever code used is to extract the first 5 bytes only.
         *        Then get the eqiv bit for the passed peripheral. (127 Group)
         */
        NVIC->EN[L_u8RegisterIndex] = (u32) (0x01 << (Copy_tPeriphID & 0x7FU));

        L_tThisFuncStatus = NVIC_SET_PERIPH_INT_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}

NVIC_ErrorStatus_t
MNVIC_tClrPeriphInt(uC_PeriphID_t Copy_tPeriphID)
{
    /** @brief To avoid unused warning */
    (void) Copy_tPeriphID;

    /* Function data types */
    NVIC_ErrorStatus_t L_tThisFuncStatus = NVIC_SET_PERIPH_INT_FAILED;

    /* Check if the passed peripheral is valid */
    if( (Copy_tPeriphID >= NVIC_MIN_INT_PERIPH_ID) &&
        (Copy_tPeriphID <= NVIC_MAX_INT_PERIPH_ID) )
    {
        /* Get the register index for the passed peripheral */
        /**
         * @brief The clever code used is to shift the peripheral number by 5 (divide by 2 x5)
         *        So that every 32 group will contain the passed 'Copy_tPeriphID'.
         */
        u8 L_u8RegisterIndex = (u8) (Copy_tPeriphID >> 0x05U);

        /**
         * @brief The clever code used is to extract the first 5 bytes only.
         *        Then get the eqiv bit for the passed peripheral. (127 Group)
         */
        NVIC->DIS[L_u8RegisterIndex] = (u32) (0x01 << (Copy_tPeriphID & 0x7FU));

        L_tThisFuncStatus = NVIC_SET_PERIPH_INT_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}

NVIC_ErrorStatus_t
MNVIC_tSetPeriphIntPend(uC_PeriphID_t Copy_tPeriphID)
{
    /** @brief To avoid unused warning */
    (void) Copy_tPeriphID;

    /* Function data types */
    NVIC_ErrorStatus_t L_tThisFuncStatus = NVIC_SET_PERIPH_PEND_FAILED;

    /* Check if the passed peripheral is valid */
    if( (Copy_tPeriphID >= NVIC_MIN_INT_PERIPH_ID) &&
        (Copy_tPeriphID <= NVIC_MAX_INT_PERIPH_ID) )
    {
        /* Get the register index for the passed peripheral */
        /**
         * @brief The clever code used is to shift the peripheral number by 5 (divide by 2 x5)
         *        So that every 32 group will contain the passed 'Copy_tPeriphID'.
         */
        u8 L_u8RegisterIndex = (u8) (Copy_tPeriphID >> 0x05U);

        /**
         * @brief The clever code used is to extract the first 5 bytes only.
         *        Then get the eqiv bit for the passed peripheral. (127 Group)
         */
        NVIC->PEND[L_u8RegisterIndex] = (u32) (0x01 << (Copy_tPeriphID & 0x7FU));

        L_tThisFuncStatus = NVIC_SET_PERIPH_PEND_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}

NVIC_ErrorStatus_t
MNVIC_tClrPeriphIntPend(uC_PeriphID_t Copy_tPeriphID)
{
    /** @brief To avoid unused warning */
    (void) Copy_tPeriphID;

    /* Function data types */
    NVIC_ErrorStatus_t L_tThisFuncStatus = NVIC_SET_PERIPH_PEND_FAILED;

    /* Check if the passed peripheral is valid */
    if( (Copy_tPeriphID >= NVIC_MIN_INT_PERIPH_ID) &&
        (Copy_tPeriphID <= NVIC_MAX_INT_PERIPH_ID) )
    {
        /* Get the register index for the passed peripheral */
        /**
         * @brief The clever code used is to shift the peripheral number by 5 (divide by 2 x5)
         *        So that every 32 group will contain the passed 'Copy_tPeriphID'.
         */
        u8 L_u8RegisterIndex = (u8) (Copy_tPeriphID >> 0x05U);

        /**
         * @brief The clever code used is to extract the first 5 bytes only.
         *        Then get the eqiv bit for the passed peripheral. (127 Group)
         */
        NVIC->UNPEND[L_u8RegisterIndex] = (u32) (0x01 << (Copy_tPeriphID & 0x7FU));

        L_tThisFuncStatus = NVIC_SET_PERIPH_PEND_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}

/*
----------------------------------------------------------------------
- Private functions implementation
----------------------------------------------------------------------
*/
