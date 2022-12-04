/**
 * @file SCR_PROGRAM.c
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief
 * @copyright Copyrights (c) 2022 Osama, Wx
 *
 */
/*
----------------------------------------------------------------------
- Headers Included
----------------------------------------------------------------------
*/

/** @defgroup public library */
#include "../../00_LIB/LIB_MVP/STD_TYPES.h"
#include "../../00_LIB/LIB_MVP/BIT_MATH.h"
#include "../../00_LIB/LIB_MVP/DEFAULT_HANDLER.h"

/** @defgroup private library */
#include "SCR_PRIVATE.h"
#include "SCR_CONFIG.h"
#include "SCR_INTERFACE.h"

/*
----------------------------------------------------------------------
- Global data types
----------------------------------------------------------------------
*/


/*
----------------------------------------------------------------------
- Public functions implementation
----------------------------------------------------------------------
*/
/** ------ New ------ Function ------ */
SCR_ErrorStatus_t
MSCR_tSystemClockInit(void)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus   = SYSCLK_CONFIG_FAILED;
    SCR_ErrorStatus_t L_tConfigFuncStatus = SYSCLK_CONFIG_FAILED;

    /* Config the system clock */
#if     (SYS_CLK == SYS_CLK_PIOSC)
    L_tConfigFuncStatus =
    tConfigSysClkPIOSC();

#elif   (SYS_CLK == SYS_CLK_PIOSC_DIV_4)
    L_tConfigFuncStatus =
    tConfigSysClkPIOSCDIV4();

#elif   (SYS_CLK == SYS_CLK_MOSC)
    L_tConfigFuncStatus =
    tConfigSysClkMOSC();

#elif   (SYS_CLK == SYS_CLK_LFIOSC)
    L_tConfigFuncStatus =
    tConfigSysClkLFIOSC();

#elif   (SYS_CLK == SYS_CLK_HMOSC)
    L_tConfigFuncStatus =
    tConfigSysClkHMOSC();
#else
    #error ("Error - System Clock is not configured properly.")
#endif
    /**
     * @brief Error handeling for the returned function.
     *
     * @todo To be completed.
     */
    switch(L_tConfigFuncStatus)
    {
        case SYSCLK_CONFIG_MOSC_FAILED:
                /* Error handling - Print to user */
                DEFAULT_ERROR_HANDLER();
            break;
        case SYSCLK_CONFIG_MOSC_TIMEOUT:
                /* Error handling - Print to user */
                DEFAULT_UNIMPLEMENTED_HANDLER();
            break;
        default:
                /* Configuration Passed - Print to user */
                L_tThisFuncStatus = SYSCLK_CONFIG_SUCC;
            break;
    }

/** @defgroup System Clock Prescaler Settings */


    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
