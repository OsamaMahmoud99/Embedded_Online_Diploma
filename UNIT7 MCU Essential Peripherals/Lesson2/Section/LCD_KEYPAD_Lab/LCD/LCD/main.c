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
#include "KEYPAD_interface.h"

int main(void)
{
    LCD_Init();
	KEYPAD_voidInit();
    
	u8 Key_Pressed;
	
    while (1) 
    {
		Key_Pressed = KEYPAD_u8GetChar();
		switch(Key_Pressed)
		{
			case 'N':  // do nothing if key no pressed
			  break;
			case 'a': 
			  LCD_Clear();
			  break;
			default:
			  LCD_WriteChar(Key_Pressed);  // write key_pressed on lcd
		}
    }
}

