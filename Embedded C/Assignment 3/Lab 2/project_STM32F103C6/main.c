/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Osama Mahmoud
 * @brief          : Toggle Led using stm32f103c6
 ******************************************************************************
 */

#include "Platform_Types.h"

#define BASE_ADDRESS_RCC     0x40021000
#define BASE_ADDRESS_PORTA   0x40010800

#define APB2ENR             *(volatile uint32 *)(BASE_ADDRESS_RCC+0x18)
#define CRH                 *(volatile uint32 *)(BASE_ADDRESS_PORTA+0x04)
#define GPIOA_ODR           *(volatile uint32 *)(BASE_ADDRESS_PORTA+0x0C)

unsigned char variable[3] = {1,2,3};
unsigned char const const_variabl[3] = {1,2,3};

int main(void)
{
	uint16 i , j;
	APB2ENR |= 1<<2;   // Set clock

	CRH &= 0xff0fffff; // clear bits
	CRH |= 0x00200000; // Set Mode

	while(1)
	{
		GPIOA_ODR |= 1 << 13;
		for(i=0; i<10000; ++i);
		GPIOA_ODR &= ~(1 << 13);
		for(j=0; j<10000; ++j);
	}

}
