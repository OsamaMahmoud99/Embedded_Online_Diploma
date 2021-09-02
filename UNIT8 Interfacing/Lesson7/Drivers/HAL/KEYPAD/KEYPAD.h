/*
 * KEYPAD.h
 *
 *  Created on: Jul 10, 2021
 *      Author: Osama Mahmoud
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "GPIO.h"

/****** keypad4X4_KIT
        keypad4X4_PROTEUS
        Design
                            ******/
#define  keypad4X4_PROTEUS

#define   COL_NUM  4

#define   R0  PIN0
#define   R1  PIN1
#define   R2  PIN3
#define   R3  PIN4
#define   C0  PIN5
#define   C1  PIN6
#define   C2  PIN7
#define   C3  PIN8


#define   KEYPAD_PORT        GPIOB




void KEYPAD_Init(void);
u8   KEYPAD_GetChar(void);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
