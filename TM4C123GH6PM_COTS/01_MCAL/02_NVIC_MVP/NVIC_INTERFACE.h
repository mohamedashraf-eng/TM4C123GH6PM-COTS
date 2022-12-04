/**
 * @file NVIC_INTERFACE.h
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Osama, Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __NVIC_INTERFACE_H__
#define __NVIC_INTERFACE_H__

#include "NVIC_PRIVATE.h"  /** @todo To be removed. */

/*
----------------------------------------------------------------------
- Macros
----------------------------------------------------------------------
*/

/**
 * @brief Function like macro to Enable all system IRQ.
 *
 */
#define MNVIC_ENABLE_ALL_IRQ do { \
                                    __asm volatile("NOP"); \
                                }while(0);

/*
#define MNVIC_ENABLE_ALL_IRQ_FAULTS do { }while(0);
#define MNVIC_DISABLE_ALL_IRQ do { }while(0);
#define MNVIC_DISABLE_ALL_IRQ_FAULTS do { }while(0);
*/

/** @defgroup NVIC Error status */
#define NVIC_SET_PERIPH_INT_FAILED   ( (u8) (0x00U) )
#define NVIC_SET_PERIPH_INT_SUCC     ( (u8) (0x01U) )
#define NVIC_SET_PERIPH_PEND_FAILED  ( (u8) (0x02U) )
#define NVIC_SET_PERIPH_PEND_SUCC    ( (u8) (0x03U) )

/** @defgroup Periphrals Interrupt ID */
#define NVIC_GPIOA          ( (u8) (0x00U) )
#define NVIC_GPIOB          ( (u8) (0x01U) )
#define NVIC_GPIOC          ( (u8) (0x02U) )
#define NVIC_GPIOD          ( (u8) (0x03U) )
#define NVIC_GPIOE          ( (u8) (0x04U) )
#define NVIC_UART0          ( (u8) (0x05U) )
#define NVIC_UART1          ( (u8) (0x06U) )
#define NVIC_SSI0           ( (u8) (0x07U) )
#define NVIC_I2C0           ( (u8) (0x08U) )
#define NVIC_PWM0_FAULT     ( (u8) (0x09U) )
#define NVIC_PWM0_0         ( (u8) (0x0AU) )
#define NVIC_PWM0_1         ( (u8) (0x0BU) )
#define NVIC_PWM0_2         ( (u8) (0x0CU) )
#define NVIC_QEI_0          ( (u8) (0x0DU) )
#define NVIC_ADC0_SEQ0      ( (u8) (0x0EU) )
#define NVIC_ADC0_SEQ1      ( (u8) (0x0FU) )
#define NVIC_ADC0_SEQ2      ( (u8) (0x10U) )
#define NVIC_ADC0_SEQ3      ( (u8) (0x11U) )
#define NVIC_WD             ( (u8) (0x12U) )
#define NVIC_TIMER0A        ( (u8) (0x13U) )
#define NVIC_TIMER0B        ( (u8) (0x14U) )
#define NVIC_TIMER1A        ( (u8) (0x15U) )
#define NVIC_TIMER1B        ( (u8) (0x16U) )
#define NVIC_TIMER2A        ( (u8) (0x17U) )
#define NVIC_TIMER2B        ( (u8) (0x18U) )
#define NVIC_ACMP0          ( (u8) (0x19U) )
#define NVIC_ACMP1          ( (u8) (0x1AU) )
#define NVIC_RESERV         ( (u8) (0x1BU) )
#define NVIC_SYSCTRL        ( (u8) (0x1CU) )
#define NVIC_FMC_EEPROMC    ( (u8) (0x1DU) )
#define NVIC_GPIOF          ( (u8) (0x1EU) )
#define NVIC_RESERV         ( (u8) (0x1FU) )
#define NVIC_UART2          ( (u8) (0x20U) )
#define NVIC_SSI1           ( (u8) (0x21U) )
#define NVIC_TIMER3A        ( (u8) (0x22U) )
#define NVIC_TIMER3B        ( (u8) (0x23U) )
#define NVIC_I2C1           ( (u8) (0x24U) )
#define NVIC_QEI_1          ( (u8) (0x25U) )
#define NVIC_CAN0           ( (u8) (0x26U) )
#define NVIC_CAN1           ( (u8) (0x27U) )
#define NVIC_RESERV         ( (u8) (0x28U) )
#define NVIC_HIB            ( (u8) (0x29U) )
#define NVIC_USB            ( (u8) (0x2AU) )
#define NVIC_PWM0_3         ( (u8) (0x2BU) )
#define NVIC_DMA_SW         ( (u8) (0x2CU) )
#define NVIC_DMA_ERR        ( (u8) (0x2DU) )
#define NVIC_ADC1_SEQ0      ( (u8) (0x2EU) )
#define NVIC_ADC1_SEQ1      ( (u8) (0x2FU) )
#define NVIC_ADC1_SEQ2      ( (u8) (0x30U) )
#define NVIC_ADC1_SEQ3      ( (u8) (0x31U) )
#define NVIC_RESERV         ( (u8) (0x32U) )
#define NVIC_SSI2           ( (u8) (0x33U) )
#define NVIC_SSI3           ( (u8) (0x34U) )
#define NVIC_UART3          ( (u8) (0x35U) )
#define NVIC_UART4          ( (u8) (0x36U) )
#define NVIC_UART5          ( (u8) (0x37U) )
#define NVIC_UART6          ( (u8) (0x38U) )
#define NVIC_UART7          ( (u8) (0x39U) )
#define NVIC_RESERV         ( (u8) (0x3AU) )
#define NVIC_I2C2           ( (u8) (0x3BU) )
#define NVIC_I2C3           ( (u8) (0x3CU) )
#define NVIC_TIMER4A        ( (u8) (0x3DU) )
#define NVIC_TIEMR4B        ( (u8) (0x3EU) )
#define NVIC_RESERV         ( (u8) (0x3FU) )
#define NVIC_TIMER5A        ( (u8) (0x40U) )
#define NVIC_TIEMR5B        ( (u8) (0x41U) )
#define NVIC_WTIMER0A       ( (u8) (0x42U) )
#define NVIC_WTIMER0B       ( (u8) (0x43U) )
#define NVIC_WTIMER1A       ( (u8) (0x44U) )
#define NVIC_WTIMER1B       ( (u8) (0x45U) )
#define NVIC_WTIMER2A       ( (u8) (0x46U) )
#define NVIC_WTIMER2B       ( (u8) (0x47U) )
#define NVIC_WTIMER3A       ( (u8) (0x48U) )
#define NVIC_WTIMER3B       ( (u8) (0x49U) )
#define NVIC_WTIMER4A       ( (u8) (0x4AU) )
#define NVIC_WTIMER4B       ( (u8) (0x4BU) )
#define NVIC_WTIMER5A       ( (u8) (0x4CU) )
#define NVIC_WTIMER5B       ( (u8) (0x4DU) )
#define NVIC_SYSEXCEP       ( (u8) (0x4EU) )
#define NVIC_RESERV         ( (u8) (0x4FU) )
#define NVIC_PWM1_0         ( (u8) (0x50U) )
#define NVIC_PWM1_1         ( (u8) (0x51U) )
#define NVIC_PWM1_2         ( (u8) (0x52U) )
#define NVIC_PWM1_3         ( (u8) (0x53U) )
#define NVIC_PWM1_FAULT     ( (u8) (0x54U) )
#define NVIC_MIN_INT_PERIPH_ID ( (u8) (NVIC_GPIOA) )
#define NVIC_MAX_INT_PERIPH_ID ( (u8) (NVIC_PWM1_FAULT) )

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
 * @brief Function to Enable the peripheral nvic interrupt.
 *
 * @param The pheripheral defined id.
 *      @see NVIC_INTERFACE.h defined microcontroller peripherals.
 *
 * @return     The nvic error status.
 */
