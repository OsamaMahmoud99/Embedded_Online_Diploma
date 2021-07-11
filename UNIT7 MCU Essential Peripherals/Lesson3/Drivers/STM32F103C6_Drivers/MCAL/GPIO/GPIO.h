/*
 * GPIO.h
 *
 *  Created on: Jul 10, 2021
 *      Author: Osama Mahmoud
 */

#ifndef MCAL_GPIO_GPIO_H_
#define MCAL_GPIO_GPIO_H_

#include "../STM32F103C6_Drivers/LIB/STM32F103C6.h"

/* SET 4PIN as OUTPUT OR INPUT for CRL and CRH
 * SET 8PIN as OUTPUT OR INPUT for CRL and CRH
 * Write a Value on the First4PIN_CRL for ODR
 * Write a Value on the Last 4PIN_CRL for ODR
 * Write a Value on the First4PIN_CRH for ODR
 * Write a Value on the Last 4PIN_CRH for ODR
 */
#define LOW_4PIN_CRL      0
#define HIGH_4PIN_CRL     1
#define LOW_4PIN_CRH      2
#define HIGH_4PIN_CRH     3
#define LOW_8PIN_CRL      4
#define HIGH_8PIN_CRH     5

//GPIO_PIN_state
#define HIGH     1
#define LOW      0

#define GPIOA    0
#define GPIOB    1
#define GPIOC    2

// GPIO_PINS_define
#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7
#define PIN8     8
#define PIN9     9
#define PIN10    10
#define PIN11    11
#define PIN12    12
#define PIN13    13
#define PIN14    14
#define PIN15    15


#define INPUT_ANLOG               0b0000  //CNFy[]=00 Analog mode , MODEy[]=00 Input mode (reset state)
#define INPUT_FLOATING            0b0100  //CNFy[]=01 Floating input , MODEy[]=00 Input mode (reset state)
#define INPUT_PULLUP_PULLDOWN     0b1000  //CNFy[]=10 Input with pull-up / pull-down , MODEy[]=00 Input mode (reset state)

//For Speed 10MHZ
#define OUTPUT_SPEED_10MHZ_PP     0b0001  //MODEy[]=01: Output mode, max speed 10 MHz., CNFy[]=00: General purpose output push-pull
#define OUTPUT_SPEED_10MHZ_OD     0b0101  //MODEy[]=01: Output mode, max speed 10 MHz., CNFy[]=01: General purpose output Open-drain
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001  //MODEy[]=01: Output mode, max speed 10 MHz., CNFy[]=10: Alternate function output Push-pull
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101  //MODEy[]=01: Output mode, max speed 10 MHz., CNFy[]=11: Alternate function output Open-drain

//For Speed 2MHZ
#define OUTPUT_SPEED_2MHZ_PP      0b0010  //MODEy[]=10: Output mode, max speed 2 MHz. , CNFy[]=00: General purpose output push-pull
#define OUTPUT_SPEED_2MHZ_OD      0b0110  //MODEy[]=10: Output mode, max speed 2 MHz. , CNFy[]=01: General purpose output Open-drain
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010  //MODEy[]=10: Output mode, max speed 2 MHz. , CNFy[]=10: Alternate function output Push-pull
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110  //MODEy[]=10: Output mode, max speed 2 MHz. , CNFy[]=11: Alternate function output Open-drain

//For Speed 50MHZ
#define OUTPUT_SPEED_50MHZ_PP     0b0011  //MODEy[]=11: Output mode, max speed 50 MHz., CNFy[]=00: General purpose output push-pull
#define OUTPUT_SPEED_50MHZ_OD     0b0111  //MODEy[]=11: Output mode, max speed 50 MHz., CNFy[]=01: General purpose output Open-drain
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011  //MODEy[]=11: Output mode, max speed 50 MHz., CNFy[]=10: Alternate function output Push-pull
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111  //MODEy[]=11: Output mode, max speed 50 MHz., CNFy[]=11: Alternate function output Open-drain


/*
 * =======================================================================================
 * 							APIs Supported by "MCAL GPIO DRIVER"
 * =======================================================================================
 */

/**================================================================
 * @Fn					-GPIO_SetPinDirection
 * @brief 				-SET the Pin as OUTPUT OR INPUT
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinNumber: specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 			    -void
 * Note				    -none
 */
void GPIO_SetPinDirection   ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode  );

/**================================================================
 * @Fn					-GPIO_SetPinValue
 * @brief 				-write on specific input pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 *@param [in] 			-PinNumber:  specifies the port bit to read. Set by @ref GPIO_PINS_define
 *@param [in] 			-Value: Pin Value
 * @retval 			    -void
 * Note				    -none
 */
void GPIO_SetPinValue       ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value );

/**================================================================
 * @Fn					-GPIO_TogPinValue
 * @brief 				-Toggles the specified GPIO pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinNumber: specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 			    -void
 * Note				    -none
 */
void GPIO_TogPinValue       ( u8 Copy_u8Port , u8 Copy_u8Pin );

/**================================================================
 * @Fn				    -GPIO_GetPinValue
 * @brief 			    -Read Specific PIN
 * @param [in] 	        -GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] 	        -PinNumber: Set Pin Number according @ref GPIO_PINS_define
 * @retval 		        -the input pin value (two values 0 or 1 )
 * Note			        -none
 */
u8   GPIO_GetPinValue       ( u8 Copy_u8Port , u8 Copy_u8Pin );

/**================================================================
 * @Fn					-GPIO_SetPortDirection
 * @brief 				-SET_PORT as OUTPUT OR INPUT depends on the Copy_u8Mode
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 				-void
 * Note					-Also can set 4PIN as a group Or 8PIN
 */
void GPIO_SetPortDirection  ( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode  );

/**================================================================
 * @Fn					-GPIO_SetPortValue
 * @brief 				-write on output port
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 				-void
 * Note					-none
 */
void GPIO_SetPortValue      ( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value );

/**================================================================
 * @Fn					-GPIO_GetPortValue
 * @brief 				-Get the value of 4PIN or 8PIN or All PORT
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 				-void
 * Note					-none
 */
u16  GPIO_GetPortValue      ( u8 Copy_u8Port , u8 Copy_u8Position );



#endif /* MCAL_GPIO_GPIO_H_ */
