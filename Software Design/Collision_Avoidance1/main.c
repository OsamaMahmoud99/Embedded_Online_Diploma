/*
 * main.c
 *
 *  Created on: Apr 2, 2021
 *      Author: Osama Mahmoud
 */

#include "CA.h"


void Setup()
{
	/* init all drivers */
	/* inti IRQ */
	/* init HAL Drivers */
	/* init Block */
	/* Set State pointer for each block */
	CA_state = STATE(CA_waiting);
}
int main()
{
	Setup();

	while(1)
	{
		/* Call state for each block */
		CA_state();

	}
	return 0;
}


