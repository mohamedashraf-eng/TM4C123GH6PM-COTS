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

/** @defgroup Ports Configuration portal */
#if (DIO_PORTF_CONFIG == DIO_PORT_CONFIG_ACTIVE)
extern St_PortCfg_t G_StPORTF_Cfg;
#endif

#if (DIO_PORTB_CONFIG == DIO_PORT_CONFIG_ACTIVE)
extern St_PortCfg_t G_StPORTB_Cfg;
#endif

#if (DIO_PORTC_CONFIG == DIO_PORT_CONFIG_ACTIVE)
extern St_PortCfg_t G_StPORTC_Cfg;
#endif

#if (DIO_PORTD_CONFIG == DIO_PORT_CONFIG_ACTIVE)
extern St_PortCfg_t G_StPORTD_Cfg;
#endif

#if (DIO_PORTE_CONFIG == DIO_PORT_CONFIG_ACTIVE)
extern St_PortCfg_t G_StPORTE_Cfg;
#endif

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
