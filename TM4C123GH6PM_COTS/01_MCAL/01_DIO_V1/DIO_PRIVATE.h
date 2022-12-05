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
#define GPIOA_APB_BASE_ADDRESS  ( (u32) (0x40004000UL) )
#define GPIOB_APB_BASE_ADDRESS  ( (u32) (0x40005000UL) )
#define GPIOC_APB_BASE_ADDRESS  ( (u32) (0x40006000UL) )
#define GPIOD_APB_BASE_ADDRESS  ( (u32) (0x40007000UL) )
#define GPIOE_APB_BASE_ADDRESS  ( (u32) (0x40024000UL) )
#define GPIOF_APB_BASE_ADDRESS  ( (u32) (0x40025000UL) )
#define GPIOA_AHB_BASE_ADDRESS  ( (u32) (0x40058000UL) )
#define GPIOB_AHB_BASE_ADDRESS  ( (u32) (0x40059000UL) )
#define GPIOC_AHB_BASE_ADDRESS  ( (u32) (0x4005A000UL) )
#define GPIOD_AHB_BASE_ADDRESS  ( (u32) (0x4005B000UL) )
#define GPIOE_AHB_BASE_ADDRESS  ( (u32) (0x4005C000UL) )
#define GPIOF_AHB_BASE_ADDRESS  ( (u32) (0x4005D000UL) )
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
#define DIO_NUM_OF_PORTS           ( (u8) (0x06U) )
#define DIO_PORT_MAX_PIN_NUMS      ( (u8) (0x08U) )
#define DIO_PORTA_MAX_PIN_NUMS     ( (u8) (0x07U) )
#define DIO_PORTB_MAX_PIN_NUMS     ( (u8) (0x07U) )
#define DIO_PORTC_MAX_PIN_NUMS     ( (u8) (0x07U) )
#define DIO_PORTD_MAX_PIN_NUMS     ( (u8) (0x07U) )
#define DIO_PORTE_MAX_PIN_NUMS     ( (u8) (0x06U) )
#define DIO_PORTF_MAX_PIN_NUMS     ( (u8) (0x05U) )

#define DIOA_APB_BUS_ID            (GPIOA_APB_BASE_ADDRESS)
#define DIOB_APB_BUS_ID            (GPIOB_APB_BASE_ADDRESS)
#define DIOC_APB_BUS_ID            (GPIOC_APB_BASE_ADDRESS)
#define DIOD_APB_BUS_ID            (GPIOD_APB_BASE_ADDRESS)
#define DIOE_APB_BUS_ID            (GPIOE_APB_BASE_ADDRESS)
#define DIOF_APB_BUS_ID            (GPIOF_APB_BASE_ADDRESS)
#define DIOA_AHB_BUS_ID            (GPIOA_AHB_BASE_ADDRESS)
#define DIOB_AHB_BUS_ID            (GPIOB_AHB_BASE_ADDRESS)
#define DIOC_AHB_BUS_ID            (GPIOC_AHB_BASE_ADDRESS)
#define DIOD_AHB_BUS_ID            (GPIOD_AHB_BASE_ADDRESS)
#define DIOE_AHB_BUS_ID            (GPIOE_AHB_BASE_ADDRESS)
#define DIOF_AHB_BUS_ID            (GPIOF_AHB_BASE_ADDRESS)

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

