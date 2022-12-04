/**
 * @file DIO_PRIVATE.h
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __DIO_PRIVATE_H__
#define __DIO_PRIVATE_H__

/*
----------------------------------------------------------------------
- Registers file
----------------------------------------------------------------------
*/

/** @defgroup Noraml memory address */
#define GPIOA_BASE_ADDRESS  ( (u32) () )
#define GPIOB_BASE_ADDRESS  ( (u32) () )
#define GPIOC_BASE_ADDRESS  ( (u32) () )
#define GPIOD_BASE_ADDRESS  ( (u32) () )
#define GPIOE_BASE_ADDRESS  ( (u32) () )
#define GPIOF_BASE_ADDRESS  ( (u32) () )

/** @defgroup Bit-Band memory address */

/*
----------------------------------------------------------------------
- Macros
----------------------------------------------------------------------
*/

/** @defgroup developr macros */
#define DIO_PORTA_PIN_NUMS      ( (u8) (0x07U) )
#define DIO_PORTB_PIN_NUMS      ( (u8) (0x07U) )
#define DIO_PORTC_PIN_NUMS      ( (u8) (0x07U) )
#define DIO_PORTD_PIN_NUMS      ( (u8) (0x07U) )
#define DIO_PORTE_PIN_NUMS      ( (u8) (0x06U) )
#define DIO_PORTF_PIN_NUMS      ( (u8) (0x05U) )


/*
----------------------------------------------------------------------
- Data types
----------------------------------------------------------------------
*/

typedef u8 uC_GPIOxID_t;

/**
 * @defgroup Struct data type.
 */
/**
 * @brief Struct to contain all possible configuration for
 *        the microcontroller pin.
 * @note packing attribute is used to reduce the padding size.
 */
__attribute__((packing))
typedef struct
{
    uC_PinID_t Pin  : 0x03U; /** @brief Pin num         */
    u8 mode         : 0x01U; /** @brief Analog/Digital  */
    u8 direction    : 0x01U; /** @brief Input/Output    */
    u8 strength     : 0x02U; /** @brief 2mA/4mA/8mA     */
    u8 pur          : 0x01U; /** @brief Active/Inactive */
    u8 pdr          : 0x01U; /** @brief Active/Inactive */
    u8 od           : 0x01U; /** @brief Active/Inactive */
    u8 af           : 0x01U; /** @brief Active/Inactive */
    u8 int_sense    : 0x02U; /** @brief Pin Int Modes   */
    u8 int_mask     : 0x01U; /** @brief Active/Inactive */
    u8 int_status   : 0x01U; /** @brief Active/Inactive */
    u8 data         : 0x01U; /** @brief High/Low        */
}St_PinCfg_t;
/**
 * @brief Struct for the microcontroller porta configurations and info.
 *
 * @note packing attribute is used to reduce the padding size.
 */
__attribute__((packing))
typedef struct
{
    /* Struct variables */
    St_PinCfg_t Pin[DIO_PORTA_PIN_NUMS];
    uC_PortID_t Port;
    uC_GPIOxID_t ID;

    /* Struct methods */

}St_PORTA_Cfg_t;


/*
----------------------------------------------------------------------
- Private functions declaration
----------------------------------------------------------------------
*/


#endif /* __DIO_PRIVATE_H__ */
