#ifndef UART_H_
#define UART_H_


#define UARTDR   *((volatile unsigned int *)((unsigned int *)0x101f1000))

void UART_SendString(unsigned char *Str);

#endif