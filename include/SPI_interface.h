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
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

typedef enum
{
    MSPI_SPI1 = 1,
    MSPI_SPI2,
    MSPI_SPI3,
    MSPI_SPI4,
}MSPI_INTERRUPT_LINE_t;


// Definitions of Bit Position on   SPI control register1 (SPI_CR1)
#define		SPI_CR1_CPHA		    0
#define		SPI_CR1_CPOL		    1
#define		SPI_CR1_MSTR		    2
#define		SPI_CR1_SPE		        6
#define		SPI_CR1_LSBFIRST		7
#define		SPI_CR1_SSI		        8
#define		SPI_CR1_SSM		        9
#define		SPI_CR1_DFF		        11


void MSPI1_voidInit(void);
u8 MSPI1_u8TrancieveSynchronous(u8 Copy_u8Data);

#endif