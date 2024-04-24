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


// Header Guard File
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

// Definition of the Input Clock to the Processor
#define     RCC_HSI             0
#define     RCC_HSE             1
#define     RCC_PLL             2

// Definition of the bus in which the Peripheral on
#define 	RCC_AHB 		    0
#define 	RCC_APB1 		    1
#define 	RCC_APB2 		    2

// Peripheral Bit Position on RCC AHB1 peripheral clock enable register (RCC_AHB1ENR) 
#define 	RCC_AHB_GPIOAEN		0
#define 	RCC_AHB_GPIOBEN		1
#define 	RCC_AHB_GPIOCEN		2
#define 	RCC_AHB_DMA1EN		21
#define 	RCC_AHB_DMA2EN		22

// Peripheral Bit Position on RCC APB1 peripheral clock enable register (RCC_APB1ENR)
#define 	RCC_APB1_TIM2EN		0
#define 	RCC_APB1_TIM3EN		1
#define 	RCC_APB1_TIM4EN		2
#define 	RCC_APB1_TIM5EN		3
#define 	RCC_APB1_WWDGEN		11
#define 	RCC_APB1_SPI2EN		14
#define 	RCC_APB1_SPI3EN		15
#define 	RCC_APB1_USART23EN	17
#define 	RCC_APB1_I2C1EN		21
#define 	RCC_APB1_I2C2EN		22
#define 	RCC_APB1_I2C3EN		23
#define 	RCC_APB1_PWREN		28

// Peripheral Bit Position on RCC APB2 peripheral clock enable register (RCC_APB2ENR)
#define 	RCC_APB2_TIM1EN		0
#define 	RCC_APB2_USART1EN	4
#define 	RCC_APB2_USART6EN	5
#define 	RCC_APB2_ADC1EN		8
#define 	RCC_APB2_SDIOEN		11
#define 	RCC_APB2_SPI1EN		12
#define 	RCC_APB2_SPI4ENEN	13
#define 	RCC_APB2_SYSCFGEN	14
#define 	RCC_APB2_TIM9EN		16
#define 	RCC_APB2_TIM10EN	17
#define 	RCC_APB2_TIM11EN	18

// Definitions of Bit Position on  RCC clock control register (RCC_CR)
#define		RCC_CR_HSION		0
#define		RCC_CR_HSIRDY		1
#define		RCC_CR_HSEON		16
#define		RCC_CR_HSERDAY		17
#define		RCC_CR_CSSON		19
#define		RCC_CR_PLLON		24
#define		RCC_CR_PLLRDY		25
#define		RCC_CR_PLLI2SON		26
#define		RCC_CR_PLLI2SRDY	27

// Definitions of Bit Position on  RCC clock configuration register (RCC_CFGR)
#define		RCC_CFGR_SW0		0
#define		RCC_CFGR_SW1		1

// Definitions of Bit Position on  RCC PLL configuration register (RCC_PLLCFGR)
#define		RCC_PLLCFGR_PLLSRC	22


// Prototype Functions
void RCC_voidInit(void);
void RCC_voidEnableClockSource(u8 Copy_u8ClockSource);
void RCC_voidDisableClockSource(u8 Copy_u8ClockSource);
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusName, u8 Copy_u8PeripheralName);
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusName, u8 Copy_u8PeripheralName);

#endif

