/**
 * @file DIO_PROGRAM.c
 * @author Ahmed Osama, Mohamed Ashraf
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
#include "DIO_PRIVATE.h"
#include "DIO_CONFIG.h"
#include "DIO_INTERFACE.h"

/*
----------------------------------------------------------------------
- Global data types
----------------------------------------------------------------------
*/

/**
 * @brief Array of function pointers to store
 *        the passed callback function for each GPIO.
 *
 */
GPIO_EXTI_FuncPtr_t GPIO_EXTI_FuncPtr[NUM_OF_PORTS] = {NULL};

/*
----------------------------------------------------------------------
- Public functions implementation
----------------------------------------------------------------------
*/

/** ------ New ------ Function ------ */
DIO_ErrorStatus_t
MDIO_tSetPinDir(uC_PortID_t Copy_tPortID,
                uC_PinID_t Copy_tPinID,
                uC_BusID_t Copy_tBusID,
                uC_PinDir_t Copy_tPinDir)
{
    /** @brief For unused warning */
	(void) Copy_tPortID;
	(void) Copy_tPinID;
    (void) Copy_tBusID;
    (void) Copy_tPinDir;

    /* Function data types */
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIR_FAILED;
    DIO_ErrorStatus_t L_tSetterFuncStatus = DIO_SET_PIN_DIR_FAILED;

    /* Check if the port is valid */
    if( (Copy_tPortID >= DIO_PORT_MIN) &&
        (Copy_tPortID <= DIO_PORT_MAX) )
    {
        /* Switch around the ports */
        switch(Copy_tPortID)
        {
            case DIO_PORTA_ID:
                    L_tSetterFuncStatus =
                    tSetPinDir_PORTA(Copy_tBusID, Copy_tPinID, Copy_tPinDir);
                break;
            case DIO_PORTB_ID:
                    L_tSetterFuncStatus =
                    tSetPinDir_PORTB(Copy_tBusID, Copy_tPinID, Copy_tPinDir);
                break;
            case DIO_PORTC_ID:
                    L_tSetterFuncStatus =
                    tSetPinDir_PORTC(Copy_tBusID, Copy_tPinID, Copy_tPinDir);
                break;
            case DIO_PORTD_ID:
                    L_tSetterFuncStatus =
                    tSetPinDir_PORTD(Copy_tBusID, Copy_tPinID, Copy_tPinDir);
                break;
            case DIO_PORTE_ID:
                    L_tSetterFuncStatus =
                    tSetPinDir_PORTE(Copy_tBusID, Copy_tPinID, Copy_tPinDir);
                break;
            case DIO_PORTF_ID:
                    L_tSetterFuncStatus =
                    tSetPinDir_PORTF(Copy_tBusID, Copy_tPinID, Copy_tPinDir);
                break;
            default:
                    /* Error handle - Print to user */
                    DEFAULT_ERROR_HANDLER();
                break;
        }
    }
    else {/* Error handle - Print to user */}

    /* Check if any of the setter function returned an error */
    if( (DIO_SET_PIN_DIR_SUCC == L_tSetterFuncStatus) )
    {
        L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
} 
/** ------ New ------ Function ------ */
DIO_ErrorStatus_t
MDIO_tSetPinCurrentDrive(uC_PortID_t Copy_tPortID,
                         uC_PinID_t Copy_tPinID,
                         uC_BusID_t Copy_tBusID,
                         uC_PinCurrentDrive_t Copy_tCurrentDrive)
{
    /** @brief For unused warning */
    (void) Copy_tPortID;
    (void) Copy_tPinID;
    (void) Copy_tBusID;
    (void) Copy_tCurrentDrive;

    /* Function data types */
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_CD_FAILED;
    DIO_ErrorStatus_t L_tSetterFuncStatus = DIO_SET_PIN_CD_FAILED;

    /* Check if the port is valid */
    if( (Copy_tPortID >= DIO_PORT_MIN) &&
        (Copy_tPortID <= DIO_PORT_MAX) )
    {
        /* Switch around the ports */
        switch(Copy_tPortID)
        {
            case DIO_PORTA_ID:
                    L_tSetterFuncStatus =
                    tSetPinCurrDrv_PORTA(Copy_tBusID, Copy_tPinID, Copy_tCurrentDrive);
                break;
            case DIO_PORTB_ID:
                    L_tSetterFuncStatus =
                    tSetPinCurrDrv_PORTB(Copy_tBusID, Copy_tPinID, Copy_tCurrentDrive);
                break;
            case DIO_PORTC_ID:
                    L_tSetterFuncStatus =
                    tSetPinCurrDrv_PORTC(Copy_tBusID, Copy_tPinID, Copy_tCurrentDrive);
                break;
            case DIO_PORTD_ID:
                    L_tSetterFuncStatus =
                    tSetPinCurrDrv_PORTD(Copy_tBusID, Copy_tPinID, Copy_tCurrentDrive);
                break;
            case DIO_PORTE_ID:
                    L_tSetterFuncStatus =
                    tSetPinCurrDrv_PORTE(Copy_tBusID, Copy_tPinID, Copy_tCurrentDrive);
                break;
            case DIO_PORTF_ID:
                    L_tSetterFuncStatus =
                    tSetPinCurrDrv_PORTF(Copy_tBusID, Copy_tPinID, Copy_tCurrentDrive);
                break;
            default:
                    /* Error handle - Print to user */
                    DEFAULT_ERROR_HANDLER();
                break;
        }
    }
    else {/* Error handle - Print to user */}

    /* Check if any of the setter function returned an error */
    if( (DIO_SET_PIN_CD_SUCC == L_tSetterFuncStatus) )
    {
        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}

DIO_ErrorStatus_t
MDIO_tSetPinDig(uC_PortID_t Copy_tPortID,
                uC_PinID_t Copy_tPinID,
                uC_BusID_t Copy_tBusID,
                uC_PinState_t Copy_tDigState)
{
    /** @brief For unused warning */
    (void) Copy_tPortID;
    (void) Copy_tPinID;
    (void) Copy_tBusID;
    (void) Copy_tDigState;

    /* Function data types */
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIG_FAILED;
    DIO_ErrorStatus_t L_tSetterFuncStatus = DIO_SET_PIN_DIG_FAILED;

    /* Check if the port is valid */
    if( (Copy_tPortID >= DIO_PORT_MIN) &&
        (Copy_tPortID <= DIO_PORT_MAX) )
    {
        /* Switch around the ports */
        switch(Copy_tPortID)
        {
            case DIO_PORTA_ID:
                    L_tSetterFuncStatus =
                    tSetPinDig_PORTA(Copy_tBusID, Copy_tPinID, Copy_tDigState);
                break;
            case DIO_PORTB_ID:
                    L_tSetterFuncStatus =
                    tSetPinDig_PORTB(Copy_tBusID, Copy_tPinID, Copy_tDigState);
                break;
            case DIO_PORTC_ID:
                    L_tSetterFuncStatus =
                    tSetPinDig_PORTC(Copy_tBusID, Copy_tPinID, Copy_tDigState);
                break;
            case DIO_PORTD_ID:
                    L_tSetterFuncStatus =
                    tSetPinDig_PORTD(Copy_tBusID, Copy_tPinID, Copy_tDigState);
                break;
            case DIO_PORTE_ID:
                    L_tSetterFuncStatus =
                    tSetPinDig_PORTE(Copy_tBusID, Copy_tPinID, Copy_tDigState);
                break;
            case DIO_PORTF_ID:
                    L_tSetterFuncStatus =
                    tSetPinDig_PORTF(Copy_tBusID, Copy_tPinID, Copy_tDigState);
                break;
            default:
                    /* Error handle - Print to user */
                    DEFAULT_ERROR_HANDLER();
                break;
        }
    }
    else {/* Error handle - Print to user */}

    /* Check if any of the setter function returned an error */
    if( (DIO_SET_PIN_DIG_SUCC == L_tSetterFuncStatus) )
    {
        L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}

DIO_ErrorStatus_t
MDIO_tSetPinVal(uC_PortID_t Copy_tPortID,
                uC_PinID_t Copy_tPinID,
                uC_BusID_t Copy_tBusID,
                uC_PinVal_t Copy_tPinVal)
{
    /** @brief For unused warning */
    (void) Copy_tPortID;
    (void) Copy_tPinID;
    (void) Copy_tBusID;
    (void) Copy_tPinVal;

    /* Function data types */
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_VAL_FAILED;
    DIO_ErrorStatus_t L_tSetterFuncStatus = DIO_SET_PIN_VAL_FAILED;

    /* Check if the port is valid */
    if( (Copy_tPortID >= DIO_PORT_MIN) &&
        (Copy_tPortID <= DIO_PORT_MAX) )
    {
        /* Switch around the ports */
        switch(Copy_tPortID)
        {
            case DIO_PORTA_ID:
                    L_tSetterFuncStatus =
                    tSetPinVal_PORTA(Copy_tBusID, Copy_tPinID, Copy_tPinVal);
                break;
            case DIO_PORTB_ID:
                    L_tSetterFuncStatus =
                    tSetPinVal_PORTB(Copy_tBusID, Copy_tPinID, Copy_tPinVal);
                break;
            case DIO_PORTC_ID:
                    L_tSetterFuncStatus =
                    tSetPinVal_PORTC(Copy_tBusID, Copy_tPinID, Copy_tPinVal);
                break;
            case DIO_PORTD_ID:
                    L_tSetterFuncStatus =
                    tSetPinVal_PORTD(Copy_tBusID, Copy_tPinID, Copy_tPinVal);
                break;
            case DIO_PORTE_ID:
                    L_tSetterFuncStatus =
                    tSetPinVal_PORTE(Copy_tBusID, Copy_tPinID, Copy_tPinVal);
                break;
            case DIO_PORTF_ID:
                    L_tSetterFuncStatus =
                    tSetPinVal_PORTF(Copy_tBusID, Copy_tPinID, Copy_tPinVal);
                break;
            default:
                    /* Error handle - Print to user */
                    DEFAULT_ERROR_HANDLER();
                break;
        }
    }
    else {/* Error handle - Print to user */}

    /* Check if any of the setter function returned an error */
    if( (DIO_SET_PIN_VAL_SUCC == L_tSetterFuncStatus) )
    {
        L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
DIO_ErrorStatus_t
MDIO_tSetPinIntSense(uC_PortID_t Copy_tPortID,
                     uC_PinID_t Copy_tPinID,
                     uC_BusID_t Copy_tBusID,
                     uC_PinInt_t Copy_tPinIntSense)
{
    /** @brief For unused warning */
    (void) Copy_tPortID;
    (void) Copy_tPinID;
    (void) Copy_tBusID;
    (void) Copy_tPinIntSense;

    /* Function data types */
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_INT_FAILED;
    DIO_ErrorStatus_t L_tSetterFuncStatus = DIO_SET_PIN_INT_FAILED;

    /* Check if the port is valid */
    if( (Copy_tPortID >= DIO_PORT_MIN) &&
        (Copy_tPortID <= DIO_PORT_MAX) )
    {
        /* Switch around the ports */
        switch(Copy_tPortID)
        {
            case DIO_PORTA_ID:
                    L_tSetterFuncStatus =
                    tSetPinIntSense_PORTA(Copy_tBusID, Copy_tPinID, Copy_tPinIntSense);
                break;
            case DIO_PORTB_ID:
                    L_tSetterFuncStatus =
                    tSetPinIntSense_PORTB(Copy_tBusID, Copy_tPinID, Copy_tPinIntSense);
                break;
            case DIO_PORTC_ID:
                    L_tSetterFuncStatus =
                    tSetPinIntSense_PORTC(Copy_tBusID, Copy_tPinID, Copy_tPinIntSense);
                break;
            case DIO_PORTD_ID:
                    L_tSetterFuncStatus =
                    tSetPinIntSense_PORTD(Copy_tBusID, Copy_tPinID, Copy_tPinIntSense);
                break;
            case DIO_PORTE_ID:
                    L_tSetterFuncStatus =
                    tSetPinIntSense_PORTE(Copy_tBusID, Copy_tPinID, Copy_tPinIntSense);
                break;
            case DIO_PORTF_ID:
                    L_tSetterFuncStatus =
                    tSetPinIntSense_PORTF(Copy_tBusID, Copy_tPinID, Copy_tPinIntSense);
                break;
            default:
                    /* Error handle - Print to user */
                    DEFAULT_ERROR_HANDLER();
                break;
        }
    }
    else {/* Error handle - Print to user */}

    /* Check if any of the setter function returned an error */
    if( (DIO_SET_PIN_INT_SUCC == L_tSetterFuncStatus) )
    {
        L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}

DIO_ErrorStatus_t
MDIO_tSetPinPUR(uC_PortID_t Copy_tPortID,
                     uC_PinID_t Copy_tPinID,
                     uC_BusID_t Copy_tBusID)
{
    /** @brief For unused warning */
    (void) Copy_tPortID;
    (void) Copy_tPinID;
    (void) Copy_tBusID;

    /* Function data types */
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PUR_FAILED;
    DIO_ErrorStatus_t L_tSetterFuncStatus = DIO_SET_PIN_PUR_FAILED;

    /* Check if the port is valid */
    if( (Copy_tPortID >= DIO_PORT_MIN) &&
        (Copy_tPortID <= DIO_PORT_MAX) )
    {
        /* Switch around the ports */
        switch(Copy_tPortID)
        {
            case DIO_PORTA_ID:
                    L_tSetterFuncStatus =
                    tSetPinPUR_PORTA(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTB_ID:
                    L_tSetterFuncStatus =
                    tSetPinPUR_PORTB(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTC_ID:
                    L_tSetterFuncStatus =
                    tSetPinPUR_PORTC(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTD_ID:
                    L_tSetterFuncStatus =
                    tSetPinPUR_PORTD(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTE_ID:
                    L_tSetterFuncStatus =
                    tSetPinPUR_PORTE(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTF_ID:
                    L_tSetterFuncStatus =
                    tSetPinPUR_PORTF(Copy_tBusID, Copy_tPinID);
                break;
            default:
                    /* Error handle - Print to user */
                    DEFAULT_ERROR_HANDLER();
                break;
        }
    }
    else {/* Error handle - Print to user */}

    /* Check if any of the setter function returned an error */
    if( (DIO_SET_PIN_PUR_SUCC == L_tSetterFuncStatus) )
    {
        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
DIO_ErrorStatus_t
MDIO_tSetPinPDR(uC_PortID_t Copy_tPortID,
                uC_PinID_t Copy_tPinID,
                uC_BusID_t Copy_tBusID)
{
   /** @brief For unused warning */
    (void) Copy_tPortID;
    (void) Copy_tPinID;
    (void) Copy_tBusID;

    /* Function data types */
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PDR_FAILED;
    DIO_ErrorStatus_t L_tSetterFuncStatus = DIO_SET_PIN_PDR_FAILED;

    /* Check if the port is valid */
    if( (Copy_tPortID >= DIO_PORT_MIN) &&
        (Copy_tPortID <= DIO_PORT_MAX) )
    {
        /* Switch around the ports */
        switch(Copy_tPortID)
        {
            case DIO_PORTA_ID:
                    L_tSetterFuncStatus =
                    tSetPinPDR_PORTA(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTB_ID:
                    L_tSetterFuncStatus =
                    tSetPinPDR_PORTB(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTC_ID:
                    L_tSetterFuncStatus =
                    tSetPinPDR_PORTC(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTD_ID:
                    L_tSetterFuncStatus =
                    tSetPinPDR_PORTD(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTE_ID:
                    L_tSetterFuncStatus =
                    tSetPinPDR_PORTE(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTF_ID:
                    L_tSetterFuncStatus =
                    tSetPinPDR_PORTF(Copy_tBusID, Copy_tPinID);
                break;
            default:
                    /* Error handle - Print to user */
                    DEFAULT_ERROR_HANDLER();
                break;
        }
    }
    else {/* Error handle - Print to user */}

    /* Check if any of the setter function returned an error */
    if( (DIO_SET_PIN_PDR_SUCC == L_tSetterFuncStatus) )
    {
        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
DIO_ErrorStatus_t
MDIO_tSetPinOD(uC_PortID_t Copy_tPortID,
               uC_PinID_t Copy_tPinID,
               uC_BusID_t Copy_tBusID)
{
   /** @brief For unused warning */
    (void) Copy_tPortID;
    (void) Copy_tPinID;
    (void) Copy_tBusID;

    /* Function data types */
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_OD_FAILED;
    DIO_ErrorStatus_t L_tSetterFuncStatus = DIO_SET_PIN_OD_FAILED;

    /* Check if the port is valid */
    if( (Copy_tPortID >= DIO_PORT_MIN) &&
        (Copy_tPortID <= DIO_PORT_MAX) )
    {
        /* Switch around the ports */
        switch(Copy_tPortID)
        {
            case DIO_PORTA_ID:
                    L_tSetterFuncStatus =
                    tSetPinOD_PORTA(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTB_ID:
                    L_tSetterFuncStatus =
                    tSetPinOD_PORTB(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTC_ID:
                    L_tSetterFuncStatus =
                    tSetPinOD_PORTC(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTD_ID:
                    L_tSetterFuncStatus =
                    tSetPinOD_PORTD(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTE_ID:
                    L_tSetterFuncStatus =
                    tSetPinOD_PORTE(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTF_ID:
                    L_tSetterFuncStatus =
                    tSetPinOD_PORTF(Copy_tBusID, Copy_tPinID);
                break;
            default:
                    /* Error handle - Print to user */
                    DEFAULT_ERROR_HANDLER();
                break;
        }
    }
    else {/* Error handle - Print to user */}

    /* Check if any of the setter function returned an error */
    if( (DIO_SET_PIN_OD_SUCC == L_tSetterFuncStatus) )
    {
        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
DIO_ErrorStatus_t
MDIO_tSetPinAF(uC_PortID_t Copy_tPortID,
               uC_PinID_t Copy_tPinID,
               uC_BusID_t Copy_tBusID)
{
   /** @brief For unused warning */
    (void) Copy_tPortID;
    (void) Copy_tPinID;
    (void) Copy_tBusID;

    /* Function data types */
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_AF_FAILED;
    DIO_ErrorStatus_t L_tSetterFuncStatus = DIO_SET_PIN_AF_FAILED;

    /* Check if the port is valid */
    if( (Copy_tPortID >= DIO_PORT_MIN) &&
        (Copy_tPortID <= DIO_PORT_MAX) )
    {
        /* Switch around the ports */
        switch(Copy_tPortID)
        {
            case DIO_PORTA_ID:
                    L_tSetterFuncStatus =
                    tSetPinAF_PORTA(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTB_ID:
                    L_tSetterFuncStatus =
                    tSetPinAF_PORTB(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTC_ID:
                    L_tSetterFuncStatus =
                    tSetPinAF_PORTC(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTD_ID:
                    L_tSetterFuncStatus =
                    tSetPinAF_PORTD(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTE_ID:
                    L_tSetterFuncStatus =
                    tSetPinAF_PORTE(Copy_tBusID, Copy_tPinID);
                break;
            case DIO_PORTF_ID:
                    L_tSetterFuncStatus =
                    tSetPinAF_PORTF(Copy_tBusID, Copy_tPinID);
                break;
            default:
                    /* Error handle - Print to user */
                    DEFAULT_ERROR_HANDLER();
                break;
        }
    }
    else {/* Error handle - Print to user */}

    /* Check if any of the setter function returned an error */
    if( (DIO_SET_PIN_AF_SUCC == L_tSetterFuncStatus) )
    {
        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
DIO_ErrorStatus_t
MDIO_tSetPinIntState(uC_PortID_t Copy_tPortID,
                     uC_PinID_t Copy_tPinID,
                     uC_BusID_t Copy_tBusID,
                     uC_PinInt_t Copy_tPinIntState)
{
    /** @brief For unused warning */
    (void) Copy_tPortID;
    (void) Copy_tPinID;
    (void) Copy_tBusID;
    (void) Copy_tPinIntState;

    /* Function data types */
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_INT_FAILED;
    DIO_ErrorStatus_t L_tSetterFuncStatus = DIO_SET_PIN_INT_FAILED;

    /* Check if the port is valid */
    if( (Copy_tPortID >= DIO_PORT_MIN) &&
        (Copy_tPortID <= DIO_PORT_MAX) )
    {
        /* Switch around the ports */
        switch(Copy_tPortID)
        {
            case DIO_PORTA_ID:
                    L_tSetterFuncStatus =
                    tSetPinIntState_PORTA(Copy_tBusID, Copy_tPinID, Copy_tPinIntState);
                break;
            case DIO_PORTB_ID:
                    L_tSetterFuncStatus =
                    tSetPinIntState_PORTB(Copy_tBusID, Copy_tPinID, Copy_tPinIntState);
                break;
            case DIO_PORTC_ID:
                    L_tSetterFuncStatus =
                    tSetPinIntState_PORTC(Copy_tBusID, Copy_tPinID, Copy_tPinIntState);
                break;
            case DIO_PORTD_ID:
                    L_tSetterFuncStatus =
                    tSetPinIntState_PORTD(Copy_tBusID, Copy_tPinID, Copy_tPinIntState);
                break;
            case DIO_PORTE_ID:
                    L_tSetterFuncStatus =
                    tSetPinIntState_PORTE(Copy_tBusID, Copy_tPinID, Copy_tPinIntState);
                break;
            case DIO_PORTF_ID:
                    L_tSetterFuncStatus =
                    tSetPinIntState_PORTF(Copy_tBusID, Copy_tPinID, Copy_tPinIntState);
                break;
            default:
                    /* Error handle - Print to user */
                    DEFAULT_ERROR_HANDLER();
                break;
        }
    }
    else {/* Error handle - Print to user */}

    /* Check if any of the setter function returned an error */
    if( (DIO_SET_PIN_INT_SUCC == L_tSetterFuncStatus) )
    {
        L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
DIO_ErrorStatus_t
MDIO_tGetPinIntStatus(uC_PortID_t Copy_tPortID,
                      uC_PinID_t Copy_tPinID,
                      uC_BusID_t Copy_tBusID,
                      uC_PinInt_t *pArg_tPinIntStatus)
{
    /** @brief For unused warning */
    (void) Copy_tPortID;
    (void) Copy_tPinID;
    (void) Copy_tBusID;
    (void *) pArg_tPinIntStatus;

    /* Function data types */
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_GET_PIN_INT_FAILED;
    DIO_ErrorStatus_t L_tSetterFuncStatus = DIO_GET_PIN_INT_FAILED;
		
    u8 L_u8PinIntStatus = DIO_PIN_INT_INACTIVE;
	
    /* Check if the port is valid */
    if( (Copy_tPortID >= DIO_PORT_MIN) &&
        (Copy_tPortID <= DIO_PORT_MAX) )
    {
        /* Switch around the ports */
        switch(Copy_tPortID)
        {
            case DIO_PORTA_ID:
                    L_tSetterFuncStatus =
                    tGetPinIntStatus_PORTA(Copy_tBusID, Copy_tPinID, &L_u8PinIntStatus);
                break;
            case DIO_PORTB_ID:
                    L_tSetterFuncStatus =
                    tGetPinIntStatus_PORTB(Copy_tBusID, Copy_tPinID, &L_u8PinIntStatus);
                break;
            case DIO_PORTC_ID:
                    L_tSetterFuncStatus =
                    tGetPinIntStatus_PORTC(Copy_tBusID, Copy_tPinID, &L_u8PinIntStatus);
                break;
            case DIO_PORTD_ID:
                    L_tSetterFuncStatus =
                    tGetPinIntStatus_PORTD(Copy_tBusID, Copy_tPinID, &L_u8PinIntStatus);
                break;
            case DIO_PORTE_ID:
                    L_tSetterFuncStatus =
                    tGetPinIntStatus_PORTE(Copy_tBusID, Copy_tPinID, &L_u8PinIntStatus);
                break;
            case DIO_PORTF_ID:
                    L_tSetterFuncStatus =
                    tGetPinIntStatus_PORTF(Copy_tBusID, Copy_tPinID, &L_u8PinIntStatus);
                break;
            default:
                    /* Error handle - Print to user */
                    DEFAULT_ERROR_HANDLER();
                break;
        }
    }
    else {/* Error handle - Print to user */}

    /* Check if any of the setter function returned an error */
    if( (DIO_GET_PIN_INT_SUCC == L_tSetterFuncStatus) )
    {
        L_tThisFuncErrStatus = DIO_GET_PIN_INT_SUCC;

        /* Assign the value */
        *pArg_tPinIntStatus = L_u8PinIntStatus;
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
/**
 * @brief Setting the EXTI Callbcak function
 */
DIO_ErrorStatus_t
MDIO_tSetCallBack(uC_PortID_t Copy_tPortID,
                  GPIO_EXTI_FuncPtr_t Copy_tCallBackFunc)
{
    /** @brief For unused warning */
    (void) Copy_tPortID;

    /* Function data types */
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_CBF_FAILED;

    if( (NULL != Copy_tCallBackFunc) )
    {
        /* Check if the port is valid */
        if( (Copy_tPortID >= DIO_PORT_MIN) &&
            (Copy_tPortID <= DIO_PORT_MAX) )
        {
            /* Switch around the ports */
            switch(Copy_tPortID)
            {
                case DIO_PORTA_ID:
                        GPIO_EXTI_FuncPtr[GPIOA_EXTI_FunctionPtr] = Copy_tCallBackFunc;
                    break;
                case DIO_PORTB_ID:
                        GPIO_EXTI_FuncPtr[GPIOB_EXTI_FunctionPtr] = Copy_tCallBackFunc;
                    break;
                case DIO_PORTC_ID:
                        GPIO_EXTI_FuncPtr[GPIOC_EXTI_FunctionPtr] = Copy_tCallBackFunc;
                    break;
                case DIO_PORTD_ID:
                        GPIO_EXTI_FuncPtr[GPIOD_EXTI_FunctionPtr] = Copy_tCallBackFunc;
                    break;
                case DIO_PORTE_ID:
                        GPIO_EXTI_FuncPtr[GPIOE_EXTI_FunctionPtr] = Copy_tCallBackFunc;
                    break;
                case DIO_PORTF_ID:
                        GPIO_EXTI_FuncPtr[GPIOF_EXTI_FunctionPtr] = Copy_tCallBackFunc;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}

/*
----------------------------------------------------------------------
- Private functions implementation
----------------------------------------------------------------------
*/
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinDir_PORTA(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinDir_t Copy_tPinDir)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIR_FAILED;

    if( (Copy_tPinDir >= DIO_PIN_DIR_INPUT) &&
        (Copy_tPinDir <= DIO_PIN_DIR_OUTPUT) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTA_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTA_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTA_APB) &&
                (Copy_tBusID <= DIO_PORTA_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTA_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOA_APB->DIR, Copy_tPinID, Copy_tPinDir);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
                        break;
                    case DIO_PORTA_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOA_AHB->DIR, Copy_tPinID, Copy_tPinDir);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinDir_PORTB(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinDir_t Copy_tPinDir)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIR_FAILED;

    if( (Copy_tPinDir >= DIO_PIN_DIR_INPUT) &&
        (Copy_tPinDir <= DIO_PIN_DIR_OUTPUT) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTB_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTB_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTB_APB) &&
                (Copy_tBusID <= DIO_PORTB_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTB_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOB_APB->DIR, Copy_tPinID, Copy_tPinDir);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
                        break;
                    case DIO_PORTA_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOB_AHB->DIR, Copy_tPinID, Copy_tPinDir);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinDir_PORTC(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinDir_t Copy_tPinDir)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIR_FAILED;

    if( (Copy_tPinDir >= DIO_PIN_DIR_INPUT) &&
        (Copy_tPinDir <= DIO_PIN_DIR_OUTPUT) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTC_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTC_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTC_APB) &&
                (Copy_tBusID <= DIO_PORTC_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTC_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOC_APB->DIR, Copy_tPinID, Copy_tPinDir);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
                        break;
                    case DIO_PORTC_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOC_AHB->DIR, Copy_tPinID, Copy_tPinDir);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinDir_PORTD(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinDir_t Copy_tPinDir)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIR_FAILED;

    if( (Copy_tPinDir >= DIO_PIN_DIR_INPUT) &&
        (Copy_tPinDir <= DIO_PIN_DIR_OUTPUT) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTD_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTD_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTD_APB) &&
                (Copy_tBusID <= DIO_PORTD_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTD_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOD_APB->DIR, Copy_tPinID, Copy_tPinDir);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
                        break;
                    case DIO_PORTD_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOD_AHB->DIR, Copy_tPinID, Copy_tPinDir);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinDir_PORTE(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinDir_t Copy_tPinDir)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIR_FAILED;

    if( (Copy_tPinDir >= DIO_PIN_DIR_INPUT) &&
        (Copy_tPinDir <= DIO_PIN_DIR_OUTPUT) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTE_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTE_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTE_APB) &&
                (Copy_tBusID <= DIO_PORTE_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTE_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOE_APB->DIR, Copy_tPinID, Copy_tPinDir);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
                        break;
                    case DIO_PORTE_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOE_AHB->DIR, Copy_tPinID, Copy_tPinDir);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinDir_PORTF(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinDir_t Copy_tPinDir)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIR_FAILED;

    if( (Copy_tPinDir >= DIO_PIN_DIR_INPUT) &&
        (Copy_tPinDir <= DIO_PIN_DIR_OUTPUT) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTF_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTF_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTF_APB) &&
                (Copy_tBusID <= DIO_PORTF_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTF_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOF_APB->DIR, Copy_tPinID, Copy_tPinDir);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
                        break;
                    case DIO_PORTF_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOF_AHB->DIR, Copy_tPinID, Copy_tPinDir);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIR_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinCurrDrv_PORTA(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinCurrentDrive_t Copy_tCurrentDrive)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_CD_FAILED;

    if( (Copy_tCurrentDrive >= DIO_PIN_CD_2MA) &&
        (Copy_tCurrentDrive <= DIO_PIN_CD_8MA) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTA_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTA_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTA_APB) &&
                (Copy_tBusID <= DIO_PORTA_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTA_APB:
                            /* Select the Current Drive */
                            switch(Copy_tCurrentDrive)
                            {
                                case DIO_PIN_CD_2MA:
                                        BIT_WRT(GPIOA_APB->DR2R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_4MA:
                                        BIT_WRT(GPIOA_APB->DR4R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_8MA:
                                        BIT_WRT(GPIOA_APB->DR8R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                default: break;
                            }
                        break;
                    case DIO_PORTA_AHB:
                            /* Select the Current Drive */
                            switch(Copy_tCurrentDrive)
                            {
                                case DIO_PIN_CD_2MA:
                                        BIT_WRT(GPIOA_AHB->DR2R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_4MA:
                                        BIT_WRT(GPIOA_AHB->DR4R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_8MA:
                                        BIT_WRT(GPIOA_AHB->DR8R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                default: break;
                            }
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinCurrDrv_PORTB(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinCurrentDrive_t Copy_tCurrentDrive)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_CD_FAILED;

    if( (Copy_tCurrentDrive >= DIO_PIN_CD_2MA) &&
        (Copy_tCurrentDrive <= DIO_PIN_CD_8MA) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTB_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTB_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTB_APB) &&
                (Copy_tBusID <= DIO_PORTB_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTB_APB:
                            /* Select the Current Drive */
                            switch(Copy_tCurrentDrive)
                            {
                                case DIO_PIN_CD_2MA:
                                        BIT_WRT(GPIOB_APB->DR2R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_4MA:
                                        BIT_WRT(GPIOB_APB->DR4R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_8MA:
                                        BIT_WRT(GPIOB_APB->DR8R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                default: break;
                            }
                        break;
                    case DIO_PORTB_AHB:
                            /* Select the Current Drive */
                            switch(Copy_tCurrentDrive)
                            {
                                case DIO_PIN_CD_2MA:
                                        BIT_WRT(GPIOB_AHB->DR2R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_4MA:
                                        BIT_WRT(GPIOB_AHB->DR4R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_8MA:
                                        BIT_WRT(GPIOB_AHB->DR8R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                default: break;
                            }
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinCurrDrv_PORTC(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinCurrentDrive_t Copy_tCurrentDrive)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_CD_FAILED;

    if( (Copy_tCurrentDrive >= DIO_PIN_CD_2MA) &&
        (Copy_tCurrentDrive <= DIO_PIN_CD_8MA) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTC_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTC_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTC_APB) &&
                (Copy_tBusID <= DIO_PORTC_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTC_APB:
                            /* Select the Current Drive */
                            switch(Copy_tCurrentDrive)
                            {
                                case DIO_PIN_CD_2MA:
                                        BIT_WRT(GPIOC_APB->DR2R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_4MA:
                                        BIT_WRT(GPIOC_APB->DR4R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_8MA:
                                        BIT_WRT(GPIOC_APB->DR8R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                default: break;
                            }
                        break;
                    case DIO_PORTC_AHB:
                            /* Select the Current Drive */
                            switch(Copy_tCurrentDrive)
                            {
                                case DIO_PIN_CD_2MA:
                                        BIT_WRT(GPIOC_AHB->DR2R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_4MA:
                                        BIT_WRT(GPIOC_AHB->DR4R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_8MA:
                                        BIT_WRT(GPIOC_AHB->DR8R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                default: break;
                            }
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinCurrDrv_PORTD(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinCurrentDrive_t Copy_tCurrentDrive)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_CD_FAILED;

    if( (Copy_tCurrentDrive >= DIO_PIN_CD_2MA) &&
        (Copy_tCurrentDrive <= DIO_PIN_CD_8MA) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTD_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTD_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTD_APB) &&
                (Copy_tBusID <= DIO_PORTD_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTD_APB:
                            /* Select the Current Drive */
                            switch(Copy_tCurrentDrive)
                            {
                                case DIO_PIN_CD_2MA:
                                        BIT_WRT(GPIOD_APB->DR2R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_4MA:
                                        BIT_WRT(GPIOD_APB->DR4R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_8MA:
                                        BIT_WRT(GPIOD_APB->DR8R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                default: break;
                            }
                        break;
                    case DIO_PORTD_AHB:
                            /* Select the Current Drive */
                            switch(Copy_tCurrentDrive)
                            {
                                case DIO_PIN_CD_2MA:
                                        BIT_WRT(GPIOD_AHB->DR2R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_4MA:
                                        BIT_WRT(GPIOD_AHB->DR4R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_8MA:
                                        BIT_WRT(GPIOD_AHB->DR8R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                default: break;
                            }
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinCurrDrv_PORTE(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinCurrentDrive_t Copy_tCurrentDrive)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_CD_FAILED;

    if( (Copy_tCurrentDrive >= DIO_PIN_CD_2MA) &&
        (Copy_tCurrentDrive <= DIO_PIN_CD_8MA) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTE_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTE_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTE_APB) &&
                (Copy_tBusID <= DIO_PORTE_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTE_APB:
                            /* Select the Current Drive */
                            switch(Copy_tCurrentDrive)
                            {
                                case DIO_PIN_CD_2MA:
                                        BIT_WRT(GPIOE_APB->DR2R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_4MA:
                                        BIT_WRT(GPIOE_APB->DR4R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_8MA:
                                        BIT_WRT(GPIOE_APB->DR8R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                default: break;
                            }
                        break;
                    case DIO_PORTE_AHB:
                            /* Select the Current Drive */
                            switch(Copy_tCurrentDrive)
                            {
                                case DIO_PIN_CD_2MA:
                                        BIT_WRT(GPIOE_AHB->DR2R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_4MA:
                                        BIT_WRT(GPIOE_AHB->DR4R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_8MA:
                                        BIT_WRT(GPIOE_AHB->DR8R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                default: break;
                            }
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinCurrDrv_PORTF(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinCurrentDrive_t Copy_tCurrentDrive)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_CD_FAILED;

    if( (Copy_tCurrentDrive >= DIO_PIN_CD_2MA) &&
        (Copy_tCurrentDrive <= DIO_PIN_CD_8MA) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTF_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTF_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTF_APB) &&
                (Copy_tBusID <= DIO_PORTF_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTF_APB:
                            /* Select the Current Drive */
                            switch(Copy_tCurrentDrive)
                            {
                                case DIO_PIN_CD_2MA:
                                        BIT_WRT(GPIOF_APB->DR2R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_4MA:
                                        BIT_WRT(GPIOF_APB->DR4R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_8MA:
                                        BIT_WRT(GPIOF_APB->DR8R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                default: break;
                            }
                        break;
                    case DIO_PORTF_AHB:
                            /* Select the Current Drive */
                            switch(Copy_tCurrentDrive)
                            {
                                case DIO_PIN_CD_2MA:
                                        BIT_WRT(GPIOF_AHB->DR2R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_4MA:
                                        BIT_WRT(GPIOF_AHB->DR4R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                case DIO_PIN_CD_8MA:
                                        BIT_WRT(GPIOF_AHB->DR8R, Copy_tPinID, Copy_tCurrentDrive);
                                        L_tThisFuncErrStatus = DIO_SET_PIN_CD_SUCC;
                                    break;
                                default: break;
                            }
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinDig_PORTA(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIG_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tDigState >= DIO_PIN_DIG_DISABLE) &&
        (Copy_tDigState <= DIO_PIN_DIG_ENABLE) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTA_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTA_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTA_APB) &&
                (Copy_tBusID <= DIO_PORTA_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTA_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOA_APB->DEN, Copy_tPinID, Copy_tDigState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
                        break;
                    case DIO_PORTA_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOA_AHB->DEN, Copy_tPinID, Copy_tDigState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinDig_PORTB(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinState_t Copy_tDigState)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIG_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tDigState >= DIO_PIN_DIG_DISABLE) &&
        (Copy_tDigState <= DIO_PIN_DIG_ENABLE) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTB_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTB_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTB_APB) &&
                (Copy_tBusID <= DIO_PORTB_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTB_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOB_APB->DEN, Copy_tPinID, Copy_tDigState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
                        break;
                    case DIO_PORTB_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOB_AHB->DEN, Copy_tPinID, Copy_tDigState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinDig_PORTC(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIG_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tDigState >= DIO_PIN_DIG_DISABLE) &&
        (Copy_tDigState <= DIO_PIN_DIG_ENABLE) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTC_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTC_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTC_APB) &&
                (Copy_tBusID <= DIO_PORTC_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTC_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOC_APB->DEN, Copy_tPinID, Copy_tDigState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
                        break;
                    case DIO_PORTC_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOC_AHB->DEN, Copy_tPinID, Copy_tDigState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinDig_PORTD(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIG_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tDigState >= DIO_PIN_DIG_DISABLE) &&
        (Copy_tDigState <= DIO_PIN_DIG_ENABLE) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTD_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTD_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTD_APB) &&
                (Copy_tBusID <= DIO_PORTD_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTD_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOD_APB->DEN, Copy_tPinID, Copy_tDigState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
                        break;
                    case DIO_PORTD_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOD_AHB->DEN, Copy_tPinID, Copy_tDigState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinDig_PORTE(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIG_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tDigState >= DIO_PIN_DIG_DISABLE) &&
        (Copy_tDigState <= DIO_PIN_DIG_ENABLE) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTE_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTE_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTE_APB) &&
                (Copy_tBusID <= DIO_PORTE_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTE_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOE_APB->DEN, Copy_tPinID, Copy_tDigState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
                        break;
                    case DIO_PORTE_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOE_AHB->DEN, Copy_tPinID, Copy_tDigState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinDig_PORTF(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_DIG_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tDigState >= DIO_PIN_DIG_DISABLE) &&
        (Copy_tDigState <= DIO_PIN_DIG_ENABLE) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTF_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTF_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTF_APB) &&
                (Copy_tBusID <= DIO_PORTF_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTF_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOF_APB->DEN, Copy_tPinID, Copy_tDigState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
                        break;
                    case DIO_PORTF_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOF_AHB->DEN, Copy_tPinID, Copy_tDigState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_DIG_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinVal_PORTA(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinVal_t Copy_tPinVal)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_VAL_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinVal >= DIO_PIN_DO_LOW) &&
        (Copy_tPinVal <= DIO_PIN_DO_HIGH) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTA_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTA_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTA_APB) &&
                (Copy_tBusID <= DIO_PORTA_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTA_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOA_APB->DATA, Copy_tPinID, Copy_tPinVal);
                            L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
                        break;
                    case DIO_PORTA_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOA_AHB->DATA, Copy_tPinID, Copy_tPinVal);
                            L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinVal_PORTB(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinVal_t Copy_tPinVal)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_VAL_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinVal >= DIO_PIN_DO_LOW) &&
        (Copy_tPinVal <= DIO_PIN_DO_HIGH) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTB_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTB_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTB_APB) &&
                (Copy_tBusID <= DIO_PORTB_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTB_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOB_APB->DATA, Copy_tPinID, Copy_tPinVal);
                            L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
                        break;
                    case DIO_PORTB_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOB_AHB->DATA, Copy_tPinID, Copy_tPinVal);
                            L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinVal_PORTC(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinVal_t Copy_tPinVal)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_VAL_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinVal >= DIO_PIN_DO_LOW) &&
        (Copy_tPinVal <= DIO_PIN_DO_HIGH) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTC_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTC_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTC_APB) &&
                (Copy_tBusID <= DIO_PORTC_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTC_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOC_APB->DATA, Copy_tPinID, Copy_tPinVal);
                            L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
                        break;
                    case DIO_PORTC_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOC_AHB->DATA, Copy_tPinID, Copy_tPinVal);
                            L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinVal_PORTD(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinVal_t Copy_tPinVal)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_VAL_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinVal >= DIO_PIN_DO_LOW) &&
        (Copy_tPinVal <= DIO_PIN_DO_HIGH) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTD_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTD_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTD_APB) &&
                (Copy_tBusID <= DIO_PORTD_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTD_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOD_APB->DATA, Copy_tPinID, Copy_tPinVal);
                            L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
                        break;
                    case DIO_PORTD_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOD_AHB->DATA, Copy_tPinID, Copy_tPinVal);
                            L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinVal_PORTE(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinVal_t Copy_tPinVal)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_VAL_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinVal >= DIO_PIN_DO_LOW) &&
        (Copy_tPinVal <= DIO_PIN_DO_HIGH) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTE_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTE_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTE_APB) &&
                (Copy_tBusID <= DIO_PORTE_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTE_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOE_APB->DATA, Copy_tPinID, Copy_tPinVal);
                            L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
                        break;
                    case DIO_PORTE_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOE_AHB->DATA, Copy_tPinID, Copy_tPinVal);
                            L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinVal_PORTF(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinVal_t Copy_tPinVal)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_VAL_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinVal >= DIO_PIN_DO_LOW) &&
        (Copy_tPinVal <= DIO_PIN_DO_HIGH) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTF_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTF_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTF_APB) &&
                (Copy_tBusID <= DIO_PORTF_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTF_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOF_APB->DATA, Copy_tPinID, Copy_tPinVal);
                            L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
                        break;
                    case DIO_PORTF_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOF_AHB->DATA, Copy_tPinID, Copy_tPinVal);
                            L_tThisFuncErrStatus = DIO_SET_PIN_VAL_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinIntSense_PORTA(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntSense)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_INT_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinIntSense >= DIO_PIN_INT_SENSE_FE) &&
        (Copy_tPinIntSense <= DIO_PIN_INT_SENSE_HL) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTA_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTA_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTA_APB) &&
                (Copy_tBusID <= DIO_PORTA_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTA_APB:
                            /* Clear the IBE Register for corresponding bit */
                            BIT_CLR(GPIOA_APB->IBE, Copy_tPinID);
                            switch(Copy_tPinIntSense)
                            {
                                case DIO_PIN_INT_SENSE_FE:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOA_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Falling */
                                        BIT_CLR(GPIOA_APB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_RE:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOA_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Rising */
                                        BIT_SET(GPIOA_APB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_LL:
                                        /* Set the pin interrupt sense as: Level */
                                        BIT_SET(GPIOA_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Low */
                                        BIT_CLR(GPIOA_APB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_HL:
                                        /* Set the pin interrupt sense as: Level */
                                        BIT_SET(GPIOA_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: High */
                                        BIT_SET(GPIOA_APB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_EB:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOA_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Both */
                                        BIT_SET(GPIOA_APB->IBE, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_LB:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_SET(GPIOA_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Both */
                                        BIT_SET(GPIOA_APB->IBE, Copy_tPinID);
                                    break;
                                default: break;
                            }
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    case DIO_PORTA_AHB:
                            /* Clear the IBE Register for corresponding bit */
                            BIT_CLR(GPIOA_APB->IBE, Copy_tPinID);
                            switch(Copy_tPinIntSense)
                            {
                                case DIO_PIN_INT_SENSE_FE:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOA_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Falling */
                                        BIT_CLR(GPIOA_AHB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_RE:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOA_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Rising */
                                        BIT_SET(GPIOA_AHB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_LL:
                                        /* Set the pin interrupt sense as: Level */
                                        BIT_SET(GPIOA_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Low */
                                        BIT_CLR(GPIOA_AHB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_HL:
                                        /* Set the pin interrupt sense as: Level */
                                        BIT_SET(GPIOA_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: High */
                                        BIT_SET(GPIOA_AHB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_EB:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOA_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Both */
                                        BIT_SET(GPIOA_AHB->IBE, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_LB:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_SET(GPIOA_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Both */
                                        BIT_SET(GPIOA_AHB->IBE, Copy_tPinID);
                                    break;
                                default: break;
                            }
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinIntSense_PORTB(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntSense)
{
    DEFAULT_UNIMPLEMENTED_HANDLER();
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinIntSense_PORTC(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntSense)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_INT_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinIntSense >= DIO_PIN_INT_SENSE_FE) &&
        (Copy_tPinIntSense <= DIO_PIN_INT_SENSE_HL) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTC_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTC_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTC_APB) &&
                (Copy_tBusID <= DIO_PORTC_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTC_APB:
                            /* Clear the IBE Register for corresponding bit */
                            /* BIT_CLR(GPIOA_APB->IBE, Copy_tPinID); */
                            switch(Copy_tPinIntSense)
                            {
                                case DIO_PIN_INT_SENSE_FE:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOC_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Falling */
                                        BIT_CLR(GPIOC_APB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_RE:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOC_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Rising */
                                        BIT_SET(GPIOC_APB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_LL:
                                        /* Set the pin interrupt sense as: Level */
                                        BIT_SET(GPIOC_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Low */
                                        BIT_CLR(GPIOC_APB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_HL:
                                        /* Set the pin interrupt sense as: Level */
                                        BIT_SET(GPIOC_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: High */
                                        BIT_SET(GPIOC_APB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_EB:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOC_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Both */
                                        BIT_SET(GPIOC_APB->IBE, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_LB:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_SET(GPIOC_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Both */
                                        BIT_SET(GPIOC_APB->IBE, Copy_tPinID);
                                    break;
                                default: break;
                            }
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    case DIO_PORTC_AHB:
                            /* Clear the IBE Register for corresponding bit */
                            /* BIT_CLR(GPIOC_APB->IBE, Copy_tPinID); */
                            switch(Copy_tPinIntSense)
                            {
                                case DIO_PIN_INT_SENSE_FE:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOC_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Falling */
                                        BIT_CLR(GPIOC_AHB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_RE:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOC_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Rising */
                                        BIT_SET(GPIOC_AHB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_LL:
                                        /* Set the pin interrupt sense as: Level */
                                        BIT_SET(GPIOC_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Low */
                                        BIT_CLR(GPIOC_AHB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_HL:
                                        /* Set the pin interrupt sense as: Level */
                                        BIT_SET(GPIOC_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: High */
                                        BIT_SET(GPIOC_AHB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_EB:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOC_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Both */
                                        BIT_SET(GPIOC_AHB->IBE, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_LB:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_SET(GPIOC_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Both */
                                        BIT_SET(GPIOC_AHB->IBE, Copy_tPinID);
                                    break;
                                default: break;
                            }
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinIntSense_PORTD(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntSense)
{
    DEFAULT_UNIMPLEMENTED_HANDLER();
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinIntSense_PORTE(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntSense)
{
    DEFAULT_UNIMPLEMENTED_HANDLER();
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinIntSense_PORTF(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntSense)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_INT_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinIntSense >= DIO_PIN_INT_SENSE_FE) &&
        (Copy_tPinIntSense <= DIO_PIN_INT_SENSE_HL) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTF_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTF_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTF_APB) &&
                (Copy_tBusID <= DIO_PORTF_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTF_APB:
                            /* Clear the IBE Register for corresponding bit */
                            /* BIT_CLR(GPIOF_APB->IBE, Copy_tPinID); */
                            switch(Copy_tPinIntSense)
                            {
                                case DIO_PIN_INT_SENSE_FE:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOF_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Falling */
                                        BIT_CLR(GPIOF_APB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_RE:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOF_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Rising */
                                        BIT_SET(GPIOF_APB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_LL:
                                        /* Set the pin interrupt sense as: Level */
                                        BIT_SET(GPIOF_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Low */
                                        BIT_CLR(GPIOF_APB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_HL:
                                        /* Set the pin interrupt sense as: Level */
                                        BIT_SET(GPIOF_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: High */
                                        BIT_SET(GPIOF_APB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_EB:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOF_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Both */
                                        BIT_SET(GPIOF_APB->IBE, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_LB:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_SET(GPIOF_APB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Both */
                                        BIT_SET(GPIOF_APB->IBE, Copy_tPinID);
                                    break;
                                default: break;
                            }
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    case DIO_PORTF_AHB:
                            /* Clear the IBE Register for corresponding bit */
                            /* BIT_CLR(GPIOF_AHB->IBE, Copy_tPinID); */
                            switch(Copy_tPinIntSense)
                            {
                                case DIO_PIN_INT_SENSE_FE:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOF_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Falling */
                                        BIT_CLR(GPIOF_AHB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_RE:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOF_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Rising */
                                        BIT_SET(GPIOF_AHB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_LL:
                                        /* Set the pin interrupt sense as: Level */
                                        BIT_SET(GPIOF_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Low */
                                        BIT_CLR(GPIOF_AHB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_HL:
                                        /* Set the pin interrupt sense as: Level */
                                        BIT_SET(GPIOF_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: High */
                                        BIT_SET(GPIOF_AHB->IEV, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_EB:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_CLR(GPIOF_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Both */
                                        BIT_SET(GPIOF_AHB->IBE, Copy_tPinID);
                                    break;
                                case DIO_PIN_INT_SENSE_LB:
                                        /* Set the pin interrupt sense as: Edge */
                                        BIT_SET(GPIOF_AHB->IS, Copy_tPinID);
                                        /* Set the pin sense trigger as: Both */
                                        BIT_SET(GPIOF_AHB->IBE, Copy_tPinID);
                                    break;
                                default: break;
                            }
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinIntState_PORTA(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntState)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_INT_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinIntState >= DIO_PIN_INT_DISABLE) &&
        (Copy_tPinIntState <= DIO_PIN_INT_ENABLE) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTA_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTA_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTA_APB) &&
                (Copy_tBusID <= DIO_PORTA_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTA_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOA_APB->IM, Copy_tPinID, Copy_tPinIntState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    case DIO_PORTA_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOA_AHB->IM, Copy_tPinID, Copy_tPinIntState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinIntState_PORTB(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntState)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_INT_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinIntState >= DIO_PIN_INT_DISABLE) &&
        (Copy_tPinIntState <= DIO_PIN_INT_ENABLE) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTB_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTB_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTB_APB) &&
                (Copy_tBusID <= DIO_PORTB_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTB_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOB_APB->IM, Copy_tPinID, Copy_tPinIntState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    case DIO_PORTB_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOB_AHB->IM, Copy_tPinID, Copy_tPinIntState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinIntState_PORTC(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntState)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_INT_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinIntState >= DIO_PIN_INT_DISABLE) &&
        (Copy_tPinIntState <= DIO_PIN_INT_ENABLE) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTC_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTC_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTC_APB) &&
                (Copy_tBusID <= DIO_PORTC_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTC_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOC_APB->IM, Copy_tPinID, Copy_tPinIntState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    case DIO_PORTC_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOC_AHB->IM, Copy_tPinID, Copy_tPinIntState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinIntState_PORTD(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntState)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_INT_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinIntState >= DIO_PIN_INT_DISABLE) &&
        (Copy_tPinIntState <= DIO_PIN_INT_ENABLE) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTD_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTD_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTD_APB) &&
                (Copy_tBusID <= DIO_PORTD_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTD_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOD_APB->IM, Copy_tPinID, Copy_tPinIntState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    case DIO_PORTD_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOD_AHB->IM, Copy_tPinID, Copy_tPinIntState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinIntState_PORTE(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntState)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_INT_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinIntState >= DIO_PIN_INT_DISABLE) &&
        (Copy_tPinIntState <= DIO_PIN_INT_ENABLE) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTE_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTE_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTE_APB) &&
                (Copy_tBusID <= DIO_PORTE_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTE_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOE_APB->IM, Copy_tPinID, Copy_tPinIntState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    case DIO_PORTE_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOE_AHB->IM, Copy_tPinID, Copy_tPinIntState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinIntState_PORTF(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntState)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_INT_FAILED;

    /* Check if the passed value is valid */
    if( (Copy_tPinIntState >= DIO_PIN_INT_DISABLE) &&
        (Copy_tPinIntState <= DIO_PIN_INT_ENABLE) )
    {
        /* Check if the pin is valid for PORT A */
        if( (Copy_tPinID >= DIO_PORTF_PIN_MIN) &&
            (Copy_tPinID <= DIO_PORTF_PIN_MAX) )
        {
            /* Check if the bus is valid */
            if( (Copy_tBusID >= DIO_PORTF_APB) &&
                (Copy_tBusID <= DIO_PORTF_AHB) )
            {
                /* Select the bus */
                switch(Copy_tBusID)
                {
                    case DIO_PORTF_APB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOF_APB->IM, Copy_tPinID, Copy_tPinIntState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    case DIO_PORTF_AHB:
                            /* Set the pin direction */
                            BIT_WRT(GPIOF_AHB->IM, Copy_tPinID, Copy_tPinIntState);
                            L_tThisFuncErrStatus = DIO_SET_PIN_INT_SUCC;
                        break;
                    default:
                            /* Error handle - Print to user */
                            DEFAULT_ERROR_HANDLER();
                        break;
                }
            }
            else {/* Error handle - Print to user */}
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinPUR_PORTA(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PUR_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTA_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTA_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTA_APB) &&
            (Copy_tBusID <= DIO_PORTA_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTA_APB:
                        /* Set the pin direction */
                        BIT_SET(GPIOA_APB->PUR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
                    break;
                case DIO_PORTA_AHB:
                        /* Set the pin direction */
                        BIT_SET(GPIOA_AHB->PUR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinPUR_PORTB(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PUR_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTB_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTB_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTB_APB) &&
            (Copy_tBusID <= DIO_PORTB_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTB_APB:
                        /* Set the pin direction */
                        BIT_SET(GPIOB_APB->PUR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
                    break;
                case DIO_PORTB_AHB:
                        /* Set the pin direction */
                        BIT_SET(GPIOB_AHB->PUR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinPUR_PORTC(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PUR_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTC_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTC_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTC_APB) &&
            (Copy_tBusID <= DIO_PORTC_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTC_APB:
                        /* Set the pin direction */
                        BIT_SET(GPIOC_APB->PUR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
                    break;
                case DIO_PORTC_AHB:
                        /* Set the pin direction */
                        BIT_SET(GPIOC_AHB->PUR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinPUR_PORTD(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PUR_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTD_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTD_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTD_APB) &&
            (Copy_tBusID <= DIO_PORTD_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTD_APB:
                        /* Set the pin direction */
                        BIT_SET(GPIOD_APB->PUR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
                    break;
                case DIO_PORTD_AHB:
                        /* Set the pin direction */
                        BIT_SET(GPIOD_AHB->PUR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinPUR_PORTE(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PUR_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTE_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTE_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTE_APB) &&
            (Copy_tBusID <= DIO_PORTE_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTE_APB:
                        /* Set the pin direction */
                        BIT_SET(GPIOE_APB->PUR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
                    break;
                case DIO_PORTE_AHB:
                        /* Set the pin direction */
                        BIT_SET(GPIOE_AHB->PUR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinPUR_PORTF(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PUR_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTF_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTF_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTF_APB) &&
            (Copy_tBusID <= DIO_PORTF_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTF_APB:
                        /* Set the pin direction */
                        BIT_SET(GPIOF_APB->PUR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
                    break;
                case DIO_PORTF_AHB:
                        /* Set the pin direction */
                        BIT_SET(GPIOF_AHB->PUR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PUR_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinPDR_PORTA(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PDR_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTA_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTA_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTA_APB) &&
            (Copy_tBusID <= DIO_PORTA_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTA_APB:
                        /* Set the pin direction */
                        BIT_SET(GPIOA_APB->PDR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
                    break;
                case DIO_PORTA_AHB:
                        /* Set the pin direction */
                        BIT_SET(GPIOA_AHB->PDR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinPDR_PORTB(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PDR_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTB_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTB_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTB_APB) &&
            (Copy_tBusID <= DIO_PORTB_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTB_APB:
                        /* Set the pin direction */
                        BIT_SET(GPIOB_APB->PDR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
                    break;
                case DIO_PORTB_AHB:
                        /* Set the pin direction */
                        BIT_SET(GPIOB_AHB->PDR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinPDR_PORTC(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PDR_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTC_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTC_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTC_APB) &&
            (Copy_tBusID <= DIO_PORTC_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTC_APB:
                        /* Set the pin direction */
                        BIT_SET(GPIOC_APB->PDR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
                    break;
                case DIO_PORTC_AHB:
                        /* Set the pin direction */
                        BIT_SET(GPIOC_AHB->PDR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinPDR_PORTD(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PDR_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTD_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTD_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTD_APB) &&
            (Copy_tBusID <= DIO_PORTD_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTD_APB:
                        /* Set the pin direction */
                        BIT_SET(GPIOD_APB->PDR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
                    break;
                case DIO_PORTD_AHB:
                        /* Set the pin direction */
                        BIT_SET(GPIOD_AHB->PDR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinPDR_PORTE(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PDR_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTE_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTE_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTE_APB) &&
            (Copy_tBusID <= DIO_PORTE_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTE_APB:
                        /* Set the pin direction */
                        BIT_SET(GPIOE_APB->PDR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
                    break;
                case DIO_PORTE_AHB:
                        /* Set the pin direction */
                        BIT_SET(GPIOE_AHB->PDR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinPDR_PORTF(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_PDR_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTF_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTF_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTF_APB) &&
            (Copy_tBusID <= DIO_PORTF_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTF_APB:
                        /* Set the pin direction */
                        BIT_SET(GPIOF_APB->PDR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
                    break;
                case DIO_PORTF_AHB:
                        /* Set the pin direction */
                        BIT_SET(GPIOF_AHB->PDR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_PDR_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinOD_PORTA(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_OD_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTA_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTA_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTA_APB) &&
            (Copy_tBusID <= DIO_PORTA_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTA_APB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOA_APB->ODR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
                    break;
                case DIO_PORTA_AHB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOA_AHB->ODR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinOD_PORTB(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_OD_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTB_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTB_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTB_APB) &&
            (Copy_tBusID <= DIO_PORTB_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTB_APB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOB_APB->ODR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
                    break;
                case DIO_PORTB_AHB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOB_AHB->ODR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinOD_PORTC(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_OD_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTC_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTC_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTC_APB) &&
            (Copy_tBusID <= DIO_PORTC_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTC_APB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOC_APB->ODR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
                    break;
                case DIO_PORTC_AHB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOC_AHB->ODR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinOD_PORTD(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_OD_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTD_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTD_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTD_APB) &&
            (Copy_tBusID <= DIO_PORTD_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTD_APB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOD_APB->ODR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
                    break;
                case DIO_PORTD_AHB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOD_AHB->ODR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinOD_PORTE(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_OD_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTE_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTE_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTE_APB) &&
            (Copy_tBusID <= DIO_PORTE_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTE_APB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOE_APB->ODR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
                    break;
                case DIO_PORTE_AHB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOE_AHB->ODR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinOD_PORTF(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_OD_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTF_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTF_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTF_APB) &&
            (Copy_tBusID <= DIO_PORTF_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTF_APB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOF_APB->ODR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
                    break;
                case DIO_PORTF_AHB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOF_AHB->ODR, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_OD_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinAF_PORTA(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_AF_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTA_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTA_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTA_APB) &&
            (Copy_tBusID <= DIO_PORTA_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTA_APB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOA_APB->AFSEL, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
                    break;
                case DIO_PORTA_AHB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOA_AHB->AFSEL, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinAF_PORTB(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_AF_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTB_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTB_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTB_APB) &&
            (Copy_tBusID <= DIO_PORTB_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTB_APB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOB_APB->AFSEL, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
                    break;
                case DIO_PORTB_AHB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOB_AHB->AFSEL, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinAF_PORTC(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_AF_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTC_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTC_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTC_APB) &&
            (Copy_tBusID <= DIO_PORTC_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTC_APB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOC_APB->AFSEL, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
                    break;
                case DIO_PORTC_AHB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOC_AHB->AFSEL, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinAF_PORTD(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_AF_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTD_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTD_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTD_APB) &&
            (Copy_tBusID <= DIO_PORTD_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTD_APB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOD_APB->AFSEL, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
                    break;
                case DIO_PORTD_AHB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOD_AHB->AFSEL, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinAF_PORTE(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_AF_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTE_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTE_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTE_APB) &&
            (Copy_tBusID <= DIO_PORTE_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTE_APB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOE_APB->AFSEL, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
                    break;
                case DIO_PORTE_AHB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOE_AHB->AFSEL, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tSetPinAF_PORTF(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_SET_PIN_AF_FAILED;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTF_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTF_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTF_APB) &&
            (Copy_tBusID <= DIO_PORTF_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTF_APB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOF_APB->AFSEL, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
                    break;
                case DIO_PORTF_AHB:
                        /* Set the pin open drain */
                        BIT_SET(GPIOF_AHB->AFSEL, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_SET_PIN_AF_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tGetPinIntStatus_PORTA(uC_BusID_t Copy_tBusID,
                       uC_PinID_t Copy_tPinID,
                       uC_PinInt_t *pArg_tPinIntStatus)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_GET_PIN_INT_FAILED;

    u8 L_u8PinIntStatus = DIO_PIN_INT_INACTIVE;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTA_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTA_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTA_APB) &&
            (Copy_tBusID <= DIO_PORTA_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTA_APB:
                        /* Set the pin open drain */
                        L_u8PinIntStatus = BIT_GET(GPIOA_APB->RIS, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_GET_PIN_INT_SUCC;
                    break;
                case DIO_PORTA_AHB:
                        /* Set the pin open drain */
                        L_u8PinIntStatus = BIT_GET(GPIOA_AHB->RIS, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_GET_PIN_INT_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    /* Check the status */
    if( (0x01U == L_u8PinIntStatus) )
    {
        *pArg_tPinIntStatus = DIO_PIN_INT_ACTIVE;
    }
    else {;}

    return L_tThisFuncErrStatus;
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tGetPinIntStatus_PORTB(uC_BusID_t Copy_tBusID,
                       uC_PinID_t Copy_tPinID,
                       uC_PinInt_t *pArg_tPinIntStatus)
{
    DEFAULT_UNIMPLEMENTED_HANDLER();
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tGetPinIntStatus_PORTC(uC_BusID_t Copy_tBusID,
                       uC_PinID_t Copy_tPinID,
                       uC_PinInt_t *pArg_tPinIntStatus)
{
    DEFAULT_UNIMPLEMENTED_HANDLER();
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tGetPinIntStatus_PORTD(uC_BusID_t Copy_tBusID,
                       uC_PinID_t Copy_tPinID,
                       uC_PinInt_t *pArg_tPinIntStatus)
{
    DEFAULT_UNIMPLEMENTED_HANDLER();
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tGetPinIntStatus_PORTE(uC_BusID_t Copy_tBusID,
                       uC_PinID_t Copy_tPinID,
                       uC_PinInt_t *pArg_tPinIntStatus)
{
    DEFAULT_UNIMPLEMENTED_HANDLER();
}
/** ------ New ------ Function ------ */
static DIO_ErrorStatus_t
tGetPinIntStatus_PORTF(uC_BusID_t Copy_tBusID,
                       uC_PinID_t Copy_tPinID,
                       uC_PinInt_t *pArg_tPinIntStatus)
{
    DIO_ErrorStatus_t L_tThisFuncErrStatus = DIO_GET_PIN_INT_FAILED;

    u8 L_u8PinIntStatus = DIO_PIN_INT_INACTIVE;

    /* Check if the pin is valid for PORT A */
    if( (Copy_tPinID >= DIO_PORTF_PIN_MIN) &&
        (Copy_tPinID <= DIO_PORTF_PIN_MAX) )
    {
        /* Check if the bus is valid */
        if( (Copy_tBusID >= DIO_PORTF_APB) &&
            (Copy_tBusID <= DIO_PORTF_AHB) )
        {
            /* Select the bus */
            switch(Copy_tBusID)
            {
                case DIO_PORTF_APB:
                        /* Set the pin open drain */
                        L_u8PinIntStatus = BIT_GET(GPIOF_APB->RIS, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_GET_PIN_INT_SUCC;
                    break;
                case DIO_PORTF_AHB:
                        /* Set the pin open drain */
                        L_u8PinIntStatus = BIT_GET(GPIOF_AHB->RIS, Copy_tPinID);
                        L_tThisFuncErrStatus = DIO_GET_PIN_INT_SUCC;
                    break;
                default:
                        /* Error handle - Print to user */
                        DEFAULT_ERROR_HANDLER();
                    break;
            }
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    /* Check the status */
    if( (0x01U == L_u8PinIntStatus) )
    {
        *pArg_tPinIntStatus = DIO_PIN_INT_ACTIVE;
    }
    else {;}

    return L_tThisFuncErrStatus;
}

/** @defgroup GPIO EXTI Handlers */
void GPIOA_Handler(void)
{
    /* Check if there is a passed callback function */
    if( (NULL != GPIO_EXTI_FuncPtr[GPIOA_EXTI_FunctionPtr]) )
    {
        /* Call the function */
        GPIO_EXTI_FuncPtr[GPIOA_EXTI_FunctionPtr]();
    }
    else {/* Do Nothing */}
}
/** ------ New ------ Function ------ */
void GPIOB_Handler(void)
{
    /* Check if there is a passed callback function */
    if( (NULL != GPIO_EXTI_FuncPtr[GPIOB_EXTI_FunctionPtr]) )
    {
        /* Call the function */
        GPIO_EXTI_FuncPtr[GPIOB_EXTI_FunctionPtr]();
    }
    else {/* Do Nothing */}
}
/** ------ New ------ Function ------ */
void GPIOC_Handler(void)
{
    /* Check if there is a passed callback function */
    if( (NULL != GPIO_EXTI_FuncPtr[GPIOC_EXTI_FunctionPtr]) )
    {
        /* Call the function */
        GPIO_EXTI_FuncPtr[GPIOC_EXTI_FunctionPtr]();
    }
    else {/* Do Nothing */}
}
/** ------ New ------ Function ------ */
void GPIOD_Handler(void)
{
    /* Check if there is a passed callback function */
    if( (NULL != GPIO_EXTI_FuncPtr[GPIOD_EXTI_FunctionPtr]) )
    {
        /* Call the function */
        GPIO_EXTI_FuncPtr[GPIOD_EXTI_FunctionPtr]();
    }
    else {/* Do Nothing */}
}
/** ------ New ------ Function ------ */
void GPIOE_Handler(void)
{
    /* Check if there is a passed callback function */
    if( (NULL != GPIO_EXTI_FuncPtr[GPIOE_EXTI_FunctionPtr]) )
    {
        /* Call the function */
        GPIO_EXTI_FuncPtr[GPIOE_EXTI_FunctionPtr]();
    }
    else {/* Do Nothing */}
}
/** ------ New ------ Function ------ */
void GPIOF_Handler(void)
{
    /* Check if there is a passed callback function */
    if( (NULL != GPIO_EXTI_FuncPtr[GPIOF_EXTI_FunctionPtr]) )
    {
        /* Call the function */
        GPIO_EXTI_FuncPtr[GPIOF_EXTI_FunctionPtr]();
    }
    else {/* Do Nothing */}
}
