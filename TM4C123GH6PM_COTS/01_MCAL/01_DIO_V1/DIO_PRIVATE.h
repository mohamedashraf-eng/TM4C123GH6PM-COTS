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

/** @defgroup Normal peripheral address */
#define GPIOA_APB_BASE_ADDRESS  ( (u32) () )
#define GPIOB_APB_BASE_ADDRESS  ( (u32) () )
#define GPIOC_APB_BASE_ADDRESS  ( (u32) () )
#define GPIOD_APB_BASE_ADDRESS  ( (u32) () )
#define GPIOE_APB_BASE_ADDRESS  ( (u32) () )
#define GPIOF_APB_BASE_ADDRESS  ( (u32) () )
#define GPIOA_AHB_BASE_ADDRESS  ( (u32) () )
#define GPIOB_AHB_BASE_ADDRESS  ( (u32) () )
#define GPIOC_AHB_BASE_ADDRESS  ( (u32) () )
#define GPIOD_AHB_BASE_ADDRESS  ( (u32) () )
#define GPIOE_AHB_BASE_ADDRESS  ( (u32) () )
#define GPIOF_AHB_BASE_ADDRESS  ( (u32) () )
/** @defgroup Normal peripheral registers addresses */
#define GPIO_DATA(_PORT_BASE_ADDR)   ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x000UL)) )
#define GPIO_DIR(_PORT_BASE_ADDR)    ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x400UL)) )
#define GPIO_IS(_PORT_BASE_ADDR)     ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x404UL)) )
#define GPIO_IBE(_PORT_BASE_ADDR)    ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x408UL)) )
#define GPIO_IEV(_PORT_BASE_ADDR)    ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x40CUL)) )
#define GPIO_IM(_PORT_BASE_ADDR)     ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x410UL)) )
#define GPIO_RIS(_PORT_BASE_ADDR)    ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x414UL)) )
#define GPIO_MIS(_PORT_BASE_ADDR)    ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x418UL)) )
#define GPIO_ICR(_PORT_BASE_ADDR)    ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x41CUL)) )
#define GPIO_AFSEL(_PORT_BASE_ADDR)  ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x420UL)) )
#define GPIO_DR2R(_PORT_BASE_ADDR)   ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x500UL)) )
#define GPIO_DR4R(_PORT_BASE_ADDR)   ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x504UL)) )
#define GPIO_DR8R(_PORT_BASE_ADDR)   ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x508UL)) )
#define GPIO_ODR(_PORT_BASE_ADDR)    ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x50CUL)) )
#define GPIO_PUR(_PORT_BASE_ADDR)    ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x510UL)) )
#define GPIO_PDR(_PORT_BASE_ADDR)    ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x514UL)) )
#define GPIO_SLR(_PORT_BASE_ADDR)    ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x518UL)) )
#define GPIO_DEN(_PORT_BASE_ADDR)    ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x51CUL)) )
#define GPIO_LOCK(_PORT_BASE_ADDR)   ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x520UL)) )
#define GPIO_CR(_PORT_BASE_ADDR)     ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x524UL)) )
#define GPIO_AMSEL(_PORT_BASE_ADDR)  ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x528UL)) )
#define GPIO_PCTL(_PORT_BASE_ADDR)   ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x52CUL)) )
#define GPIO_ADCCTL(_PORT_BASE_ADDR) ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x530UL)) )
#define GPIO_DMACTL(_PORT_BASE_ADDR) ( REG32RWM(ADD_OFFSET(_PORT_BASE_ADDR, 0x534UL)) )

/** @defgroup Bit-Band memory address */
/** @defgroup Bit-Band peripheral registers addresses */

/*
----------------------------------------------------------------------
- Macros
----------------------------------------------------------------------
*/

/**
 * @brief Function like macro to access 32-bit register
 *        for read write modify.
 *
 */
#define REG32RWM(_REG_ADDR) ( *((Reg_t * const)(_REG_ADDR)) )
/**
 * @brief Function like macro to add offset to the base address.
 *
 */
#define ADD_OFFSET(_BASE_ADDR, _OFFSET) (_BASE_ADDR + _OFFSET)

/** @defgroup developr macros */
#define DIO_PORT_MAX_PIN_NUMS      ( (u8) (0x08U) )
#define DIO_PORTA_MAX_PIN_NUMS     ( (u8) (0x07U) )
#define DIO_PORTB_MAX_PIN_NUMS     ( (u8) (0x07U) )
#define DIO_PORTC_MAX_PIN_NUMS     ( (u8) (0x07U) )
#define DIO_PORTD_MAX_PIN_NUMS     ( (u8) (0x07U) )
#define DIO_PORTE_MAX_PIN_NUMS     ( (u8) (0x06U) )
#define DIO_PORTF_MAX_PIN_NUMS     ( (u8) (0x05U) )

/*
----------------------------------------------------------------------
- Data types
----------------------------------------------------------------------
*/

/**
 * @defgroup User defined data type.
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
    u8 mode         : 0x01U; /** @brief Analog/Digital  */
    u8 direction    : 0x01U; /** @brief Input/Output    */
    u8 dr2          : 0x01U; /** @brief 2mA  drive      */
    u8 dr4          : 0x01U; /** @brief 4mA  drive      */
    u8 dr8          : 0x01U; /** @brief 8mA  drive      */
    u8 pur          : 0x01U; /** @brief Active/Inactive */
    u8 pdr          : 0x01U; /** @brief Active/Inactive */
    u8 slr          : 0x01U; /** @brief Active/Inactive */
    u8 od           : 0x01U; /** @brief Active/Inactive */
    u8 af           : 0x01U; /** @brief Active/Inactive */
    u8 dmactl       : 0x01U; /** @brief Active/Inactive */
    u8 adcctl       : 0x01U; /** @brief Active/Inactive */
    u8 commit       : 0x01U; /** @brief Active/Inactive */
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
    uC_PortID_t Port;
    St_PinCfg_t Pin[DIO_PORT_MAX_PIN_NUMS];
    uC_GPIOxID_t ID;

    /* Struct methods */

}St_PortCfg_t;


/*
----------------------------------------------------------------------
- Private functions declaration
----------------------------------------------------------------------
*/

__attribute__((always_inline))
static En_DIO_ErrorStatus_t
EnSetPORTA_Cfg(const St_PinCfg_t * const Copy_tPinCfgInstance);

__attribute__((always_inline))
static En_DIO_ErrorStatus_t
EnSetPORTB_Cfg(const St_PinCfg_t * const Copy_tCPinfgInstance);

__attribute__((always_inline))
static En_DIO_ErrorStatus_t
EnSetPORTC_Cfg(const St_PinCfg_t * const Copy_tPinCfgInstance);

__attribute__((always_inline))
static En_DIO_ErrorStatus_t
EnSetPORTD_Cfg(const St_PinCfg_t * const Copy_tPinCfgInstance);

__attribute__((always_inline))
static En_DIO_ErrorStatus_t
EnSetPORTE_Cfg(const St_PinCfg_t * const Copy_tPinCfgInstance);

__attribute__((always_inline))
static En_DIO_ErrorStatus_t
EnSetPORTF_Cfg(const St_PinCfg_t * const Copy_tPinCfgInstance);


static En_DIO_ErrorStatus_t
EnPortCfgInstanceHandler(const St_PortCfg_t * const Copy_tPortCfgInstance);

#endif /* __DIO_PRIVATE_H__ */
