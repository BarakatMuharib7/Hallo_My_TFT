/****************************************************************************************
* Author:				Barakat S. Muharib
* Creation Data:		12 Apr, 2024
* Version:				v1.0
* Compiler:				GNU ARM-GCC
* Controller:			STM32F401CCU6
* Layer:				MCAL
****************************************************************************************/
/***************************************************************************************
* Version	  Date				  	Author				  			Description
* v1.0		  12 Apr, 2024			Barakat S. Muharib  		  	Initial Creation
***************************************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/*
* Options:
*   SPI_CPOL_HIGH
*   SPI_CPOL_LOW
*/
#define     SPI_CPOL_OPTION  SPI_CPOL_HIGH

/*
* Options:
*   SPI_CPHA_HIGH
*   SPI_CPHA_LOW
*/
#define     SPI_CPHA_OPTION  SPI_CPHA_HIGH 

/*
* Options:
*   SPI_MSTR_CFG
*   SPI_SLV_CFG
*/
#define     SPI_MSTR_SLV  SPI_MSTR_CFG 

/*Options:
	SPI_BR_CLCK_DIV_2
	SPI_BR_CLCK_DIV_4
	SPI_BR_CLCK_DIV_8
	SPI_BR_CLCK_DIV_16
    SPI_BR_CLCK_DIV_32
	SPI_BR_CLCK_DIV_64
	SPI_BR_CLCK_DIV_128
	SPI_BR_CLCK_DIV_256
	*/
#define		SPI_BR_CLCK_PRESCALER	SPI_BR_CLCK_DIV_2 

/*
* Options:
*   SPI_SPE_ENABLE
*   SPI_SPE_DISABLE
*/
#define     SPI_SPE_OPTION  SPI_SPE_ENABLE

/*
* Options:
*   SPI_LSB_FIRST
*   SPI_MSB_FIRST
*/
#define   SPI_LSB_MSB  SPI_MSB_FIRST

/*
* Options:
*   SPI_DFF_8_BIT
*   SPI_DFF_16_BIT
*/
#define   SPI_DFF_OPTION  SPI_DFF_8_BIT

/*
* Options:
*   SPI_SSM_HW
*   SPI_SSM_SW
*/
#define   SPI_SSM_OPTION  SPI_SSM_HW 

/*
* Options: This bit has an effect only when the SSM bit is set (SPI_SSM_SW)
*   SPI_SSI_0
*   SPI_SSI_1
*/
#define   SPI_SSI_VALUE  SPI_SSI_0

#endif