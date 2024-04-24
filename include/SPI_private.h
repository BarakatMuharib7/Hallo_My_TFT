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
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
}SPI_t;


#define      MSPI1      ((volatile SPI_t *)0x40013000)
#define      MSPI2      ((volatile SPI_t *)0x40003800)
#define      MSPI3      ((volatile SPI_t *)0x40003C00)
#define      MSPI4      ((volatile SPI_t *)0x40013400)


#define     SPI_CPOL_HIGH       1
#define     SPI_CPOL_LOW        0

#define     SPI_CPHA_HIGH       1
#define     SPI_CPHA_LOW        0 

#define     SPI_MSTR_CFG        1
#define     SPI_SLV_CFG         0 

#define     SPI_SPE_ENABLE      1
#define     SPI_SPE_DISABLE     0 

#define     SPI_LSB_FIRST       1
#define     SPI_MSB_FIRST       0 

#define     SPI_DFF_16_BIT      1
#define     SPI_DFF_8_BIT       0 

#define     SPI_SSM_SW          1
#define     SPI_SSM_HW          0 

#define     SPI_SSI_1           1
#define     SPI_SSI_0           0 

// SPI Baud Rate  Clock Prescaler Setting 
#define     SPI_BR_PRESCALER_MASK	        0b111

#define 	SPI_BR_CLCK_DIV_2		        0b000
#define 	SPI_BR_CLCK_DIV_4		        0b001
#define 	SPI_BR_CLCK_DIV_8		        0b010
#define 	SPI_BR_CLCK_DIV_16		        0b011
#define 	SPI_BR_CLCK_DIV_32		        0b100
#define 	SPI_BR_CLCK_DIV_64		        0b101
#define 	SPI_BR_CLCK_DIV_128		        0b110
#define 	SPI_BR_CLCK_DIV_256		        0b111


#endif