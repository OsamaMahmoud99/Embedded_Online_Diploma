/*
 * USART.h
 *
 *  Created on: Jul 28, 2021
 *      Author: Osama Mahmoud
 */

#ifndef MCAL_USART_H_
#define MCAL_USART_H_

#include "STM32F103C6.h"
#include "RCC.h"
#include "GPIO.h"


typedef enum{

	USART_IRQ_TXE,   //transmit data register empty
	USART_IRQ_TC,    //Transmission complete
	USART_IRQ_RXNE,  //Received data ready to be read
	USART_IRQ_ORE,   //Overrun error detected
	USART_IEQ_PE     //Parity error

}USART_IRQ_Event;

//Configuration structure

typedef struct {

  u8         USART_Mode;  // Specifies TX/RX Enable/Disable
                          // This parameter must be set based on @ref USART_Mode_define

  u32        BaudRate;     // This parameter must be set based on @ref USART_BaudRate_define

  u8         WordLength;   // This parameter must be set based on @ref USART_WordLength_define

  u8         Parity;       // This parameter must be set based on @ref USART_Parity_define

  u8         StopBits;     // This parameter must be set based on @ref USART_StopBits_define

  u8         IRQ_Enable;

  void(* P_IRQ_CallBack)(USART_IRQ_Event Flag); // set c function which will be called once the IRQ Happen



}USART_Config;


//@ref USART_Mode_define

#define USART_Mode_RX            (1<<2)        //Bit 2RE: Receiver enable
#define USART_Mode_TX            (1<<3)        //Bit 3TE: Transmitter enable
#define USART_Mode_RX_TX         ((1<<2)|(1<<3))

//@ref USART_BaudRate_define

#define USART_BaudRate_2400      2400
#define USART_BaudRate_9600      9600
#define USART_BaudRate_19200     19200
#define USART_BaudRate_57600     57600
#define USART_BaudRate_115200    115200

//@ref USART_WordLength_define

#define USART_WordLength_8B             (u32)(0)
#define USART_Wordlength_9B             (u32)(1<<12)

//@ref USART_Parity_define

#define USART_Parity_NONE               (u32)(0)
#define USART_Parity_EVEN               (u32)(1<<10)
#define USART_Parity_ODD                ((u32)(1<<10 | 1<<9))

//@ref USART_StopBits_define

#define USART_StopBits_half             (u32)(1<<12)
#define USART_StopBits_1                (u32)(0)
#define USART_StopBits_1_half           (u32)(3<<12)
#define USART_StopBits_2                (u32)(2<<12)

//@ref USART_IRQ_Enable_define

#define USART_IRQ_Enable_NONE           (u32)(0)
#define USART_IRQ_Enable_TXE            (u32)(1<<7)
#define USART_IRQ_Enable_TC             (u32)(1<<6)
#define USART_IRQ_Enable_RXNE           (u32)(1<<5)
#define USART_IRQ_Enable_PE             (u32)(1<<8)



typedef enum{
	enable,
	disable
}Polling_Mechanism;


//BaudRate Calculation
//USARTDIV = fclk / (16 * Baudrate)
//USARTDIV_MUL100 =
//u32(100 * fclk) / (16 * Baudrate) = (25 * fclk) / (4* Baudrate)
//DIV_Mantissa_MUL100 = Integer Part (USARTDIV) * 100
//DIV_Mantissa = Integer part (USARTDIV)
//DIV_Fraction = (( USARTDIV_MUL100 - DIV_Mantissa_MUL100) * 16) / 100

#define USARTDIV(_PCLK_, _BAUD_)            (u32)(_PCLK_/(16 * _BAUD_))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)     (u32)((25 * _PCLK_) / (4 * _BAUD_))
#define Mantissa_MUL100(_PCLK_, _BAUD_)    (u32)(USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)           (u32)(USARTDIV(_PCLK_, _BAUD_))
#define DIV_Fraction(_PCLK_, _BAUD_)       (u32)(((USARTDIV_MUL100(_PCLK_, _BAUD_) - Mantissa_MUL100(_PCLK_, _BAUD_)) * 16) / 100)
#define UART_BRR_Register(_PCLK_, _BAUD_)  ((Mantissa(_PCLK_, _BAUD_)) <<4 )|((DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )


/*
 * =======================================================================================
 * 							APIs Supported by "MCAL GPIO DRIVER"
 * =======================================================================================
 */

void USART_Init(USART_t* USARTx , USART_Config* USART_Config);
void USART_DeInit(USART_t* USARTx);

void USART_GPIO_SetPins(USART_t* USARTx);

void USART_SendData(USART_t* USARTx , u16* Buffer , Polling_Mechanism PollingEn);
void USART_RecieveData(USART_t* USARTx , u16* Buffer , Polling_Mechanism PollingEn);




#endif /* MCAL_USART_H_ */
