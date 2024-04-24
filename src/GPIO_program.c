/*********************************************
 * Author:				Barakat S. Muharib
 * Creation Data:		23 Feb, 2024
 * Version:				v3.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  23 Feb, 2024	Barakat S. Muharib		  Initial Creation
 * v2.0		  01 Mar, 2024	Abdullah M. Abdullah		  Adding Some New APIs
 * v3.0		  19 Apr, 2024	Abdullah M. Abdullah		  Adding the Alternative function API
*********************************************/

// Library Inclusion
# include "../include/STD_TYPES.h"
# include "../include/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
# include "../include/GPIO_interface.h"
# include "../include/GPIO_private.h"
# include "../include/GPIO_config.h"


void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Mode)
{

	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			// GPIOA_MODER Setting 
			GPIOA_MODER &= ~(GPIO_MODER_MASK << (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOA_MODER |=  (Copy_u8Mode 	 << (Copy_u8PinNumber * PIN_OFFSET));
		break;
		
		case GPIO_PORTB:
		
			// GPIOB_MODER Setting 
			GPIOB_MODER &= ~(GPIO_MODER_MASK << (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOB_MODER |=  (Copy_u8Mode 	 << (Copy_u8PinNumber * PIN_OFFSET));
		break;
		
		case GPIO_PORTC:
		
			// GPIOC_MODER Setting 
			GPIOC_MODER &= ~(GPIO_MODER_MASK << (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOC_MODER |=  (Copy_u8Mode 	 << (Copy_u8PinNumber * PIN_OFFSET));
		break;
		default:
		// Error
		break;
	}
}


void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputMode)
{
	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			if (Copy_u8OutputMode == GPIO_OUTPUT_PP)
				CLR_BIT(GPIOA_OTYPER, Copy_u8PinNumber);
			else if (Copy_u8OutputMode == GPIO_OUTPUT_OD)
				SET_BIT(GPIOA_OTYPER, Copy_u8PinNumber);
			else
			{
				// Error ;
			}
		break;
		
		case GPIO_PORTB:
			if (Copy_u8OutputMode == GPIO_OUTPUT_PP)
				CLR_BIT(GPIOB_OTYPER, Copy_u8PinNumber);
			else if (Copy_u8OutputMode == GPIO_OUTPUT_OD)
				SET_BIT(GPIOB_OTYPER, Copy_u8PinNumber);
			else
			{
				// Error ;
			}
		break;
		
		case GPIO_PORTC:
			if (Copy_u8OutputMode == GPIO_OUTPUT_PP)
				CLR_BIT(GPIOC_OTYPER, Copy_u8PinNumber);
			else if (Copy_u8OutputMode == GPIO_OUTPUT_OD)
				SET_BIT(GPIOC_OTYPER, Copy_u8PinNumber);
			else
			{
				// Error ;
			}
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OSpeedMode)
{

	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			// GPIOA_OSPEEDR Setting 
			GPIOA_OSPEEDR &= ~(GPIO_OSPEEDR_MASK 		<< (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOA_OSPEEDR |=  (Copy_u8OSpeedMode 		<< (Copy_u8PinNumber * PIN_OFFSET));
			
		break;
		
		case GPIO_PORTB:
		
			// GPIOB_OSPEEDR Setting 
			GPIOB_OSPEEDR &= ~(GPIO_OSPEEDR_MASK 		<< (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOB_OSPEEDR |=  (Copy_u8OSpeedMode		<< (Copy_u8PinNumber * PIN_OFFSET));
		break;
		
		case GPIO_PORTC:
		
			// GPIOC_OSPEEDR Setting 
			GPIOC_OSPEEDR &= ~(GPIO_OSPEEDR_MASK 		<< (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOC_OSPEEDR |=  (Copy_u8OSpeedMode 	 	<< (Copy_u8PinNumber * PIN_OFFSET));
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputValue)
{
	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			if (Copy_u8OutputValue == GPIO_PIN_HIGH)
                GPIOA_BSRR |= (1 << Copy_u8PinNumber );
			else if (Copy_u8OutputValue == GPIO_PIN_LOW)
                GPIOA_BSRR |= (1 << (Copy_u8PinNumber + GPIO_BSRR_PIN_OFFSET_RESET));// go to the Reset Bit Position of the Pin
			else
			{
				// Error ;	
			}
		break;
		
		case GPIO_PORTB:
			if (Copy_u8OutputValue == GPIO_PIN_HIGH)
                GPIOB_BSRR = (1 << Copy_u8PinNumber );
			else if (Copy_u8OutputValue == GPIO_PIN_LOW)
                GPIOB_BSRR = (1 << (Copy_u8PinNumber + GPIO_BSRR_PIN_OFFSET_RESET));// go to the Reset Bit Position of the Pin
			else
			{
				// Error ;	
			}
		break;
		
		case GPIO_PORTC:
			if (Copy_u8OutputValue == GPIO_PIN_HIGH)
                GPIOC_BSRR = (1 << Copy_u8PinNumber );
			else if (Copy_u8OutputValue == GPIO_PIN_LOW)
                GPIOC_BSRR = (1 << (Copy_u8PinNumber + GPIO_BSRR_PIN_OFFSET_RESET));// go to the Reset Bit Position of the Pin
			else
			{
				// Error ;
			}
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPullupDownResister(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullupDownState)
{
	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			// GPIOA_PUBDR Setting 
			GPIOA_PUPDR &= ~(GPIO_PUPDR_MASK 		<< (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOA_PUPDR |=  (Copy_u8PullupDownState << (Copy_u8PinNumber * PIN_OFFSET));
			
		break;
		
		case GPIO_PORTB:
		
			// GPIOB_PUBDR Setting 
			GPIOA_PUPDR &= ~(GPIO_PUPDR_MASK 		<< (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOA_PUPDR |=  (Copy_u8PullupDownState << (Copy_u8PinNumber * PIN_OFFSET));
		break;
		
		case GPIO_PORTC:
		
			// GPIOC_PUBDR Setting 
			GPIOA_PUPDR &= ~(GPIO_PUPDR_MASK 		<< (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOA_PUPDR |=  (Copy_u8PullupDownState << (Copy_u8PinNumber * PIN_OFFSET));
		break;
		default:
		// Error
		break;
	}
}

u8 MGPIO_u8GetInputPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	u8 Local_u8BitValue = 0xFF;
		switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			Local_u8BitValue = GET_BIT(GPIOA_IDR, Copy_u8PinNumber);
		break;
		
		case GPIO_PORTB:
		
			Local_u8BitValue = GET_BIT(GPIOB_IDR, Copy_u8PinNumber);
		break;
		
		case GPIO_PORTC:
		
			Local_u8BitValue = GET_BIT(GPIOC_IDR, Copy_u8PinNumber);
		break;
		default:
		// Error
		break;
	}
	
	return Local_u8BitValue;
	
}

void MGPIO_voidLockPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
		switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			CLR_BIT(GPIOA_LCKR, GPIO_LCKK16);// unlock to let write to the Lockbit of Pin 
			SET_BIT(GPIOA_LCKR, Copy_u8PinNumber);
			//write in LCKK the sequence 1, 0, 1 keeping the Lockbit value of Pin unchanged
			GPIOA_LCKR |=  (1<< GPIO_LCKK16) | (1<< Copy_u8PinNumber);
			GPIOA_LCKR = (GPIOA_LCKR & ( ~(1<< GPIO_LCKK16))) | (1<< Copy_u8PinNumber);
			GPIOA_LCKR |=  (1<< GPIO_LCKK16) | (1<< Copy_u8PinNumber);

		break;
		
		case GPIO_PORTB:
			CLR_BIT(GPIOB_LCKR, GPIO_LCKK16);// unlock to let write to the Lockbit of Pin 
			SET_BIT(GPIOB_LCKR, Copy_u8PinNumber);
			//write in LCKK the sequence 1, 0, 1 keeping the Lockbit value of Pin unchanged
			GPIOB_LCKR |=  (1<< GPIO_LCKK16) | (1<< Copy_u8PinNumber);
			GPIOB_LCKR = (GPIOB_LCKR & ( ~(1<< GPIO_LCKK16))) | (1<< Copy_u8PinNumber);
			GPIOB_LCKR |=  (1<< GPIO_LCKK16) | (1<< Copy_u8PinNumber);
		break;
		
		case GPIO_PORTC:
			CLR_BIT(GPIOC_LCKR, GPIO_LCKK16);// unlock to let write to the Lockbit of Pin 
			SET_BIT(GPIOC_LCKR, Copy_u8PinNumber);
			//write in LCKK the sequence 1, 0, 1 keeping the Lockbit value of Pin unchanged
			GPIOC_LCKR |=  (1<< GPIO_LCKK16) | (1<< Copy_u8PinNumber);
			GPIOC_LCKR = (GPIOC_LCKR & ( ~(1<< GPIO_LCKK16))) | (1<< Copy_u8PinNumber);
			GPIOC_LCKR |=  (1<< GPIO_LCKK16) | (1<< Copy_u8PinNumber);
		break;
		default:
		// Error
		break;
	}
	
}

//********************* Functions for the whole Port Begin ***************************

void MGPIO_voidSetPortMode(u8 Copy_u8PortName, u32 Copy_u32Mode)
{

	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			// GPIOA_MODER Setting 
			GPIOA_MODER  &= ~(GPIO_MODER_MASK_PORT);// Bitmasking
			GPIOA_MODER |=  (Copy_u32Mode);
			
		break;
		
		case GPIO_PORTB:

			// GPIOB_MODER Setting
			GPIOB_MODER  &= ~(GPIO_MODER_MASK_PORT);// Bitmasking
			GPIOB_MODER |=  (Copy_u32Mode);
		break;

		case GPIO_PORTC:

			// GPIOC_MODER Setting
			GPIOC_MODER  &=~(GPIO_MODER_MASK_PORT);// Bitmasking
			GPIOC_MODER |=  (Copy_u32Mode);
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPortOutputType(u8 Copy_u8PortName, u32 Copy_u32PortOutputMode)
{
	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
				GPIOA_OTYPER &= ~ GPIO_OTYPER_MASK_PORT;
				GPIOA_OTYPER |= Copy_u32PortOutputMode;
		break;
		
		case GPIO_PORTB:
				GPIOB_OTYPER &= ~ GPIO_OTYPER_MASK_PORT;
				GPIOB_OTYPER |= Copy_u32PortOutputMode;;
		break;
		
		case GPIO_PORTC:
				GPIOC_OTYPER &= ~ GPIO_OTYPER_MASK_PORT;
				GPIOC_OTYPER |= Copy_u32PortOutputMode;
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPortOutputSpeed(u8 Copy_u8PortName, u32 Copy_u32OSpeedMode)
{

	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			// GPIOA_OSPEEDR Setting 
			GPIOA_OSPEEDR &= ~ GPIO_OSPEEDR_MASK_PORT;
			GPIOA_OSPEEDR |= Copy_u32OSpeedMode;	
		break;
		
		case GPIO_PORTB:
			// GPIOB_OSPEEDR Setting 
			GPIOB_OSPEEDR &= ~ GPIO_OSPEEDR_MASK_PORT;
			GPIOB_OSPEEDR |= Copy_u32OSpeedMode;
		break;
		
		case GPIO_PORTC:
			// GPIOC_OSPEEDR Setting 
			GPIOC_OSPEEDR &= ~ GPIO_OSPEEDR_MASK_PORT;
			GPIOC_OSPEEDR |= Copy_u32OSpeedMode;
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPortOutputValue(u8 Copy_u8PortName, u32 Copy_u32OutputValue)
{

	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			switch(Copy_u32OutputValue)
			{
				case GPIO_PORT_HIGH:
					GPIOA_ODR &= ~ GPIO_ODR_MASK_PORT;
					GPIOA_ODR |= 0xFFFF;
				break;

				case GPIO_PORT_LOW:
					GPIOA_ODR &= ~ GPIO_ODR_MASK_PORT;
					GPIOA_ODR |= 0x0;
				break;
			}
			// GPIOA_ODR Setting 
//			GPIOA_ODR &= ~ GPIO_ODR_MASK_PORT;
//			GPIOA_ODR |= Copy_u32OutputValue;

//			GPIOA_ODR &= ~ GPIO_ODR_MASK_PORT;
//			GPIOA_ODR |= Copy_u32OutputValue;

//			if (Copy_u8OutputValue == GPIO_PIN_HIGH)
//                GPIOA_BSRR = (1 << Copy_u8PinNumber );
//			else if (Copy_u8OutputValue == GPIO_PIN_LOW)
//                GPIOA_BSRR = (1 << (Copy_u8PinNumber + GPIO_BSRR_PIN_OFFSET_RESET));


		break;
		
		case GPIO_PORTB:
			// GPIOB_ODR Setting 
			GPIOB_ODR &= ~ GPIO_ODR_MASK_PORT;
			GPIOB_ODR |= Copy_u32OutputValue;
		break;
		
		case GPIO_PORTC:
			// GPIOC_ODR Setting 
			GPIOC_ODR &= ~ GPIO_ODR_MASK_PORT;
			GPIOC_ODR |= Copy_u32OutputValue;
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPortPullupDownResister(u8 Copy_u8PortName, u32 Copy_u32PullupDownState)
{
	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			// GPIOA_PUBDR Setting 
			GPIOA_PUPDR  = (GPIO_PUPDR_ZERO );
			GPIOA_PUPDR |= (Copy_u32PullupDownState );
			
		break;
		
		case GPIO_PORTB:
		
			// GPIOB_PUBDR Setting 
			GPIOB_PUPDR  = (GPIO_PUPDR_ZERO );
			GPIOB_PUPDR |= (Copy_u32PullupDownState );
		break;
		
		case GPIO_PORTC:
		
			// GPIOC_PUBDR Setting 
			GPIOC_PUPDR  = (GPIO_PUPDR_ZERO );
			GPIOC_PUPDR |= (Copy_u32PullupDownState );
		break;
		default:
		// Error
		break;
	}
}

u32 MGPIO_u32GetInputPortValue(u8 Copy_u8PortName)
{
	u32 Local_u32PortValue  = 0xFFFF ;
		switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			Local_u32PortValue = (GPIOA_IDR & GPIO_IDR_PORT_MASK);
		break;
		
		case GPIO_PORTB:
		
			Local_u32PortValue = (GPIOB_IDR & GPIO_IDR_PORT_MASK);
		break;
		
		case GPIO_PORTC:
		
			Local_u32PortValue = (GPIOC_IDR & GPIO_IDR_PORT_MASK);
		break;
		default:
		// Error
		break;
	}
	
	return Local_u32PortValue;
	
}

void MGPIO_voidLockPort(u8 Copy_u8PortName)
{
		switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			CLR_BIT(GPIOA_LCKR, GPIO_LCKK16);// unlock to let write to the LockPort
			GPIOA_LCKR &= GPIO_LCKR_PORT_LOCKED;
			//write in LCKK the sequence 1, 0, 1 keeping the LockPort value of Port unchanged
			GPIOA_LCKR = (GPIOA_LCKR | (1<< GPIO_LCKK16)) 	  & GPIO_LCKR_PORT_LOCKED;
			GPIOA_LCKR = (GPIOA_LCKR & ( ~(1<< GPIO_LCKK16))) & GPIO_LCKR_PORT_LOCKED;
			GPIOA_LCKR = (GPIOA_LCKR | (1<< GPIO_LCKK16))	  & GPIO_LCKR_PORT_LOCKED;

		break;
		
		case GPIO_PORTB:
			CLR_BIT(GPIOB_LCKR, GPIO_LCKK16);// unlock to let write to the LockPort
			GPIOB_LCKR &= GPIO_LCKR_PORT_LOCKED;
			//write in LCKK the sequence 1, 0, 1 keeping the LockPort value of Port unchanged
			GPIOB_LCKR = (GPIOB_LCKR | (1<< GPIO_LCKK16)) 	  & GPIO_LCKR_PORT_LOCKED;
			GPIOB_LCKR = (GPIOB_LCKR & ( ~(1<< GPIO_LCKK16))) & GPIO_LCKR_PORT_LOCKED;
			GPIOB_LCKR = (GPIOB_LCKR | (1<< GPIO_LCKK16))	  & GPIO_LCKR_PORT_LOCKED;
		break;
		
		case GPIO_PORTC:
			CLR_BIT(GPIOC_LCKR, GPIO_LCKK16);// unlock to let write to the LockPort
			GPIOC_LCKR &= GPIO_LCKR_PORT_LOCKED;
			//write in LCKK the sequence 1, 0, 1 keeping the LockPort value of Port unchanged
			GPIOC_LCKR = (GPIOC_LCKR | (1<< GPIO_LCKK16)) 	  & GPIO_LCKR_PORT_LOCKED;
			GPIOC_LCKR = (GPIOC_LCKR & ( ~(1<< GPIO_LCKK16))) & GPIO_LCKR_PORT_LOCKED;
			GPIOC_LCKR = (GPIOC_LCKR | (1<< GPIO_LCKK16))	  & GPIO_LCKR_PORT_LOCKED;
		break;
		default:
		// Error
		break;
	}
	
}


/**
 * @brief A Function to set the alternative function for a pin
 * 
 * @param Copy_u8PortName: GPIO_PORTA, GPIO_PORTB, GPIO_PORTC
 * @param Copy_u8PinNumber: GPIO_PIN0, GPIO_PIN1, ..., GPIO_PIN15 
 * @param Copy_u8AlternativeFunction: GPIO_AF00, GPIO_AF01, ..., GPIO_AF15
 */
void MGPIO_voidSetAlternativeFunction(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8AlternativeFunction)
{
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			// Check for the pin part
			if(Copy_u8PinNumber <= GPIO_PIN7 /* && Copy_u8PinNumber >= GPIO_PIN0*/)
			{
				// Clear the 4 bits associated for that pin (Bit Masking)
				GPIOA_AFRL &= ~(AF_MASK << (Copy_u8PinNumber * AF_BITS_OFFSET));
				// Set the Alternative function number in the bits
				GPIOA_AFRL |= (Copy_u8AlternativeFunction << (Copy_u8PinNumber * AF_BITS_OFFSET));
			}
			else if(Copy_u8PinNumber <= GPIO_PIN15 && Copy_u8PinNumber >= GPIO_PIN8)
			{
				// Clear the 4 bits associated for that pin (Bit Masking)
				GPIOA_AFRH &= ~(AF_MASK << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) * AF_BITS_OFFSET));
				// Set the Alternative function number in the bits
				GPIOA_AFRH |= (Copy_u8AlternativeFunction << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) * AF_BITS_OFFSET));
			}
			else
			{
				// Error
			}
		break;
		
		case GPIO_PORTB:
		break;

		case GPIO_PORTC:
		break;

		default:
			// Error
		break;
	}
}
