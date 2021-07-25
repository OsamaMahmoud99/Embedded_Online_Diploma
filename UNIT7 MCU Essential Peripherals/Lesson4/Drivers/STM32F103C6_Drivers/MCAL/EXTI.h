/*
 * EXTI.h
 *
 *  Created on: Jul 18, 2021
 *      Author: Osama Mahmoud
 */

#ifndef MCAL_EXTI_EXTI_H_
#define MCAL_EXTI_EXTI_H_

#include "STM32F103C6.h"
#include "GPIO.h"

typedef struct
{
	u16     EXTI_Line_Number;
	GPIO_t* GPIO_Port;
	u16     GPIO_PIN;
	u8      IVT_IRQ_Number;

}EXTI_GPIO_Mapping_t;

typedef struct
{
	EXTI_GPIO_Mapping_t EXTI_PIN;                    // Specifies the External interrupt GPIO Mapping.
	                                                 // This parameter must be set based on @ref EXTI_define.

	u8                  EXTI_Mode;                  // Specifies RISING or FALLING or Both trigger.
	                                                // This parameter must be set based on @ref EXTI_Mode_define.

	u8                  IRQ_EN;                     // Enable or Disable the EXTI IRQ (That will Enable IRQ Mask in EXTI and Also on the NVIC
	                                                // This parameter must be set based on @ref EXTI_IRQ_define.

	void(*P_IRQ_CallBack)(void);                    // Set the C Function() which will be called once the IRQ happened.

}EXTI_PinConfig_t ;



//External Interrupt Lines

#define EXTI_LINE0  0
#define EXTI_LINE1  1
#define EXTI_LINE2  2
#define EXTI_LINE3  3

#define EXTI_LINE4  4
#define EXTI_LINE5  5
#define EXTI_LINE6  6
#define EXTI_LINE7  7

#define EXTI_LINE8  8
#define EXTI_LINE9  9
#define EXTI_LINE10 10
#define EXTI_LINE11 11

#define EXTI_LINE12 12
#define EXTI_LINE13 13
#define EXTI_LINE14 14
#define EXTI_LINE15 15


// Reference Macros

//@ref EXTI_define


//EXTI0
#define EXTI0PA0             (EXTI_GPIO_Mapping_t){EXTI_LINE0, GPIOA, PIN0, EXTI0IRQn}
#define EXTI0PB0             (EXTI_GPIO_Mapping_t){EXTI_LINE0, GPIOB, PIN0, EXTI0IRQn}
#define EXTI0PC0             (EXTI_GPIO_Mapping_t){EXTI_LINE0, GPIOC, PIN0, EXTI0IRQn}
#define EXTI0PD0             (EXTI_GPIO_Mapping_t){EXTI_LINE0, GPIOD, PIN0, EXTI0IRQn}


//EXTI1
#define EXTI1PA1             (EXTI_GPIO_Mapping_t){EXTI_LINE1, GPIOA, PIN1, EXTI1IRQn}
#define EXTI1PB1             (EXTI_GPIO_Mapping_t){EXTI_LINE1, GPIOB, PIN1, EXTI1IRQn}
#define EXTI1PC1             (EXTI_GPIO_Mapping_t){EXTI_LINE1, GPIOC, PIN1, EXTI1IRQn}
#define EXTI1PD1             (EXTI_GPIO_Mapping_t){EXTI_LINE1, GPIOD, PIN1, EXTI1IRQn}


//EXTI2
#define EXTI2PA2             (EXTI_GPIO_Mapping_t){EXTI_LINE2, GPIOA, PIN2, EXTI2IRQn}
#define EXTI2PB2             (EXTI_GPIO_Mapping_t){EXTI_LINE2, GPIOB, PIN2, EXTI2IRQn}
#define EXTI2PC2             (EXTI_GPIO_Mapping_t){EXTI_LINE2, GPIOC, PIN2, EXTI2IRQn}
#define EXTI2PD2             (EXTI_GPIO_Mapping_t){EXTI_LINE2, GPIOD, PIN2, EXTI2IRQn}


