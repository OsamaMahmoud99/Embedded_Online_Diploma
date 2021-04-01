/*
 * main.c
 *
 *  Created on: Mar 26, 2021
 *      Author: Osama Mahmoud
 */

#include "stdio.h"
#include "stdlib.h"
#include "LIFO.h"

#define LENGTH_BUFFER1   5
#define LENGTH_BUFFER2   5

unsigned int Buffer1[LENGTH_BUFFER1];


int main()
{
	unsigned int Temp = 0 , i;
	LIFO_Buf_t UART_LIFO , I2C_LIFO;

	/* Static Allocation */
	LIFO_ECreate(&UART_LIFO, Buffer1 , LENGTH_BUFFER1);

	/* Dynamic Allocation */
	unsigned int *Buffer2 = (unsigned int *)malloc(LENGTH_BUFFER2 * sizeof(unsigned int));
	LIFO_ECreate(&I2C_LIFO, Buffer2 , LENGTH_BUFFER2);

	for(i=0; i<LENGTH_BUFFER1; ++i){
		if( ( LIFO_EPushItem(&UART_LIFO, i) ) == LIFO_NO_ERROR){
			printf("UART_LIFO Push  : %d \n",i);
		}

	}
    printf("=====================\n");
	for(i=0; i<LENGTH_BUFFER1; ++i){
		if( ( LIFO_EPopItem(&UART_LIFO, &Temp) ) == LIFO_NO_ERROR){
			printf("UART_LIFO Pop  : %d \n",Temp);
		}

	}
	return 0;
}


