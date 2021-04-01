/*
 * FIFO.h
 *
 *  Created on: Mar 26, 2021
 *      Author: Osama Mahmoud
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"


/* Select Element Type:
 * uint8_t , uint16_t , uint32_t
 */
#define ELEMENT_TYPE   uint8_t

/* Create Buffer */
#define LENGTH  5
ELEMENT_TYPE Buff[LENGTH];

typedef struct{
	unsigned int  Length;
	unsigned int  Count;
	ELEMENT_TYPE* Base;
	ELEMENT_TYPE* Head;
	ELEMENT_TYPE* Tail;
}FIFO_Buf_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_NOT_FULL,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_NULL
}FIFO_Buf_s;

/*
	Function Name        : FIFO_ECreate
	Function Returns     : Enum
	Function Arguments   : Pointer to struct Lifo_Buf,Pointer to ELEMENT_TYPE Buffer,unsigned int Length
	Function Description : Create the the Queue to Add data.
 */
FIFO_Buf_s FIFO_ECreate(FIFO_Buf_t* FIFO_Buf , ELEMENT_TYPE* Buffer , uint32_t Length);

/*
	Function Name        : FIFO_EIsFull
	Function Returns     : Enum
	Function Arguments   : Pointer to struct Lifo_Buf
	Function Description : Check if Queue Is full or not
 */
FIFO_Buf_s FIFO_EIsFull(FIFO_Buf_t* FIFO_Buf);

/*
	Function Name        : FIFO_EIsEmpty
	Function Returns     : Enum
	Function Arguments   : Pointer to struct Lifo_Buf
	Function Description : Check if Queue Is Empty or not
 */
FIFO_Buf_s FIFO_EIsEmpty(FIFO_Buf_t* FIFO_Buf);

/*
	Function Name        : FIFO_EEnQueue
	Function Returns     : Enum
	Function Arguments   : Pointer to struct Lifo_Buf,ELEMENT_TYPE Item
	Function Description : Add an Item in the Queue.
 */
FIFO_Buf_s FIFO_EEnQueue(FIFO_Buf_t* FIFO_Buf , ELEMENT_TYPE Item);

/*
	Function Name        : FIFO_EDeQueue
	Function Returns     : Enum
	Function Arguments   : Pointer to struct Lifo_Buf,Pointer to `ELEMENT_TYPE Item
	Function Description : Remove an Item from the Queue.
 */
FIFO_Buf_s FIFO_EDeQueue(FIFO_Buf_t* FIFO_Buf , ELEMENT_TYPE* Item);

/*
	Function Name        : FIFO_vPrint
	Function Returns     : void
	Function Arguments   : Pointer to struct Lifo_Buf
	Function Description : Print the elemets in the Queue.
 */
void FIFO_vPrint(FIFO_Buf_t* FIFO_Buf);


#endif /* FIFO_H_ */
