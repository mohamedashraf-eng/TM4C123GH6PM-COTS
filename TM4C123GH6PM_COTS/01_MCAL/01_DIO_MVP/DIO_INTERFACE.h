/**
 * @file DIO_INTERFACE.h
 * @author Ahmed Osama, Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Osama, Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __DIO_INTERFACE_H__
#define __DIO_INTERFACE_H__

#include "DIO_PRIVATE.h"  /** @todo To be removed. */

/*
----------------------------------------------------------------------
- Macros
----------------------------------------------------------------------
*/

/** @defgroup DIO Peripheral error status */
#define DIO_SET_PIN_DIR_FAILED      ( (u8) (0x00U) )
#define DIO_SET_PIN_DIR_SUCC        ( (u8) (0x01U) )
#define DIO_SET_PIN_CD_FAILED       ( (u8) (0x02U) )
#define DIO_SET_PIN_CD_SUCC         ( (u8) (0x03U) )
#define DIO_SET_PIN_DIG_FAILED      ( (u8) (0x04U) )
#define DIO_SET_PIN_DIG_SUCC        ( (u8) (0x05U) )
#define DIO_SET_PIN_VAL_FAILED      ( (u8) (0x06U) )
#define DIO_SET_PIN_VAL_SUCC        ( (u8) (0x07U) )
#define DIO_SET_PIN_INT_FAILED      ( (u8) (0x08U) )
#define DIO_SET_PIN_INT_SUCC        ( (u8) (0x09U) )
#define DIO_SET_PIN_PUR_FAILED      ( (u8) (0x0AU) )
#define DIO_SET_PIN_PUR_SUCC        ( (u8) (0x0BU) )
#define DIO_SET_PIN_PDR_FAILED      ( (u8) (0x0EU) )
#define DIO_SET_PIN_PDR_SUCC        ( (u8) (0x0FU) )
#define DIO_SET_PIN_OD_FAILED       ( (u8) (0x10U) )
#define DIO_SET_PIN_OD_SUCC         ( (u8) (0x11U) )
#define DIO_SET_PIN_AF_FAILED       ( (u8) (0x12U) )
#define DIO_SET_PIN_AF_SUCC         ( (u8) (0x13U) )
#define DIO_SET_PIN_ANALOG_FAILED   ( (u8) (0x14U) )
#define DIO_SET_PIN_ANALOG_SUCC     ( (u8) (0x15U) )
#define DIO_SET_CBF_FAILED          ( (u8) (0x16U) )
#define DIO_SET_CBF_SUCC            ( (u8) (0x17U) )
#define DIO_GET_PIN_INT_FAILED      ( (u8) (0x18U) )
#define DIO_GET_PIN_INT_SUCC        ( (u8) (0x19U) )

/** @defgroup DIO Pin Directions */
#define DIO_PIN_DIR_INPUT       ( (u8) (0x00U) )
#define DIO_PIN_DIR_OUTPUT      ( (u8) (0x01U) )

/** @defgroup DIO Pin Current Drive */
#define DIO_PIN_CD_2MA          ( (u8) (0x00U) )
#define DIO_PIN_CD_4MA          ( (u8) (0x01U) )
#define DIO_PIN_CD_8MA          ( (u8) (0x02U) )

/** @defgroup DIO Pin Digital */
#define DIO_PIN_DIG_DISABLE     ( (u8) (0x00U) )
#define DIO_PIN_DIG_ENABLE      ( (u8) (0x01U) )

/** @defgroup DIO Output Pin Digital Value  */
#define DIO_PIN_DO_LOW          ( (u8) (0x00U) )
#define DIO_PIN_DO_HIGH         ( (u8) (0x01U) )

/** @defgroup DIO Pin EXTI  */
#define DIO_PIN_INT_SENSE_FE    ( (u8) (0x00U) )
#define DIO_PIN_INT_SENSE_RE    ( (u8) (0x01U) )
#define DIO_PIN_INT_SENSE_LL    ( (u8) (0x02U) )
#define DIO_PIN_INT_SENSE_HL    ( (u8) (0x03U) )
#define DIO_PIN_INT_SENSE_EB    ( (u8) (0x04U) )
#define DIO_PIN_INT_SENSE_LB    ( (u8) (0x05U) )
#define DIO_PIN_INT_DISABLE     ( (u8) (0x00U) )
#define DIO_PIN_INT_ENABLE      ( (u8) (0x01U) )

