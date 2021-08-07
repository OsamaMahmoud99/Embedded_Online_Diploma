/*
 * SPI_Master.c
 *
 * Created: 8/7/2021 5:16:08 PM
 * Author : Osama Mahmoud
 */ 

#define F_CPU       8000000UL
#include <util/delay.h>

#include "Mem_Map32.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"



int main(void)
{
	DIO_Init();
	SPI_voidInit();
	
	u8 counter = 0;
	while (counter < 10)
	{
		SPI_u8SendReceive(counter+48);
		_delay_ms(300);
		counter++;	
	}
}