//EXTI3
#define EXTI3PA3             (EXTI_GPIO_Mapping_t){EXTI_LINE3, GPIOA, PIN3, EXTI3IRQn}
#define EXTI3PB3             (EXTI_GPIO_Mapping_t){EXTI_LINE3, GPIOB, PIN3, EXTI3IRQn}
#define EXTI3PC3             (EXTI_GPIO_Mapping_t){EXTI_LINE3, GPIOC, PIN3, EXTI3IRQn}
#define EXTI3PD3             (EXTI_GPIO_Mapping_t){EXTI_LINE3, GPIOD, PIN3, EXTI3IRQn}


//EXTI4
#define EXTI4PA4             (EXTI_GPIO_Mapping_t){EXTI_LINE4, GPIOA, PIN4, EXTI4IRQn}
#define EXTI4PB4             (EXTI_GPIO_Mapping_t){EXTI_LINE4, GPIOB, PIN4, EXTI4IRQn}
#define EXTI4PC4             (EXTI_GPIO_Mapping_t){EXTI_LINE4, GPIOC, PIN4, EXTI4IRQn}
#define EXTI4PD4             (EXTI_GPIO_Mapping_t){EXTI_LINE4, GPIOD, PIN4, EXTI4IRQn}


//EXTI5
#define EXTI5PA5             (EXTI_GPIO_Mapping_t){EXTI_LINE5, GPIOA, PIN5, EXTI5IRQn}
#define EXTI5PB5             (EXTI_GPIO_Mapping_t){EXTI_LINE5, GPIOB, PIN5, EXTI5IRQn}
#define EXTI5PC5             (EXTI_GPIO_Mapping_t){EXTI_LINE5, GPIOC, PIN5, EXTI5IRQn}
#define EXTI5PD5             (EXTI_GPIO_Mapping_t){EXTI_LINE5, GPIOD, PIN5, EXTI5IRQn}


//EXTI6
#define EXTI6PA6             (EXTI_GPIO_Mapping_t){EXTI_LINE6, GPIOA, PIN6, EXTI6IRQn}
#define EXTI6PB6             (EXTI_GPIO_Mapping_t){EXTI_LINE6, GPIOB, PIN6, EXTI6IRQn}
#define EXTI6PC6             (EXTI_GPIO_Mapping_t){EXTI_LINE6, GPIOC, PIN6, EXTI6IRQn}
#define EXTI6PD6             (EXTI_GPIO_Mapping_t){EXTI_LINE6, GPIOD, PIN6, EXTI6IRQn}


//EXTI7
#define EXTI7PA7             (EXTI_GPIO_Mapping_t){EXTI_LINE7, GPIOA, PIN7, EXTI7IRQn}
#define EXTI7PB7             (EXTI_GPIO_Mapping_t){EXTI_LINE7, GPIOB, PIN7, EXTI7IRQn}
#define EXTI7PC7             (EXTI_GPIO_Mapping_t){EXTI_LINE7, GPIOC, PIN7, EXTI7IRQn}
#define EXTI7PD7             (EXTI_GPIO_Mapping_t){EXTI_LINE7, GPIOD, PIN7, EXTI7IRQn}


//EXTI8
#define EXTI8PA8             (EXTI_GPIO_Mapping_t){EXTI_LINE8, GPIOA, PIN8, EXTI8IRQn}
#define EXTI8PB8             (EXTI_GPIO_Mapping_t){EXTI_LINE8, GPIOB, PIN8, EXTI8IRQn}
#define EXTI8PC8             (EXTI_GPIO_Mapping_t){EXTI_LINE8, GPIOC, PIN8, EXTI8IRQn}
#define EXTI8PD8             (EXTI_GPIO_Mapping_t){EXTI_LINE8, GPIOD, PIN8, EXTI8IRQn}


//EXTI9
#define EXTI9PA9             (EXTI_GPIO_Mapping_t){EXTI_LINE9, GPIOA, PIN9, EXTI9IRQn}
#define EXTI9PB9             (EXTI_GPIO_Mapping_t){EXTI_LINE9, GPIOB, PIN9, EXTI9IRQn}
#define EXTI9PC9             (EXTI_GPIO_Mapping_t){EXTI_LINE9, GPIOC, PIN9, EXTI9IRQn}
#define EXTI9PD9             (EXTI_GPIO_Mapping_t){EXTI_LINE9, GPIOD, PIN9, EXTI9IRQn}


