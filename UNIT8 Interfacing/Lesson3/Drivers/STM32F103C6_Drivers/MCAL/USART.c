/*
 * USART.c
 *
 *  Created on: Jul 28, 2021
 *      Author: Osama Mahmoud
 */

#include "USART.h"


/*
 * =================================================================
 *                            Global Variables
 * =================================================================
 */

USART_Config* Global_USART_Config = NULL;


/*
 * =================================================================
 *                            APIS
 * =================================================================
 */

void USART_Init(USART_t* USARTx , USART_Config* USART_Config)
{
	u32 Pclk , BRR;
	Global_USART_Config = USART_Config;

	// enable clock
	if(USARTx == USART1){
		RCC_USART1_CLK_EN();
	}
	else if(USARTx == USART2){
		RCC_USART2_CLK_EN();
	}
	else if(USARTx == USART3){
		RCC_USART3_CLK_EN();
	}

	//Enable USART_Module
	USARTx->CR1 |= 1 << 13;

	//Enable TX or RX according to config table
	USARTx->CR1 |= USART_Config->USART_Mode;

	//WordLength
	USARTx->CR1 |= USART_Config->WordLength;

	//Parity
	USARTx->CR1 |= USART_Config->Parity;

	//StopBits
	USARTx->CR2 |= USART_Config->StopBits;

	//BaudRate
	//PCLK1 for USART2 , 3
	//PCLK2 for USART1
	if(USARTx == USART1){
		Pclk = RCC_GetPCLK2Freq();
	}
	else{
		Pclk = RCC_GetPCLK1Freq();
	}

	BRR = UART_BRR_Register(Pclk , USART_Config->BaudRate);
	USARTx->BRR = BRR;

	//Enable / Disable Interrupt
	//USART_CR1
	if(USART_Config->IRQ_Enable != USART_IRQ_Enable_NONE){

		USARTx->CR1 |= USART_Config->IRQ_Enable;

		//Enble NVIC for USARTx_IRQ
		if(USARTx == USART1){
			NVIC_IRQ_USART_Enable(USART1IRQn);
		}
		else if(USARTx == USART2){
			NVIC_IRQ_USART_Enable(USART2IRQn);
		}
		else if(USARTx == USART3){
			NVIC_IRQ_USART_Enable(USART3IRQn);
		}
	}


}

void USART_DeInit(USART_t* USARTx)
{
	if(USARTx == USART1){
		RCC_USART1_CLK_DIS();
		NVIC_IRQ_USART_Disable(USART1IRQn);
	}
	else if(USARTx == USART2){
		RCC_USART2_CLK_DIS();
		NVIC_IRQ_USART_Disable(USART2IRQn);
	}
	else if(USARTx == USART3){
		RCC_USART3_CLK_DIS();
		NVIC_IRQ_USART_Disable(USART3IRQn);
	}
}

void USART_SendData(USART_t* USARTx , u16* Buffer , Polling_Mechanism PollingEn)
{
	//wait until TXE flag is set in SR
	if(PollingEn == enable){
		while(! (USARTx->SR & 1<<7) );
	}

	if(Global_USART_Config->WordLength == USART_Wordlength_9B){

		/*When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
		the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
		because it is replaced by the parity.
		When receiving with the parity enabled, the value read in the MSB bit is the received parity
		bit.*/

		USARTx->DR = (*Buffer & (u16)0x01FF);
	}
	else{
		// This is 8bit data transfer
		USARTx->DR = (*Buffer & (u8)0xFF);
	}
}

