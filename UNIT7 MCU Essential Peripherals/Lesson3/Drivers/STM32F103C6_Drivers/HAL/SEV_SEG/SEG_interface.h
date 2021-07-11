/***************************************************/
/* Author : Osama Mahmoud                          */
/* Date   : 2/11/2020                              */
/***************************************************/
#ifndef  SEG_INTERFACE_H
#define  SEG_INTERFACE_H




#include "GPIO.h"


#include "SEG_config.h"
#include "SEG_private.h"

#define  CATHODE   0
#define  ANODE     1


void SEG_voidInit(u8 Copy_u8DisplayID);
void SEG_voidDisplayNumber(u8 Copy_u8DisplayID , u8 Copy_u8DisplayNumber);

#endif
