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

/** @defgroup Call back functions */
DIO_CallBackFuncPtr_t G_tCallBackFuncPtr[DIO_NUM_OF_PORTS] = {NULL, NULL, NULL,
                                                              NULL, NULL, NULL};

/*
----------------------------------------------------------------------
- Public functions implementation
----------------------------------------------------------------------
*/

/** ------ New ------ Function ------ */
En_DIO_ErrorStatus_t
MDIO_EnSetCfg(const St_PortCfg_t * const Copy_tPortCfgInstance)
{
    /* Function variables */
    En_DIO_ErrorStatus_t L_EnThisFuncErrStatus = DIO_NOK;

    /* Check if the passed argument is valid */
    if( (DIO_OK == EnPortCfgInstanceHandler(Copy_tPortCfgInstance)) )
    {
        /* Set the configurations */
        vSetPORT_PinCfg(Copy_tPortCfgInstance);

        L_EnThisFuncErrStatus = DIO_OK;
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
/** ------ New ------ Function ------ */
static En_DIO_ErrorStatus_t
EnPortCfgInstanceHandler(const St_PortCfg_t * const Copy_tPortCfgInstance)
{
    /* Function variables */
    En_DIO_ErrorStatus_t L_EnThisFuncErrStatus = DIO_OK;

    /*DEFAULT_UNIMPLEMENTED_HANDLER();*/

    return L_EnThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static void
vSetPORT_PinCfg(const St_PortCfg_t * const Copy_tPortCfgInstance)
{
    s8 L_s8Iterator = DIO_PORTF_MAX_PIN_NUMS;

    /* Loop for all portf pins */
    for(; (L_s8Iterator >= 0x00U); --L_s8Iterator)
    {
        /* Set all the registers configuration */
        BIT_WRT(GPIO_DATA(Copy_tPortCfgInstance->Port),  L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].data);
        BIT_WRT(GPIO_DIR(Copy_tPortCfgInstance->Port),   L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].direction);
        BIT_WRT(GPIO_AFSEL(Copy_tPortCfgInstance->Port), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].af);
        BIT_WRT(GPIO_DR2R(Copy_tPortCfgInstance->Port),  L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].dr2);
        BIT_WRT(GPIO_DR4R(Copy_tPortCfgInstance->Port),  L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].dr4);
        BIT_WRT(GPIO_DR4R(Copy_tPortCfgInstance->Port),  L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].dr8);
        BIT_WRT(GPIO_ODR(Copy_tPortCfgInstance->Port),   L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].od);
        BIT_WRT(GPIO_PUR(Copy_tPortCfgInstance->Port),   L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].pur);
        BIT_WRT(GPIO_PDR(Copy_tPortCfgInstance->Port),   L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].pdr);
        BIT_WRT(GPIO_SLR(Copy_tPortCfgInstance->Port),   L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].slr);
        BIT_WRT(GPIO_CR(Copy_tPortCfgInstance->Port),    L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].commit);
        (DIO_PIN_MODE_DIGITAL == Copy_tPinCfgInstance[L_s8Iterator].mode) ? /* Set Analog/Digital */
                                                    BIT_SET(GPIO_DEN(Copy_tPortCfgInstance->Port), L_s8Iterator)  :
                                                    BIT_SET(GPIO_AMSEL(Copy_tPortCfgInstance->Port), L_s8Iterator);
        BIT_WRT(GPIO_ADCCTL(Copy_tPortCfgInstance->Port), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].adcctl);
        BIT_WRT(GPIO_DMACTL(Copy_tPortCfgInstance->Port), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].dmactl);

        /** @defgroup Set interrupt configurations */
        BIT_WRT(GPIO_IM(Copy_tPortCfgInstance->Port), L_s8Iterator, Copy_tPinCfgInstance[L_s8Iterator].int_mask);

        /** @todo set the interrupt sense */
    }
}
/** ------ New ------ Function ------ */
/** @defgroup Interrupt ISR functions */
static En_DIO_ErrorStatus_t
EnSetCallBack(uC_PortID_t Copy_tPortID,
              DIO_CallBackFuncPtr_t Copy_tCallBackFunc)
{
    En_DIO_ErrorStatus_t L_EnThisFuncErrStatus = DIO_NOK;

    /* Check the function validity */
    if( (NULL != Copy_tCallBackFunc) )
    {
        /* Switch on the port */
        switch(Copy_tPortID)
        {
            case DIO_PORTA_ID:
                    G_tCallBackFuncPtr[DIO_PORTA_ID] = Copy_tCallBackFunc;
                break;
            case DIO_PORTB_ID:
                    G_tCallBackFuncPtr[DIO_PORTB_ID] = Copy_tCallBackFunc;
                break;
            case DIO_PORTC_ID:
                    G_tCallBackFuncPtr[DIO_PORTC_ID] = Copy_tCallBackFunc;
                break;
            case DIO_PORTD_ID:
                    G_tCallBackFuncPtr[DIO_PORTD_ID] = Copy_tCallBackFunc;
                break;
            case DIO_PORTE_ID:
                    G_tCallBackFuncPtr[DIO_PORTE_ID] = Copy_tCallBackFunc;
                break;
            case DIO_PORTF_ID:
                    G_tCallBackFuncPtr[DIO_PORTF_ID] = Copy_tCallBackFunc;
                break;

            default:
                    /* Error handle - Print to user */
                break;
        }

        L_EnThisFuncErrStatus = DIO_OK;
    }
    else {/* Error handle - Print to user */}

    return L_EnThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
void GPIOA_Handler(void)
{
    /* Check the function validity */
    if( (NULL != G_tCallBackFuncPtr[DIO_PORTA_ID]) )
    {
        /* Call the function */
        G_tCallBackFuncPtr[DIO_PORTA_ID]();
    }
    else {/* Error handle - Print to user */}
}
/** ------ New ------ Function ------ */
void GPIOB_Handler(void)
{
    /* Check the function validity */
    if( (NULL != G_tCallBackFuncPtr[DIO_PORTB_ID]) )
    {
        /* Call the function */
        G_tCallBackFuncPtr[DIO_PORTB_ID]();
    }
    else {/* Error handle - Print to user */}
}
/** ------ New ------ Function ------ */
void GPIOC_Handler(void)
{
    /* Check the function validity */
    if( (NULL != G_tCallBackFuncPtr[DIO_PORTC_ID]) )
    {
        /* Call the function */
        G_tCallBackFuncPtr[DIO_PORTC_ID]();
    }
    else {/* Error handle - Print to user */}
}
/** ------ New ------ Function ------ */
void GPIOD_Handler(void)
{
    /* Check the function validity */
    if( (NULL != G_tCallBackFuncPtr[DIO_PORTD_ID]) )
    {
        /* Call the function */
        G_tCallBackFuncPtr[DIO_PORTD_ID]();
    }
    else {/* Error handle - Print to user */}
}
/** ------ New ------ Function ------ */
void GPIOE_Handler(void)
{
    /* Check the function validity */
    if( (NULL != G_tCallBackFuncPtr[DIO_PORTE_ID]) )
    {
        /* Call the function */
        G_tCallBackFuncPtr[DIO_PORTE_ID]();
    }
    else {/* Error handle - Print to user */}
}
/** ------ New ------ Function ------ */
void GPIOF_Handler(void)
{
    /* Check the function validity */
    if( (NULL != G_tCallBackFuncPtr[DIO_PORTF_ID]) )
    {
        /* Call the function */
        G_tCallBackFuncPtr[DIO_PORTF_ID]();
    }
    else {/* Error handle - Print to user */}
}
