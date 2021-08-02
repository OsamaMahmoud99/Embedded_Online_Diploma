#include "UART_services.h"

static void Func_TX(void);
static void Func_RX(void);

/**********************************************variables*******************************************************/

static volatile  u8 flag=1;
static u8  *Asynch_Send_Str;
static u8  *Asynch_receive_str;

/*******************************************Send Functions*****************************************************/

void UART_SendString(u8 *Str)
{
	u8 i = 0;
	while(Str[i] != '\0')
	{
		UART_SendByte(Str[i]);
		i++;
	}
}

void UART_SendString_Asynch(u8 *Str)
{
	Asynch_Send_Str=Str;
	UART_SendByteNoBlock(Str[0]);

	UART_TX_SetCallBack(Func_TX);
	UART_TX_InterruptEnable();

}

static void Func_TX(void)
{
	static u8 i=1;
	if(Asynch_Send_Str[i] !='\0')
	{
		UART_SendByteNoBlock(Asynch_Send_Str[i]);
		i++;
	}
	else
	{
		i=1;
		//UART_TX_InterruptDisable();
	}
}

void UART_SendNumberU32(u32 num)
{
	u8 *Ptr = &num;
	UART_SendByte(Ptr[0]);
	UART_SendByte(Ptr[1]);
	UART_SendByte(Ptr[2]);
	UART_SendByte(Ptr[3]);
}


/*****************************************Receive Functions*****************************************************/

void UART_ReceiveString(u8 *Str)       //receive until 'enter'
{
	/*u8 i = 0;
	Str[i] = UART_ReceiveByte();
	while(Str[i] != 0x0d)
	{
		i++;
		Str[i] = UART_ReceiveByte();
	}
	Str[i] = '\0';*/
	
	u8 i = 0;
	
	do 
	{
		Str[i] = UART_ReceiveByte();
		
	} while (Str[i++] != 0x0d);
	Str[i - 1] = '\0'; 
}

void UART_ReceiveString_Asynch(u8 *Str)
{
	Asynch_receive_str = Str;
	UART_RX_SetCallBack(Func_RX);
	UART_RX_InterruptEnable();
}

void Func_RX(void)
{
	u8 static i = 0;
	
	Asynch_receive_str[i++] = UART_ReceiveByteNoBlock();
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




