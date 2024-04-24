/*********************************************
 * Author:				Barakat S. Muharib
 * Creation Data:		23 Feb, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  23 Feb, 2024	Barakat S. Muharib		  Initial Creation
*********************************************/

// Library Inclusion
# include "../include/STD_TYPES.h"
# include "../include/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
# include "../include/RCC_interface.h"
# include "../include/RCC_private.h"
# include "../include/RCC_config.h"

// Pre-Build Configuration
void RCC_voidInit(void)
{
	#if RCC_CLOCK_SOURCE == RCC_CLK_HSI
		SET_BIT(RCC_CR, RCC_CR_HSION);			   // Enable HSI
		CLR_BIT(RCC_CR, RCC_CR_HSEON);			   // Disable HSE
		CLR_BIT(RCC_CR, RCC_CR_PLLON);			   // Disable PLL
		
		// Polling (Busy wait) till the HSI is Ready 
		while(GET_BIT(RCC_CR, RCC_CR_HSIRDY) == 0);
		
		// Select HSI as Input Clock source to the Processor 
		CLR_BIT(RCC_CFGR, RCC_CFGR_SW0);
		CLR_BIT(RCC_CFGR, RCC_CFGR_SW1);
	#elif RCC_CLOCK_SOURCE == RCC_CLK_HSE
		SET_BIT(RCC_CR, RCC_CR_HSEON);			   // Enable HSE
		CLR_BIT(RCC_CR, RCC_CR_HSION);			   // Disable HSI
      CLR_BIT(RCC_CR, RCC_CR_PLLON);			   // Disable PLL
         
		// Polling (Busy wait) till the HSE is Ready
		while(GET_BIT(RCC_CR,RCC_CR_HSERDAY) == 0);
		
		// Select HSE as Input Clock source to the Processor 
		SET_BIT(RCC_CFGR, RCC_CFGR_SW0);
		CLR_BIT(RCC_CFGR, RCC_CFGR_SW1);
	#elif RCC_CLOCK_SOURCE == RCC_CLK_PLL
		#if RCC_CLK_PLL_SRC == RCC_CLK_HSI
			CLR_BIT(RCC_PLLCFGR, RCC_PLLCFGR_PLLSRC);
		#elif RCC_CLK_PLL_SRC == RCC_CLK_HSE
			SET_BIT(RCC_PLLCFGR, RCC_PLLCFGR_PLLSRC);
		#else 
			#error "RCC_CLK_PLL_SRC Configuration Error"
		#endif
		SET_BIT(RCC_CR, RCC_CR_PLLON);			   // Enable PLL
		CLR_BIT(RCC_CR, RCC_CR_HSION);			   // Disable HSI
		CLR_BIT(RCC_CR, RCC_CR_HSEON);			   // Disable HSE
		
		// Polling (Busy wait) till the PLL is Ready
		while(GET_BIT(RCC_CR, RCC_CR_PLLRDY) == 0);
		
		// Select PLL as Input Clock source to the Processor 
		CLR_BIT(RCC_CFGR, RCC_CFGR_SW0);
		SET_BIT(RCC_CFGR, RCC_CFGR_SW1);
		
	#else
		#error	"RCC_CLOCK_SOURCE Configuration Error"
	#endif

	// AHB Prescaler Setting 
	RCC_CFGR &= ~(RCC_AHB_PRESCALER_MASK << 4);// Bitmasking
	RCC_CFGR |= (RCC_AHB_PRESCALER << 4);
	
	// APB1 Prescaler Setting 
	RCC_CFGR &= ~(RCC_APB1_PRESCALER_MASK << 10);// Bitmasking
	RCC_CFGR |=  (RCC_APB1_PRESCALER << 10);

	// APB2 Prescaler Setting 
	RCC_CFGR &= ~(RCC_APB2_PRESCALER_MASK << 13);// Bitmasking
	RCC_CFGR |=  (RCC_APB2_PRESCALER << 13);
		
}

// Post-Build Configuration
void RCC_voidEnableClockSource(u8 Copy_u8ClockSource)
{
    if(Copy_u8ClockSource == RCC_HSI)
    {
       SET_BIT(RCC_CR, RCC_CR_HSION); 
    }
    else if(Copy_u8ClockSource == RCC_HSE)
    {
       SET_BIT(RCC_CR, RCC_CR_HSEON); 
    }
    else if(Copy_u8ClockSource == RCC_PLL)
    {
       SET_BIT(RCC_CR, RCC_CR_PLLON); 
    }
    else
    {
       // error
    }
}


void RCC_voidDisableClockSource(u8 Copy_u8ClockSource)
{
    if(Copy_u8ClockSource == RCC_HSI)
    {
       CLR_BIT(RCC_CR, RCC_CR_HSION); 
    }
    else if(Copy_u8ClockSource == RCC_HSE)
    {
       CLR_BIT(RCC_CR, RCC_CR_HSEON); 
    }
    else if(Copy_u8ClockSource == RCC_PLL)
    {
       CLR_BIT(RCC_CR, RCC_CR_PLLON); 
    }
    else
    {
       // error
    }
}

void RCC_voidEnablePeripheralClock(u8 Copy_u8BusName, u8 Copy_u8PeripheralName)
{
	switch(Copy_u8BusName)
	{
		case RCC_AHB:
			SET_BIT(RCC_AHB1ENR, Copy_u8PeripheralName);
			
		break;
		
		case RCC_APB1:
			SET_BIT(RCC_APB1ENR, Copy_u8PeripheralName);
			
		break;
		
		case RCC_APB2:
			SET_BIT(RCC_APB2ENR, Copy_u8PeripheralName);
		break;
		default:
		// Error
		break;
	}
	
}

void RCC_voidDisablePeripheralClock(u8 Copy_u8BusName, u8 Copy_u8PeripheralName)
{
		switch(Copy_u8BusName)
	{
		case RCC_AHB:
			CLR_BIT(RCC_AHB1ENR, Copy_u8PeripheralName);
			
		break;
		
		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralName);
			
		break;
		
		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralName);
		break;
		default:
		// Error
		break;
	}
}
