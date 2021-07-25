#include "UART_services.h"



void UART_SendString(u8 *Str)
{
	u8 i = 0;
	while(Str[i] != '\0')
	{
		UART_SendByte(Str[i]);
		i++;
	}
}

void UART_ReceiveString(u8 *Str)       //receive until 'enter'
{
	u8 i = 0;
	Str[i] = UART_ReceiveByte();
	while(Str[i] != 0x0d)
	{
		i++;
		Str[i] = UART_ReceiveByte();
	}
	Str[i] = '\0';
}

void UART_SendNumberU32(u32 num)
{
	u8 *Ptr = &num;
	UART_SendByte(Ptr[0]);
	UART_SendByte(Ptr[1]);
	UART_SendByte(Ptr[2]);
	UART_SendByte(Ptr[3]);
}
u32  UART_ReceiveNumberU32(void)
{
	u32 Num , Sum = 0;
	u8 *Ptr = &Num;
	
	Ptr[0] = UART_ReceiveByte() - '0';
	Ptr[1] = UART_ReceiveByte() - '0';
	Ptr[2] = UART_ReceiveByte() - '0';
	Ptr[3] = UART_ReceiveByte() - '0';
    
	Sum = Ptr[0]*1000 + Ptr[1]*100 + Ptr[2]*10 + Ptr[3];
	return Sum;
	
	//return Num   /* if we return Num it will convert from HEXa to Decimal */
}



