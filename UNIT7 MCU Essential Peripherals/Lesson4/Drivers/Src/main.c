/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Osama Mahmoud
 * @brief          : Main program body
 ******************************************************************************
 */

#include "STM32F103C6.h"
#include "GPIO.h"
#include "EXTI.h"
#include "LCD.h"

u8 IRQ_Flag = 0;

void Delay_ms(u32 Time)
{
	u32 i = 0;
	u8  j = 0;
	for(i=0; i<Time; ++i){
		for(j=0; j<255; ++j);
	}
}
void EXTI9_CallBack(void)
{
	IRQ_Flag = 1;
	LCD_WriteSentence((u8*)"IRQ EXTI9 is happened _|- ");
	Delay_ms(1000);
}
int main(void)
{
	/* Enable GPIOA Clock */
	RCC_GPIOA_CLK_EN();
	/* Enable GPIOB Clock */
	RCC_GPIOB_CLK_EN();
	/* Enble AFIO Clock */
	RCC_AFIO_CLK_EN();

	LCD_Init();
	LCD_Clear();

	EXTI_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN = EXTI9PB9;
	EXTI_CFG.EXTI_Mode = EXTI_RISING_EDGE;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_CallBack;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_Enable;

	EXTI_GPIO_Init(&EXTI_CFG);


	IRQ_Flag = 1;

	while(1){

		if(IRQ_Flag)
		{
			LCD_Clear();
			IRQ_Flag = 0;
		}

	}
}
