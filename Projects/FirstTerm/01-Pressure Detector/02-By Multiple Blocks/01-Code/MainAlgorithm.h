/*
 * MainAlgorithm.h
 *
 *  Created on: Apr 15, 2021
 *      Author: Osama Mahmoud
 */

#ifndef MAINALGORITHM_H_
#define MAINALGORITHM_H_

#include "State.h"
#include "stdio.h"

typedef enum{
	HIGH_Pressure_State
}Pressure_State_Id;

void Set_PressureVal(int P_Val);
extern void High_Pressure_Detected();
STATE_DEFINE(HIGH_Pressure_State);

extern void (*Main_State)();

#endif /* MAINALGORITHM_H_ */

