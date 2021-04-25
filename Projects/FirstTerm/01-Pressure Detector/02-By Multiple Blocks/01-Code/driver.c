#include "driver.h"
#include <stdint.h>
#include <stdio.h>
void Delay(int nCount)
{
	for(; nCount != 0; nCount--);
}

int getPressureVal(void)
{
	return (GPIOA_IDR & 0xFF);
}

void Set_LED(LED_State i)
{
	if (i == HIGH){
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == LOW){
		RESET_BIT(GPIOA_ODR,13);
	}
}

void GPIO_INITIALIZATION (void)
{
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}
