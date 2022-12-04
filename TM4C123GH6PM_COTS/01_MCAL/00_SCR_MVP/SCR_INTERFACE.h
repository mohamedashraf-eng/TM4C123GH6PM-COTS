/**
 * @file SCR_INTERFACE.h
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Osama, Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __SCR_INTERFACE_H__
#define __SCR_INTERFACE_H__

#include "SCR_PRIVATE.h" /** @todo To be removed. */

/*
----------------------------------------------------------------------
- Macros
----------------------------------------------------------------------
*/

/** @defgroup System Clock Config error codes */
/**
 * @brief Peripheral Error states.
 */
#define SYSCLK_CONFIG_FAILED             ( (u8) (0x00U) )
#define SYSCLK_CONFIG_SUCC               ( (u8) (0x01U) )
#define SYSCLK_CONFIG_MOSC_FAILED        ( (u8) (0x02U) )
#define SYSCLK_CONFIG_MOSC_SUCC          ( (u8) (0x03U) )
#define SYSCLK_CONFIG_MOSC_TIMEOUT       ( (u8) (0x04U) )
/** @todo */
#define SYSCLK_CONFIG_PIOSC_FAILED       ( (u8) (0x00U) )
#define SYSCLK_CONFIG_PIOSC_SUCC         ( (u8) (0x00U) )
#define SYSCLK_CONFIG_PIOSCDIV4_FAILED   ( (u8) (0x00U) )
#define SYSCLK_CONFIG_PIOSCDIV4_SUCC     ( (u8) (0x00U) )
#define SYSCLK_CONFIG_LFIOSC_FAILED      ( (u8) (0x00U) )
#define SYSCLK_CONFIG_LFIOSC_SUCC        ( (u8) (0x00U) )
#define SYSCLK_CONFIG_HMOSC_FAILED       ( (u8) (0x00U) )
#define SYSCLK_CONFIG_HMOSC_SUCC         ( (u8) (0x00U) )
/** @defgroup Clock Enabling error codes */
#define CLOCK_ENABLE_FAILED              ( (u8) (0x00U) )
#define CLOCK_ENABLE_SUCC                ( (u8) (0x01U) )
/** @defgroup GPIO BUS SETerror codes */
#define GPIO_BUS_FAILED                  ( (u8) (0x00U) )
#define GPIO_BUS_SUCC                    ( (u8) (0x01U) )
/** @defgroup Pheripheral Presented error codes */
#define PERIPHERAL_IS_NOT_PRESENTED      ( (u8) (0x00U) )
#define PERIPHERAL_IS_PRESENTED          ( (u8) (0x01U) )

/** @defgroup Microcontroller Specific Enums */
#define SCR_PORTA_ID            ( (u8) (0x00U) )
#define SCR_PORTB_ID            ( (u8) (0x01U) )
#define SCR_PORTC_ID            ( (u8) (0x02U) )
#define SCR_PORTD_ID            ( (u8) (0x03U) )
#define SCR_PORTE_ID            ( (u8) (0x04U) )
#define SCR_PORTF_ID            ( (u8) (0x05U) )
/**
 * @brief Microcontroller [TM4C123GH6PM] Peripherals.
 */
