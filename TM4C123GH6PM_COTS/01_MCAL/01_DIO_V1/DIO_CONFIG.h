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
 *      @arg DIOx_APB_BUS_ID
 *      @arg DIOx_AHB_BUS_ID
 *          @note 'x' beside the "DIOx" is for replacment by
 *                 the desired port [A, B, C, D, E, F].
 */
#define DIO_PORTA_BUS   ( DIOA_APB_BUS_ID )
#define DIO_PORTB_BUS   ( DIOB_APB_BUS_ID )
#define DIO_PORTC_BUS   ( DIOC_APB_BUS_ID )
#define DIO_PORTD_BUS   ( DIOD_APB_BUS_ID )
#define DIO_PORTE_BUS   ( DIOE_APB_BUS_ID )
#define DIO_PORTF_BUS   ( DIOF_AHB_BUS_ID )
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
#define DIO_PORTF_CONFIG  ( DIO_PORT_CONFIG_ACTIVE )

/** @degroup Port A specific configurations */
/** @brief Check if the port is active or inactive */
#if (DIO_PORTA_MODE == DIO_PORT_CONFIG_ACTIVE)


#else
    #warning ("PORTA CONFIG MODE: INACTIVE")
#endif /* DIO_PORTA_CONFIG */

/** @degroup Port B specific configurations */
/** @brief Check if the port is active or inactive */
#if (DIO_PORTB_MODE == DIO_PORT_CONFIG_ACTIVE)


#else
    #warning ("PORTB CONFIG MODE: INACTIVE")
#endif /* DIO_PORTB_CONFIG */

/** @degroup Port C specific configurations */
/** @brief Check if the port is active or inactive */
#if (DIO_PORTC_MODE == DIO_PORT_CONFIG_ACTIVE)


#else
    #warning ("PORTC CONFIG MODE: INACTIVE")
#endif /* DIO_PORTC_CONFIG */

/** @degroup Port D specific configurations */
/** @brief Check if the port is active or inactive */
#if (DIO_PORTD_MODE == DIO_PORT_CONFIG_ACTIVE)


#else
    #warning ("PORTD CONFIG MODE: INACTIVE")
#endif /* DIO_PORTD_CONFIG */

/** @degroup Port E specific configurations */
/** @brief Check if the port is active or inactive */
#if (DIO_PORTE_MODE == DIO_PORT_CONFIG_ACTIVE)


#else
    #warning ("PORTE CONFIG MODE: INACTIVE")
#endif /* DIO_PORTE_CONFIG */

/** @degroup Port A specific configurations */
/** @brief Check if the port is active or inactive */
#if (DIO_PORTF_CONFIG == DIO_PORT_CONFIG_ACTIVE)

