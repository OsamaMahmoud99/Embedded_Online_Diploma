/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Osama Mahmoud
 * @brief          : Main program body
 ******************************************************************************
 */

//#define MCU_ACT_AS_MASTER
#define MCU_ACT_AS_SLAVE

#include "STM32F103C6.h"
#include "GPIO.h"
#include "USART.h"
#include "SPI.h"



u16 ch;


void SPI_IRQ_CallBack(struct S_IRQ_SRC irq_src)
{
#ifdef MCU_ACT_AS_SLAVE

	ch = 0x0f;
	SPI_RecieveData(SPI1, &ch, SPI_disable);
	USART_SendData(USART1, &ch, UART_enable);

#endif

}
void USART_IRQ_CallBack(USART_IRQ_Event Flag)
{
#ifdef MCU_ACT_AS_MASTER
	USART_RecieveData(USART1, &ch, UART_disable);
	USART_SendData(USART1, &ch, UART_enable);

	//Send to SPI
	GPIO_SetPinValue(GPIOA, PIN4, LOW);
	SPI_RX_TX(SPI1, &ch, SPI_enable);
	GPIO_SetPinValue(GPIOA, PIN4, HIGH);
#endif

}


int main(void)
{

	/* Enable GPIOA Clock */
	RCC_GPIOA_CLK_EN();
	/* Enable GPIOB Clock */
	RCC_GPIOB_CLK_EN();
	/* Enble AFIO Clock */
	RCC_AFIO_CLK_EN();

	/************ UART Init************/
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

	/************SPI Init*************/
	SPI_Config SPI_CFG;

	SPI_CFG.Clock_Phase = SPI_CLK_Phase_First_CLK_First_DataCaptureEdge;
	SPI_CFG.Clock_Polarity = SPI_CLK_Polarity_HIGH;
	SPI_CFG.Data_Size = SPI_DATA_8BIT;
	SPI_CFG.Frame_Format = SPI_MSB_FIRST;
	SPI_CFG.BaudRate = SPI_FPCLK_DIVIDED_BY_8;
	SPI_CFG.Communication_Mode = SPI_Direction_2Lines;

#ifdef MCU_ACT_AS_MASTER
	SPI_CFG.Device_Mode = SPI_Device_Mode_Master;
	SPI_CFG.IRQ_Enable = SPI_INT_DISABLE;
	SPI_CFG.NSS = SPI_NSS_Soft_InternalSlave_Set;
	SPI_CFG.P_IRQ_CallBack = NULL;

	//configure SS on PA4 by GPIO
	GPIO_SetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_10MHZ_PP);

	//Force the Slave Select (HIGH) idle Mode
	GPIO_SetPinValue(GPIOA, PIN4, HIGH);

#endif

#ifdef MCU_ACT_AS_SLAVE
	SPI_CFG.Device_Mode = SPI_Device_Mode_Slave;
	SPI_CFG.IRQ_Enable = SPI_RXNE_INT_ENABLE;
	SPI_CFG.NSS =  SPI_NSS_Hard_Slave;
	SPI_CFG.P_IRQ_CallBack = SPI_IRQ_CallBack;
#endif


	SPI_Init(SPI1, &SPI_CFG);
	SPI_GPIO_SetPins(SPI1);



	while(1){

	}
}