/** @defgroup Macro Configuration parameters declaration */
/** @defgroup Pin mode config param */
#define DIO_PIN_MODE_DIGITAL        ( (u8) (0x00U) )
#define DIO_PIN_MODE_ANALOG         ( (u8) (0x01U) )
/** @defgroup Pin dir config param */
#define DIO_PIN_DIR_INPUT           ( (u8) (0x00U) )
#define DIO_PIN_DIR_OUTPUT          ( (u8) (0x01U) )
/** @defgroup Pin data config param */
#define DIO_PIN_DATA_LOW            ( (u8) (0x00U) )
#define DIO_PIN_DATA_HIGH           ( (u8) (0x01U) )
/** @defgroup Pin af config param */
#define DIO_PIN_AF_INACTIVE         ( (u8) (0x00U) )
#define DIO_PIN_AF_ACTIVE           ( (u8) (0x01U) )
/** @defgroup Pin pur config param */
#define DIO_PIN_PUR_INACTIVE        ( (u8) (0x00U) )
#define DIO_PIN_PUR_ACTIVE          ( (u8) (0x01U) )
/** @defgroup Pin pdr config param */
#define DIO_PIN_PDR_INACTIVE        ( (u8) (0x00U) )
#define DIO_PIN_PDR_ACTIVE          ( (u8) (0x01U) )
/** @defgroup Pin od config param */
#define DIO_PIN_OD_INACTIVE         ( (u8) (0x00U) )
#define DIO_PIN_OD_ACTIVE           ( (u8) (0x01U) )
/** @defgroup Pin slr config param */
#define DIO_PIN_SLR_INACTIVE        ( (u8) (0x00U) )
#define DIO_PIN_SLR_ACTIVE          ( (u8) (0x01U) )
/** @defgroup Pin commit config param */
#define DIO_PIN_COMMIT_INACTIVE     ( (u8) (0x00U) )
#define DIO_PIN_COMMIT_ACTIVE       ( (u8) (0x01U) )
/** @defgroup Pin adctl config param */
#define DIO_PIN_ADCTL_INACTIVE      ( (u8) (0x00U) )
#define DIO_PIN_ADCTL_ACTIVE        ( (u8) (0x01U) )
/** @defgroup Pin dmactl config param */
#define DIO_PIN_DMACTL_INACTIVE     ( (u8) (0x00U) )
#define DIO_PIN_DMACTL_ACTIVE       ( (u8) (0x01U) )
/** @defgroup Pin dr2 config param */
#define DIO_PIN_DR2_INACTIVE        ( (u8) (0x00U) )
#define DIO_PIN_DR2_ACTIVE          ( (u8) (0x01U) )
/** @defgroup Pin dr4 config param */
#define DIO_PIN_DR4_INACTIVE        ( (u8) (0x00U) )
#define DIO_PIN_DR4_ACTIVE          ( (u8) (0x01U) )
/** @defgroup Pin dr8 config param */
#define DIO_PIN_DR8_INACTIVE        ( (u8) (0x00U) )
#define DIO_PIN_DR8_ACTIVE          ( (u8) (0x01U) )
/** @defgroup Pin int mask config param */
#define DIO_PIN_INTMASK_INACTIVE    ( (u8) (0x00U) )
#define DIO_PIN_INTMASK_ACTIVE      ( (u8) (0x01U) )
/** @defgroup Pin int sense config param */
#define DIO_PIN_INTSENSE_FE         ( (u8) (0x00U) )
#define DIO_PIN_INTSENSE_RE         ( (u8) (0x01U) )
#define DIO_PIN_INTSENSE_LL         ( (u8) (0x02U) )
#define DIO_PIN_INTSENSE_HL         ( (u8) (0x03U) )
#define DIO_PIN_INTSENSE_BE         ( (u8) (0x04U) )
#define DIO_PIN_INTSENSE_BL         ( (u8) (0x05U) )
/** @defgroup Pin int status config param */
#define DIO_PIN_INTSTATUS_INACTIVE  ( (u8) (0x00U) )
#define DIO_PIN_INTSTATUS_ACTIVE    ( (u8) (0x01U) )

/*
----------------------------------------------------------------------
- Data types
----------------------------------------------------------------------
*/

/**
 * @brief DIO error status enum.
 */
typedef enum
{
    DIO_NOK  = 0x00U,
    DIO_OK
}En_DIO_ErrorStatus_t;

/**
 * @defgroup User defined data type.
 */
typedef u8 uC_GPIOxID_t;
typedef void (*DIO_CallBackFuncPtr_t)(void);

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
    Reg_t Port;
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
static void
vSetPORT_PinCfg(const St_PortCfg_t * const Copy_tPortCfgInstance);

static En_DIO_ErrorStatus_t
EnPortCfgInstanceHandler(const St_PortCfg_t * const Copy_tPortCfgInstance);

/** @defgroup Interrupt ISR functions */
static En_DIO_ErrorStatus_t
EnSetCallBack(uC_PortID_t Copy_tPortID,
              DIO_CallBackFuncPtr_t Copy_tCallBackFunc);

__attribute__((signal, used))
void GPIOA_Handler(void);

__attribute__((signal, used))
void GPIOB_Handler(void);

__attribute__((signal, used))
void GPIOC_Handler(void);

__attribute__((signal, used))
void GPIOD_Handler(void);

__attribute__((signal, used))
void GPIOE_Handler(void);

__attribute__((signal, used))
void GPIOF_Handler(void);

#endif /* __DIO_PRIVATE_H__ */