St_PortCfg_t G_StPORTF_Cfg =
{
    /* Set the port id */
    .Port = DIO_PORTF_BUS,

    /* Configure port f pins */
    /** @defgroup PIN0 */
    .Pin[DIO_PIN0_ID].mode       = DIO_PIN_MODE_DIGITAL,
    .Pin[DIO_PIN0_ID].direction  = DIO_PIN_DIR_INPUT,
    .Pin[DIO_PIN0_ID].dr2        = DIO_PIN_DR2_INACTIVE,
    .Pin[DIO_PIN0_ID].dr4        = DIO_PIN_DR4_ACTIVE,
    .Pin[DIO_PIN0_ID].dr8        = DIO_PIN_DR8_INACTIVE,
    .Pin[DIO_PIN0_ID].pur        = DIO_PIN_PUR_INACTIVE,
    .Pin[DIO_PIN0_ID].pdr        = DIO_PIN_PDR_INACTIVE,
    .Pin[DIO_PIN0_ID].slr        = DIO_PIN_SLR_INACTIVE,
    .Pin[DIO_PIN0_ID].od         = DIO_PIN_OD_INACTIVE,
    .Pin[DIO_PIN0_ID].af         = DIO_PIN_AF_INACTIVE,
    .Pin[DIO_PIN0_ID].dmactl     = DIO_PIN_DMACTL_INACTIVE,
    .Pin[DIO_PIN0_ID].adcctl     = DIO_PIN_ADCTL_INACTIVE,
    .Pin[DIO_PIN0_ID].commit     = DIO_PIN_COMMIT_INACTIVE,
    .Pin[DIO_PIN0_ID].int_sense  = DIO_PIN_INTSENSE_FE,
    .Pin[DIO_PIN0_ID].int_mask   = DIO_PIN_INTMASK_INACTIVE,
    .Pin[DIO_PIN0_ID].int_status = DIO_PIN_INTSTATUS_INACTIVE,
    .Pin[DIO_PIN0_ID].data       = DIO_PIN_DATA_HIGH,
    /** @defgroup PIN1 */
    .Pin[DIO_PIN1_ID].mode       = DIO_PIN_MODE_DIGITAL,
    .Pin[DIO_PIN1_ID].direction  = DIO_PIN_DIR_INPUT,
    .Pin[DIO_PIN1_ID].dr2        = DIO_PIN_DR2_INACTIVE,
    .Pin[DIO_PIN1_ID].dr4        = DIO_PIN_DR4_ACTIVE,
    .Pin[DIO_PIN1_ID].dr8        = DIO_PIN_DR8_INACTIVE,
    .Pin[DIO_PIN1_ID].pur        = DIO_PIN_PUR_INACTIVE,
    .Pin[DIO_PIN1_ID].pdr        = DIO_PIN_PDR_INACTIVE,
    .Pin[DIO_PIN1_ID].slr        = DIO_PIN_SLR_INACTIVE,
    .Pin[DIO_PIN1_ID].od         = DIO_PIN_OD_INACTIVE,
    .Pin[DIO_PIN1_ID].af         = DIO_PIN_AF_INACTIVE,
    .Pin[DIO_PIN1_ID].dmactl     = DIO_PIN_DMACTL_INACTIVE,
    .Pin[DIO_PIN1_ID].adcctl     = DIO_PIN_ADCTL_INACTIVE,
    .Pin[DIO_PIN1_ID].commit     = DIO_PIN_COMMIT_INACTIVE,
    .Pin[DIO_PIN1_ID].int_sense  = DIO_PIN_INTSENSE_FE,
    .Pin[DIO_PIN1_ID].int_mask   = DIO_PIN_INTMASK_INACTIVE,
    .Pin[DIO_PIN1_ID].int_status = DIO_PIN_INTSTATUS_INACTIVE,
    .Pin[DIO_PIN1_ID].data       = DIO_PIN_DATA_HIGH,
    /** @defgroup PIN2 */
    .Pin[DIO_PIN2_ID].mode       = DIO_PIN_MODE_DIGITAL,
    .Pin[DIO_PIN2_ID].direction  = DIO_PIN_DIR_OUTPUT,
    .Pin[DIO_PIN2_ID].dr2        = DIO_PIN_DR2_INACTIVE,
    .Pin[DIO_PIN2_ID].dr4        = DIO_PIN_DR4_ACTIVE,
    .Pin[DIO_PIN2_ID].dr8        = DIO_PIN_DR8_INACTIVE,
    .Pin[DIO_PIN2_ID].pur        = DIO_PIN_PUR_INACTIVE,
    .Pin[DIO_PIN2_ID].pdr        = DIO_PIN_PDR_INACTIVE,
    .Pin[DIO_PIN2_ID].slr        = DIO_PIN_SLR_INACTIVE,
    .Pin[DIO_PIN2_ID].od         = DIO_PIN_OD_INACTIVE,
    .Pin[DIO_PIN2_ID].af         = DIO_PIN_AF_INACTIVE,
    .Pin[DIO_PIN2_ID].dmactl     = DIO_PIN_DMACTL_INACTIVE,
    .Pin[DIO_PIN2_ID].adcctl     = DIO_PIN_ADCTL_INACTIVE,
    .Pin[DIO_PIN2_ID].commit     = DIO_PIN_COMMIT_INACTIVE,
    .Pin[DIO_PIN2_ID].int_sense  = DIO_PIN_INTSENSE_FE,
    .Pin[DIO_PIN2_ID].int_mask   = DIO_PIN_INTMASK_INACTIVE,
    .Pin[DIO_PIN2_ID].int_status = DIO_PIN_INTSTATUS_INACTIVE,
    .Pin[DIO_PIN2_ID].data       = DIO_PIN_DATA_HIGH,
    /** @defgroup PIN3 */
    .Pin[DIO_PIN3_ID].mode       = DIO_PIN_MODE_DIGITAL,
    .Pin[DIO_PIN3_ID].direction  = DIO_PIN_DIR_INPUT,
    .Pin[DIO_PIN3_ID].dr2        = DIO_PIN_DR2_INACTIVE,
    .Pin[DIO_PIN3_ID].dr4        = DIO_PIN_DR4_ACTIVE,
    .Pin[DIO_PIN3_ID].dr8        = DIO_PIN_DR8_INACTIVE,
    .Pin[DIO_PIN3_ID].pur        = DIO_PIN_PUR_INACTIVE,
    .Pin[DIO_PIN3_ID].pdr        = DIO_PIN_PDR_INACTIVE,
    .Pin[DIO_PIN3_ID].slr        = DIO_PIN_SLR_INACTIVE,
    .Pin[DIO_PIN3_ID].od         = DIO_PIN_OD_INACTIVE,
    .Pin[DIO_PIN3_ID].af         = DIO_PIN_AF_INACTIVE,
    .Pin[DIO_PIN3_ID].dmactl     = DIO_PIN_DMACTL_INACTIVE,
    .Pin[DIO_PIN3_ID].adcctl     = DIO_PIN_ADCTL_INACTIVE,
    .Pin[DIO_PIN3_ID].commit     = DIO_PIN_COMMIT_INACTIVE,
    .Pin[DIO_PIN3_ID].int_sense  = DIO_PIN_INTSENSE_FE,
    .Pin[DIO_PIN3_ID].int_mask   = DIO_PIN_INTMASK_INACTIVE,
    .Pin[DIO_PIN3_ID].int_status = DIO_PIN_INTSTATUS_INACTIVE,
    .Pin[DIO_PIN3_ID].data       = DIO_PIN_DATA_HIGH,
    /** @defgroup PIN4 */
    .Pin[DIO_PIN4_ID].mode       = DIO_PIN_MODE_DIGITAL,
    .Pin[DIO_PIN4_ID].direction  = DIO_PIN_DIR_INPUT,
    .Pin[DIO_PIN4_ID].dr2        = DIO_PIN_DR2_INACTIVE,
    .Pin[DIO_PIN4_ID].dr4        = DIO_PIN_DR4_ACTIVE,
    .Pin[DIO_PIN4_ID].dr8        = DIO_PIN_DR8_INACTIVE,
    .Pin[DIO_PIN4_ID].pur        = DIO_PIN_PUR_INACTIVE,
    .Pin[DIO_PIN4_ID].pdr        = DIO_PIN_PDR_INACTIVE,
    .Pin[DIO_PIN4_ID].slr        = DIO_PIN_SLR_INACTIVE,
    .Pin[DIO_PIN4_ID].od         = DIO_PIN_OD_INACTIVE,
    .Pin[DIO_PIN4_ID].af         = DIO_PIN_AF_INACTIVE,
    .Pin[DIO_PIN4_ID].dmactl     = DIO_PIN_DMACTL_INACTIVE,
    .Pin[DIO_PIN4_ID].adcctl     = DIO_PIN_ADCTL_INACTIVE,
    .Pin[DIO_PIN4_ID].commit     = DIO_PIN_COMMIT_INACTIVE,
    .Pin[DIO_PIN4_ID].int_sense  = DIO_PIN_INTSENSE_FE,
    .Pin[DIO_PIN4_ID].int_mask   = DIO_PIN_INTMASK_INACTIVE,
    .Pin[DIO_PIN4_ID].int_status = DIO_PIN_INTSTATUS_INACTIVE,
    .Pin[DIO_PIN4_ID].data       = DIO_PIN_DATA_HIGH,
    /** @defgroup PIN5 */
    .Pin[DIO_PIN5_ID].mode       = DIO_PIN_MODE_DIGITAL,
    .Pin[DIO_PIN5_ID].direction  = DIO_PIN_DIR_INPUT,
    .Pin[DIO_PIN5_ID].dr2        = DIO_PIN_DR2_INACTIVE,
    .Pin[DIO_PIN5_ID].dr4        = DIO_PIN_DR4_ACTIVE,
    .Pin[DIO_PIN5_ID].dr8        = DIO_PIN_DR8_INACTIVE,
    .Pin[DIO_PIN5_ID].pur        = DIO_PIN_PUR_INACTIVE,
    .Pin[DIO_PIN5_ID].pdr        = DIO_PIN_PDR_INACTIVE,
    .Pin[DIO_PIN5_ID].slr        = DIO_PIN_SLR_INACTIVE,
    .Pin[DIO_PIN5_ID].od         = DIO_PIN_OD_INACTIVE,
    .Pin[DIO_PIN5_ID].af         = DIO_PIN_AF_INACTIVE,
    .Pin[DIO_PIN5_ID].dmactl     = DIO_PIN_DMACTL_INACTIVE,
    .Pin[DIO_PIN5_ID].adcctl     = DIO_PIN_ADCTL_INACTIVE,
    .Pin[DIO_PIN5_ID].commit     = DIO_PIN_COMMIT_INACTIVE,
    .Pin[DIO_PIN5_ID].int_sense  = DIO_PIN_INTSENSE_FE,
    .Pin[DIO_PIN5_ID].int_mask   = DIO_PIN_INTMASK_INACTIVE,
    .Pin[DIO_PIN5_ID].int_status = DIO_PIN_INTSTATUS_INACTIVE,
    .Pin[DIO_PIN5_ID].data       = DIO_PIN_DATA_HIGH,
};

#else
    #warning ("PORTF CONFIG MODE: INACTIVE")
#endif /* DIO_PORTF_CONFIG */


#endif /* __DIO_CONFIG_H__ */
