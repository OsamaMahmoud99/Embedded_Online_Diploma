#include "Uart.h"


unsigned char  Str[100] = "Learn_In_Depth:<Osama Mahmoud>";
int main()
{
	
	UART_SendString(Str);
	
	while(1)
	{
		
	}
}