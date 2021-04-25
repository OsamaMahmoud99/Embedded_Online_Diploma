/*
 * PressureSensor.h
 *
 *  Created on: Apr 15, 2021
 *      Author: Osama Mahmoud
 */

#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_

#include "State.h"
#include "driver.h"

enum{
	Reading
}PS_State_Id;

/* Function to get the Pressure Value */
STATE_DEFINE(Reading);

void PS_init(void);

/* Pointer to Function */
extern void (*PS_State)();

#endif /* PRESSURESENSOR_H_ */
