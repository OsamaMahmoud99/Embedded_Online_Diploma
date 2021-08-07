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
	
	u8 ch = 0 , data;
	
	for(ch=0; ch<=255; ++ch){
		_delay_ms(1000);
		data = SPI_u8SendReceive(ch);
		DIO_WritePort(PA , data);
	}
	
	
    while (1) 
    {
    }
}

