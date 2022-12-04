/**
 * @file DIO_PROGRAM.c
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
#include "DIO_PRIVATE.h"
#include "DIO_CONFIG.h"
#include "DIO_INTERFACE.h"

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

/** ------ New ------ Function ------ */
En_DIO_ErrorStatus_t
DIO_EnSetCfg(const St_PortCfg_t * const Copy_tPortCfgInstance)
{
    /* Function variables */
    En_DIO_ErrorStatus_t L_EnThisFuncErrStatus = DIO_NOK;
    En_DIO_ErrorStatus_t L_EnSetterFuncErrStatus = DIO_NOK;

    /* Check if the passed argument is valid */
    if( (DIO_OK == EnPortCfgInstanceHandler(Copy_tCfgInstance)) )
    {
        /* Switch on the passed port */
        switch(Copy_tCfgInstance->Port)
        {
            case DIO_PORTA_ID:
                    L_EnSetterFuncErrStatus =
                    EnSetPORTA_Cfg(Copy_tPortCfgInstance->Pin);
                break;

            case DIO_PORTB_ID:
                    L_EnSetterFuncErrStatus =
                    EnSetPORTB_Cfg(Copy_tPortCfgInstance->Pin);
                break;

            case DIO_PORTC_ID:
                    L_EnSetterFuncErrStatus =
                    EnSetPORTC_Cfg(Copy_tPortCfgInstance->Pin);
                break;

            case DIO_PORTD_ID:
                    L_EnSetterFuncErrStatus =
                    EnSetPORTD_Cfg(Copy_tPortCfgInstance->Pin);
                break;

            case DIO_PORTE_ID:
                    L_EnSetterFuncErrStatus =
                    EnSetPORTE_Cfg(Copy_tPortCfgInstance->Pin);
                break;

            case DIO_PORTF_ID:
                    L_EnSetterFuncErrStatus =
                    EnSetPORTF_Cfg(Copy_tPortCfgInstance->Pin);
                break;

            default:
                    /* Error handle - Print to user */
                break;
        }
        /* Check if the setter function is ok/nok */
        if( (DIO_OK == L_EnSetterFuncErrStatus) )
        {
            /* Error handle - Print to user */
            L_EnThisFuncErrStatus = DIO_OK;
        }
        else {/* Error handle - Print to user */}
    }
    else
    {/* Error handle - Print to user */}

    return L_EnThisFuncErrStatus;
}

/*
----------------------------------------------------------------------
- Private functions implementation
----------------------------------------------------------------------
*/

static En_DIO_ErrorStatus_t
EnSetPORTA_Cfg(const St_PinCfg_t * const Copy_tPinCfgInstance)
{
    /* Function variables */
    En_DIO_ErrorStatus_t L_EnThisFuncErrStatus = DIO_NOK;

    DEFAULT_UNIMPLEMENTED_HANDLER();

    return L_EnThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static En_DIO_ErrorStatus_t
EnSetPORTB_Cfg(const St_PinCfg_t * const Copy_tPinCfgInstance)
{
    /* Function variables */
    En_DIO_ErrorStatus_t L_EnThisFuncErrStatus = DIO_NOK;

    DEFAULT_UNIMPLEMENTED_HANDLER();

    return L_EnThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static En_DIO_ErrorStatus_t
EnSetPORTC_Cfg(const St_PinCfg_t * const Copy_tPinCfgInstance)
{
    /* Function variables */
    En_DIO_ErrorStatus_t L_EnThisFuncErrStatus = DIO_NOK;

    DEFAULT_UNIMPLEMENTED_HANDLER();

    return L_EnThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static En_DIO_ErrorStatus_t
EnSetPORTD_Cfg(const St_PinCfg_t * const Copy_tPinCfgInstance)
{
    /* Function variables */
    En_DIO_ErrorStatus_t L_EnThisFuncErrStatus = DIO_NOK;

    DEFAULT_UNIMPLEMENTED_HANDLER();

    return L_EnThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static En_DIO_ErrorStatus_t
EnSetPORTE_Cfg(const St_PinCfg_t * const Copy_tPinCfgInstance)
{
    /* Function variables */
    En_DIO_ErrorStatus_t L_EnThisFuncErrStatus = DIO_NOK;

    DEFAULT_UNIMPLEMENTED_HANDLER();

    return L_EnThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static En_DIO_ErrorStatus_t
EnSetPORTF_Cfg(const St_PinCfg_t * const Copy_tPinCfgInstance)
{
    /* Function variables */
    En_DIO_ErrorStatus_t L_EnThisFuncErrStatus = DIO_NOK;
    s8 L_s8Iterator = DIO_PORTF_MAX_PIN_NUMS;

    /* Loop for all portf pins */
    for(; (L_s8Iterator >= 0x00U); --L_s8Iterator)
    {
        /* Set all the registers configuration */
        BIT_WRT(GPIO_DATA(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].data);
        BIT_WRT(GPIO_DIR(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].direction);
        BIT_WRT(GPIO_AFSEL(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].af);
        BIT_WRT(GPIO_DR2R(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].dr2);
        BIT_WRT(GPIO_DR4R(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].dr4);
        BIT_WRT(GPIO_DR4R(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].dr8);
        BIT_WRT(GPIO_ODR(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].od);
        BIT_WRT(GPIO_PUR(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].pur);
        BIT_WRT(GPIO_PDR(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].pdr);
        BIT_WRT(GPIO_SLR(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].slr);
        BIT_WRT(GPIO_CR(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].commit);
        (Dio_PinMode_Digital == Copy_tPinCfgInstance[L_s8Iterator].mode) ? /* Set Analog/Digital */
                                                    BIT_SET(GPIO_DEN(GPIOF_APB_BASE_ADDRESS), L_s8Iterator); :
                                                    BIT_SET(GPIO_AMSEL(GPIOF_APB_BASE_ADDRESS), L_s8Iterator);
        BIT_WRT(GPIO_ADCCTL(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].adcctl);
        BIT_WRT(GPIO_DMACTL(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].dmactl);

        /** @defgroup Set interrupt configurations */
        BIT_WRT(GPIO_IM(DIO_PORTF_BUS), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].int_mask);

        /** @todo set the interrupt sense */
    }

    L_EnThisFuncErrStatus = DIO_OK;

    return L_EnThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static En_DIO_ErrorStatus_t
EnPortCfgInstanceHandler(const St_PortCfg_t * const Copy_tPortCfgInstance)
{
    /* Function variables */
    En_DIO_ErrorStatus_t L_EnThisFuncErrStatus = DIO_NOK;

    DEFAULT_UNIMPLEMENTED_HANDLER();

    return L_EnThisFuncErrStatus;
}
