/**
 * @file main.c
 * @author Mohamed Wx
 * @date 26 Nov 2022
 * @version v0.0
 * @copyrights Copyrights (c) 2022 Mohamed Ashraf
 *
 */

/** @defgroup Included headers */
#include "../00_LIB/LIB_MVP/STD_TYPES.h"
#include "../00_LIB/LIB_MVP/BIT_MATH.h"
#include "../00_LIB/LIB_MVP/DEFAULT_HANDLER.h"

#include "../01_MCAL/00_SCR_MVP/SCR_INTERFACE.h"
#include "../01_MCAL/01_DIO_V1/DIO_INTERFACE.h"
#include "../01_MCAL/02_NVIC_MVP/NVIC_INTERFACE.h"

/**
 * @brief Entry point function
 *
 */
int main(void)
{ 
	
	MSCR_tSetGPIOxBus(SCR_PORTF_ID, AHB_ID);
	MSCR_tEnableClock(GPIO_ID, SCR_PORTF_ID);
	
	MDIO_EnSetCfg(&G_StPORTF_Cfg);
	
	while(1)
	{

	
	}
	
	return 0;
}

