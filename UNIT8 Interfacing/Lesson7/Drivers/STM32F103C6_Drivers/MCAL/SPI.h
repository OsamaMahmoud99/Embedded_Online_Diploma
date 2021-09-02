/*
 * SPI.h
 *
 *  Created on: Aug 10, 2021
 *      Author: Osama Mahmoud
 */

#ifndef MCAL_SPI_H_
#define MCAL_SPI_H_

//Includes
#include "STM32F103C6.h"
#include "GPIO.h"

struct S_IRQ_SRC
{
	u8 TXE:1;     // TX buffer empty interrupt
	u8 RXNE:1;    // RX buffer not empty interrupt
	u8 ERRI:1;    // Error interrupt
	u8 Reserved:5;
};

//configuration structure
typedef struct
{
	u16   Device_Mode;          // Specifies operating mode @ref SPI_Device_Mode
	u16   Communication_Mode;   // Specifies the spi bidirectional mode state @ref SPI_Communication_Mode
	u16   Frame_Format;         // Specifies LSB or MSB @ref SPI_Frame_Format
	u16   Data_Size;            // Specifies DataSize 8bit or 16bit @ref SPI_DataSize
	u16   Clock_Polarity;       // SPecifies Clock_Polarity @ref SPI_Clock_Polarity
	u16   Clock_Phase;          // Specifies Clock_Phase @ref SPI_Clock_Phase
	u16   NSS;                  // Specifies whether the NSS Signal is managed by hardware or by software using SSI and SSM pin @ref SPI_NSS
	u16   BaudRate;             /* Specifies the Baud rate Prescaler value which will be
	                               used to configue the Transmit and receive Clock
	                               This parameter is set @ref SPI_BaudRate*/


	u16   IRQ_Enable;                // This parameter is set @ref SPI_IRQ_Enable

	void(* P_IRQ_CallBack)(struct S_IRQ_SRC irq_src);    // Set the c function() which will be called once the IRQ happen

}SPI_Config;


/************Reference Macros****************/

//@ref SPI_Device_Mode
#define SPI_Device_Mode_Slave                (0x00000000U)
#define SPI_Device_Mode_Master               (u32)(1<<2)               // CR1 -> Bit 2MSTR: Master selection

//@ref SPI_Communication_Mode
#define SPI_Direction_2Lines                 (0x00000000U)
#define SPI_Direction_2Lines_RXONLY          (0x1U<<10)             // CR1 -> Bit 10 RXONLY: Receive only
#define SPI_Direction_1Lines_Receive_Only    (0x1U<<15)             // CR1 -> Bit 15BIDIMODE: Bidirectional data mode enable
#define SPI_Direction_1Lines_Transmit_Only   (0x1U<<15 | 0x1U<<14)  // CR1 -> Bit 15BIDIMODE: Bidirectional data mode enable , Bit 14 BIDIOE: Output enable in bidirectional mode

//@ref SPI_Frame_Format
//Note: This bit should not be changed when communication is ongoing.
#define SPI_MSB_FIRST                         (0x00000000U)
#define SPI_LSB_FIRST                         (0x1U<<7)              // Bit 7LSBFIRST: Frame format

//@ref SPI_DataSize
//Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation.
#define SPI_DATA_8BIT                         (0x00000000U)
#define SPI_DATA_16BIT                        (0x1U<<11)            // 1: 16-bit data frame format is selected for transmission/reception

//@ref SPI_Clock_Polarity
#define SPI_CLK_Polarity_LOW                  (0x00000000U)        // 0: CK to 0 when idle
#define SPI_CLK_Polarity_HIGH                 (0x1U<<1)            // 1: CK to 1 when idle

//@ref SPI_Clock_Phase
#define SPI_CLK_Phase_First_CLK_First_DataCaptureEdge  (0x00000000U)
#define SPI_CLK_Phase_Second_CLK_First_DataCaptureEdge (0x1U<<0)   //Bit 0CPHA: Clock phase

//@ref SPI_NSS
//Hardware
#define SPI_NSS_Hard_Slave                       ~(0x1U<<9)
#define SPI_NSS_Hard_Master_SS_Output_Enable     (0x1U<<2)       // CR2 -> Bit 2SSOE: SS output enable
#define SPI_NSS_Hard_Master_SS_Output_Disable    ~(0x1U<<2)      // CR2 -> Bit 2SSOE: SS output enable

//Software
//When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
#define SPI_NSS_Soft_InternalSlave_Reset         (0x1U<<9)       // Bit 9SSM: Software slave management
#define SPI_NSS_Soft_InternalSlave_Set           (0x1U<<9)|(0x1U<<8)

//@ref SPI_BaudRate
#define SPI_FPCLK_DIVIDED_BY_2      (0b000<<3)
#define SPI_FPCLK_DIVIDED_BY_4      (0b001<<3)
#define SPI_FPCLK_DIVIDED_BY_8      (0b010<<3)
#define SPI_FPCLK_DIVIDED_BY_16     (0b011<<3)
#define SPI_FPCLK_DIVIDED_BY_32     (0b100<<3)
#define SPI_FPCLK_DIVIDED_BY_64     (0b101<<3)
#define SPI_FPCLK_DIVIDED_BY_128    (0b110<<3)
#define SPI_FPCLK_DIVIDED_BY_256    (0b111<<3)

//@ref SPI_IRQ_Enable
#define SPI_INT_DISABLE             (u32)(0)
#define SPI_TXE_INT_ENABLE          (u32)(1<<7)  //CR2-> Bit7 TXEIE: Tx buffer empty interrupt enable
#define SPI_RXNE_INT_ENABLE         (u32)(1<<6)  //CR2-> Bit6 RXNEIE: RX buffer not empty interrupt enable
#define SPI_ERRIE_INT_ENABLE        (u32)(1<<5)  //CR2-> Bit5 ERRIE: Error interrupt enable


typedef enum{
	SPI_enable,
	SPI_disable
}SPI_Polling_Mechanism;



/*
 * =======================================================================================
 * 							APIs Supported by "MCAL SPI DRIVER"
 * =======================================================================================
 */

void SPI_Init(SPI_t* SPIx , SPI_Config* SPI_Config);
void SPI_DeInit(SPI_t* SPIx);

void SPI_GPIO_SetPins(SPI_t* SPIx);

void SPI_SendData(SPI_t* SPIx , u16* Buffer , SPI_Polling_Mechanism PollingEn);
void SPI_RecieveData(SPI_t* SPIx , u16* Buffer , SPI_Polling_Mechanism PollingEn);

void SPI_RX_TX(SPI_t* SPIx , u16* Buffer ,SPI_Polling_Mechanism PollingEn);


#endif /* MCAL_SPI_H_ */
