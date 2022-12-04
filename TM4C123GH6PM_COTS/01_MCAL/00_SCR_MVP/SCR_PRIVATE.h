/**
 * @file_SCR_PRIVATE.h
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Osama, Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __SCR_PRIVATE_H__
#define __SCR_PRIVATE_H__

/*
----------------------------------------------------------------------
- Registers file
----------------------------------------------------------------------
*/

#define SCR_BASE_ADDRESS    ( (u32) (0x400FE000U) )

/**
 * @brief Register map for SCR
 */
typedef struct
{
    /** @defrgroup System Clock & Config Registers */
    Reg_t DID0;
    Reg_t DID1;
    Reg_t DC0;
    const u32 RESERVED;
    Reg_t DC1;
    Reg_t DC2;
    Reg_t DC3;
    Reg_t DC4;
    Reg_t DC5;
    Reg_t DC6;
    Reg_t DC7;
    Reg_t DC8;
    Reg_t PBORCTL;
    const u32  RESERVED1[3];
    Reg_t SRCR0;
    Reg_t SRCR1;
    Reg_t SRCR2;
    const u32  RESERVED2;
    Reg_t RIS;
    Reg_t IMC;
    Reg_t MISC;
    Reg_t RESC;
    Reg_t RCC;
   const u32  RESERVED3[2];
    Reg_t GPIOHBCTL;
    Reg_t RCC2;
    const u32  RESERVED4[2];
    Reg_t MOSCCTL;
    const u32  RESERVED5[32];
    Reg_t RCGC0;
    Reg_t RCGC1;
    Reg_t RCGC2;
    const u32  RESERVED6;
    Reg_t SCGC0;
    Reg_t SCGC1;
    Reg_t SCGC2;
    const u32  RESERVED7;
    Reg_t DCGC0;
    Reg_t DCGC1;
    Reg_t DCGC2;
    const u32 RESERVED8[6];
    Reg_t DSLPCLKCFG;
    const u32  RESERVED9;
    Reg_t SYSPROP;
    Reg_t PIOSCCAL;
    Reg_t PIOSCSTAT;
    const u32  RESERVED10[2];
    Reg_t PLLFREQ0;
    Reg_t PLLFREQ1;
    Reg_t PLLSTAT;
    const u32  RESERVED11[7];
    Reg_t SLPPWRCFG;
    Reg_t DSLPPWRCFG;
    Reg_t DC9;
    const u32  RESERVED12[3];
    Reg_t NVMSTAT;
    const u32  RESERVED13[4];
    Reg_t LDOSPCTL;
    const u32  RESERVED14;
    u32 volatile LDODPCTL;
    const u32  RESERVED15[80];
    /** @defrgroup Peripheral Presented Registers */
    Reg_t PPWD;
    Reg_t PPTIMER;
    Reg_t PPGPIO;
    Reg_t PPDMA;
    const u32  RESERVED16;
    Reg_t PPHIB;
    Reg_t PPUART;
    Reg_t PPSSI;
    Reg_t PPI2C;
    const u32  RESERVED17;
    u32 volatile PPUSB;
    const u32  RESERVED18[2];
    Reg_t PPCAN;
    Reg_t PPADC;
    Reg_t PPACMP;
    Reg_t PPPWM;
    Reg_t PPQEI;
    const u32  RESERVED19[4];
    Reg_t PPEEPROM;
    Reg_t PPWTIMER;
    const u32  RESERVED20[104];
    /** @defrgroup Software Reset Registers */
    Reg_t SRWD;
    Reg_t SRTIMER;
    Reg_t SRGPIO;
    Reg_t SRDMA;
    const u32  RESERVED21;
    Reg_t SRHIB;
    Reg_t SRUART;
    Reg_t SRSSI;
    Reg_t SRI2C;
    const u32  RESERVED22;
    Reg_t SRUSB;
    const u32  RESERVED23[2];
    Reg_t SRCAN;
    Reg_t SRADC;
    Reg_t SRACMP;
    Reg_t SRPWM;
    Reg_t SRQEI;
    const u32  RESERVED24[4];
    Reg_t SREEPROM;
    Reg_t SRWTIMER;
    const u32  RESERVED25[40];
    /** @defrgroup Run-Mode Clock Gating Control Registers */
    Reg_t RCGCWD;
    Reg_t RCGCTIMER;
    Reg_t RCGCGPIO;
    Reg_t RCGCDMA;
    const u32  RESERVED26;
    Reg_t RCGCHIB;
    Reg_t RCGCUART;
    Reg_t RCGCSSI;
    Reg_t RCGCI2C;
    const u32  RESERVED27;
    Reg_t RCGCUSB;
    const u32 RESERVED28[2];
    Reg_t RCGCCAN;
    Reg_t RCGCADC;
    Reg_t RCGCACMP;
    Reg_t RCGCPWM;
    Reg_t RCGCQEI;
    const u32 RESERVED29[4];
    Reg_t RCGCEEPROM;
    Reg_t RCGCWTIMER;
    const u32 RESERVED30[40];
    /** @defrgroup Sleep-Mode Clock Gating Control Registers */
    Reg_t SCGCWD;
    Reg_t SCGCTIMER;
    Reg_t SCGCGPIO;
    Reg_t SCGCDMA;
    const u32 RESERVED31;
    Reg_t SCGCHIB;
    Reg_t SCGCUART;
    Reg_t SCGCSSI;
    Reg_t SCGCI2C;
    const u32 RESERVED32;
    Reg_t SCGCUSB;
    const u32 RESERVED33[2];
    Reg_t SCGCCAN;
    Reg_t SCGCADC;
    Reg_t SCGCACMP;
    Reg_t SCGCPWM;
    Reg_t SCGCQEI;
    const u32 RESERVED34[4];
    Reg_t SCGCEEPROM;
    Reg_t SCGCWTIMER;
    /** @defrgroup Deep Sleep-Mode Clock Gating Control Registers */
    const u32 RESERVED35[40];
    Reg_t DCGCWD;
    Reg_t DCGCTIMER;
    Reg_t DCGCGPIO;
    Reg_t DCGCDMA;
    const u32  RESERVED36;
    Reg_t DCGCHIB;
    Reg_t DCGCUART;
    Reg_t DCGCSSI;
    Reg_t DCGCI2C;
    const u32  RESERVED37;
    Reg_t DCGCUSB;
    const u32  RESERVED38[2];
    Reg_t DCGCCAN;
    Reg_t DCGCADC;
    Reg_t DCGCACMP;
    Reg_t DCGCPWM;
    Reg_t DCGCQEI;
    const u32  RESERVED39[4];
    Reg_t DCGCEEPROM;
    Reg_t DCGCWTIMER;
    /** @defrgroup Periphral Ready Registers */
    const u32 RESERVED40[104];
    Reg_t PRWD;
    Reg_t PRTIMER;
    Reg_t PRGPIO;
    Reg_t PRDMA;
    const u32 RESERVED41;
    Reg_t PRHIB;
    Reg_t PRUART;
    Reg_t PRSSI;
    Reg_t PRI2C;
    const u32 RESERVED42;
    Reg_t PRUSB;
    const u32 RESERVED43[2];
    Reg_t PRCAN;
    Reg_t PRADC;
    Reg_t PRACMP;
    Reg_t PRPWM;
    Reg_t PRQEI;
    const u32 RESERVED44[4];
    Reg_t PREEPROM;
    Reg_t PRWTIMER;

}ST_SCRRegisters_t;

