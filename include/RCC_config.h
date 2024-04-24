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
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*
Options:
    RCC_CLK_HSI
    RCC_CLK_HSE
    RCC_CLK_PLL
    */
   //  HSI (16Mhz)
#define     RCC_CLOCK_SOURCE        RCC_CLK_HSI 

/*Options:
	RCC_CLK_HSI
	RCC_CLK_HSE
	*/
#define 	RCC_CLK_PLL_SRC 		RCC_CLK_HSI

/*Options:
	RCC_AHB_DIV_1
	RCC_AHB_DIV_2
	RCC_AHB_DIV_4
	RCC_AHB_DIV_8
	RCC_AHB_DIV_16
	RCC_AHB_DIV_64
	RCC_AHB_DIV_128
	RCC_AHB_DIV_256
	RCC_AHB_DIV_512
	*/
    // so Clock freq on AHB is 16(HSI)/2 = 8 MHz
#define		RCC_AHB_PRESCALER	RCC_AHB_DIV_2 

/*Options:
    RCC_APB1_DIV_1
    RCC_APB1_DIV_2
    RCC_APB1_DIV_4
    RCC_APB1_DIV_8
    RCC_APB1_DIV_16
    */
#define		RCC_APB1_PRESCALER RCC_APB1_DIV_1

/*Options:
    RCC_APB2_DIV_1
    RCC_APB2_DIV_2
    RCC_APB2_DIV_4
    RCC_APB2_DIV_8
    RCC_APB2_DIV_16
    */
#define		RCC_APB2_PRESCALER RCC_APB2_DIV_1

#endif
