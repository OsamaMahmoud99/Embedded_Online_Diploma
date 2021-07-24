#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "UART_interface.h"




void UART_SendString( u8 *Str);
void UART_ReceiveString(u8 *Str); // Receive until press Enter
void UART_SendNumberU32(u32 num);
u32  UART_ReceiveNumberU32(void);






#endif /* UART_SERVICES_H_ */