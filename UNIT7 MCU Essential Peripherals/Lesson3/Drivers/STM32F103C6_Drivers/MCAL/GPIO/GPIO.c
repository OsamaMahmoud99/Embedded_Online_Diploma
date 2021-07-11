/*
 * GPIO.c
 *
 *  Created on: Jul 10, 2021
 *      Author: Osama Mahmoud
 */

#include "GPIO.h"

void GPIO_SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		if(Copy_u8Pin <= 7){
			MGPIOA->CRL &= ~((0b1111) << (Copy_u8Pin * 4));     // Clear the Four Bits Of each pin
			MGPIOA->CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4)); // Set 4 Bit of each pin by Copy_u8Mode Value
		}
		else if(Copy_u8Pin <= 15){
			Copy_u8Pin = Copy_u8Pin - 8;
			MGPIOA->CRH &= ~((0b1111) << (Copy_u8Pin * 4));
			MGPIOA->CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		break;
	case GPIOB:
		if(Copy_u8Pin <= 7){
			MGPIOB->CRL &= ~((0b1111) << (Copy_u8Pin * 4));
			MGPIOB->CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else if(Copy_u8Pin <= 15){
			Copy_u8Pin = Copy_u8Pin - 8;
			MGPIOB->CRH &= ~((0b1111) << (Copy_u8Pin * 4));
			MGPIOB->CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		break;
	case GPIOC:
		if(Copy_u8Pin <= 7){
			MGPIOC->CRL &= ~((0b1111) << (Copy_u8Pin * 4));
			MGPIOC->CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else if(Copy_u8Pin <= 15){
			Copy_u8Pin = Copy_u8Pin - 8;
			MGPIOC->CRH &= ~((0b1111) << (Copy_u8Pin * 4));
			MGPIOC->CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		break;
	default:
		break;

	}
}
void GPIO_SetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value )
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		if(Copy_u8Value == HIGH){
			SET_BIT(MGPIOA->ODR , Copy_u8Pin);
		}
		else if(Copy_u8Value == LOW){
			CLEAR_BIT(MGPIOA->ODR , Copy_u8Pin);
		}
		break;
	case GPIOB:
		if(Copy_u8Value == HIGH){
			SET_BIT(MGPIOB->ODR , Copy_u8Pin);
		}
		else if(Copy_u8Value == LOW){
			CLEAR_BIT(MGPIOB->ODR , Copy_u8Pin);
		}
		break;
	case GPIOC:
		if(Copy_u8Value == HIGH){
			SET_BIT(MGPIOC->ODR , Copy_u8Pin);
		}
		else if(Copy_u8Value == LOW){
			CLEAR_BIT(MGPIOC->ODR , Copy_u8Pin);
		}
		break;
	default:
		break;
	}
}
void GPIO_TogPinValue( u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		TOGGLE_BIT(MGPIOA->ODR , Copy_u8Pin);
		break;
	case GPIOB:
		TOGGLE_BIT(MGPIOB->ODR , Copy_u8Pin);
		break;
	case GPIOC:
		TOGGLE_BIT(MGPIOC->ODR , Copy_u8Pin);
		break;
	default:
		break;
	}
}
u8   GPIO_GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Value = 0;
	switch(Copy_u8Port)
	{
	case GPIOA:
		Value = CHECK_BIT(MGPIOA->IDR , Copy_u8Pin);
		break;
	case GPIOB:
		Value = CHECK_BIT(MGPIOB->IDR , Copy_u8Pin);
		break;
	case GPIOC:
		Value = CHECK_BIT(MGPIOC->IDR , Copy_u8Pin);
		break;
	default:
		break;
	}
	return Value;
}