void USART_RecieveData(USART_t* USARTx , u16* Buffer , Polling_Mechanism PollingEn)
{
	//wait until RXNE flag is set in SR
	if(PollingEn == enable){
		while(! (USARTx->SR & 1<<5) );
	}

	if(Global_USART_Config->WordLength == USART_Wordlength_9B){
		if(Global_USART_Config->Parity == USART_Parity_NONE){
			//no parity so all bits is considered data
			*((u16*)Buffer) = USARTx->DR;
		}
		else{
			//parity is used so 8Bits will be of user data and 1Bit is parity
			*((u16*)Buffer) = (USARTx->DR & (u8)0xFF);
		}
	}
	else{
		if(Global_USART_Config->WordLength == USART_Parity_NONE){
			//no parity so all bits is considered data
			*((u16*)Buffer) = (USARTx->DR & (u8)0xFF);
		}
		else{
			//parity is used so 7Bits will be of user data and 1Bit is parity
			*((u16*)Buffer) = (USARTx->DR & (u8)0x7F);
		}
	}
}

void USART_GPIO_SetPins(USART_t* USARTx)
{
	if(USARTx == USART1){
		// TX PA9
		// RX PA10
		GPIO_SetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_10MHZ_AFPP);
		GPIO_SetPinDirection(GPIOA, PIN10, INPUT_FLOATING);
	}
	else if(USARTx == USART2){
		// TX PA2
		// RX PA3
		GPIO_SetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_10MHZ_AFPP);
		GPIO_SetPinDirection(GPIOA, PIN3, INPUT_FLOATING);
	}
	else if(USARTx == USART3){
		// TX PB10
		// RX PB11
		GPIO_SetPinDirection(GPIOB, PIN10, OUTPUT_SPEED_10MHZ_AFPP);
		GPIO_SetPinDirection(GPIOB, PIN11, INPUT_FLOATING);
	}
}

//ISR

void USART1_IRQHandler(void)
{
	USART_IRQ_Event Flag;

	if(USART1->SR & 1<<7){
		Flag = USART_IRQ_TXE;
	}
	else if(USART1->SR & 1<<6){
		Flag = USART_IRQ_TC;

		//clear by writing 0
		USART1->SR &= ~(1<<6);
	}
	else if(USART1->SR & 1<<5){
		Flag = USART_IRQ_RXNE;

		//clear by writing 0
		USART1->SR &= ~(1<<5);
	}
	else if(USART1->SR & 1<<3){
		Flag = USART_IRQ_ORE;
	}
	else if(USART1->SR & 1<<0){
		Flag = USART_IEQ_PE;
	}

	Global_USART_Config->P_IRQ_CallBack(Flag);
}

void USART2_IRQHandler(void)
{
	USART_IRQ_Event Flag;

	if(USART2->SR & 1<<7){
		Flag = USART_IRQ_TXE;
	}
	else if(USART2->SR & 1<<6){
		Flag = USART_IRQ_TC;

		//clear by writing 0
		USART2->SR &= ~(1<<6);
	}
	else if(USART2->SR & 1<<5){
		Flag = USART_IRQ_RXNE;

		//clear by writing 0
		USART2->SR &= ~(1<<5);
	}
	else if(USART2->SR & 1<<3){
		Flag = USART_IRQ_ORE;
	}
	else if(USART2->SR & 1<<0){
		Flag = USART_IEQ_PE;
	}

	Global_USART_Config->P_IRQ_CallBack(Flag);
}

void USART3_IRQHandler(void)
{
	USART_IRQ_Event Flag;

	if(USART3->SR & 1<<7){
		Flag = USART_IRQ_TXE;
	}
	else if(USART3->SR & 1<<6){
		Flag = USART_IRQ_TC;

		//clear by writing 0
		USART3->SR &= ~(1<<6);
	}
	else if(USART3->SR & 1<<5){
		Flag = USART_IRQ_RXNE;

		//clear by writing 0
		USART3->SR &= ~(1<<5);
	}
	else if(USART3->SR & 1<<3){
		Flag = USART_IRQ_ORE;
	}
	else if(USART3->SR & 1<<0){
		Flag = USART_IEQ_PE;
	}

	Global_USART_Config->P_IRQ_CallBack(Flag);
}

