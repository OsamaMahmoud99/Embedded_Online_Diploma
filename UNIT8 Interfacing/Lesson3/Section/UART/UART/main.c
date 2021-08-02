/*
 * UART.c
 *
 * Created: 8/1/2021 3:17:26 PM
 * Author : Osama Mahmoud
 */ 

#define  F_CPU 8000000UL
#include <util/delay.h>

#include "DIO_interface.h"
#include "UART_interface.h"
#include "UART_services.h"
#include "LCD.h"



int main(void)
{
	sei();
    DIO_Init();
	LCD_Init();
	UART_Init();
	
	
	u8 data , x = 1;
	u8 Str[100];
	/*LCD_WriteSentence("TX");
	LCD_GoTo(1 , 0);
	
	LCD_WriteNumber(x);*/
	//UART_SendString("UART UART");
	
	UART_SendString_Asynch("Osama Mahmoud");
	UART_ReceiveString_Asynch(Str);
		
    while (1) 
    {
		/****************Receive with polling **************/
		/*data = UART_ReceiveByte();
		LCD_GoTo(1 , 5);
		LCD_WriteChar(data);
		
		LCD_GoTo(0 , 5);
		LCD_WriteNumber(x);
		x++;
		if (x == 10)
		{
			x = 0;
		}
		_delay_ms(100);*/
		
		/****************Receive with periodic check **************/
		/*if (UART_ReceiveBytePeriodicCheck(&data))
		{
			LCD_GoTo(1 , 5);
			LCD_WriteChar(data);
		}
		
		LCD_GoTo(0 , 5);
		LCD_WriteNumber(x);
		x++;
		if (x == 10)
		{
			x = 0;
		}
		_delay_ms(100);*/
		
		/****************Receive String**************/
		/*UART_ReceiveString(Str);
		LCD_GoTo(1 , 0);
		LCD_WriteSentence("                 ");
		LCD_GoTo(1 , 0);
		LCD_WriteSentence(Str);
		LCD_GoTo(0 , 5);
		LCD_WriteNumber(x);
		x++;
		if (x == 10)
		{
			x = 0;
		}
		_delay_ms(100);*/
		
		/****************Receive String Asynch**************/
		LCD_GoTo(1 , 0);
		LCD_WriteSentence(Str);
		LCD_GoTo(0 , 5);
		LCD_WriteNumber(x);
		x++;
		if(x == 10){ x = 0;}
		_delay_ms(300);	
		
    }
}