/** @defgroup Periphral: WD */
#define WD_ID                  ( (u8) (0x00U) ) /* Main peripheral*/
#define WD0_ID                   ( (u8) (0x00U) )
#define WD1_ID                   ( (u8) (0x01U) )
/** @defgroup Periphral: WD */
#define TIMER_ID               ( (u8) (0x01U) ) /* Main peripheral*/
#define TIMER0_ID                ( (u8) (0x00U) )
#define TIMER1_ID                ( (u8) (0x01U) )
#define TIMER2_ID                ( (u8) (0x02U) )
#define TIMER3_ID                ( (u8) (0x03U) )
#define TIMER4_ID                ( (u8) (0x04U) )
#define TIMER5_ID                ( (u8) (0x05U) )
/** @defgroup Periphral: GPIO */
#define GPIO_ID                ( (u8) (0x02U) ) /* Main peripheral*/
#define GPIOA_ID                 ( (u8) (0x00U) )
#define GPIOB_ID                 ( (u8) (0x01U) )
#define GPIOC_ID                 ( (u8) (0x02U) )
#define GPIOD_ID                 ( (u8) (0x03U) )
#define GPIOE_ID                 ( (u8) (0x04U) )
#define GPIOF_ID                 ( (u8) (0x05U) )
/** @defgroup Periphral: DMA */
#define DMA_ID                 ( (u8) (0x03U) ) /* Main peripheral*/
#define DMA1_ID                  ( (u8) (0x00U) )
/** @defgroup Periphral: HIB */
#define HIB_ID                 ( (u8) (0x04U) ) /* Main peripheral*/
#define HIB1_ID                  ( (u8) (0x00U) )
/** @defgroup Periphral: UART */
#define UART_ID                ( (u8) (0x05U) ) /* Main peripheral*/
#define UART1_ID                 ( (u8) (0x00U) )
#define UART2_ID                 ( (u8) (0x01U) )
#define UART3_ID                 ( (u8) (0x02U) )
#define UART4_ID                 ( (u8) (0x03U) )
#define UART5_ID                 ( (u8) (0x04U) )
#define UART6_ID                 ( (u8) (0x05U) )
#define UART7_ID                 ( (u8) (0x06U) )
#define UART8_ID                 ( (u8) (0x07U) )
/** @defgroup Periphral: SSI */
#define SSI_ID                 ( (u8) (0x06U) ) /* Main peripheral*/
#define SSI1_ID                  ( (u8) (0x00U) )
#define SSI2_ID                  ( (u8) (0x01U) )
#define SSI3_ID                  ( (u8) (0x02U) )
#define SSI4_ID                  ( (u8) (0x03U) )
/** @defgroup Periphral: I2C */
#define I2C_ID                 ( (u8) (0x07U) ) /* Main peripheral*/
#define I2C1_ID                  ( (u8) (0x00U) )
#define I2C2_ID                  ( (u8) (0x01U) )
#define I2C3_ID                  ( (u8) (0x02U) )
#define I2C4_ID                  ( (u8) (0x03U) )
/** @defgroup Periphral: USB */
#define USB_ID                 ( (u8) (0x08U) ) /* Main peripheral*/
#define USB1_ID                  ( (u8) (0x00U) )
/** @defgroup Periphral: CAN */
#define CAN_ID                 ( (u8) (0x09U) ) /* Main peripheral*/
#define CAN1_ID                  ( (u8) (0x00U) )
#define CAN2_ID                  ( (u8) (0x01U) )
/** @defgroup Periphral: ADC */
#define ADC_ID                 ( (u8) (0x0AU) ) /* Main peripheral*/
#define ADC1_ID                  ( (u8) (0x00U) )
#define ADC2_ID                  ( (u8) (0x01U) )
/** @defgroup Periphral: ACMP */
#define ACMP_ID                ( (u8) (0x0BU) ) /* Main peripheral*/
#define ACMP1_ID                 ( (u8) (0x00U) )
/** @defgroup Periphral: PWM */
#define PWM_ID                 ( (u8) (0x0CU) ) /* Main peripheral*/
#define PWM1_ID                  ( (u8) (0x00U) )
#define PWM2_ID                  ( (u8) (0x01U) )
/** @defgroup Periphral: QEI */
#define QEI_ID                 ( (u8) (0x0DU) ) /* Main peripheral*/
#define QEI1_ID                  ( (u8) (0x00U) )
#define QEI2_ID                  ( (u8) (0x01U) )
/** @defgroup Periphral: EEPROM */
#define EEPROM_ID              ( (u8) (0x0EU) ) /* Main peripheral*/
#define EEPROM1_ID               ( (u8) (0x00U) )
/** @defgroup Periphral: WIDE TIMER */
#define WTIMER_ID              ( (u8) (0x0FU) ) /* Main peripheral*/
#define WTIMER1_ID               ( (u8) (0x00U) )
#define WTIMER2_ID               ( (u8) (0x01U) )
#define WTIMER3_ID               ( (u8) (0x02U) )
#define WTIMER4_ID               ( (u8) (0x03U) )
#define WTIMER3_ID               ( (u8) (0x04U) )
#define WTIMER4_ID               ( (u8) (0x05U) )
/**
 * @brief Microcontroller [TM4C123GH6PM] Buses.
 */
#define APB_ID              ( (u8) (0x00U) )
#define AHB_ID              ( (u8) (0x01U) )

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

/** @defgroup Setter Functions */
/**
 * @brief Function to configure the microcontroller clock
 *        via the Configuration Header File.
 *
 * @param void
 *
 * @retval Error Status Typedef.
 *      @brief Returns error status.
 */
extern SCR_ErrorStatus_t
MSCR_tSystemClockInit(void);
/**
 * @brief Function to enable the bus clock for the
 *        spceified microcontroller periphral.
 *
 * @param The periphral id.
 *      @arg See predefined uC periphrals.
 *
 * @param The periphral num.
 *      @arg See predefined uC periphrals numbers.
 *
 * @retval Error Status Typedef.
 *      @brief Returns error status.
 */
extern SCR_ErrorStatus_t
MSCR_tEnableClock(uC_PeriphID_t Copy_tPeriphID,
                  uC_PeriphNum_t Copy_tPeriphNum);
/**
 * @brief Function to specify the GPIOx microcontroller bus.
 *
 * @param The port id
 *      @arg See predefined uC ports.
 *
 * @param The bus id
 *      @arg See the specified uC Buses.
 *
 * @retval Error Status Typedef.
 *      @brief Returns error status.
 */
extern SCR_ErrorStatus_t
MSCR_tSetGPIOxBus(uC_PortID_t Copy_tPortID,
                  uC_BusID_t Copy_tBusID);
/** @defgroup Getter Functions */
/**
 * @brief Function to get the periphral current uC state.
 *
 * @param Reference address for the variable to save the state.
 *
 * @retval Error Status Typedef.
 *      @brief Returns error status.
 */
extern SCR_ErrorStatus_t
MSCR_tGetPeriphState(uC_PeriphID_t Copy_tPeriphID,
                     u8 *pArg_u8PeriphState);

#endif /* __SCR_INTERFACE_H__ */
