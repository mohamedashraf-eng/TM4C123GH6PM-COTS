/**
 * @file DIO_PRIVATE.h
 * @author Ahmed Osama, Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Osama, Wx
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

#define GPIOA_APB_BASE_ADDRESS  ( (u32) (0x40004000U) )
#define GPIOA_AHB_BASE_ADDRESS  ( (u32) (0x40058000U) )

#define GPIOB_APB_BASE_ADDRESS  ( (u32) (0x40005000U) )
#define GPIOB_AHB_BASE_ADDRESS  ( (u32) (0x40059000U) )

#define GPIOC_APB_BASE_ADDRESS  ( (u32) (0x40006000U) )
#define GPIOC_AHB_BASE_ADDRESS  ( (u32) (0x4005A000U) )

#define GPIOD_APB_BASE_ADDRESS  ( (u32) (0x40007000U) )
#define GPIOD_AHB_BASE_ADDRESS  ( (u32) (0x4005B000U) )

#define GPIOE_APB_BASE_ADDRESS  ( (u32) (0x40024000U) )
#define GPIOE_AHB_BASE_ADDRESS  ( (u32) (0x4005C000U) )

#define GPIOF_APB_BASE_ADDRESS  ( (u32) (0x40025000U) )
#define GPIOF_AHB_BASE_ADDRESS  ( (u32) (0x4005D000U) )

typedef struct
{
    const u32 MEMORY_BLOCK_1_RESERVED[255U];
    u32 volatile DATA;
    u32 volatile DIR;
    u32 volatile IS;
    u32 volatile IBE;
    u32 volatile IEV;
    u32 volatile IM;
    u32 volatile RIS;
    u32 volatile MIS;
    u32 volatile ICR;
    u32 volatile AFSEL;
    const u32 MEMORY_BLOCK_2_RESERVED[55U];
    u32 volatile DR2R;
    u32 volatile DR4R;
    u32 volatile DR8R;
    u32 volatile ODR;
    u32 volatile PUR;
    u32 volatile PDR;
    u32 volatile SLR;
    u32 volatile DEN;
    u32 volatile LOCK;
    u32 volatile CR;
    u32 volatile AMSEL;
    u32 volatile PCTL;
    u32 volatile DCTL;
    u32 volatile DMACTL;
	/* To be added
    u32 volatile PeriphID4;
    u32 volatile PeriphID5;
    u32 volatile PeriphID6;
    u32 volatile PeriphID7;
    u32 volatile PeriphID0;
    u32 volatile PeriphID1;
    u32 volatile PeriphID2;
    u32 volatile PeriphID3;
    u32 volatile PCellID0;
    u32 volatile PCellID1;
    u32 volatile PCellID2;
    u32 volatile PCellID3;
	*/
}ST_GPIOxRegisters_t;

#define GPIOA_APB ( (ST_GPIOxRegisters_t volatile * const) (GPIOA_APB_BASE_ADDRESS) )
#define GPIOA_AHB ( (ST_GPIOxRegisters_t volatile * const) (GPIOA_AHB_BASE_ADDRESS) )

#define GPIOB_APB ( (ST_GPIOxRegisters_t volatile * const) (GPIOB_APB_BASE_ADDRESS) )
#define GPIOB_AHB ( (ST_GPIOxRegisters_t volatile * const) (GPIOB_AHB_BASE_ADDRESS) )

#define GPIOC_APB ( (ST_GPIOxRegisters_t volatile * const) (GPIOC_APB_BASE_ADDRESS) )
#define GPIOC_AHB ( (ST_GPIOxRegisters_t volatile * const) (GPIOC_AHB_BASE_ADDRESS) )

#define GPIOD_APB ( (ST_GPIOxRegisters_t volatile * const) (GPIOD_APB_BASE_ADDRESS) )
#define GPIOD_AHB ( (ST_GPIOxRegisters_t volatile * const) (GPIOD_AHB_BASE_ADDRESS) )

#define GPIOE_APB ( (ST_GPIOxRegisters_t volatile * const) (GPIOE_APB_BASE_ADDRESS) )
#define GPIOE_AHB ( (ST_GPIOxRegisters_t volatile * const) (GPIOE_AHB_BASE_ADDRESS) )

#define GPIOF_APB ( (ST_GPIOxRegisters_t volatile * const) (GPIOF_APB_BASE_ADDRESS) )
#define GPIOF_AHB ( (ST_GPIOxRegisters_t volatile * const) (GPIOF_AHB_BASE_ADDRESS) )

/*
----------------------------------------------------------------------
- Macros
----------------------------------------------------------------------
*/

#define NUM_OF_PORTS           ( (u8) (0x06U) )
/** @defgroup Call Back functions indecies */
#define GPIOA_EXTI_FunctionPtr ( (u8) (0x00U) )
#define GPIOB_EXTI_FunctionPtr ( (u8) (0x01U) )
#define GPIOC_EXTI_FunctionPtr ( (u8) (0x02U) )
#define GPIOD_EXTI_FunctionPtr ( (u8) (0x03U) )
#define GPIOE_EXTI_FunctionPtr ( (u8) (0x04U) )
#define GPIOF_EXTI_FunctionPtr ( (u8) (0x05U) )

/*
----------------------------------------------------------------------
- Data types
----------------------------------------------------------------------
*/

typedef u8 DIO_ErrorStatus_t;

typedef u8 uC_PinDir_t;

typedef u8 uC_PinCurrentDrive_t;

typedef u8 uC_PinState_t;

typedef u8 uC_PinVal_t;

typedef u8 uC_PinInt_t;

typedef u8 uC_PinMode_t;

/** @brief Function pointer type for the EXTI Callback */
typedef void (*GPIO_EXTI_FuncPtr_t)(void);