#define SCR     ( (ST_SCRRegisters_t volatile * const) (SCR_BASE_ADDRESS) )

/*
----------------------------------------------------------------------
- Macros
----------------------------------------------------------------------
*/
/** @defgroup Developer Private Macros */
#define SCR_CCLKMOSC_TIMEOUT_VAL     ( (u32) (0xF4240U) )
#define SCR_PRx_TIMEOUT_VAL          ( (u32) (0xF4240U) )
#define SCR_PERIPHRAL_NOT_READY      ( (u8)  (0x00U) )
#define SCR_PERIPHRAL_READY          ( (u8)  (0x01U) )
/** @defgroup System Clock Parameters */
#define SYS_CLK_PIOSC                ( (0x00U) )
#define SYS_CLK_PIOSC_DIV_4          ( (0x01U) )
#define SYS_CLK_MOSC                 ( (0x02U) )
#define SYS_CLK_LFIOSC               ( (0x03U) )
#define SYS_CLK_HMOSC                ( (0x04U) )
/** @defgroup PLL Parameters */
#define SYS_PLL_DIV_1                ( (0x00U) )
#define SYS_PLL_DIV_2                ( (0x01U) )
#define SYS_PLL_DISABLE              ( (0x00U) )
#define SYS_PLL_ENABLE               ( (0x01U) )
/** @defgroup XTAL External Oscillator Values */
#define XTAL_EXOSCCLK_4MHZ           ( (u8) (0x06U) )
#define XTAL_EXOSCCLK_4f096MHZ       ( (u8) (0x07U) )
#define XTAL_EXOSCCLK_4f9152MHZ      ( (u8) (0x08U) )
#define XTAL_EXOSCCLK_5MHZ_USB       ( (u8) (0x09U) )
#define XTAL_EXOSCCLK_5f12MHZ        ( (u8) (0x0AU) )
#define XTAL_EXOSCCLK_6MHZ_USB       ( (u8) (0x0BU) )
#define XTAL_EXOSCCLK_6f144MHZ       ( (u8) (0x0CU) )
#define XTAL_EXOSCCLK_7f372MHZ       ( (u8) (0x0DU) )
#define XTAL_EXOSCCLK_8MHZ_USB       ( (u8) (0x0EU) )
#define XTAL_EXOSCCLK_8f192MHZ       ( (u8) (0x0FU) )
#define XTAL_EXOSCCLK_10MHZ_USB      ( (u8) (0x10U) )
#define XTAL_EXOSCCLK_12MHZ_USB      ( (u8) (0x11U) )
#define XTAL_EXOSCCLK_12f288MHZ      ( (u8) (0x12U) )
#define XTAL_EXOSCCLK_13f256MHZ      ( (u8) (0x13U) )
#define XTAL_EXOSCCLK_14f318MHZ      ( (u8) (0x14U) )
#define XTAL_EXOSCCLK_16MHZ_USB      ( (u8) (0x15U) )
#define XTAL_EXOSCCLK_16f384MHZ      ( (u8) (0x16U) )
#define XTAL_EXOSCCLK_18MHZ_USB      ( (u8) (0x17U) )
#define XTAL_EXOSCCLK_20MHZ_USB      ( (u8) (0x18U) )
#define XTAL_EXOSCCLK_24MHZ_USB      ( (u8) (0x19U) )
#define XTAL_EXOSCCLK_25MHZ_USB      ( (u8) (0x1AU) )
/** @defgroup SYSDIV2 System Clock divisor values */
#define SYS_CLK_DIV_1    ( (u8) (0x00U) )
#define SYS_CLK_DIV_2    ( (u8) (0x01U) )
#define SYS_CLK_DIV_3    ( (u8) (0x02U) )
#define SYS_CLK_DIV_4    ( (u8) (0x03U) )
#define SYS_CLK_DIV_5    ( (u8) (0x04U) )
#define SYS_CLK_DIV_6    ( (u8) (0x05U) )
#define SYS_CLK_DIV_7    ( (u8) (0x06U) )
#define SYS_CLK_DIV_8    ( (u8) (0x07U) )
#define SYS_CLK_DIV_9    ( (u8) (0x08U) )
#define SYS_CLK_DIV_10   ( (u8) (0x09U) )
#define SYS_CLK_DIV_11   ( (u8) (0x0AU) )
#define SYS_CLK_DIV_12   ( (u8) (0x0BU) )
#define SYS_CLK_DIV_13   ( (u8) (0x0CU) )
#define SYS_CLK_DIV_14   ( (u8) (0x0DU) )
#define SYS_CLK_DIV_15   ( (u8) (0x0EU) )
#define SYS_CLK_DIV_16   ( (u8) (0x0FU) )
#define SYS_CLK_DIV_17   ( (u8) (0x10U) )
#define SYS_CLK_DIV_18   ( (u8) (0x11U) )
#define SYS_CLK_DIV_19   ( (u8) (0x12U) )
#define SYS_CLK_DIV_20   ( (u8) (0x13U) )
#define SYS_CLK_DIV_21   ( (u8) (0x14U) )
#define SYS_CLK_DIV_22   ( (u8) (0x15U) )
#define SYS_CLK_DIV_23   ( (u8) (0x16U) )
#define SYS_CLK_DIV_24   ( (u8) (0x17U) )
#define SYS_CLK_DIV_25   ( (u8) (0x18U) )
#define SYS_CLK_DIV_26   ( (u8) (0x19U) )
#define SYS_CLK_DIV_27   ( (u8) (0x1AU) )
#define SYS_CLK_DIV_28   ( (u8) (0x1BU) )
#define SYS_CLK_DIV_29   ( (u8) (0x1CU) )
#define SYS_CLK_DIV_30   ( (u8) (0x1DU) )
#define SYS_CLK_DIV_31   ( (u8) (0x1EU) )
#define SYS_CLK_DIV_32   ( (u8) (0x1FU) )
#define SYS_CLK_DIV_33   ( (u8) (0x20U) )
#define SYS_CLK_DIV_34   ( (u8) (0x21U) )
#define SYS_CLK_DIV_35   ( (u8) (0x22U) )
#define SYS_CLK_DIV_36   ( (u8) (0x23U) )
#define SYS_CLK_DIV_37   ( (u8) (0x24U) )
#define SYS_CLK_DIV_38   ( (u8) (0x25U) )
#define SYS_CLK_DIV_39   ( (u8) (0x26U) )
#define SYS_CLK_DIV_40   ( (u8) (0x27U) )
#define SYS_CLK_DIV_41   ( (u8) (0x28U) )
#define SYS_CLK_DIV_42   ( (u8) (0x29U) )
#define SYS_CLK_DIV_43   ( (u8) (0x2AU) )
#define SYS_CLK_DIV_44   ( (u8) (0x2BU) )
#define SYS_CLK_DIV_45   ( (u8) (0x2CU) )
#define SYS_CLK_DIV_46   ( (u8) (0x2DU) )
#define SYS_CLK_DIV_47   ( (u8) (0x2EU) )
#define SYS_CLK_DIV_48   ( (u8) (0x2FU) )
#define SYS_CLK_DIV_49   ( (u8) (0x30U) )
#define SYS_CLK_DIV_50   ( (u8) (0x31U) )
#define SYS_CLK_DIV_51   ( (u8) (0x32U) )
#define SYS_CLK_DIV_52   ( (u8) (0x34U) )
#define SYS_CLK_DIV_53   ( (u8) (0x34U) )
#define SYS_CLK_DIV_54   ( (u8) (0x35U) )
#define SYS_CLK_DIV_55   ( (u8) (0x36U) )
#define SYS_CLK_DIV_56   ( (u8) (0x37U) )
#define SYS_CLK_DIV_57   ( (u8) (0x38U) )
#define SYS_CLK_DIV_58   ( (u8) (0x39U) )
#define SYS_CLK_DIV_59   ( (u8) (0x3AU) )
#define SYS_CLK_DIV_60   ( (u8) (0x3BU) )
#define SYS_CLK_DIV_61   ( (u8) (0x3CU) )
#define SYS_CLK_DIV_62   ( (u8) (0x3DU) )
#define SYS_CLK_DIV_63   ( (u8) (0x3EU) )
#define SYS_CLK_DIV_64   ( (u8) (0x3FU) )

