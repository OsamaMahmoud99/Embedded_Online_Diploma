#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


#include "Mem_Map32.h"
#include "Std_types.h"
#include "BIT_MATH.h"



void UART_Init(void);

void UART_SendByte(u8 data);
u8   UART_ReceiveByte(void);



#endif /* UART_H_ */
