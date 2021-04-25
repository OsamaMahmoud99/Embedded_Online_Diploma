#include <stdint.h>
#include <stdio.h>

#include "PressureSensor.h"


int main (){


	PS_init();
	PS_State = STATE(Reading);
	

	while (1)
	{
		PS_State();
	}

}
