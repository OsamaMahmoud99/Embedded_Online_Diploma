/***************************************************/
/* Author : Osama Mahmoud                          */
/* Date   : 2/11/2020                              */
/***************************************************/

#include "SEG_interface.h"


void SEG_voidInit(u8 Copy_u8DisplayID)
{
	GPIO_SetPinDirection(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOA, SEG_PINMAP[Copy_u8DisplayID].SEG_PINA, OUTPUT_SPEED_10MHZ_PP);
	GPIO_SetPinDirection(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOB, SEG_PINMAP[Copy_u8DisplayID].SEG_PINB, OUTPUT_SPEED_10MHZ_PP);
	GPIO_SetPinDirection(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOC, SEG_PINMAP[Copy_u8DisplayID].SEG_PINC, OUTPUT_SPEED_10MHZ_PP);
	GPIO_SetPinDirection(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOD, SEG_PINMAP[Copy_u8DisplayID].SEG_PIND, OUTPUT_SPEED_10MHZ_PP);
	GPIO_SetPinDirection(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOE, SEG_PINMAP[Copy_u8DisplayID].SEG_PINE, OUTPUT_SPEED_10MHZ_PP);
	GPIO_SetPinDirection(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOF, SEG_PINMAP[Copy_u8DisplayID].SEG_PINF, OUTPUT_SPEED_10MHZ_PP);
	GPIO_SetPinDirection(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOG, SEG_PINMAP[Copy_u8DisplayID].SEG_PING, OUTPUT_SPEED_10MHZ_PP);
}

void SEG_voidDisplayNumber(u8 Copy_u8DisplayID , u8 Copy_u8DisplayNumber)
{
	static u8 SEG_DataNumber[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

	if(SEG_PINMAP[Copy_u8DisplayID].SEG_MODE == CATHODE)
	{
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOA, SEG_PINMAP[Copy_u8DisplayID].SEG_PINA, CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],0));
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOB, SEG_PINMAP[Copy_u8DisplayID].SEG_PINB, CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],1));
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOC, SEG_PINMAP[Copy_u8DisplayID].SEG_PINC, CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],2));
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOD, SEG_PINMAP[Copy_u8DisplayID].SEG_PIND, CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],3));
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOE, SEG_PINMAP[Copy_u8DisplayID].SEG_PINE, CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],4));
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOF, SEG_PINMAP[Copy_u8DisplayID].SEG_PINF, CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],5));
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOG, SEG_PINMAP[Copy_u8DisplayID].SEG_PING, CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],6));
		//GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIODot, SEG_PINMAP[Copy_u8DisplayID].SEG_PINDot, CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],7));
	}
	else if(SEG_PINMAP[Copy_u8DisplayID].SEG_MODE == ANODE)
	{
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOA, SEG_PINMAP[Copy_u8DisplayID].SEG_PINA, ~CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],0));
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOB, SEG_PINMAP[Copy_u8DisplayID].SEG_PINB, ~CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],1));
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOC, SEG_PINMAP[Copy_u8DisplayID].SEG_PINC, ~CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],2));
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOD, SEG_PINMAP[Copy_u8DisplayID].SEG_PIND, ~CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],3));
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOE, SEG_PINMAP[Copy_u8DisplayID].SEG_PINE, ~CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],4));
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOF, SEG_PINMAP[Copy_u8DisplayID].SEG_PINF, ~CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],5));
		GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIOG, SEG_PINMAP[Copy_u8DisplayID].SEG_PING, ~CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],6));
		//GPIO_SetPinValue(SEG_PINMAP[Copy_u8DisplayID].SEG_GPIODot, SEG_PINMAP[Copy_u8DisplayID].SEG_PINDot, ~CHECK_BIT(SEG_DataNumber[Copy_u8DisplayNumber],7));
	}
}