/** @defgroup DIO Pin Interrupt Status */
#define DIO_PIN_INT_INACTIVE    ( (u8) (0x00U) )
#define DIO_PIN_INT_ACTIVE      ( (u8) (0x01U) )

/** @defgroup DIO Ports */
#define DIO_PORTA_APB ( (u8) (0x00U) )
#define DIO_PORTA_AHB ( (u8) (0x01U) )
#define DIO_PORTB_APB ( (u8) (0x02U) )
#define DIO_PORTB_AHB ( (u8) (0x03U) )
#define DIO_PORTC_APB ( (u8) (0x04U) )
#define DIO_PORTC_AHB ( (u8) (0x05U) )
#define DIO_PORTD_APB ( (u8) (0x06U) )
#define DIO_PORTD_AHB ( (u8) (0x07U) )
#define DIO_PORTE_APB ( (u8) (0x08U) )
#define DIO_PORTE_AHB ( (u8) (0x09U) )
#define DIO_PORTF_APB ( (u8) (0x0AU) )
#define DIO_PORTF_AHB ( (u8) (0x0BU) )

/**
 * @brief Microcontroller [TM4C123GH6PM] Ports.
 */
#define DIO_PORTA_ID            ( (u8) (0x00U) )
#define DIO_PORTB_ID            ( (u8) (0x01U) )
#define DIO_PORTC_ID            ( (u8) (0x02U) )
#define DIO_PORTD_ID            ( (u8) (0x03U) )
#define DIO_PORTE_ID            ( (u8) (0x04U) )
#define DIO_PORTF_ID            ( (u8) (0x05U) )
#define DIO_PORT_MIN            ( DIO_PORTA_ID )
#define DIO_PORT_MAX            ( DIO_PORTF_ID )
/**
 * @brief Microcontroller [TM4C123GH6PM] Ports Specific Pins.
 */
/** @defgroup Port A Pins */
#define DIO_PORTA_PIN0          ( (u8) (0x00U) )
#define DIO_PORTA_PIN1          ( (u8) (0x01U) )
#define DIO_PORTA_PIN2          ( (u8) (0x02U) )
#define DIO_PORTA_PIN3          ( (u8) (0x03U) )
#define DIO_PORTA_PIN4          ( (u8) (0x04U) )
#define DIO_PORTA_PIN5          ( (u8) (0x05U) )
#define DIO_PORTA_PIN6          ( (u8) (0x06U) )
#define DIO_PORTA_PIN7          ( (u8) (0x07U) )
#define DIO_PORTA_PIN_MIN       ( DIO_PORTA_PIN0 )
#define DIO_PORTA_PIN_MAX       ( DIO_PORTA_PIN7 )
/** @defgroup Port B Pins */
#define DIO_PORTB_PIN0          ( (u8) (0x00U) )
#define DIO_PORTB_PIN1          ( (u8) (0x01U) )
#define DIO_PORTB_PIN2          ( (u8) (0x02U) )
#define DIO_PORTB_PIN3          ( (u8) (0x03U) )
#define DIO_PORTB_PIN4          ( (u8) (0x04U) )
#define DIO_PORTB_PIN5          ( (u8) (0x05U) )
#define DIO_PORTB_PIN6          ( (u8) (0x06U) )
#define DIO_PORTB_PIN7          ( (u8) (0x07U) )
#define DIO_PORTB_PIN_MIN       ( DIO_PORTB_PIN0 )
#define DIO_PORTB_PIN_MAX       ( DIO_PORTB_PIN7 )
/** @defgroup Port C Pins */
#define DIO_PORTC_PIN0          ( (u8) (0x00U) )
#define DIO_PORTC_PIN1          ( (u8) (0x01U) )
#define DIO_PORTC_PIN2          ( (u8) (0x02U) )
#define DIO_PORTC_PIN3          ( (u8) (0x03U) )
#define DIO_PORTC_PIN4          ( (u8) (0x04U) )
#define DIO_PORTC_PIN5          ( (u8) (0x05U) )
#define DIO_PORTC_PIN6          ( (u8) (0x06U) )
#define DIO_PORTC_PIN7          ( (u8) (0x07U) )
#define DIO_PORTC_PIN_MIN       ( DIO_PORTC_PIN0 )
#define DIO_PORTC_PIN_MAX       ( DIO_PORTC_PIN7 )
/** @defgroup Port D Pins */
#define DIO_PORTD_PIN0          ( (u8) (0x00U) )
#define DIO_PORTD_PIN1          ( (u8) (0x01U) )
#define DIO_PORTD_PIN2          ( (u8) (0x02U) )
#define DIO_PORTD_PIN3          ( (u8) (0x03U) )
#define DIO_PORTD_PIN4          ( (u8) (0x04U) )
#define DIO_PORTD_PIN5          ( (u8) (0x05U) )
#define DIO_PORTD_PIN6          ( (u8) (0x06U) )
#define DIO_PORTD_PIN7          ( (u8) (0x07U) )
#define DIO_PORTD_PIN_MIN       ( DIO_PORTD_PIN0 )
#define DIO_PORTD_PIN_MAX       ( DIO_PORTD_PIN7 )
/** @defgroup Port E Pins */
#define DIO_PORTE_PIN0          ( (u8) (0x00U) )
#define DIO_PORTE_PIN1          ( (u8) (0x01U) )
#define DIO_PORTE_PIN2          ( (u8) (0x02U) )
#define DIO_PORTE_PIN3          ( (u8) (0x03U) )
#define DIO_PORTE_PIN4          ( (u8) (0x04U) )
#define DIO_PORTE_PIN5          ( (u8) (0x05U) )
#define DIO_PORTE_PIN6          ( (u8) (0x06U) )
#define DIO_PORTE_PIN_MIN       ( DIO_PORTE_PIN0 )
#define DIO_PORTE_PIN_MAX       ( DIO_PORTE_PIN6 )
/** @defgroup Port F Pins */
#define DIO_PORTF_PIN0          ( (u8) (0x00U) )
#define DIO_PORTF_PIN1          ( (u8) (0x01U) )
#define DIO_PORTF_PIN2          ( (u8) (0x02U) )
#define DIO_PORTF_PIN3          ( (u8) (0x03U) )
#define DIO_PORTF_PIN4          ( (u8) (0x04U) )
#define DIO_PORTF_PIN5          ( (u8) (0x05U) )
#define DIO_PORTF_PIN_MIN       ( DIO_PORTF_PIN0 )
#define DIO_PORTF_PIN_MAX       ( DIO_PORTF_PIN5 )

