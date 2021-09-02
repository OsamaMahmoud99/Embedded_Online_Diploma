/*
 * SPI.c
 *
 *  Created on: Aug 10, 2021
 *      Author: Osama Mahmoud
 */

#include "SPI.h"


/*
 * =================================================================
 *                            Global Variables
 * =================================================================
 */

SPI_Config* G_SPI_Config[2] = {NULL , NULL};
SPI_Config  G_SPI1_Config;
SPI_Config  G_SPI2_Config;

/*
 * =================================================================
 *                            Generic Macros
 * =================================================================
 */

#define   SPI1_Index      0
#define   SPI2_Index      1

#define   RXNE_PIN            1<<0         //Bit 0 RXNE: Receive buffer not empty
#define   TXE_PIN             1<<1         //Bit 1 TXE: Transmit buffer empty

/*
 * =================================================================
 *                            APIS
 * =================================================================
 */
void SPI_Init(SPI_t* SPIx , SPI_Config* SPI_Config)
{
	//safety for registers
	u16 Temp_CR1 = 0;
	u16 Temp_CR2 = 0;

	if(SPIx == SPI1){

		G_SPI1_Config = *SPI_Config;
		G_SPI_Config[SPI1_Index] = &G_SPI1_Config;
		RCC_SPI1_CLK_EN();
	}
	else if(SPIx == SPI2){

		G_SPI2_Config = *SPI_Config;
		G_SPI_Config[SPI1_Index] = &G_SPI2_Config;
		RCC_SPI2_CLK_EN();
	}

	//Enable SPI CR1 -> Bit6 SPE: SPI enable
	Temp_CR1 = (u32)(1 << 6);

	//Master or Slave
	Temp_CR1 |= SPI_Config->Device_Mode;

	//SPI_communication_Mode
	Temp_CR1 |= SPI_Config->Communication_Mode;

	//SPI_Frame_Format
	Temp_CR1 |= SPI_Config->Frame_Format;

	//SPI_DataSize
	Temp_CR1 |= SPI_Config->Data_Size;

	//SPI_Clock_Polarity
	Temp_CR1 |= SPI_Config->Clock_Polarity;

	//SPI_CLock_Phase
	Temp_CR1 |= SPI_Config->Clock_Phase;

	if(SPI_Config->NSS == SPI_NSS_Hard_Master_SS_Output_Enable){
		Temp_CR2 |= SPI_Config->NSS;
	}
	else if(SPI_Config->NSS == SPI_NSS_Hard_Master_SS_Output_Disable){
		Temp_CR2 &= SPI_Config->NSS;
	}
	else{
		Temp_CR1 &= SPI_Config->NSS;
	}

	//SPI_BaudRate
	Temp_CR1 |= SPI_Config->BaudRate;

	//SPI_Interrupt
	if(SPI_Config->IRQ_Enable != SPI_INT_DISABLE){

		Temp_CR2 |= SPI_Config->IRQ_Enable;

		if(SPIx == SPI1){

			NVIC_IRQ_SPI_Enable(SPI1IRQn);
		}
		else if(SPIx == SPI2){

			NVIC_IRQ_SPI_Enable(SPI2IRQn);
		}
	}

	SPIx->CR1 = Temp_CR1;
	SPIx->CR2 = Temp_CR2;

}
void SPI_DeInit(SPI_t* SPIx)
{
	if(SPIx == SPI1){

		NVIC_IRQ_SPI_Disable(SPI1IRQn);
		RCC_SPI1_CLK_DIS();
	}
	else if(SPIx == SPI2){

		NVIC_IRQ_SPI_Disable(SPI2IRQn);
		RCC_SPI2_CLK_DIS();
	}
}

void SPI_SendData(SPI_t* SPIx , u16* Buffer , SPI_Polling_Mechanism PollingEn)
{
	if(PollingEn == SPI_enable){
		while(! ((SPIx->SR) & TXE_PIN));
	}
	SPIx->DR = *Buffer;
}

void SPI_RecieveData(SPI_t* SPIx , u16* Buffer , SPI_Polling_Mechanism PollingEn)
{
	if(PollingEn == SPI_enable){
		while(!((SPIx->SR) & RXNE_PIN));
	}
	*Buffer = SPIx->DR;
}

void SPI_RX_TX(SPI_t* SPIx , u16* Buffer , SPI_Polling_Mechanism PollingEn)
{
	if(PollingEn == SPI_enable){
		while(! ((SPIx->SR) & TXE_PIN));
	}
	SPIx->DR = *Buffer;

	if(PollingEn == SPI_enable){
		while(! ((SPIx->SR) & RXNE_PIN));
	}
	*Buffer = SPIx->DR;
}

