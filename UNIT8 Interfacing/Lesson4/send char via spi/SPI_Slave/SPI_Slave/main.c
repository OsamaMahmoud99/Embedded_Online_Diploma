/*
 * SPI_Slave.c
 *
 * Created: 8/7/2021 6:30:23 PM
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
	LCD_Init();
    SPI_voidInit();
    
    u8 x = 0;
	u8 y = 0;
	
    while (y < 10) 
    {
		  x = SPI_u8SendReceive(x);
		  LCD_WriteChar(x);
		  y++;
    }
}

