/**
 * @file SCR_CONFIG.h
 * @author Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard types
 * @copyright Copyrights (c) 2022 Osama, Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __SCR_CONFIG_H__
#define __SCR_CONFIG_H__

/*
----------------------------------------------------------------------
- Configuration Parameters
----------------------------------------------------------------------
*/

/**
 * @breif System Input Clock Source
 * @defgroup Configuration Parameters:
 *      @arg SYS_CLK_PIOSC
 *      @arg SYS_CLK_PIOSC_DIV_4
 *      @arg SYS_CLK_MOSC
 *      @arg SYS_CLK_LFIOSC
 *      @arg SYS_CLK_HMOSC
 */
#define SYS_CLK     (SYS_CLK_MOSC)
/**
 * @breif Enable/Disable PLL Input Clock
 * @defgroup Configuration Parameters:
 *      @arg SYS_PLL_ENABLE
 *      @arg SYS_PLL_DISABLE
 */
#define SYS_PLL     (SYS_PLL_ENABLE)
/**
 * @breif System PLL Divisor
 * @defgroup Configuration Parameters:
 *      @arg SYS_PLL_DIV_2
 *      @arg SYS_PLL_DIV_1
 */
#define SYS_PLL_DIV     (SYS_PLL_DIV_1)
/**
 * @breif System Clock Divisor
 * @defgroup Configuration Parameters:
 *      @arg SYS_CLK_DIV_1
 *      @arg SYS_CLK_DIV_2
 *      @arg SYS_CLK_DIV_3
 *      @arg SYS_CLK_DIV_4
 *      @arg SYS_CLK_DIV_5
 *      @arg SYS_CLK_DIV_6
 *      @arg SYS_CLK_DIV_7
 *      @arg SYS_CLK_DIV_8
 *      @arg SYS_CLK_DIV_9
 *      @arg SYS_CLK_DIV_10
 *      @arg SYS_CLK_DIV_11
 *      @arg SYS_CLK_DIV_12
 *      @arg SYS_CLK_DIV_13
 *      @arg SYS_CLK_DIV_14
 *      @arg SYS_CLK_DIV_15
 *      @arg SYS_CLK_DIV_16
 *
 * @note The SYS_CLK_DIV_XX Continued to (XX = 64)
 */
#define SYS_CLK_DIV     (SYS_CLK_DIV_5)
/**
 * @breif XTAL Value (Developer Sepcific Config)
 * @defgroup Configuration Parameters:
 *      @arg XTAL_EXOSCCLK_4MHZ
 *      @arg XTAL_EXOSCCLK_4f096MHZ
 *      @arg XTAL_EXOSCCLK_4f9152MHZ
 *      @arg XTAL_EXOSCCLK_5MHZ_USB
 *      @arg XTAL_EXOSCCLK_5f12MHZ
 *      @arg XTAL_EXOSCCLK_6MHZ_USB
 *      @arg XTAL_EXOSCCLK_6f144MHZ
 *      @arg XTAL_EXOSCCLK_7f372MHZ
 *      @arg XTAL_EXOSCCLK_8MHZ_USB
 *      @arg XTAL_EXOSCCLK_8f192MHZ
 *      @arg XTAL_EXOSCCLK_10MHZ_USB
 *      @arg XTAL_EXOSCCLK_12MHZ_USB
 *      @arg XTAL_EXOSCCLK_12f288MHZ
 *      @arg XTAL_EXOSCCLK_13f256MHZ
 *      @arg XTAL_EXOSCCLK_14f318MHZ
 *      @arg XTAL_EXOSCCLK_16MHZ_USB
 *      @arg XTAL_EXOSCCLK_16f384MHZ
 *      @arg XTAL_EXOSCCLK_18MHZ_USB
 *      @arg XTAL_EXOSCCLK_20MHZ_USB
 *      @arg XTAL_EXOSCCLK_24MHZ_USB
 *      @arg XTAL_EXOSCCLK_25MHZ_USB
 */
#define RCC_XTAL_VAL    (XTAL_EXOSCCLK_16f384MHZ)


#endif /* __SCR_CONFIG_H__ */
