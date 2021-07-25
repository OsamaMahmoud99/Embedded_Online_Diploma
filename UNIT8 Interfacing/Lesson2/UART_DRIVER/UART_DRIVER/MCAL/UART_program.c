#include "UART_interface.h"
#include "LCD.h"

void UART_Init(void)
{
	// transmission speed
	CLEAR_BIT(UCSRA,U2X);   // Normal Speed

	//enable UART  receiver.
	SET_BIT(UCSRB,RXEN);

	//enable UART  transmitter .
	SET_BIT(UCSRB,TXEN);

	//B- 8-Bit data
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	CLEAR_BIT(UCSRB,UCSZ2);

	//Async
	CLEAR_BIT(UCSRC,UMSEL);
	//NO parity
	CLEAR_BIT(UCSRC,UPM0);
	CLEAR_BIT(UCSRC,UPM1);
	// One stop bit
	CLEAR_BIT(UCSRC,USBS);


	// BaudRate 9600 F_cpu = 8MHZ
	UBRRH = 0;
	UBRRL = 51;
}


void UART_SendByte(u8 data)
{
	/*UDRE flag is set when the buffer is empty and ready
	for transmitting a new byte so wait until this flag is set to one 
	and it will cleared by hardware when u write  new data to puffer.*/
	while(!(CHECK_BIT(UCSRA,UDRE)));  
	UDR = data;
}

u8 UART_ReceiveByte(void)
{
	/*RXC flag is set when the UART receive data so  wait until this flag is set to one
	and it will cleared by hardware when u read the data*/
	while(!(CHECK_BIT(UCSRA,RXC)));  
    return UDR;
}










