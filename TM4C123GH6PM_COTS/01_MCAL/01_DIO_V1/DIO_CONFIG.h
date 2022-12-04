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

/** @degroup Port A specific configurations */
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_MODE_DIGITAL
 *      @arg DIO_PORTA_PIN_MODE_ANALOG
 */
#define DIO_PORTA_PIN_MODE
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_DIR_INPUT
 *      @arg DIO_PORTA_PIN_DIR_OUTPUT
 */
#define DIO_PORTA_PIN_DIR
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_STRENGTH_2MA
 *      @arg DIO_PORTA_PIN_STRENGTH_4MA
 *      @arg DIO_PORTA_PIN_STRENGTH_8MA
 */
#define DIO_PORTA_PIN_STRENGTH
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_PUR_ACTIVE
 *      @arg DIO_PORTA_PIN_PUR_INACTIVE
 */
#define DIO_PORTA_PIN_PUR
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_PDR_ACTIVE
 *      @arg DIO_PORTA_PIN_PDR_INACTIVE
 */
#define DIO_PORTA_PIN_PDR
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_OD_ACTIVE
 *      @arg DIO_PORTA_PIN_OD_INACTIVE
 */
#define DIO_PORTA_PIN_OD
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_AF_ACTIVE
 *      @arg DIO_PORTA_PIN_AF_INACTIVE
 */
#define DIO_PORTA_PIN_AF
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
#define DIO_PORTA_PIN_INT_SENSE
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_INT_MASK_ACTIVE
 *      @arg DIO_PORTA_PIN_INT_MASK_INACTIVE
 */
#define DIO_PORTA_PIN_INT_MASK
/**
 * @brief .
 *
 * @defgroup Config Params
 *      @arg DIO_PORTA_PIN_INIT_DATA_LOW
 *      @arg DIO_PORTA_PIN_INIT_DATA_HIGH
 */
#define DIO_PORTA_PIN_INIT_DATA



#endif /* __DIO_CONFIG_H__ */
