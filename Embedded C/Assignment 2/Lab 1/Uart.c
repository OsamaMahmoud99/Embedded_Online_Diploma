#include "Uart.h"


void UART_SendString(unsigned char *Str)
{
	while(*Str != '\0')
	{
		UARTDR = *Str;
		Str++;
	}
}