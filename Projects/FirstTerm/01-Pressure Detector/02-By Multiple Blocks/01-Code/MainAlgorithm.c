/*
 * MainAlgorithm.c
 *
 *  Created on: Apr 15, 2021
 *      Author: Osama Mahmoud
 */

#include "MainAlgorithm.h"
#include "PressureSensor.h"

static int Pressure_Val = 0;

static int Threshold = 20;  // 20bar

void (*Main_State)();

void Set_PressureVal(int P_Val)
{
	Pressure_Val = P_Val;
	Main_State = STATE(HIGH_Pressure_State);
}

STATE_DEFINE(HIGH_Pressure_State)
{
	
	if(Pressure_Val <= Threshold){
		
		Main_State = STATE(HIGH_Pressure_State);
	}
	else{
		High_Pressure_Detected();
		Main_State = STATE(HIGH_Pressure_State);
	}
}

