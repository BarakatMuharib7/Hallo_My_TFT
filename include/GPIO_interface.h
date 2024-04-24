/*********************************************
 * Author:				Barakat S. Muharib
 * Creation Data:		23 Feb, 2024
 * Version:				v2.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  23 Feb, 2024	Barakat S. Muharib		    Initial Creation
 * v1.1       29 Feb, 2024	Barakat S. Muharib		    unify GPIO Pins for all registers
 * v2.0		  19 Apr, 2024	Abdullah M. Abdullah        Adding a new API to set the Alternative functions
*********************************************/

// Header Guard File
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

//GPIO PORT Name 
#define GPIO_PORTA 		        0
#define GPIO_PORTB 		        1
#define GPIO_PORTC 		        2

// GPIO Pins 
#define GPIO_PIN0         	            0
#define GPIO_PIN1         	            1
#define GPIO_PIN2         	            2
#define GPIO_PIN3         	            3
#define GPIO_PIN4         	            4
#define GPIO_PIN5         	            5
#define GPIO_PIN6         	            6
#define GPIO_PIN7         	            7
#define GPIO_PIN8         	            8
#define GPIO_PIN9         	            9
#define GPIO_PIN10         	            10
#define GPIO_PIN11        	            11
#define GPIO_PIN12        	            12
#define GPIO_PIN13        	            13
#define GPIO_PIN14        	            14
#define GPIO_PIN15        	            15

// GPIO_MODER Mode for Pin
#define GPIO_INPUT				0b00
#define GPIO_OUTPUT				0b01
#define GPIO_AF					0b10
#define GPIO_ANALOG				0b11

// GPIO_MODER Mode for the whole Port(from A0 to A7 only)
#define GPIO_MODE_INPUT_PORT		0x0
#define GPIO_MODE_OUTPUT_PORT		0x5555
#define GPIO_MODE_AF_PORT			0xAAAA
#define GPIO_MODE_ANALOG_PORT		0xFFFF

// GPIO_OTYPER Output Mode for Pin    Push Pull (PP) or Open Drain (OD)
#define GPIO_OUTPUT_PP 					0
#define GPIO_OUTPUT_OD			 	    1

// GPIO_OTYPER Output Mode for Port    
#define GPIO_OTYPER_PORT_PUSH_PULL 		0x0000
#define GPIO_OTYPER_PORT_OPEN_DRAIN 	0xFFFF

// GPIO_OSPEEDR Mode for Pin
#define GPIO_LOW_SPEED		        0b00
#define GPIO__MED_SPEED		        0b01
#define GPIO_HIGH_SPEED             0b10
#define GPIO_VERY_HIGH_SPEED		0b11

// GPIO_OSPEEDR Mode for Port
#define GPIO_OSPEEDR_PORT_LOW_SPEED		        0x00000000
#define GPIO_OSPEEDR_PORT_MED_SPEED		        0x55555555
#define GPIO_OSPEEDR_PORT_HIGH_SPEED            0xAAAAAAAA
#define GPIO_OSPEEDR_PORT_VERY_HIGH_SPEED		0xFFFFFFFF

// Output Value(0 or 1) of the corresponding Pin  in the GPIO_ODR 
#define GPIO_PIN_LOW		0
#define GPIO_PIN_HIGH   	1

// Output Value(0 or 1) of the whole Port  in the GPIO_ODR 
#define GPIO_PORT_LOW 		0
#define GPIO_PORT_HIGH 		1

// GPIO_PUPDR Pin State
#define GPIO_PUPDR_PIN_FLOAT	        0b00
#define GPIO_PUPDR_PIN_PULL_UP	        0b01
#define GPIO_PUPDR_PIN_PULL_DOWN        0b10

// GPIO_PUPDR Port State
#define GPIO_PUPDR_PORT_FLOAT	        0x00000000
#define GPIO_PUPDR_PORT_PULL_UP	        0x55555555
#define GPIO_PUPDR_PORT_PULL_DOWN       0xAAAAAAAA

// Prototype Functions for the GPIO Pin
void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Mode);
void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputMode);
void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OSpeedMode);
void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputValue);
void MGPIO_voidSetPullupDownResister(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullupDownState);
u8 MGPIO_u8GetInputPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
void MGPIO_voidLockPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber);

// Prototype Functions for the whole GPIO PORT
void MGPIO_voidSetPortMode(u8 Copy_u8PortName, u32 Copy_u32Mode);
void MGPIO_voidSetPortOutputType(u8 Copy_u8PortName, u32 Copy_u32PortOutputMode);
void MGPIO_voidSetPortOutputSpeed(u8 Copy_u8PortName, u32 Copy_u32OSpeedMode);
void MGPIO_voidSetPortOutputValue(u8 Copy_u8PortName, u32 Copy_u32OutputValue);
void MGPIO_voidSetPortPullupDownResister(u8 Copy_u8PortName, u32 Copy_u32PullupDownState);
u32  MGPIO_u32GetInputPortValue(u8 Copy_u8PortName);
void MGPIO_voidLockPort(u8 Copy_u8PortName);
void MGPIO_voidSetAlternativeFunction(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8AlternativeFunction);

#endif