SCR_ErrorStatus_t
MSCR_tEnableClock(uC_PeriphID_t Copy_tPeriphID,
                  uC_PeriphNum_t Copy_tPeriphNum)
{
    /** @brief To avoid unused warning */
    (void) Copy_tPeriphID;
    (void) Copy_tPeriphNum;

    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;
    SCR_ErrorStatus_t L_tSetterFuncStatus = CLOCK_ENABLE_FAILED;

    switch(Copy_tPeriphID)
    {
        case WD_ID :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_WD(Copy_tPeriphNum);
            break;
        case TIMER_ID :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_TIMER(Copy_tPeriphNum);
            break;
        case GPIO_ID  :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_GPIO(Copy_tPeriphNum);
            break;
        case DMA_ID   :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_DMA(Copy_tPeriphNum);
            break;
        case HIB_ID   :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_UART(Copy_tPeriphNum);
            break;
        case UART_ID  :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_UART(Copy_tPeriphNum);
            break;
        case SSI_ID   :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_SSI(Copy_tPeriphNum);
            break;
        case I2C_ID   :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_I2C(Copy_tPeriphNum);
            break;
        case USB_ID   :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_USB(Copy_tPeriphNum);
            break;
        case CAN_ID   :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_CAN(Copy_tPeriphNum);
            break;
        case ADC_ID   :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_ADC(Copy_tPeriphNum);
            break;
        case ACMP_ID  :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_ACMP(Copy_tPeriphNum);
            break;
        case PWM_ID   :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_PWM(Copy_tPeriphNum);
            break;
        case QEI_ID   :
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_QEI(Copy_tPeriphNum);
            break;
        case EEPROM_ID:
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_EEPROM(Copy_tPeriphNum);
            break;
        case WTIMER_ID:
                /* Switch the periphral No. */
                L_tSetterFuncStatus = tEnableCLK_WTIMER(Copy_tPeriphNum);
            break;
        default:
                /* Error handler - Print to user */
                DEFAULT_ERROR_HANDLER();
            break;
    }
    /* Check if the peripheral clock is enabled succesffully */
    if( (CLOCK_ENABLE_SUCC == L_tSetterFuncStatus) )
    {
        L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
    }
    else
    {
        /* Error handle - Print to user */
        /* DEFAULT_ERROR_HANDLER(); */
    }

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
SCR_ErrorStatus_t
MSCR_tSetGPIOxBus(uC_PortID_t Copy_tPortID,
                  uC_BusID_t Copy_tBusID)
{
    /** @brief To avoid unused warning */
    (void) Copy_tPortID;
    (void) Copy_tBusID;

    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = GPIO_BUS_FAILED;

    switch(Copy_tPortID)
    {
        case SCR_PORTA_ID:
                BIT_WRT(SCR->GPIOHBCTL, SCR_PORTA_ID, Copy_tBusID);
                L_tThisFuncStatus = GPIO_BUS_SUCC;
            break;
        case SCR_PORTB_ID:
                BIT_WRT(SCR->GPIOHBCTL, SCR_PORTB_ID, Copy_tBusID);
                L_tThisFuncStatus = GPIO_BUS_SUCC;
            break;
        case SCR_PORTC_ID:
                BIT_WRT(SCR->GPIOHBCTL, SCR_PORTC_ID, Copy_tBusID);
                L_tThisFuncStatus = GPIO_BUS_SUCC;
            break;
        case SCR_PORTD_ID:
                BIT_WRT(SCR->GPIOHBCTL, SCR_PORTD_ID, Copy_tBusID);
                L_tThisFuncStatus = GPIO_BUS_SUCC;
            break;
        case SCR_PORTE_ID:
                BIT_WRT(SCR->GPIOHBCTL, SCR_PORTE_ID, Copy_tBusID);
                L_tThisFuncStatus = GPIO_BUS_SUCC;
            break;
        case SCR_PORTF_ID:
                BIT_WRT(SCR->GPIOHBCTL, SCR_PORTF_ID, Copy_tBusID);
                L_tThisFuncStatus = GPIO_BUS_SUCC;
            break;
        default:
                /* Error handler - Print to user */
                DEFAULT_ERROR_HANDLER();
            break;
    }

    return L_tThisFuncStatus;
}
/*
----------------------------------------------------------------------
- Private functions implementation
----------------------------------------------------------------------
*/
/** ------ New ------ Function ------ */
/**
 * Function Procedure:
 * 1. Enable RCC2 Access.
 * 2. Bypass2 the PLL while init.
 * 3. Set the 'XTAL' clock source osc value.
 * 4. Set the clock source
 * 5. Set the PLL DIV
 * 6. Set the System Clock DIV
 * 7. Poll the PLL_READY Flag
 */
/** @todo to be optimized - MVP */
static SCR_ErrorStatus_t
tConfigSysClkMOSC(void)
{
  /* Function data types */
  SCR_ErrorStatus_t L_tThisFuncStatus = SYSCLK_CONFIG_MOSC_FAILED;

  /* Enable RCC2 Access */
  BIT_SET(SCR->RCC2, 0x1FU);

#if (SYS_PLL == SYS_PLL_ENABLE)

  /* Bypass the PLL */
  BIT_SET(SCR->RCC2, 0x0BU);

  /* Clear XTAL */
  SCR->RCC2 &= (~((u32)0x7C0U));
  /* Set XTAL */
  SCR->RCC |= (((u32)RCC_XTAL_VAL) << 0x06U);

  /* Activate the PLL */
  BIT_CLR(SCR->RCC2, 0x0DU);

  /* Select DIV400 */
  BIT_SET(SCR->RCC2, 0x1EU);

  /* Set the system divisor */
  SCR->RCC2 &= (~(0x1FC00000UL));
  SCR->RCC2 |= (((u32)SYS_CLK_DIV) << 0x16U);

  /* Wait for PLL to be locked */
  while( (0x00U == (u8)BIT_GET(SCR->RIS, 0x06U)) )
  {
    ; /* Sync */
  }

  /* Bypass the MOSC */
  BIT_CLR(SCR->RCC2, 0x0BU);

#else

#endif

  return L_tThisFuncStatus;
}
/** **************************************
 * @defgroup Getters Private Functions
 ** **************************************
 */
/** ------ New ------ Function ------ */
static u8
u8GetPllLockStatus(void)
{
    /* Fetch the flag bit and store it */
    u8 L_u8PllLockStatus = (u8) BIT_GET(SCR->PLLSTAT, 0x00U);

    return L_u8PllLockStatus;
}
/** ------ New ------ Function ------ */
static u8
u8GetPllTrStatus(void)
{
    /* Fetch the flag bit and store it */
    u8 L_u8PllTrStatus = (u8) BIT_GET(SCR->RIS, 0x06U);

    return L_u8PllTrStatus;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_WD(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x02U) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRWD, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {;}
    }
    else {;}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_TIMER(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x06U) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRTIMER, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {;}
    }
    else {;}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_GPIO(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x06U) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRGPIO, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_DMA(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (0x00U == Copy_tPeriphNum) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRDMA, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_HIB(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (0x00U == Copy_tPeriphNum) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRHIB, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_UART(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x09U) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRUART, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_SSI(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x04U) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRSSI, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_I2C(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x04U) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRI2C, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_USB(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (0x00U == Copy_tPeriphNum) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRUSB, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_CAN(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x02U) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRCAN, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_ADC(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x02U) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRADC, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_ACMP(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (0x00U == Copy_tPeriphNum) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRACMP, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static PeriphState_t
tGetPeriphState_PWM(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x02U) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRPWM, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_QEI(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x02U) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRQEI, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_EEPROM(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (0x00U == Copy_tPeriphNum) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PREEPROM, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** ------ New ------ Function ------ */
static const PeriphState_t
tGetPeriphState_WTIMER(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    PeriphState_t L_tThisPeriphralState = SCR_PERIPHRAL_NOT_READY;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x06U) )
    {
        /* Get the periphral state bit and switch it to  readable state */
        if( (SCR_PERIPHRAL_READY == (u8) BIT_GET(SCR->PRWTIMER, Copy_tPeriphNum)) )
        {
            L_tThisPeriphralState = SCR_PERIPHRAL_READY;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisPeriphralState;
}
/** **************************************
 * @defgroup Setters Private Functions
 ** **************************************
 */
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_WD(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x02U) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCWD, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_WD(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_TIMER(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x06U) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCTIMER, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_TIMER(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_GPIO(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x06U) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCGPIO, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_GPIO(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_DMA(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (0x00U == Copy_tPeriphNum) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCDMA, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_DMA(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_UART(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x09U) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCUART, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_UART(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_SSI(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x04U) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCSSI, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_SSI(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_I2C(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x04U) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCI2C, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_I2C(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_USB(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (0x00U == Copy_tPeriphNum) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCUSB, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_USB(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_CAN(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x02U) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCCAN, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_CAN(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_ADC(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x02U) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCADC, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_ADC(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_ACMP(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (0x00U == Copy_tPeriphNum) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCACMP, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_ACMP(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_PWM(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x02U) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCPWM, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_PWM(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_QEI(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x02U) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCQEI, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_QEI(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_EEPROM(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (0x00U == Copy_tPeriphNum) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCEEPROM, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_EEPROM(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
/** ------ New ------ Function ------ */
static const SCR_ErrorStatus_t
tEnableCLK_WTIMER(uC_PeriphNum_t Copy_tPeriphNum)
{
    /* Function data types */
    SCR_ErrorStatus_t L_tThisFuncStatus = CLOCK_ENABLE_FAILED;

    /* Check the validity of the passed integer */
    if( (Copy_tPeriphNum >= 0x00U) && (Copy_tPeriphNum < 0x06U) )
    {
        /* Enable the peripheral clock */
        BIT_SET(SCR->RCGCWTIMER, Copy_tPeriphNum);
        /* Check wether the  periphral unlocked or not */
        if( (SCR_PERIPHRAL_READY == tGetPeriphState_WTIMER(Copy_tPeriphNum)) )
        {
            L_tThisFuncStatus = CLOCK_ENABLE_SUCC;
        }
        else {/* Error handle - Print to user */}
    }
    else {/* Error handle - Print to user */}

    return L_tThisFuncStatus;
}