void GPIO_SetPortDirection( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode )
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		if(Copy_u8Position == LOW_8PIN_CRL){
			MGPIOA->CRL = 0x11111111 * Copy_u8Mode;
		}
		else if(Copy_u8Position == HIGH_8PIN_CRH){
			MGPIOA->CRH = 0x11111111 * Copy_u8Mode;
		}
		else if(Copy_u8Position == LOW_4PIN_CRL){
			MGPIOA->CRL = (MGPIOA->CRL & 0xFFFF0000) | ( (0x11111111 * Copy_u8Mode) & 0x0000FFFF);
		}
		else if(Copy_u8Position == HIGH_4PIN_CRL){
			MGPIOA->CRL = (MGPIOA->CRL & 0x0000FFFF) | (( (0x11111111 * Copy_u8Mode) << 16) & 0xFFFF0000);
		}
		else if(Copy_u8Position == LOW_4PIN_CRH){
			MGPIOA->CRH = (MGPIOA->CRH & 0xFFFF0000) | ( (0x11111111 * Copy_u8Mode) & 0x0000FFFF);
		}
		else if(Copy_u8Position == HIGH_4PIN_CRH){
			MGPIOA->CRH = (MGPIOA->CRH & 0x0000FFFF) | (( (0x11111111 * Copy_u8Mode) << 16) & 0xFFFF0000);
		}
		break;
	case GPIOB:
		if(Copy_u8Position == LOW_8PIN_CRL){
			MGPIOB->CRL = 0x11111111 * Copy_u8Mode;
		}
		else if(Copy_u8Position == HIGH_8PIN_CRH){
			MGPIOB->CRH = 0x11111111 * Copy_u8Mode;
		}
		else if(Copy_u8Position == LOW_4PIN_CRL){
			MGPIOB->CRL = (MGPIOB->CRL & 0xFFFF0000) | ( (0x11111111 * Copy_u8Mode) & 0x0000FFFF);
		}
		else if(Copy_u8Position == HIGH_4PIN_CRL){
			MGPIOB->CRL = (MGPIOB->CRL & 0x0000FFFF) | (( (0x11111111 * Copy_u8Mode) << 16) & 0xFFFF0000);
		}
		else if(Copy_u8Position == LOW_4PIN_CRH){
			MGPIOB->CRH = (MGPIOB->CRH & 0xFFFF0000) | ( (0x11111111 * Copy_u8Mode) & 0x0000FFFF);
		}
		else if(Copy_u8Position == HIGH_4PIN_CRH){
			MGPIOB->CRH = (MGPIOB->CRH & 0x0000FFFF) | (( (0x11111111 * Copy_u8Mode) << 16) & 0xFFFF0000);
		}
		break;
	case GPIOC:
		if(Copy_u8Position == LOW_8PIN_CRL){
			MGPIOC->CRL = 0x11111111 * Copy_u8Mode;
		}
		else if(Copy_u8Position == HIGH_8PIN_CRH){
			MGPIOC->CRH = 0x11111111 * Copy_u8Mode;
		}
		else if(Copy_u8Position == LOW_4PIN_CRL){
			MGPIOC->CRL = (MGPIOC->CRL & 0xFFFF0000) | ( (0x11111111 * Copy_u8Mode) & 0x0000FFFF);
		}
		else if(Copy_u8Position == HIGH_4PIN_CRL){
			MGPIOC->CRL = (MGPIOC->CRL & 0x0000FFFF) | (( (0x11111111 * Copy_u8Mode) << 16) & 0xFFFF0000);
		}
		else if(Copy_u8Position == LOW_4PIN_CRH){
			MGPIOC->CRH = (MGPIOC->CRH & 0xFFFF0000) | ( (0x11111111 * Copy_u8Mode) & 0x0000FFFF);
		}
		else if(Copy_u8Position == HIGH_4PIN_CRH){
			MGPIOC->CRH = (MGPIOC->CRH & 0x0000FFFF) | (( (0x11111111 * Copy_u8Mode) << 16) & 0xFFFF0000);
		}
		break;
	default:
		break;
	}
}
void GPIO_SetPortValue( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value )
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		if(Copy_u8Position == LOW_8PIN_CRL){
			MGPIOA->ODR = (MGPIOA->ODR & 0xFF00) |(Copy_u8Value & 0x00FF);
		}
		else if(Copy_u8Position == HIGH_8PIN_CRH){
			MGPIOA->ODR = (MGPIOA->ODR & 0x00FF) |(Copy_u8Value << 8);
		}
		else if(Copy_u8Position == LOW_4PIN_CRL){
			MGPIOA->ODR = (MGPIOA->ODR & 0xFFF0) | ( (u8)Copy_u8Value );
		}
		else if(Copy_u8Position == HIGH_4PIN_CRL){
			MGPIOA->ODR = (MGPIOA->ODR & 0xFF0F) | ( (u8)Copy_u8Value << 4 );
		}
		else if(Copy_u8Position == LOW_4PIN_CRH){
			MGPIOA->ODR = (MGPIOA->ODR & 0xF0FF) | ( (u8)Copy_u8Value << 8 );
		}
		else if(Copy_u8Position == HIGH_4PIN_CRH){
			MGPIOA->ODR = (MGPIOA->ODR & 0x0FFF) | ( (u8)Copy_u8Value << 12 );
		}
		break;
	case GPIOB:
		if(Copy_u8Position == LOW_8PIN_CRL){
			MGPIOB->ODR = (MGPIOB->ODR & 0xFF00) |(Copy_u8Value & 0x00FF);
		}
		else if(Copy_u8Position == HIGH_8PIN_CRH){
			MGPIOB->ODR = (MGPIOB->ODR & 0x00FF) |(Copy_u8Value << 8);
		}
		else if(Copy_u8Position == LOW_4PIN_CRL){
			MGPIOB->ODR = (MGPIOB->ODR & 0xFFF0) | ( (u8)Copy_u8Value );
		}
		else if(Copy_u8Position == HIGH_4PIN_CRL){
			MGPIOB->ODR = (MGPIOB->ODR & 0xFF0F) | ( (u8)Copy_u8Value << 4 );
		}
		else if(Copy_u8Position == LOW_4PIN_CRH){
			MGPIOB->ODR = (MGPIOB->ODR & 0xF0FF) | ( (u8)Copy_u8Value << 8 );
		}
		else if(Copy_u8Position == HIGH_4PIN_CRH){
			MGPIOB->ODR = (MGPIOB->ODR & 0x0FFF) | ( (u8)Copy_u8Value << 12 );
		}
		break;
	case GPIOC:
		if(Copy_u8Position == LOW_8PIN_CRL){
			MGPIOC->ODR = (MGPIOC->ODR & 0xFF00) |(Copy_u8Value & 0x00FF);
		}
		else if(Copy_u8Position == HIGH_8PIN_CRH){
			MGPIOC->ODR = (MGPIOC->ODR & 0x00FF) |(Copy_u8Value << 8);
		}
		else if(Copy_u8Position == LOW_4PIN_CRL){
			MGPIOC->ODR = (MGPIOC->ODR & 0xFFF0) | ( (u8)Copy_u8Value );
		}
		else if(Copy_u8Position == HIGH_4PIN_CRL){
			MGPIOC->ODR = (MGPIOC->ODR & 0xFF0F) | ( (u8)Copy_u8Value << 4 );
		}
		else if(Copy_u8Position == LOW_4PIN_CRH){
			MGPIOC->ODR = (MGPIOC->ODR & 0xF0FF) | ( (u8)Copy_u8Value << 8 );
		}
		else if(Copy_u8Position == HIGH_4PIN_CRH){
			MGPIOC->ODR = (MGPIOC->ODR & 0x0FFF) | ( (u8)Copy_u8Value << 12 );
		}
		break;
	default:
		break;
	}
}
u16  GPIO_GetPortValue( u8 Copy_u8Port , u8 Copy_u8Position)
{
	u16 Value = 0;
	switch(Copy_u8Port)
	{
	case GPIOA:
		if(Copy_u8Position == LOW_8PIN_CRL){
			Value = MGPIOA->IDR & 0x00FF;
		}
		else if(Copy_u8Position == HIGH_8PIN_CRH){
			Value = MGPIOA->IDR & 0xFF00;
		}
		else if(Copy_u8Position == LOW_4PIN_CRL){
			Value = MGPIOA->IDR & 0x000F;
		}
		else if(Copy_u8Position == HIGH_4PIN_CRL){
			Value = MGPIOA->IDR & 0x00F0;
		}
		else if(Copy_u8Position == LOW_4PIN_CRH){
			Value = MGPIOA->IDR & 0x0F00;
		}
		else if(Copy_u8Position == HIGH_4PIN_CRH){
			Value = MGPIOA->IDR & 0xF000;
		}
		break;
	case GPIOB:
		if(Copy_u8Position == LOW_8PIN_CRL){
			Value = MGPIOB->IDR & 0x00FF;
		}
		else if(Copy_u8Position == HIGH_8PIN_CRH){
			Value = MGPIOB->IDR & 0xFF00;
		}
		else if(Copy_u8Position == LOW_4PIN_CRL){
			Value = MGPIOB->IDR & 0x000F;
		}
		else if(Copy_u8Position == HIGH_4PIN_CRL){
			Value = MGPIOB->IDR & 0x00F0;
		}
		else if(Copy_u8Position == LOW_4PIN_CRH){
			Value = MGPIOB->IDR & 0x0F00;
		}
		else if(Copy_u8Position == HIGH_4PIN_CRH){
			Value = MGPIOB->IDR & 0xF000;
		}
		break;
	case GPIOC:
		if(Copy_u8Position == LOW_8PIN_CRL){
			Value = MGPIOC->IDR & 0x00FF;
		}
		else if(Copy_u8Position == HIGH_8PIN_CRH){
			Value = MGPIOC->IDR & 0xFF00;
		}
		else if(Copy_u8Position == LOW_4PIN_CRL){
			Value = MGPIOC->IDR & 0x000F;
		}
		else if(Copy_u8Position == HIGH_4PIN_CRL){
			Value = MGPIOC->IDR & 0x00F0;
		}
		else if(Copy_u8Position == LOW_4PIN_CRH){
			Value = MGPIOC->IDR & 0x0F00;
		}
		else if(Copy_u8Position == HIGH_4PIN_CRH){
			Value = MGPIOC->IDR & 0xF000;
		}
		break;
	default:
		break;
	}
	return Value;
}
