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
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/SPI_interface.h"
#include "../include/SPI_private.h"
#include "../include/SPI_config.h"


// Array Of Pointers to Function
// static void *MSPI1_pNotificationFunction(void) = NULLPTR
static void (*MSPI_pNotificationFunction[5])(void) = {NULLPTR};


// Pre-build configuration (Task)
void MSPI1_voidInit(void)
{
    /*Setup GPIO Pins (delayed)*/

    /* CPOL Configuration */
    #if SPI_CPOL_OPTION == SPI_CPOL_HIGH  // Idle High CPOL
	    SET_BIT(MSPI1->CR1, SPI_CR1_CPOL);	

    #elif SPI_CPOL_OPTION == SPI_CPOL_LOW  // Idle Low CPOL
	    CLR_BIT(MSPI1->CR1, SPI_CR1_CPOL);	
	#else 
		#error "SPI_CPOL_OPTION Configuration Error"
	#endif

    /* CPHA Configuration */
    #if SPI_CPHA_OPTION == SPI_CPHA_HIGH  // The second clock transition is the first data capture edge
	    SET_BIT(MSPI1->CR1, SPI_CR1_CPHA);// The Trailing clock transition is Receive	

    #elif SPI_CPHA_OPTION == SPI_CPHA_LOW  // The first clock transition is the first data capture edge
	    CLR_BIT(MSPI1->CR1, SPI_CR1_CPHA); // The Leading clock transition is Receive	
	#else 
		#error "SPI_CPHA_OPTION Configuration Error"
	#endif

    /* MSTR/SLV Configuration (Master/Slave Selection)*/
    #if SPI_MSTR_SLV == SPI_MSTR_CFG  //  Master Config
	    SET_BIT(MSPI1->CR1, SPI_CR1_MSTR);	

    #elif SPI_MSTR_SLV == SPI_SLV_CFG  // Slave Config
	    CLR_BIT(MSPI1->CR1, SPI_CR1_MSTR);	
	#else 
		#error "SPI_MSTR_SLV Configuration Error"
	#endif

    // SPI Baud Rate Clock Prescaler Setting 
	MSPI1->CR1 &= ~(SPI_BR_PRESCALER_MASK << 3);// Bitmasking
	MSPI1->CR1 |= (SPI_BR_CLCK_DIV_2 << 3);

    /* SPE Enabe/Disable Configuration */
    #if SPI_SPE_OPTION == SPI_SPE_ENABLE  // SPI Peripheral Enable
	    SET_BIT(MSPI1->CR1, SPI_CR1_SPE);	

    #elif SPI_SPE_OPTION == SPI_SPE_DISABLE  // SPI Peripheral Disable
	    CLR_BIT(MSPI1->CR1, SPI_CR1_CPOL);	
	#else 
		#error "SPI_SPE_OPTION Configuration Error"
	#endif

    /*  LSB/MSB first Configuration */
    #if SPI_LSB_MSB == SPI_LSB_FIRST                // SPI LSBFIRST
	    SET_BIT(MSPI1->CR1, SPI_CR1_LSBFIRST);	

    #elif SPI_LSB_MSB == SPI_MSB_FIRST              // SPI MSBFIRST
	    CLR_BIT(MSPI1->CR1, SPI_CR1_LSBFIRST);	
	#else 
		#error "SPI_LSB_MSB Configuration Error"
	#endif

    /* Data Frame Format 8-bit/16-bit  Configuration */
    #if SPI_DFF_OPTION == SPI_DFF_16_BIT                // SPI Data Frame Format 16-bit
	    SET_BIT(MSPI1->CR1, SPI_CR1_DFF);	

    #elif SPI_DFF_OPTION == SPI_DFF_8_BIT              // SPI Data Frame Format 8-bit
	    CLR_BIT(MSPI1->CR1, SPI_CR1_DFF);	
	#else 
		#error "SPI_DFF_OPTION Configuration Error"
	#endif

    /* SSM: Software slave management*/
    #if SPI_SSM_OPTION == SPI_SSM_SW                // SPI Software slave management enabled
	    SET_BIT(MSPI1->CR1, SPI_CR1_SSM);
        /*SSI: Internal slave select*/
        #if SPI_SSI_VALUE == SPI_SSI_0    //0 is forced onto the NSS pin of the Slave and the GPIO value is ignored
            CLR_BIT(MSPI1->CR1, SPI_CR1_SSI);     
        #elif SPI_SSI_VALUE == SPI_SSI_1 //1 is forced onto the NSS pin of the Slave and the GPIO value is ignored
            SET_BIT(MSPI1->CR1, SPI_CR1_SSI);
        #else 
		    #error "SPI_SSI_VALUE Configuration Error"
	    #endif		

    #elif SPI_SSM_OPTION == SPI_SSM_HW              // SPI Software slave management Disabled
	    CLR_BIT(MSPI1->CR1, SPI_CR1_SSM);	
	#else 
		#error "SPI_SSM_OPTION Configuration Error"
	#endif


}

u8 MSPI1_u8TrancieveSynchronous(u8 Copy_u8Data)
{
    u8 Local_u8ReceivedData;
    MSPI1 -> DR = Copy_u8Data;
    while(GET_BIT(MSPI1 -> SR, 7));        // while(GET_BIT(MSPI1 -> SR, 7) == 1);
    Local_u8ReceivedData = MSPI1 -> DR;
    return Local_u8ReceivedData;
}

void MSPI_voidSetCallBack(MSPI_INTERRUPT_LINE_t Copy_tInterrupLine, void (*pCallBackFunction)(void))
{

	MSPI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
}

// ISR For SPI1
void SPI1_IRQHandler(void)
{
    // if(MSPI1_pNotificationFunction != NULLPTR)
    if(MSPI_pNotificationFunction[1] != NULLPTR)
    {
        // MSPI1_pNotificationFunction();
        MSPI_pNotificationFunction[1]();
    }
    else
    {
        // Do Nothing
    }

    /*Flag Clearance */
    //  MSPI1->CR2 

    /*  SPI RXNEIE & TXEIE Disable Tx Rx interrupt */
	//  MSPI1->CR2 &= ~(0b11 << 6);// Bitmasking
	//  MSPI1->CR2 |= (0b00 << 6);
}

// ISR For SPI2
void SPI2_IRQHandler(void)
{
    // if(MSPI2_pNotificationFunction != NULLPTR)
    if(MSPI_pNotificationFunction[2] != NULLPTR)
    {
        // MSPI2_pNotificationFunction();
        MSPI_pNotificationFunction[2]();
    }
    else
    {
        // Do Nothing
    }

    /*Flag Clearance */
    //MSPI2->CR2 
}

// ISR For SPI3
void SPI3_IRQHandler(void)
{
    // if(MSPI3_pNotificationFunction != NULLPTR)
    if(MSPI_pNotificationFunction[3] != NULLPTR)
    {
        // MSPI3_pNotificationFunction();
        MSPI_pNotificationFunction[3]();
    }
    else
    {
        // Do Nothing
    }

    /*Flag Clearance */
    //MSPI3->CR2 
}

// ISR For SPI4
void SPI4_IRQHandler(void)
{
    // if(MSPI4_pNotificationFunction != NULLPTR)
    if(MSPI_pNotificationFunction[4] != NULLPTR)
    {
        // MSPI4_pNotificationFunction();
        MSPI_pNotificationFunction[4]();
    }
    else
    {
        // Do Nothing
    }

    /*Flag Clearance */
    //MSPI4->CR2 
}

/*
* Tasks:
*       - Complete Init function 
*       - Implement ISR of SPI1, SPI2, SPI3, and SP
*
*/
