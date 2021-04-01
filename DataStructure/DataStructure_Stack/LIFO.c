/*
 * LIFO.c
 *
 *  Created on: Mar 26, 2021
 *      Author: Osama Mahmoud
 */

#include "LIFO.h"

#define     NULL    (void*)0

LIFO_Buf_s LIFO_ECreate(LIFO_Buf_t* Lifo_Buf , unsigned int* Buffer , unsigned int Length)
{
	/* Check if the Buffer is existed or not */
	if(Buffer == NULL)
		return LIFO_NULL;

	Lifo_Buf->Base   = Buffer; // points to the first address of the Buffer
	Lifo_Buf->Head   = Buffer; // points to the first address of the Buffer
	Lifo_Buf->Length = Length;
	Lifo_Buf->Count  = 0;

	return LIFO_NO_ERROR;
}

LIFO_Buf_s LIFO_EIsFull(LIFO_Buf_t* Lifo_Buf)
{
	if(Lifo_Buf->Count == Lifo_Buf->Length)
		return LIFO_FULL;
	else
		return LIFO_NOT_FULL;
}

LIFO_Buf_s LIFO_EIsEmpty(LIFO_Buf_t* Lifo_Buf)
{
	if(Lifo_Buf->Count == 0)
		return LIFO_EMPTY;
	else
		return LIFO_NOT_EMPTY;
}

LIFO_Buf_s LIFO_EPushItem(LIFO_Buf_t* Lifo_Buf , unsigned int Item)
{
	/* Check if the LIFO is existed or not */
	if(Lifo_Buf->Base == NULL || Lifo_Buf->Head == NULL)
		return LIFO_NULL;
	/* Check if LIFO is Full or Not */
	if(LIFO_EIsFull(Lifo_Buf) == LIFO_FULL)
		return LIFO_FULL;

	*(Lifo_Buf->Head) = Item;
	Lifo_Buf->Head++;
	Lifo_Buf->Count++;

	return LIFO_NO_ERROR;

}

LIFO_Buf_s LIFO_EPopItem(LIFO_Buf_t* Lifo_Buf , unsigned int* Item)
{
	/* Check if the LIFO is existed or not */
	if(Lifo_Buf->Base == NULL || Lifo_Buf->Head == NULL)
		return LIFO_NULL;
	/* Check if LIFO is Empty or Not */
	if(LIFO_EIsEmpty(Lifo_Buf) == LIFO_EMPTY)
		return LIFO_EMPTY;

	Lifo_Buf->Head--;
	*Item = *(Lifo_Buf->Head);
	Lifo_Buf->Count--;

	return LIFO_NO_ERROR;

}




