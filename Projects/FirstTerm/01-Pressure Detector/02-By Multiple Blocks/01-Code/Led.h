/*
 * Led.h
 *
 *  Created on: Apr 15, 2021
 *      Author: Osama Mahmoud
 */

#ifndef LED_H_
#define LED_H_


#include "State.h"
#include "driver.h"

enum{
	LED_OFF,
	LED_ON,
}LED_State_Id;

extern void Turn_On();
extern void Turn_Off();

void LED_init(void);

#endif /* LED_H_ */