extern NVIC_ErrorStatus_t
MNVIC_tSetPeriphInt(uC_PeriphID_t Copy_tPeriphID);
/**
 * @brief Function to Disable the peripheral nvic interrupt.
 *
 * @param The pheripheral defined id.
 *      @see NVIC_INTERFACE.h defined microcontroller peripherals.
 *
 * @return     The nvic error status.
 */
extern NVIC_ErrorStatus_t
MNVIC_tClrPeriphInt(uC_PeriphID_t Copy_tPeriphID);
/**
 * @brief Function to set the peripheral pending bit.
 *
 * @param The pheripheral defined id.
 *      @see NVIC_INTERFACE.h defined microcontroller peripherals.
 *
 * @return     The nvic error status.
 */
extern NVIC_ErrorStatus_t
MNVIC_tSetPeriphIntPend(uC_PeriphID_t Copy_tPeriphID);
/**
 * @brief Function to clear the peripheral pending bit.
 *
 * @param The pheripheral defined id.
 *      @see NVIC_INTERFACE.h defined microcontroller peripherals.
 *
 * @return     The nvic error status.
 */
extern NVIC_ErrorStatus_t
MNVIC_tClrPeriphIntPend(uC_PeriphID_t Copy_tPeriphID);
/**
 * @brief Function to set the peripheral priority setts.
 *
 * @param The pheripheral defined id.
 *      @see NVIC_INTERFACE.h defined microcontroller peripherals.
 *
 * @return     The nvic error status.
 */
extern NVIC_ErrorStatus_t
MNVIC_tSetPeriphIntPrio(uC_PeriphID_t Copy_tPeriphID,
                        uC_NvicInt_t Copy_tNvicIntPrio);

#endif /* __NVIC_INTERFACE_H__ */
