/*
 * SPI_Master.c
 *
 * Created: 8/7/2021 5:16:08 PM
 * Author : Osama Mahmoud
 */ 

#define F_CPU       1000000UL
#include <util/delay.h>

#include "Mem_Map32.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"


void MAX7221_PacketFormat(u8 command , u8 data)
{
	  DIO_WritePin(PINB4 , LOW); // initialize the packet by writing 0 on SS
	  SPDR = command;           // send command first
	  while(CHECK_BIT(SPSR , SPIF) == 0);
	  SPDR = data;              // send data
	  while(CHECK_BIT(SPSR , SPIF) == 0);
	  DIO_WritePin(PINB4 , HIGH); // terminate the packet by writing 1 on SS
}

int main(void)
{
	DIO_Init();
	SPI_voidInit();
	
	u8 counter = 0;
	u8 index_display = 1;
	
	MAX7221_PacketFormat(0x09, 0xFF); // set decoding mode
	MAX7221_PacketFormat(0x0A, 0xFF); // Max intensity
	MAX7221_PacketFormat(0x0B, 0xF7); // set scan limit
	MAX7221_PacketFormat(0x0C, 0x01); // turn on display
	while (1)
	{
		for (index_display = 1; index_display < 9; index_display++)
		MAX7221_PacketFormat(index_display, counter++);
		_delay_ms(1000);
	}
}