/*
----------------------------------------------------------------------
- Data types
----------------------------------------------------------------------
*/


/*
----------------------------------------------------------------------
- Public functions declaration
----------------------------------------------------------------------
*/

/**
 * @brief Function to set the GPIOx pin direction.
 *
 * @param The GPIO defined ports id.
 *      @see DIO_INTERFACE.h defined microcontroller ports.
 *
 * @param The GPIO Port defined pin id.
 *      @see DIO_INTERFACE.h defined pins for each port.
 *
 * @param The Microcontroller [TM4C123GH6PM] defined bus.
 *      @see SCR_INTERFACE.h defined microcontroller buses.
 *
 * @param The GPIO pin directions available.
 *      @arg DIO_PIN_DIR_INPUT
 *      @arg DIO_PIN_DIR_OUTPUT
 *
 * @return     The dio error status.
 */
extern DIO_ErrorStatus_t
MDIO_tSetPinDir(uC_PortID_t Copy_tPortID,
                uC_PinID_t Copy_tPinID,
                uC_BusID_t Copy_tBusID,
                uC_PinDir_t Copy_tPinDir);
/**
 * @brief Function to set the GPIOx pin current driven
 *        @note The maximum current driven should be calculated
 *              to avoid damaging the port/pin
 *
 * @param The GPIO defined ports id.
 *      @see DIO_INTERFACE.h defined microcontroller ports.
 *
 * @param The GPIO Port defined pin id.
 *      @see DIO_INTERFACE.h defined pins for each port.
 *
 * @param The Microcontroller [TM4C123GH6PM] defined bus.
 *      @see SCR_INTERFACE.h defined microcontroller buses.
 *
 * @param The GPIO pin current drivers available.
 *      @arg DIO_PIN_CD_2MA
 *      @arg DIO_PIN_CD_4MA
 *      @arg DIO_PIN_CD_8MA
 *
 * @return The dio error status.
 */
