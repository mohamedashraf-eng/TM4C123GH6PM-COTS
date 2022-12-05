/**
 * @file DIO_INTERFACE.h
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __DIO_INTERFACE_H__
#define __DIO_INTERFACE_H__

#include "DIO_PRIVATE.h"
/*
----------------------------------------------------------------------
- Macros
----------------------------------------------------------------------
*/

/** @defgroup Available ports */
#define DIO_PORTA_ID        ( (u8) (0x00U) )
#define DIO_PORTB_ID        ( (u8) (0x01U) )
#define DIO_PORTC_ID        ( (u8) (0x02U) )
#define DIO_PORTD_ID        ( (u8) (0x03U) )
#define DIO_PORTE_ID        ( (u8) (0x04U) )
#define DIO_PORTF_ID        ( (u8) (0x05U) )
/** @defgroup Available pins */
#define DIO_PIN0_ID         ( (u8) (0x00U) )
#define DIO_PIN1_ID         ( (u8) (0x01U) )
#define DIO_PIN2_ID         ( (u8) (0x02U) )
#define DIO_PIN3_ID         ( (u8) (0x03U) )
#define DIO_PIN4_ID         ( (u8) (0x04U) )
#define DIO_PIN5_ID         ( (u8) (0x05U) )
#define DIO_PIN6_ID         ( (u8) (0x06U) )
#define DIO_PIN7_ID         ( (u8) (0x07U) )

/*
----------------------------------------------------------------------
- Data types
----------------------------------------------------------------------
*/

/** @defgroup Enum data type. */


/** @defgroup Pin configuration parameters */
typedef enum
{
    Dio_PinMode_Digital = 0x00U,
    Dio_PinMode_Analog
}En_PinMode_t;

typedef enum
{
    Dio_PinStrength_2mA_Inactive = 0x00U,
    Dio_PinStrength_2mA_Active   = 0x01U,
    Dio_PinStrength_4mA_Inactive = 0x00U,
    Dio_PinStrength_4mA_Active   = 0x01U,
    Dio_PinStrength_8mA_Inactive = 0x00U,
    Dio_PinStrength_8mA_Active   = 0x01U
}En_PinStrength_t;

typedef enum
{
    Dio_PinData_Low = 0x00U,
    Dio_PinData_High
}En_PinData_t;

typedef enum
{
    Dio_PinDir_Input = 0x00U,
    Dio_PinDir_Output
}En_PinDir_t;

typedef enum
{
    Dio_PinAF_Inactive = 0x00U,
    Dio_PinAF_Active
}En_PinAF_t;

typedef enum
{
    Dio_PinOD_Inactive = 0x00U,
    Dio_PinOD_Active
}En_PinOD_t;

typedef enum
{
    Dio_PinPUR_Inactive = 0x00U,
    Dio_PinPUR_Active
}En_PinPUR_t;

typedef enum
{
    Dio_PinPDR_Inactive = 0x00U,
    Dio_PinPDR_Active
}En_PinPDR_t;

typedef enum
{
    Dio_PinSLR_Inactive = 0x00U,
    Dio_PinSLR_Active
}En_PinSLR_t;
typedef enum
{
    Dio_PinCommit_Inactive = 0x00U,
    Dio_PinCommit_Active
}En_PinCommit_t;

typedef enum
{
    Dio_PinADCTL_Inactive = 0x00U,
    Dio_PinADCTL_Active
}En_PinADCTL_t;

typedef enum
{
    Dio_PinDMACTL_Inactive = 0x00U,
    Dio_PinDMACTL_Active
}En_PinDMACTL_t;

typedef enum
{
    Dio_PinIntSense_FE = 0x00U,
    Dio_PinIntSense_RE,
    Dio_PinIntSense_LL,
    Dio_PinIntSense_HL,
    Dio_PinIntSense_BE,
    Dio_PinIntSense_BL,
}En_PinIntSense_t;

typedef enum
{
    Dio_PinIntMask_Inactive = 0x00U,
    Dio_PinIntMask_Active
}En_PinIntMask_t;

#if (DIO_PORTF_CONFIG == DIO_PORT_CONFIG_ACTIVE)
extern St_PortCfg_t G_StPORTF_Cfg;
#endif

/*
----------------------------------------------------------------------
- Public functions declaration
----------------------------------------------------------------------
*/

extern En_DIO_ErrorStatus_t
MDIO_EnSetCfg(const St_PortCfg_t * const Copy_tPortCfgInstance);

extern En_DIO_ErrorStatus_t
MDIO_EnSetPin(const uC_PortID_t Copy_tPortID,
              const uC_PinID_t  Copy_tPinNum);

extern En_DIO_ErrorStatus_t
MDIO_EnClrPin(const uC_PortID_t Copy_tPortID,
              const uC_PinID_t  Copy_tPinNum);

#endif /* __DIO_INTERFACE_H__ */