//EXTI10
#define EXTI10PA10             (EXTI_GPIO_Mapping_t){EXTI_LINE10, GPIOA, PIN10, EXTI10IRQn}
#define EXTI10PB10             (EXTI_GPIO_Mapping_t){EXTI_LINE10, GPIOB, PIN10, EXTI10IRQn}
#define EXTI10PC10             (EXTI_GPIO_Mapping_t){EXTI_LINE10, GPIOC, PIN10, EXTI10IRQn}
#define EXTI10PD10             (EXTI_GPIO_Mapping_t){EXTI_LINE10, GPIOD, PIN10, EXTI10IRQn}


//EXTI11
#define EXTI11PA11             (EXTI_GPIO_Mapping_t){EXTI_LINE11, GPIOA, PIN11, EXTI11IRQn}
#define EXTI11PB11             (EXTI_GPIO_Mapping_t){EXTI_LINE11, GPIOB, PIN11, EXTI11IRQn}
#define EXTI11PC11             (EXTI_GPIO_Mapping_t){EXTI_LINE11, GPIOC, PIN11, EXTI11IRQn}
#define EXTI11PD11             (EXTI_GPIO_Mapping_t){EXTI_LINE11, GPIOD, PIN11, EXTI11IRQn}


//EXTI12
#define EXTI12PA12             (EXTI_GPIO_Mapping_t){EXTI_LINE12, GPIOA, PIN12, EXTI12IRQn}
#define EXTI12PB12             (EXTI_GPIO_Mapping_t){EXTI_LINE12, GPIOB, PIN12, EXTI12IRQn}
#define EXTI12PC12             (EXTI_GPIO_Mapping_t){EXTI_LINE12, GPIOC, PIN12, EXTI12IRQn}
#define EXTI12PD12             (EXTI_GPIO_Mapping_t){EXTI_LINE12, GPIOD, PIN12, EXTI12IRQn}


//EXTI13
#define EXTI13PA13             (EXTI_GPIO_Mapping_t){EXTI_LINE13, GPIOA, PIN13, EXTI13IRQn}
#define EXTI13PB13             (EXTI_GPIO_Mapping_t){EXTI_LINE13, GPIOB, PIN13, EXTI13IRQn}
#define EXTI13PC13             (EXTI_GPIO_Mapping_t){EXTI_LINE13, GPIOC, PIN13, EXTI13IRQn}
#define EXTI13PD13             (EXTI_GPIO_Mapping_t){EXTI_LINE13, GPIOD, PIN13, EXTI13IRQn}


//EXTI14
#define EXTI14PA14             (EXTI_GPIO_Mapping_t){EXTI_LINE14, GPIOA, PIN14, EXTI14IRQn}
#define EXTI14PB14             (EXTI_GPIO_Mapping_t){EXTI_LINE14, GPIOB, PIN14, EXTI14IRQn}
#define EXTI14PC14             (EXTI_GPIO_Mapping_t){EXTI_LINE14, GPIOC, PIN14, EXTI14IRQn}
#define EXTI14PD14             (EXTI_GPIO_Mapping_t){EXTI_LINE14, GPIOD, PIN14, EXTI14IRQn}


//EXTI15
#define EXTI15PA15             (EXTI_GPIO_Mapping_t){EXTI_LINE15, GPIOA, PIN15, EXTI15IRQn}
#define EXTI15PB15             (EXTI_GPIO_Mapping_t){EXTI_LINE15, GPIOB, PIN15, EXTI15IRQn}
#define EXTI15PC15             (EXTI_GPIO_Mapping_t){EXTI_LINE15, GPIOC, PIN15, EXTI15IRQn}
#define EXTI15PD15             (EXTI_GPIO_Mapping_t){EXTI_LINE15, GPIOD, PIN15, EXTI15IRQn}


//External Interrupt Modes
//@ref EXTI_Mode_define
#define EXTI_RISING_EDGE    0
#define EXTI_FALLING_EDGE   1
#define EXTI_ON_CHANGE      2

//@ref EXTI_IRQ_define
#define EXTI_IRQ_Enable     1
#define EXTI_IRQ_Disable    0


/*
 * =======================================================================================
 * 							APIs Supported by "MCAL GPIO DRIVER"
 * =======================================================================================
 */

void EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config);
void EXTI_GPIO_DeInit(void);

void EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config);

#endif /* MCAL_EXTI_EXTI_H_ */
