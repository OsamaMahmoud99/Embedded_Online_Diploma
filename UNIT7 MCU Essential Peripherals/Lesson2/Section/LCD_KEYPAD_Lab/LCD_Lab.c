/*
 * LCD.c
 *
 * Created: 7/7/2021 5:35:56 PM
 * Author : Osama Mahmoud
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "LCD_interface.h"

int main(void)
{
    LCD_Init();
	KEYPAD_voidInit();

    while (1) 
    {
		LCD_WriteSentence("My Name Is Osama Mahmoud, Student at Electrical Engineering");
		LCD_Clear();
		LCD_WriteSentence("Numbers Examples:");
		LCD_WriteRealNumber(30.127);
		LCD_WriteSentence("  ");
		LCD_WriteNumber(12);
		LCD_Clear();
		_delay_ms(1000);
    }
}

