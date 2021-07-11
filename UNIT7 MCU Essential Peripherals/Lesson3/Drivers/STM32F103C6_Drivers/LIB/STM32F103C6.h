/*
 * STM32F103C6.h
 *
 *  Created on: Jul 10, 2021
 *      Author: Osama Mahmoud
 */

#ifndef STM32F103C6_H_
#define STM32F103C6_H_


//-----------------------------
//Includes
//-----------------------------

#include "stdio.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_Memory_BASE 							0x08000000UL
#define System_Memory_BASE 							0x1FFFF000UL
#define SRAM_Memory_BASE 							0x20000000UL


#define Peripherals_BASE 							0x40000000UL

#define Cortex_M3_Internal_Peripherals_BASE 		0xE0000000UL

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
//RCC
#define RCC_BASE 							        0x40021000UL


//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

//GPIO
//A,B fully included in LQFP48 Package
#define GPIOA_BASE 							        0x40010800UL
#define GPIOB_BASE 							        0x40010C00UL


//C,D Partial  included in LQFP48 Package
#define GPIOC_BASE 							        0x40011000UL
#define GPIOD_BASE 							        0x40011400UL


//E not  included in LQFP48 Package
#define GPIOE_BASE 							        0x40011800UL

//EXTI
#define EXTI_BASE 							        0x40010400UL

//AFIO
#define AFIO_BASE 							        0x40010000UL

//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------


//======================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile u32  CRL  ; // 0x00
	volatile u32  CRH  ; // 0x04
	volatile u32  IDR  ; // 0x08
	volatile u32  ODR  ;
	volatile u32  BSRR ;
	volatile u32  BRR  ;
	volatile u32  LCKR ;

}GPIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile u32  CR       ;
	volatile u32  CFGR     ;
	volatile u32  CIR      ;
	volatile u32  APB2RSTR ;
	volatile u32  APB1RSTR ;
	volatile u32  AHBENR   ;
	volatile u32  APB2ENR  ;
	volatile u32  APB1ENR  ;
	volatile u32  BDCR     ;
	volatile u32  CSR      ;

}RCC_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile u32  IMR   ;
	volatile u32  EMR   ;
	volatile u32  RSTR  ;
	volatile u32  FTSR  ;
	volatile u32  SWIER ;
	volatile u32  PR    ;

}EXTI_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile u32  EVCR      ;
	volatile u32  MAPR      ;
	volatile u32  EXTICR1   ;
	volatile u32  EXTICR2   ;
	volatile u32  EXTICR3   ;
	volatile u32  EXTICR4   ;
	volatile u32  RESERVED0 ;    //0x18
	volatile u32  MAPR2     ;   // 0x1c


}AFIO_t;

//==============================================================


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define MGPIOA      					((GPIO_t *)GPIOA_BASE)
#define MGPIOB      					((GPIO_t *)GPIOB_BASE)
#define MGPIOC      					((GPIO_t *)GPIOC_BASE)
#define MGPIOD      					((GPIO_t *)GPIOD_BASE)
#define MGPIOE      					((GPIO_t *)GPIOE_BASE)

#define RCC      					((RCC_t *)RCC_BASE)

#define EXTI      					((EXTI_t *)EXTI_BASE)

#define AFIO      					((AFIO_t *)AFIO_BASE)


//==============================================================


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1<<6)

#define AFIO_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1<<0)


#endif /* STM32F103C6_H_ */
