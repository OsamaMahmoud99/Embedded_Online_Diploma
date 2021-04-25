/*
 * Led.c
 *
 *  Created on: Apr 15, 2021
 *      Author: Osama Mahmoud
 */

#include "Led.h"
#include "MonitorIndicator.h"


void LED_init(void)
{
	GPIO_INITIALIZATION();
}

void Turn_On()
{
	LED_State_Id = LED_ON;
	Set_LED(0);
}
void Turn_Off()
{
	LED_State_Id = LED_OFF;
	Set_LED(1);
}