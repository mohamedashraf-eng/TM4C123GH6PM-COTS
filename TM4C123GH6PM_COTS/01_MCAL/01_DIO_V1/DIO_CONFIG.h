/**
 * @file DIO_CONFIG.h
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __DIO_CONFIG_H__
#define __DIO_CONFIG_H__

/*
----------------------------------------------------------------------
- Configuration Parameters
----------------------------------------------------------------------
*/

/**
 * @brief PORTx Access via BUSx
 *        set the bus id for each port.
 *
 * @defgroup Config Params
 *      @arg DIO_APB_BUS_ID
 *      @arg DIO_AHB_BUS_ID
 */
#define DIO_PORTA_BUS   ( DIO_APB_BUS_ID )
#define DIO_PORTB_BUS   ( DIO_APB_BUS_ID )
#define DIO_PORTC_BUS   ( DIO_APB_BUS_ID )
#define DIO_PORTD_BUS   ( DIO_APB_BUS_ID )
#define DIO_PORTE_BUS   ( DIO_APB_BUS_ID )
#define DIO_PORTF_BUS   ( DIO_AHB_BUS_ID )
/**
 * @brief PORT mode.
 *
 * @defgroup Config Params
 *      @arg DIO_PORT_CONFIG_ACTIVE
 *      @arg DIO_PORT_CONFIG_INACTIVE
 */
#define DIO_PORTA_CONFIG  ( DIO_PORT_CONFIG_INACTIVE )
#define DIO_PORTB_CONFIG  ( DIO_PORT_CONFIG_INACTIVE )
#define DIO_PORTC_CONFIG  ( DIO_PORT_CONFIG_INACTIVE )
#define DIO_PORTD_CONFIG  ( DIO_PORT_CONFIG_INACTIVE )
#define DIO_PORTE_CONFIG  ( DIO_PORT_CONFIG_INACTIVE )
#define DIO_PORTF_CONFIG  ( DIO_PORT_CONFIG_INACTIVE )

/** @degroup Port A specific configurations */
/** @brief Check if the port is active or inactive */
#if (DIO_PORTA_MODE == DIO_PORT_CONFIG_ACTIVE)

/** @defgroup Port A, Pin 0 */
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_MODE_DIGITAL
 *      @arg DIO_PORTA_PIN_MODE_ANALOG
 */
#define DIO_PORTA_PIN0_MODE
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_DIR_INPUT
 *      @arg DIO_PORTA_PIN_DIR_OUTPUT
 */
#define DIO_PORTA_PIN0_DIR
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_STRENGTH_2MA
 *      @arg DIO_PORTA_PIN_STRENGTH_4MA
 *      @arg DIO_PORTA_PIN_STRENGTH_8MA
 */
#define DIO_PORTA_PIN0_STRENGTH
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_PUR_ACTIVE
 *      @arg DIO_PORTA_PIN_PUR_INACTIVE
 */
#define DIO_PORTA_PIN0_PUR
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_PDR_ACTIVE
 *      @arg DIO_PORTA_PIN_PDR_INACTIVE
 */
#define DIO_PORTA_PIN0_PDR
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_OD_ACTIVE
 *      @arg DIO_PORTA_PIN_OD_INACTIVE
 */
#define DIO_PORTA_PIN0_OD
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_AF_ACTIVE
 *      @arg DIO_PORTA_PIN_AF_INACTIVE
 */
#define DIO_PORTA_PIN0_AF
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_INT_SENSE_FE << Falling Edge.
 *      @arg DIO_PORTA_PIN_INT_SENSE_RE << Rising Edge.
 *      @arg DIO_PORTA_PIN_INT_SENSE_LL << Low Level.
 *      @arg DIO_PORTA_PIN_INT_SENSE_HL << High Level.
 *      @arg DIO_PORTA_PIN_INT_SENSE_EB << Both Edge.
 *      @arg DIO_PORTA_PIN_INT_SENSE_LB << Both Level.
 */
#define DIO_PORTA_PIN0_INT_SENSE
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_INT_MASK_ACTIVE
 *      @arg DIO_PORTA_PIN_INT_MASK_INACTIVE
 */
#define DIO_PORTA_PIN0_INT_MASK
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_INIT_DATA_LOW
 *      @arg DIO_PORTA_PIN_INIT_DATA_HIGH
 */
#define DIO_PORTA_PIN0_INIT_DATA

/** @defgroup Port A, Pin 1 */
/** @defgroup Port A, Pin 2 */
/** @defgroup Port A, Pin 3 */
/** @defgroup Port A, Pin 4 */
/** @defgroup Port A, Pin 5 */
/** @defgroup Port A, Pin 6 */
/** @defgroup Port A, Pin 7 */

#else
    #warning ("PORTA MODE: INACTIVE")
#endif

#endif /* __DIO_CONFIG_H__ */
