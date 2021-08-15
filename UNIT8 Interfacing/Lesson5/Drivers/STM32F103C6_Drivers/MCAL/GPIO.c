/*
 * GPIO.c
 *
 *  Created on: Jul 10, 2021
 *      Author: Osama Mahmoud
 */

#include "GPIO.h"

void GPIO_SetPinDirection(GPIO_t* GPIOx , u8 Copy_u8Pin , u8 Copy_u8Mode)
{

	if(Copy_u8Pin <= 7){
		GPIOx->CRL &= ~((0b1111) << (Copy_u8Pin * 4));     // Clear the Four Bits Of each pin
		GPIOx->CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4)); // Set 4 Bit of each pin by Copy_u8Mode Value
	}
	else if(Copy_u8Pin <= 15){
		Copy_u8Pin = Copy_u8Pin - 8;
		GPIOx->CRH &= ~((0b1111) << (Copy_u8Pin * 4));
		GPIOx->CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
	}

}
void GPIO_SetPinValue( GPIO_t* GPIOx , u8 Copy_u8Pin , u8 Copy_u8Value )
{
	if(Copy_u8Value == HIGH){
		SET_BIT(GPIOx->ODR , Copy_u8Pin);
	}
	else if(Copy_u8Value == LOW){
		CLEAR_BIT(GPIOx->ODR , Copy_u8Pin);
	}
}
void GPIO_TogPinValue( GPIO_t* GPIOx , u8 Copy_u8Pin)
{

	TOGGLE_BIT(GPIOx->ODR , Copy_u8Pin);

}
u8   GPIO_GetPinValue( GPIO_t* GPIOx , u8 Copy_u8Pin)
{
	u8 Value = 0;

	Value = CHECK_BIT(GPIOx->IDR , Copy_u8Pin);

	return Value;
}

void GPIO_SetPortDirection( GPIO_t* GPIOx , u8 Copy_u8Position , u8 Copy_u8Mode )
{

	if(Copy_u8Position == LOW_8PIN_CRL){
		GPIOx->CRL = 0x11111111 * Copy_u8Mode;
	}
	else if(Copy_u8Position == HIGH_8PIN_CRH){
		GPIOx->CRH = 0x11111111 * Copy_u8Mode;
	}
	else if(Copy_u8Position == LOW_4PIN_CRL){
		GPIOx->CRL = (GPIOx->CRL & 0xFFFF0000) | ( (0x11111111 * Copy_u8Mode) & 0x0000FFFF);
	}
	else if(Copy_u8Position == HIGH_4PIN_CRL){
		GPIOx->CRL = (GPIOx->CRL & 0x0000FFFF) | (( (0x11111111 * Copy_u8Mode) << 16) & 0xFFFF0000);
	}
	else if(Copy_u8Position == LOW_4PIN_CRH){
		GPIOx->CRH = (GPIOx->CRH & 0xFFFF0000) | ( (0x11111111 * Copy_u8Mode) & 0x0000FFFF);
	}
	else if(Copy_u8Position == HIGH_4PIN_CRH){
		GPIOx->CRH = (GPIOx->CRH & 0x0000FFFF) | (( (0x11111111 * Copy_u8Mode) << 16) & 0xFFFF0000);
	}

}
void GPIO_SetPortValue( GPIO_t* GPIOx , u8 Copy_u8Position , u16 Copy_u8Value )
{

	if(Copy_u8Position == LOW_8PIN_CRL){
		GPIOx->ODR = (GPIOx->ODR & 0xFF00) |(Copy_u8Value & 0x00FF);
	}
	else if(Copy_u8Position == HIGH_8PIN_CRH){
		GPIOx->ODR = (GPIOx->ODR & 0x00FF) |(Copy_u8Value << 8);
	}
	else if(Copy_u8Position == LOW_4PIN_CRL){
		GPIOx->ODR = (GPIOx->ODR & 0xFFF0) | ( (u8)Copy_u8Value );
	}
	else if(Copy_u8Position == HIGH_4PIN_CRL){
		GPIOx->ODR = (GPIOx->ODR & 0xFF0F) | ( (u8)Copy_u8Value << 4 );
	}
	else if(Copy_u8Position == LOW_4PIN_CRH){
		GPIOx->ODR = (GPIOx->ODR & 0xF0FF) | ( (u8)Copy_u8Value << 8 );
	}
	else if(Copy_u8Position == HIGH_4PIN_CRH){
		GPIOx->ODR = (GPIOx->ODR & 0x0FFF) | ( (u8)Copy_u8Value << 12 );
	}

}
u16  GPIO_GetPortValue( GPIO_t* GPIOx , u8 Copy_u8Position)
{
	u16 Value = 0;

	if(Copy_u8Position == LOW_8PIN_CRL){
		Value = GPIOx->IDR & 0x00FF;
	}
	else if(Copy_u8Position == HIGH_8PIN_CRH){
		Value = GPIOx->IDR & 0xFF00;
	}
	else if(Copy_u8Position == LOW_4PIN_CRL){
		Value = GPIOx->IDR & 0x000F;
	}
	else if(Copy_u8Position == HIGH_4PIN_CRL){
		Value = GPIOx->IDR & 0x00F0;
	}
	else if(Copy_u8Position == LOW_4PIN_CRH){
		Value = GPIOx->IDR & 0x0F00;
	}
	else if(Copy_u8Position == HIGH_4PIN_CRH){
		Value = GPIOx->IDR & 0xF000;
	}

	return Value;
}