/*
----------------------------------------------------------------------
- Data types
----------------------------------------------------------------------
*/

/** @def Default error status type for the SCR module */
typedef u8 SCR_ErrorStatus_t;
/** @def Variable to store the periphral state */
typedef u8 PeriphState_t;

/*
----------------------------------------------------------------------
- Private functions declaration
----------------------------------------------------------------------
*/

/** @defgroup Clocking Private Functions */
/**
 * @brief Functions for system clock configuration.
 *
 */
__attribute__((always_inline))
static SCR_ErrorStatus_t
tConfigSysClkPIOSC(void);

__attribute__((always_inline))
static SCR_ErrorStatus_t
tConfigSysClkPIOSCDIV4(void);

__attribute__((always_inline))
static SCR_ErrorStatus_t
tConfigSysClkMOSC(void);

__attribute__((always_inline))
static SCR_ErrorStatus_t
tConfigSysClkLFIOSC(void);

__attribute__((always_inline))
static SCR_ErrorStatus_t
tConfigSysClkHMOSC(void);

/** @defgroup Getters Private Functions */
/**
 * @brief Functions to get/fetch and data from the periphrals.
 *        SW-USER Interface.
 *
 */
__attribute__((always_inline))
static u8
u8GetPllLockStatus(void);

__attribute__((always_inline))
static u8
u8GetPllTrStatus(void);

/**
 * @todo To be changed to 1
 *       Polymorphismed Function.
 */
__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_WD(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_TIMER(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_GPIO(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_DMA(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_HIB(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_UART(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_SSI(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tEGetPeriphStateI2C(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_USB(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_CAN(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_ADC(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_ACMP(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static PeriphState_t
tGetPeriphState_PWM(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_QEI(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_EEPROM(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const PeriphState_t
tGetPeriphState_WTIMER(uC_PeriphNum_t Copy_tPeriphNum);

/** @defgroup Setters Private Functions */
/**
 * @brief Functions to set/fire some peripheral's functions.
 *        SW-USER Interface.
 *
 */
/**
 * @todo To be changed to 1
 *       Polymorphismed Function.
 */
__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_WD(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_TIMER(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_GPIO(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_DMA(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_UART(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_SSI(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_I2C(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_USB(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_CAN(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_ADC(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_ACMP(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_PWM(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_QEI(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_EEPROM(uC_PeriphNum_t Copy_tPeriphNum);

__attribute__((always_inline))
static const SCR_ErrorStatus_t
tEnableCLK_WTIMER(uC_PeriphNum_t Copy_tPeriphNum);

#endif /* __SCR_PRIVATE_H__ */
