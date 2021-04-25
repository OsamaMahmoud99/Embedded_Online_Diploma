/*
 * PressureSensor.c
 *
 *  Created on: Apr 15, 2021
 *      Author: Osama Mahmoud
 */

#include "PressureSensor.h"

static int Pressure_Val = 0;
static int Threshold = 20;
//int Period = 20000;

void (*PS_State)();

void PS_init(void)
{
	GPIO_INITIALIZATION();
}

STATE_DEFINE(Reading)
{
	/* Set state of Pressure Sensor in Reading State */
	PS_State_Id = Reading;

	/* Get The Pressure Value and Store It */
	Pressure_Val = getPressureVal();

	if(Pressure_Val > Threshold){
		
		Set_LED(0);
		Delay(5000);
		Set_LED(1);
	}
	else{
		
		Set_LED(1);
	}

}