extern DIO_ErrorStatus_t
MDIO_tSetPinCurrentDrive(uC_PortID_t Copy_tPortID,
                         uC_PinID_t Copy_tPinID,
                         uC_BusID_t Copy_tBusID,
                         uC_PinCurrentDrive_t Copy_tCurrentDrive);
/**
 * @brief Function to set the GPIOx pin as digital or other.
 *        @note The maximum current driven should be calculated
 *              to avoid damaging the port/pin
 *
 * @param The GPIO defined ports id.
 *      @see DIO_INTERFACE.h defined microcontroller ports.
 *
 * @param The GPIO Port defined pin id.
 *      @see DIO_INTERFACE.h defined pins for each port.
 *
 * @param The Microcontroller [TM4C123GH6PM] defined bus.
 *      @see SCR_INTERFACE.h defined microcontroller buses.
 *
 * @param The GPIO pin digital state
 *      @brief The pin digital state is require to define
 *             the pin as digital or as Analog/AF
 *      @arg DIO_PIN_DIG_DISABLE
 *      @arg DIO_PIN_DIG_ENABLE
 *
 * @return The dio error status.
 */
extern DIO_ErrorStatus_t
MDIO_tSetPinDig(uC_PortID_t Copy_tPortID,
                uC_PinID_t Copy_tPinID,
                uC_BusID_t Copy_tBusID,
                uC_PinState_t Copy_tDigState);
/**
 * @brief Function to set the GPIOx pin current driven
 *        @note The maximum current driven should be calculated
 *              to avoid damaging the port/pin
 *
 * @param The GPIO defined ports id.
 *      @see DIO_INTERFACE.h defined microcontroller ports.
 *
 * @param The GPIO Port defined pin id.
 *      @see DIO_INTERFACE.h defined pins for each port.
 *
 * @param The Microcontroller [TM4C123GH6PM] defined bus.
 *      @see SCR_INTERFACE.h defined microcontroller buses.
 *
 * @param The GPIO pin value
 *      @arg DIO_PIN_VAL_LOW
 *      @arg DIO_PIN_VAL_HIGH
 *
 * @return The dio error status.
 */
extern DIO_ErrorStatus_t
MDIO_tSetPinVal(uC_PortID_t Copy_tPortID,
                uC_PinID_t Copy_tPinID,
                uC_BusID_t Copy_tBusID,
                uC_PinVal_t Copy_tPinVal);
/**
 * @brief Function to set the GPIOx pin as Alternate Function
 *
 * @param The GPIO defined ports id.
 *      @see DIO_INTERFACE.h defined microcontroller ports.
 *
 * @param The GPIO Port defined pin id.
 *      @see DIO_INTERFACE.h defined pins for each port.
 *
 * @param The Microcontroller [TM4C123GH6PM] defined bus.
 *      @see SCR_INTERFACE.h defined microcontroller buses.
 *
 * @return The dio error status.
 */
extern DIO_ErrorStatus_t
MDIO_tSetPinAF(uC_PortID_t Copy_tPortID,
               uC_PinID_t Copy_tPinID,
               uC_BusID_t Copy_tBusID);
/**
 * @brief Function to set the GPIOx pin as Open Drain
 *
 * @param The GPIO defined ports id.
 *      @see DIO_INTERFACE.h defined microcontroller ports.
 *
 * @param The GPIO Port defined pin id.
 *      @see DIO_INTERFACE.h defined pins for each port.
 *
 * @param The Microcontroller [TM4C123GH6PM] defined bus.
 *      @see SCR_INTERFACE.h defined microcontroller buses.
 *
 * @return The dio error status.
 */
extern DIO_ErrorStatus_t
MDIO_tSetPinOD(uC_PortID_t Copy_tPortID,
               uC_PinID_t Copy_tPinID,
               uC_BusID_t Copy_tBusID);
/**
 * @brief Function to set the GPIOx pin as Pulled Up (By Resistor)
 *
 * @param The GPIO defined ports id.
 *      @see DIO_INTERFACE.h defined microcontroller ports.
 *
 * @param The GPIO Port defined pin id.
 *      @see DIO_INTERFACE.h defined pins for each port.
 *
 * @param The Microcontroller [TM4C123GH6PM] defined bus.
 *      @see SCR_INTERFACE.h defined microcontroller buses.
 *
 * @return The dio error status.
 */