/*
----------------------------------------------------------------------
- Private functions declaration
----------------------------------------------------------------------
*/
/**
 * @defgroup Pin Function: Pin Direction
 */
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinDir_PORTA(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinDir_t Copy_tPinDir);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinDir_PORTB(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinDir_t Copy_tPinDir);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinDir_PORTC(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinDir_t Copy_tPinDir);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinDir_PORTD(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinDir_t Copy_tPinDir);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinDir_PORTE(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinDir_t Copy_tPinDir);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinDir_PORTF(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinDir_t Copy_tPinDir);
/**
 * @defgroup Pin Function: Current Drive
 */
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinCurrDrv_PORTA(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinCurrentDrive_t Copy_tCurrentDrive);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinCurrDrv_PORTB(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinCurrentDrive_t Copy_tCurrentDrive);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinCurrDrv_PORTC(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinCurrentDrive_t Copy_tCurrentDrive);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinCurrDrv_PORTD(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinCurrentDrive_t Copy_tCurrentDrive);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinCurrDrv_PORTE(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinCurrentDrive_t Copy_tCurrentDrive);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinCurrDrv_PORTF(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinCurrentDrive_t Copy_tCurrentDrive);
/**
 * @defgroup Pin Function: Pin Digitality
 */
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinDig_PORTA(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinState_t Copy_tDigState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinDig_PORTB(uC_BusID_t Copy_tBusID,
                     uC_PinID_t Copy_tPinID,
                     uC_PinState_t Copy_tDigState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinDig_PORTC(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinDig_PORTD(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinDig_PORTE(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinDig_PORTF(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState);
/**
 * @defgroup Pin Function: Data Value
 */
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinVal_PORTA(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinVal_PORTB(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinVal_PORTC(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinVal_PORTD(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinVal_PORTE(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinState_t Copy_tDigState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinVal_PORTF(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID,
                 uC_PinVal_t Copy_tPinVal);
/**
 * @defgroup Pin Function: Interrupt Sense
 */
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinIntSense_PORTA(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntSense);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinIntSense_PORTB(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntSense);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinIntSense_PORTC(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntSense);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinIntSense_PORTD(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntSense);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinIntSense_PORTE(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntSense);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinIntSense_PORTF(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntSense);
/**
 * @defgroup Pin Function: Interrupt State
 */
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinIntState_PORTA(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinIntState_PORTB(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinIntState_PORTC(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinIntState_PORTD(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinIntState_PORTE(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntState);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinIntState_PORTF(uC_BusID_t Copy_tBusID,
                      uC_PinID_t Copy_tPinID,
                      uC_PinInt_t Copy_tPinIntState);
/**
 * @defgroup Pin Function: Pull Up Resistance
 */
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinPUR_PORTA(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinPUR_PORTB(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinPUR_PORTC(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinPUR_PORTD(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinPUR_PORTE(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinPUR_PORTF(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID);
/**
 * @defgroup Pin Function: Pull Down Resistance
 */
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinPDR_PORTA(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinPDR_PORTB(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinPDR_PORTC(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinPDR_PORTD(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinPDR_PORTE(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinPDR_PORTF(uC_BusID_t Copy_tBusID,
                 uC_PinID_t Copy_tPinID);
/**
 * @defgroup Pin Function: Open Drain
 */
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinOD_PORTA(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinOD_PORTB(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinOD_PORTC(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinOD_PORTD(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinOD_PORTE(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinOD_PORTF(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID);
/**
 * @defgroup Pin Function: Alternate Function
 */
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinAF_PORTA(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinAF_PORTB(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinAF_PORTC(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinAF_PORTD(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinAF_PORTE(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tSetPinAF_PORTF(uC_BusID_t Copy_tBusID,
                uC_PinID_t Copy_tPinID);
/**
 * @defgroup Pin Function: Get interrupt status
 */
__attribute__((always_inline))
static DIO_ErrorStatus_t
tGetPinIntStatus_PORTA(uC_BusID_t Copy_tBusID,
                       uC_PinID_t Copy_tPinID,
                       uC_PinInt_t *pArg_tPinIntStatus);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tGetPinIntStatus_PORTB(uC_BusID_t Copy_tBusID,
                       uC_PinID_t Copy_tPinID,
                       uC_PinInt_t *pArg_tPinIntStatus);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tGetPinIntStatus_PORTC(uC_BusID_t Copy_tBusID,
                       uC_PinID_t Copy_tPinID,
                       uC_PinInt_t *pArg_tPinIntStatus);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tGetPinIntStatus_PORTD(uC_BusID_t Copy_tBusID,
                       uC_PinID_t Copy_tPinID,
                       uC_PinInt_t *pArg_tPinIntStatus);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tGetPinIntStatus_PORTE(uC_BusID_t Copy_tBusID,
                       uC_PinID_t Copy_tPinID,
                       uC_PinInt_t *pArg_tPinIntStatus);
__attribute__((always_inline))
static DIO_ErrorStatus_t
tGetPinIntStatus_PORTF(uC_BusID_t Copy_tBusID,
                       uC_PinID_t Copy_tPinID,
                       uC_PinInt_t *pArg_tPinIntStatus);

/** @defgroup GPIO EXTI Handlers */
__attribute__((vector, used))
void GPIOA_Handler(void);
__attribute__((vector, used))
void GPIOB_Handler(void);
__attribute__((vector, used))
void GPIOC_Handler(void);
__attribute__((vector, used))
void GPIOD_Handler(void);
__attribute__((vector, used))
void GPIOE_Handler(void);
__attribute__((vector, used))
void GPIOF_Handler(void);

#endif /* __DIO_PRIVATE_H__ */
