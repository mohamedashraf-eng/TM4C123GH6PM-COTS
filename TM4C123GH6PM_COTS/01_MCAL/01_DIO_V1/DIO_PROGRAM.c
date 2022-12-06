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
    s8 L_s8PinNum = DIO_PORTF_MAX_PIN_NUMS;

    /* Loop for all portf pins */
    for(; (L_s8PinNum >= 0x00U); --L_s8PinNum)
    {
        /* Set all the registers configuration */
        vSetPin_DATA(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].data);
        vSetPin_DIR(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].direction);
        vSetPin_AFSEL(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].af);
        vSetPin_DR2(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].dr2);
        vSetPin_DR4(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].dr4);
        vSetPin_DR8(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].dr8);
        vSetPin_OD(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].od);
        vSetPin_PUR(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].pur);
        vSetPin_PDR(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].pdr);
        vSetPin_SLR(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].slr);
        vSetPin_COMMIT(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].commit);
        (DIO_PIN_MODE_DIGITAL == Copy_tPortCfgInstance->Pin[L_s8PinNum].mode) ? /* Set Analog/Digital */
                                                    vSetPin_DIG(Copy_tPortCfgInstance->Port, L_s8PinNum)  :
                                                    vSetPin_AMSEL(Copy_tPortCfgInstance->Port, L_s8PinNum);
        vSetPin_ADCTL(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].adcctl);
        vSetPin_DMACTL(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].dmactl);

        /** @defgroup Set interrupt configurations */
        vSetPin_INTMASK(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].int_mask);
        vSetPin_INTSENSE(Copy_tPortCfgInstance->Port, L_s8PinNum, Copy_tPortCfgInstance->Pin[L_s8PinNum].int_sense);

    }
}
/** ------ New ------ Function ------ */
static void
vSetPin_DATA(Reg_t Copy_tRegAddr,
             uC_PinID_t Copy_tPinNum,
             u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_DATA(Copy_tRegAddr),  Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_DIG(Reg_t Copy_tRegAddr,
            uC_PinID_t Copy_tPinNum)
{
    BIT_SET(GPIO_DEN(Copy_tRegAddr),  Copy_tPinNum);
}
/** ------ New ------ Function ------ */
static void
vSetPin_AMSEL(Reg_t Copy_tRegAddr,
             uC_PinID_t Copy_tPinNum)
{
    BIT_SET(GPIO_AMSEL(Copy_tRegAddr),  Copy_tPinNum);
}
/** ------ New ------ Function ------ */
static void
vSetPin_DIR(Reg_t Copy_tRegAddr,
            uC_PinID_t Copy_tPinNum,
            u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_DIR(Copy_tRegAddr),  Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_AFSEL(Reg_t Copy_tRegAddr,
              uC_PinID_t Copy_tPinNum,
              u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_AFSEL(Copy_tRegAddr),  Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_OD(Reg_t Copy_tRegAddr,
             uC_PinID_t Copy_tPinNum,
             u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_ODR(Copy_tRegAddr),  Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_PUR(Reg_t Copy_tRegAddr,
            uC_PinID_t Copy_tPinNum,
            u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_PUR(Copy_tRegAddr),  Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_PDR(Reg_t Copy_tRegAddr,
             uC_PinID_t Copy_tPinNum,
             u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_PDR(Copy_tRegAddr),  Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_SLR(Reg_t Copy_tRegAddr,
            uC_PinID_t Copy_tPinNum,
            u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_SLR(Copy_tRegAddr),  Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_COMMIT(Reg_t Copy_tRegAddr,
               uC_PinID_t Copy_tPinNum,
               u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_CR(Copy_tRegAddr),  Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_DR2(Reg_t Copy_tRegAddr,
            uC_PinID_t Copy_tPinNum,
            u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_DR2R(Copy_tRegAddr),  Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_DR4(Reg_t Copy_tRegAddr,
            uC_PinID_t Copy_tPinNum,
            u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_DR4R(Copy_tRegAddr),  Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_DR8(Reg_t Copy_tRegAddr,
            uC_PinID_t Copy_tPinNum,
            u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_DR8R(Copy_tRegAddr), Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_ADCTL(Reg_t Copy_tRegAddr,
              uC_PinID_t Copy_tPinNum,
              u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_ADCCTL(Copy_tRegAddr), Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_DMACTL(Reg_t Copy_tRegAddr,
               uC_PinID_t Copy_tPinNum,
               u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_DMACTL(Copy_tRegAddr), Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_INTMASK(Reg_t Copy_tRegAddr,
             uC_PinID_t Copy_tPinNum,
             u8 Copy_u8PinState)
{
    BIT_WRT(GPIO_IM(Copy_tRegAddr), Copy_tPinNum, Copy_u8PinState);
}
/** ------ New ------ Function ------ */
static void
vSetPin_INTSENSE(Reg_t Copy_tRegAddr,
                 uC_PinID_t Copy_tPinNum,
                 u8 Copy_u8PinState)
{
    /**/
}

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
