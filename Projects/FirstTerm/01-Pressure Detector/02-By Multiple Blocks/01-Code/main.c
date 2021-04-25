#include <stdint.h>
#include <stdio.h>

#include "PressureSensor.h"
#include "MainAlgorithm.h"
#include "MonitorIndicator.h"
#include "Led.h"


int main ()
{
	/* Init of pressure sensor Block */
	PS_init();

    PS_State        = STATE(Reading); 
	Main_State      = STATE(HIGH_Pressure_State);
	Indicator_State = STATE(Stop_Indicator);

	while (1)
	{
		PS_State();          // Calling pressure sensor Block
		Main_State();        // Calling the Main Algorithm Block
	    Indicator_State();   // Calling the Indicator_Monitor Block
	}

}
