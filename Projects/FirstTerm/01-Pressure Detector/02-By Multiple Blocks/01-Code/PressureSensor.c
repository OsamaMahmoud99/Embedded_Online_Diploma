/*
 * PressureSensor.c
 *
 *  Created on: Apr 15, 2021
 *      Author: Osama Mahmoud
 */

#include "PressureSensor.h"

static int Pressure_Val = 0;

void (*PS_State)();

void PS_init(void)
{
	GPIO_INITIALIZATION();
}

STATE_DEFINE(Reading)
{
	/* Set the Name state of Pressure Sensor in Reading State */
	PS_State_Id = Reading;

	/* Get The Pressure Value and Store It */
	Pressure_Val = getPressureVal();

	/* Send The val to MainAlgorithm */
	Set_PressureVal(Pressure_Val);
}


