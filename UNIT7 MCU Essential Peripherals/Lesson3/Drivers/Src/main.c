/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Osama Mahmoud
 * @brief          : Main program body
 ******************************************************************************
 */

#include "STM32F103C6.h"
#include "GPIO.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "SEG_interface.h"

int main(void)
{
	/* Enable GPIOA Clock */
	RCC_GPIOA_CLK_EN();
	/* Enable GPIOB Clock */
	RCC_GPIOB_CLK_EN();

	LCD_Init();
	SEG_voidInit(0);
	u8 Key_Pressed = 0;
	u8 LCD_Char[]={'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'};
	u8 i = 0;
	for(i=0; i<9; ++i){
		SEG_voidDisplayNumber(0, i);
		LCD_WriteChar(LCD_Char[i]);
		_delay_ms(1000);
	}

	if(i == 9)
	{
		KEYPAD_Init();
		LCD_Clear();
		LCD_WriteSentence((u8*)"Keypad is ready");
		_delay_ms(1000);
		LCD_Clear();
	}
	while(1){


		Key_Pressed = KEYPAD_GetChar();

		switch(Key_Pressed)
		{
		case 'a':
			LCD_Clear();
			break;
		case 'N':
			break;
		default:
			LCD_WriteChar(Key_Pressed);
			break;
		}


	}
}
