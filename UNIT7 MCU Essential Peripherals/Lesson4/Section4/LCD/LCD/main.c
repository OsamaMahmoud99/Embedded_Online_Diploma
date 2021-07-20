/*
 * LCD.c
 *
 * Created: 7/19/2021 1:16:36 PM
 * Author : Osama Mahmoud
 */ 

#define F_CPU  8000000UL
#include "Mem_Map32.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interface.h"


int main(void)
{
	DIO_Init();   // Pins defined as Output or Input from DIO_config.c
	LCD_Init();
    
	LCD_WriteSentence("Learn In depth");
    while (1) 
    {
    }
}