void SPI_GPIO_SetPins(SPI_t* SPIx)
{
	if(SPIx == SPI1){

		//   PA4 : SPI1_NSS
		//   PA5 : SPI1_SCK
		//   PA6 : SPI1_MISO
		//   PA7 : SPI1_MOSI

		if(G_SPI_Config[SPI1_Index]->Device_Mode == SPI_Device_Mode_Master){

			//   PA4 : SPI1_NSS
			switch(G_SPI_Config[SPI1_Index]->NSS){

			case SPI_NSS_Hard_Master_SS_Output_Disable:
				GPIO_SetPinDirection(GPIOA, PIN4, INPUT_FLOATING);
				break;
			case SPI_NSS_Hard_Master_SS_Output_Enable:
				GPIO_SetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_10MHZ_AFPP);
				break;
			}

			//   PA5 : SPI1_SCK
			GPIO_SetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_10MHZ_AFPP);

			//   PA6 : SPI1_MISO (supported only full duplex)
			GPIO_SetPinDirection(GPIOA, PIN6, INPUT_FLOATING);

			//   PA7 : SPI1_MOSI
			GPIO_SetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_10MHZ_AFPP);
		}
		else if(G_SPI_Config[SPI1_Index]->Device_Mode == SPI_Device_Mode_Slave){

			//   PA4 : SPI1_NSS
			if(G_SPI_Config[SPI1_Index]->NSS == SPI_NSS_Hard_Slave){
				GPIO_SetPinDirection(GPIOA, PIN4, INPUT_FLOATING);
			}

			//   PA5 : SPI1_SCK
			GPIO_SetPinDirection(GPIOA, PIN5, INPUT_FLOATING);

			//   PA6 : SPI1_MISO (supported only full duplex)
			GPIO_SetPinDirection(GPIOA, PIN6, OUTPUT_SPEED_10MHZ_AFPP);

			//   PA7 : SPI1_MOSI
			GPIO_SetPinDirection(GPIOA, PIN7, INPUT_FLOATING);

		}

	}
	else if(SPIx == SPI2){

		//   PB12 : SPI2_NSS
		//   PB13 : SPI2_SCK
		//   PB14 : SPI2_MISO
		//   PB15 : SPI2_MOSI

		if(G_SPI_Config[SPI2_Index]->Device_Mode == SPI_Device_Mode_Master){

			//   PB12 : SPI2_NSS
			switch(G_SPI_Config[SPI2_Index]->NSS){

			case SPI_NSS_Hard_Master_SS_Output_Disable:
				GPIO_SetPinDirection(GPIOB, PIN12, INPUT_FLOATING);
				break;
			case SPI_NSS_Hard_Master_SS_Output_Enable:
				GPIO_SetPinDirection(GPIOB, PIN12, OUTPUT_SPEED_10MHZ_AFPP);
				break;
			}

			//   PB13 : SPI2_SCK
			GPIO_SetPinDirection(GPIOB, PIN13, OUTPUT_SPEED_10MHZ_AFPP);

			//   PB14 : SPI2_MISO
			GPIO_SetPinDirection(GPIOB, PIN14, INPUT_FLOATING);

			//   PB15 : SPI2_MOSI
			GPIO_SetPinDirection(GPIOB, PIN15, OUTPUT_SPEED_10MHZ_AFPP);
		}
		else{

			//   PB12 : SPI2_NSS
			if(G_SPI_Config[SPI2_Index]->NSS == SPI_NSS_Hard_Slave){
				GPIO_SetPinDirection(GPIOB, PIN12, INPUT_FLOATING);
			}

			//   PB13 : SPI2_SCK
			GPIO_SetPinDirection(GPIOB, PIN13, INPUT_FLOATING);

			//   PB14 : SPI2_MISO
			GPIO_SetPinDirection(GPIOB, PIN14, OUTPUT_SPEED_10MHZ_AFPP);

			//   PB15 : SPI2_MOSI
			GPIO_SetPinDirection(GPIOB, PIN15, INPUT_FLOATING);

		}

	}
}

/*
 * =================================================================
 *                            IRQ
 * =================================================================
 */

void SPI1_IRQHandler(void)
{
	struct S_IRQ_SRC irq_src;

	irq_src.TXE  = ((SPI1->SR & (TXE_PIN)) >> 1);
	irq_src.RXNE = ((SPI1->SR & (RXNE_PIN)) >> 1);

	G_SPI_Config[SPI1_Index]->P_IRQ_CallBack(irq_src);
}

void SPI2_IRQHandler(void)
{
	struct S_IRQ_SRC irq_src;

	irq_src.TXE  = ((SPI2->SR & (TXE_PIN)) >> 1);
	irq_src.RXNE = ((SPI2->SR & (RXNE_PIN)) >> 1);

	G_SPI_Config[SPI2_Index]->P_IRQ_CallBack(irq_src);
}







