/*
 * MonitorIndicator.h
 *
 *  Created on: Apr 15, 2021
 *      Author: Osama Mahmoud
 */

#ifndef MONITORINDICATOR_H_
#define MONITORINDICATOR_H_

#include "State.h"
#include "driver.h"

enum{
	Indicator_ON,
	Indicator_oFF
}Indicator_State_Id;

STATE_DEFINE(Start_Indicator);
STATE_DEFINE(Stop_Indicator);

extern void (*Indicator_State)();

#endif /* MONITORINDICATOR_H_ */
