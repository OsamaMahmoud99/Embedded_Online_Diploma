/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Osama Mahmoud
 * @brief          : Main program body
 ******************************************************************************
 */

#include "STM32F103C6.h"
#include "GPIO.h"
#include "USART.h"


u16 ch;

void USART_IRQ_CallBack(USART_IRQ_Event Flag)
{
	USART_RecieveData(USART1, &ch, disable);
	USART_SendData(USART1, &ch, enable);
}

int main(void)
{

	/* Enable GPIOA Clock */
	RCC_GPIOA_CLK_EN();
	/* Enable GPIOB Clock */
	RCC_GPIOB_CLK_EN();
	/* Enble AFIO Clock */
	RCC_AFIO_CLK_EN();

	USART_Config USART_CFG;
	USART_CFG.BaudRate   = USART_BaudRate_115200;
	USART_CFG.IRQ_Enable = USART_IRQ_Enable_RXNE;
	USART_CFG.P_IRQ_CallBack = USART_IRQ_CallBack;
	USART_CFG.Parity = USART_Parity_NONE;
	USART_CFG.WordLength = USART_WordLength_8B;
	USART_CFG.StopBits = USART_StopBits_1;
	USART_CFG.USART_Mode = USART_Mode_RX_TX;

	USART_Init(USART1 , &USART_CFG);
	USART_GPIO_SetPins(USART1);


	while(1){

	}
}
