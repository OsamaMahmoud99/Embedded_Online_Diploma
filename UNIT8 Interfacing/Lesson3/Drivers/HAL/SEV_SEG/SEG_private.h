/***************************************************/
/* Author : Osama Mahmoud                          */
/* Date   : 2/11/2020                              */
/***************************************************/
#ifndef SEG_PRIVATE_H
#define SEG_PRIVATE_H



typedef struct{
	
	u8 SEG_MODE;
	u8 SEG_PINA;
	u8 SEG_GPIOA;
	u8 SEG_PINB;
	u8 SEG_GPIOB;
	u8 SEG_PINC;
	u8 SEG_GPIOC;
	u8 SEG_PIND;
	u8 SEG_GPIOD;
	u8 SEG_PINE;
	u8 SEG_GPIOE;
	u8 SEG_PINF;
	u8 SEG_GPIOF;
	u8 SEG_PING;
	u8 SEG_GPIOG;
	//u8 SEG_PINDot;
	//u8 SEG_GPIODot;
	
}SEG_PinMap;

extern SEG_PinMap    SEG_PINMAP[Copy_u8SEGNumber];











#endif
