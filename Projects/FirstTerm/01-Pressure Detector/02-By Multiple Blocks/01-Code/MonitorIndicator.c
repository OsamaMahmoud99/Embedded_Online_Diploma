/*
 * MonitorIndicator.c
 *
 *  Created on: Apr 15, 2021
 *      Author: Osama Mahmoud
 */

#include "MonitorIndicator.h"

void (*Indicator_State)();

int Indicator_period = 20000;  // 60 Seconds

void High_Pressure_Detected()
{
	Indicator_State = STATE(Start_Indicator);
}
STATE_DEFINE(Stop_Indicator)
{
	Turn_Off();
	Delay(Indicator_period);
	Indicator_State_Id = Indicator_oFF;
	Indicator_State = STATE(Stop_Indicator);
}

STATE_DEFINE(Start_Indicator)
{
	Indicator_State_Id = Indicator_ON;
	
	Turn_On();
	Delay(Indicator_period);
	Turn_Off();
	  
	Indicator_State = STATE(Stop_Indicator);
}

