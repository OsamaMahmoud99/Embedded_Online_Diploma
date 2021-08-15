/*
 * KEYPAD.c
 *
 *  Created on: Jul 10, 2021
 *      Author: Osama Mahmoud
 */

#include "KEYPAD.h"

#ifdef keypad4X4_KIT
static u8  keypadchars[4][4] = {       {'1','2','3','a'},
		{'4','5','6','b'},
		{'7','8','9','c'},
		{'*','0','#','d'}
};
#elif defined(keypad4X4_PROTEUS)
static u8   keypadchars[4][4] = {{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'a','0','=','+'}};
#elif defined (Design)
static u8   keypadchars[4][3] = {       {'1','2','3'},
		{'4','5','6'},
		{'7','8','9'},
		{'*','0','#'}};

#endif

u8 Keypad_Row[] = {R0 , R1 , R2 , R3};
u8 Keypad_Col[] = {C0 , C1 , C2 , C3};

void delay_ms(unsigned int Time){
	unsigned int i = 0 , j = 0;
	for(i=0; i<Time; ++i){
		for(j=0; j<255; ++j);
	}
}

void KEYPAD_Init(void)
{
	// the upper part(Raws) Output
	GPIO_SetPinDirection(KEYPAD_PORT, R0, OUTPUT_SPEED_10MHZ_PP);
	GPIO_SetPinDirection(KEYPAD_PORT, R1, OUTPUT_SPEED_10MHZ_PP);
	GPIO_SetPinDirection(KEYPAD_PORT, R2, OUTPUT_SPEED_10MHZ_PP);
	GPIO_SetPinDirection(KEYPAD_PORT, R3, OUTPUT_SPEED_10MHZ_PP);
	// the lower part(Columns) Output
	GPIO_SetPinDirection(KEYPAD_PORT, C0, OUTPUT_SPEED_10MHZ_PP);
	GPIO_SetPinDirection(KEYPAD_PORT, C1, OUTPUT_SPEED_10MHZ_PP);
	GPIO_SetPinDirection(KEYPAD_PORT, C2, OUTPUT_SPEED_10MHZ_PP);
	GPIO_SetPinDirection(KEYPAD_PORT, C3, OUTPUT_SPEED_10MHZ_PP);

	// Row and Columns High
	GPIO_SetPortValue(KEYPAD_PORT, LOW_8PIN_CRL, 0xFF);
	GPIO_SetPinValue(KEYPAD_PORT, C3, HIGH);
}

u8 KEYPAD_GetChar(void)
{
	u8 col = 0;      //counter for loop
	u8 row = 0;      //get value of row
	u8 key = 'N' ;

	for (col=0; col<COL_NUM; ++col)
	{
		GPIO_SetPinValue(KEYPAD_PORT, Keypad_Col[0] , HIGH);
		GPIO_SetPinValue(KEYPAD_PORT, Keypad_Col[1] , HIGH);
		GPIO_SetPinValue(KEYPAD_PORT, Keypad_Col[2] , HIGH);
		GPIO_SetPinValue(KEYPAD_PORT, Keypad_Col[3] , HIGH);
		GPIO_SetPinValue(KEYPAD_PORT, Keypad_Col[col] , LOW);
		delay_ms(10);

		for(row=0; row < COL_NUM; ++row)
		{
			if(GPIO_GetPinValue(KEYPAD_PORT, Keypad_Row[row]) == 0)    // Check if key is pressed
			{
				while( GPIO_GetPinValue(KEYPAD_PORT, Keypad_Row[row]) == 0);  // wait for key to be released

				switch(col)
				{
				case 0:
					if(row == 0) key = keypadchars[0][0];
					else if(row == 1) key = keypadchars[1][0];
					else if(row == 2) key = keypadchars[2][0];
					else if(row == 3) key = keypadchars[3][0];
					break;
				case 1:
					if(row == 0) key = keypadchars[0][1];
					else if(row == 1) key = keypadchars[1][1];
					else if(row == 2) key = keypadchars[2][1];
					else if(row == 3) key = keypadchars[3][1];
					break;
				case 2:
					if(row == 0) key = keypadchars[0][2];
					else if(row == 1) key = keypadchars[1][2];
					else if(row == 2) key = keypadchars[2][2];
					else if(row == 3) key = keypadchars[3][2];
					break;
				case 3:
					if(row == 0) key = keypadchars[0][3];
					else if(row == 1) key = keypadchars[1][3];
					else if(row == 2) key = keypadchars[2][3];
					else if(row == 3) key = keypadchars[3][3];
					break;
				}
			}
		}
	}
	return key;
}



