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
#include "KEYPAD_interface.h"
#include "SPI_interface.h"



int main(void)
{
	DIO_Init();
	KEYPAD_voidInit();
	SPI_voidInit();
	
	
	while (1)
	{
		u8 data = KEYPAD_u8GetPressed();
		SPI_u8SendReceive(data);
	}
}

