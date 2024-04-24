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
 * v1.0		  23 Feb, 2024	Barakat S. Muharib		      Initial Creation
 * v2.0		  19 Apr, 2024	Abdullah M. Abdullah		  Adding the Definition of the AFR registers, and some new definitions
*********************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define     GPIOA_BASE_ADDRESS          0x40020000
#define     GPIOB_BASE_ADDRESS          0x40020400
#define     GPIOC_BASE_ADDRESS          0x40020800
#define     GPIOD_BASE_ADDRESS          0x40020C00
#define     GPIOE_BASE_ADDRESS          0x40021000
#define     GPIOH_BASE_ADDRESS          0x40021C00

//GPIOA  Register definitions according to register map
#define     GPIOA_MODER                 *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x00))
#define     GPIOA_OTYPER                *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x04))
#define     GPIOA_OSPEEDR               *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x08))
#define     GPIOA_PUPDR                 *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x0C))
#define     GPIOA_IDR                   *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x10))
#define     GPIOA_ODR                   *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x14))
#define     GPIOA_BSRR                  *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x18))
#define     GPIOA_LCKR                  *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x1C))
#define     GPIOA_AFRL                  *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x20))
#define     GPIOA_AFRH                  *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x24))

//GPIOB  Register definitions according to register map
#define     GPIOB_MODER                 *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x00))
#define     GPIOB_OTYPER                *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x04))
#define     GPIOB_OSPEEDR               *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x08))
#define     GPIOB_PUPDR                 *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x0C))
#define     GPIOB_IDR                   *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x10))
#define     GPIOB_ODR                   *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x14))
#define     GPIOB_BSRR                  *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x18))
#define     GPIOB_LCKR                  *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x1C))
#define     GPIOB_AFRL                  *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x20))
#define     GPIOB_AFRH                  *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x24))

//GPIOC  Register definitions according to register map
#define     GPIOC_MODER                 *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x00))
#define     GPIOC_OTYPER                *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x04))
#define     GPIOC_OSPEEDR               *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x08))
#define     GPIOC_PUPDR                 *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x0C))
#define     GPIOC_IDR                   *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x10))
#define     GPIOC_ODR                   *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x14))
#define     GPIOC_BSRR                  *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x18))
#define     GPIOC_LCKR                  *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x1C))
#define     GPIOC_AFRL                  *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x20))
#define     GPIOC_AFRH                  *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x24))

//GPIOD  Register definitions according to register map
#define     GPIOD_MODER                 *((volatile u32 *)(GPIOD_BASE_ADDRESS + 0x00))
#define     GPIOD_OTYPER                *((volatile u32 *)(GPIOD_BASE_ADDRESS + 0x04))
#define     GPIOD_OSPEEDR               *((volatile u32 *)(GPIOD_BASE_ADDRESS + 0x08))
#define     GPIOD_PUPDR                 *((volatile u32 *)(GPIOD_BASE_ADDRESS + 0x0C))
#define     GPIOD_IDR                   *((volatile u32 *)(GPIOD_BASE_ADDRESS + 0x10))
#define     GPIOD_ODR                   *((volatile u32 *)(GPIOD_BASE_ADDRESS + 0x14))
#define     GPIOD_BSRR                  *((volatile u32 *)(GPIOD_BASE_ADDRESS + 0x18))
#define     GPIOD_LCKR                  *((volatile u32 *)(GPIOD_BASE_ADDRESS + 0x1C))
#define     GPIOD_AFRL                  *((volatile u32 *)(GPIOD_BASE_ADDRESS + 0x20))
#define     GPIOD_AFRH                  *((volatile u32 *)(GPIOD_BASE_ADDRESS + 0x24))

//GPIOE  Register definitions according to register map
#define     GPIOE_MODER                 *((volatile u32 *)(GPIOE_BASE_ADDRESS + 0x00))
#define     GPIOE_OTYPER                *((volatile u32 *)(GPIOE_BASE_ADDRESS + 0x04))
#define     GPIOE_OSPEEDR               *((volatile u32 *)(GPIOE_BASE_ADDRESS + 0x08))
#define     GPIOE_PUPDR                 *((volatile u32 *)(GPIOE_BASE_ADDRESS + 0x0C))
#define     GPIOE_IDR                   *((volatile u32 *)(GPIOE_BASE_ADDRESS + 0x10))
#define     GPIOE_ODR                   *((volatile u32 *)(GPIOE_BASE_ADDRESS + 0x14))
#define     GPIOE_BSRR                  *((volatile u32 *)(GPIOE_BASE_ADDRESS + 0x18))
#define     GPIOE_LCKR                  *((volatile u32 *)(GPIOE_BASE_ADDRESS + 0x1C))
#define     GPIOE_AFRL                  *((volatile u32 *)(GPIOE_BASE_ADDRESS + 0x20))
#define     GPIOE_AFRH                  *((volatile u32 *)(GPIOE_BASE_ADDRESS + 0x24))

//GPIOH  Register definitions according to register map
#define     GPIOH_MODER                 *((volatile u32 *)(GPIOH_BASE_ADDRESS + 0x00))
#define     GPIOH_OTYPER                *((volatile u32 *)(GPIOH_BASE_ADDRESS + 0x04))
#define     GPIOH_OSPEEDR               *((volatile u32 *)(GPIOH_BASE_ADDRESS + 0x08))
#define     GPIOH_PUPDR                 *((volatile u32 *)(GPIOH_BASE_ADDRESS + 0x0C))
#define     GPIOH_IDR                   *((volatile u32 *)(GPIOH_BASE_ADDRESS + 0x10))
#define     GPIOH_ODR                   *((volatile u32 *)(GPIOH_BASE_ADDRESS + 0x14))
#define     GPIOH_BSRR                  *((volatile u32 *)(GPIOH_BASE_ADDRESS + 0x18))
#define     GPIOH_LCKR                  *((volatile u32 *)(GPIOH_BASE_ADDRESS + 0x1C))
#define     GPIOH_AFRL                  *((volatile u32 *)(GPIOH_BASE_ADDRESS + 0x20))
#define     GPIOH_AFRH                  *((volatile u32 *)(GPIOH_BASE_ADDRESS + 0x24))

// GPIO Mode Setting
#define GPIO_MODER_MASK			        		0b11

// GPIO Out SPEED Reg. Setting mask
#define GPIO_OSPEEDR_MASK		        0b11

// GPIO_PUPDR  state mask
#define GPIO_PUPDR_MASK		            0b11

// GPIO_BSRR Bit Position Offset of Pin to reset
#define GPIO_BSRR_PIN_OFFSET_RESET 		16

// GPIO_IDR Port value mask
#define GPIO_IDR_PORT_MASK		        0x0000FFFF

// GPIO_LCKR Port value Mask to let Port be locked
#define GPIO_LCKR_PORT_LOCKED	0x0001FFFF


#define GPIO_MODER_MASK_PORT			0xFFFF
#define GPIO_OTYPER_MASK_PORT		    0xFFFF
#define GPIO_OSPEEDR_MASK_PORT		    0xFFFF
#define GPIO_ODR_MASK_PORT              0xFFFF
#define GPIO_PUPDR_ZERO                 0x00000000 

#define		PIN_OFFSET					2
#define		GPIO_LCKK16        	        16

#define     AF_MASK					0b1111
#define     AF_BITS_OFFSET			4
#define     AF_HIGH_BITS_OFFSET		8




#endif
