/*
 * main.c
 *
 *  Created on: Mar 26, 2021
 *      Author: Osama Mahmoud
 */

#include "stdio.h"
#include "FIFO.h"

int main()
{
	FIFO_Buf_t FIFO_UART;
	ELEMENT_TYPE i ,Temp;

	if(FIFO_ECreate(&FIFO_UART, Buff, LENGTH) == FIFO_NO_ERROR){
		printf("FIFO Create --------Done \n");
	}

	for(i=0; i<7; ++i){
		printf("FIFO Enqueue (%x)\n",i);
		if(FIFO_EEnQueue(&FIFO_UART, i) == FIFO_NO_ERROR){
			printf("\t FIFO Enqueue------Done\n");
		}
		else{
			printf("\t FIFO Enqueue------Failed\n");
		}
	}
	/* Print the Elements */
	FIFO_vPrint(&FIFO_UART);

	if(FIFO_EDeQueue(&FIFO_UART, &Temp) == FIFO_NO_ERROR){
		printf("FIFO Dequeue(%x)------Done\n",Temp);
	}
	if(FIFO_EDeQueue(&FIFO_UART, &Temp) == FIFO_NO_ERROR){
		printf("FIFO Dequeue(%x)------Done\n",Temp);
	}
	/* Print the Elements after remove two elements */
	FIFO_vPrint(&FIFO_UART);

	return 0;
}


