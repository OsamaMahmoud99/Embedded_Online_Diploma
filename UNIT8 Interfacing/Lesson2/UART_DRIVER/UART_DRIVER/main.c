#define  F_CPU          8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "UART_services.h"



u8 X;
u32 Num_Send = 300;
u32 Num_Rec;
u8 Str[] = "Osama";
u8 Str1[10];
int main(void)
{
	DIO_Init();
	LCD_Init();
	UART_Init();
	
	LCD_GoTo( 0 , 0);
	//LCD_WriteSentence("Uart Tr ");
	
	//UART_SendString(Str);
	
	//UART_SendNumberU32(Num_Send);
	
	Num_Rec = UART_ReceiveNumberU32();
	
	LCD_WriteNumber(Num_Rec);
	
	while(1)
	{
		/*UART_ReceiveString(Str1);
		LCD_WriteSentence(Str1);*/
	}
}