extern DIO_ErrorStatus_t
MDIO_tSetPinPUR(uC_PortID_t Copy_tPortID,
                uC_PinID_t Copy_tPinID,
                uC_BusID_t Copy_tBusID);
/**
 * @brief Function to set the GPIOx pin as Pulled Down (By Resistor)
 *
 * @param The GPIO defined ports id.
 *      @see DIO_INTERFACE.h defined microcontroller ports.
 *
 * @param The GPIO Port defined pin id.
 *      @see DIO_INTERFACE.h defined pins for each port.
 *
 * @param The Microcontroller [TM4C123GH6PM] defined bus.
 *      @see SCR_INTERFACE.h defined microcontroller buses.
 *
 * @return The dio error status.
 */
extern DIO_ErrorStatus_t
MDIO_tSetPinPDR(uC_PortID_t Copy_tPortID,
                uC_PinID_t Copy_tPinID,
                uC_BusID_t Copy_tBusID);
/**
 * @brief Function to set the GPIOx pin interrupt sense mode.
 *
 * @param The GPIO defined ports id.
 *      @see DIO_INTERFACE.h defined microcontroller ports.
 *
 * @param The GPIO Port defined pin id.
 *      @see DIO_INTERFACE.h defined pins for each port.
 *
 * @param The Microcontroller [TM4C123GH6PM] defined bus.
 *      @see SCR_INTERFACE.h defined microcontroller buses.
 *
 * @param The GPIO pin sense mode
 *      @see DIO_INTERFACE.h defined pins interrupt sense modes.
 *
 * @return The dio error status.
 */
extern DIO_ErrorStatus_t
MDIO_tSetPinIntSense(uC_PortID_t Copy_tPortID,
                     uC_PinID_t Copy_tPinID,
                     uC_BusID_t Copy_tBusID,
                     uC_PinInt_t Copy_tPinIntSense);
/**
 * @brief Function to set the GPIOx pin interrupt mask state.
 *
 * @param The GPIO defined ports id.
 *      @see DIO_INTERFACE.h defined microcontroller ports.
 *
 * @param The GPIO Port defined pin id.
 *      @see DIO_INTERFACE.h defined pins for each port.
 *
 * @param The Microcontroller [TM4C123GH6PM] defined bus.
 *      @see SCR_INTERFACE.h defined microcontroller buses.
 *
 * @param The GPIO pin interrupt mask state.
 *      @arg DIO_PIN_INT_ENABLE
 *      @arg DIO_PIN_INT_DISABLE
 *
 * @return The dio error status.
 */
extern DIO_ErrorStatus_t
MDIO_tSetPinIntState(uC_PortID_t Copy_tPortID,
                     uC_PinID_t Copy_tPinID,
                     uC_BusID_t Copy_tBusID,
                     uC_PinInt_t Copy_tPinIntState);
/**
 * @brief Function to get the GPIOx pin interrupt status.
 *
 * @param The GPIO defined ports id.
 *      @see DIO_INTERFACE.h defined microcontroller ports.
 *
 * @param The GPIO Port defined pin id.
 *      @see DIO_INTERFACE.h defined pins for each port.
 *
 * @param The Microcontroller [TM4C123GH6PM] defined bus.
 *      @see SCR_INTERFACE.h defined microcontroller buses.
 *
 * @param The GPIO pin interrupt status
 *
 * @return The dio error status.
 */
extern DIO_ErrorStatus_t
MDIO_tGetPinIntStatus(uC_PortID_t Copy_tPortID,
                      uC_PinID_t Copy_tPinID,
                      uC_BusID_t Copy_tBusID,
                      uC_PinInt_t *pArg_tPinIntStatus);
/**
 * @brief Function to set the GPIOx PORTx
 *        Interrupt Service Routine Function
 *        (Call Back Function)
 *
 * @param The GPIO defined ports id.
 *      @see DIO_INTERFACE.h defined microcontroller ports.
 *
 * @param The PORTx Call Back Function
 *      @brief Function pointer to the defined
 *             call back ISR Function.
 *      @note Function should be defined as
 *            void FUNCTION_NAME(void) {}
 *
 * @return The dio error status.
 */
extern DIO_ErrorStatus_t
MDIO_tSetCallBack(uC_PortID_t Copy_tPortID,
                  GPIO_EXTI_FuncPtr_t Copy_tCallBackFunc);

#endif /* __DIO_INTERFACE_H__ */
