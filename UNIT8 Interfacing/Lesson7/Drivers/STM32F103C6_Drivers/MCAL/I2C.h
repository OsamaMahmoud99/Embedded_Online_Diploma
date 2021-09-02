/*
 * I2C.h
 *
 *  Created on: Aug 28, 2021
 *      Author: Osama Mahmoud
 */

#ifndef MCAL_I2C_H_
#define MCAL_I2C_H_

//Includes
#include "STM32F103C6.h"
#include "GPIO.h"
#include "RCC.h"


struct S_I2C_Slave_Device_Address
{
	u16 Enable_Dual_ADD;   //1-Enable 0-Disable
	u16 Primary_Slave_Address;
	u16 Secondary_Slave_Address;
	u32 I2C_Addressing_Slave_Mode;   //@I2C_Addressing_Slave

};

typedef enum
{
	I2C_Ev_Stop,
	I2C_ERROR_AF,
	I2C_EV_ADD_Matched,
	I2C_EV_DATA_REQ,    //The App layer should send the data(I2C_SlaveSendData)in this state
	I2C_EV_DATA_RCV     //The App layer should read the data(I2C_SlaveReceiveData)in this state

}Slave_State;
typedef struct
{
	u32 ClockSpeed;     /* specifies the clock frequency
	                       this parameter must be set to  @I2C_SCLK */

	u32 StretchMode;     /* this parameter must be set to  @I2C_StretchMode */

	u32 Mode;            /* this parameter must be set to  @Mode */

	u32 ACK_Control;      /* this parameter must be set to  @I2C_Ack */

	struct S_I2C_Slave_Device_Address   Slave_Device_Address;

	void(*P_Slave_Event_CallBack)(Slave_State State);

}I2C_Config;


/************Reference Macros****************/
//@I2C_SCLK
//Standard Speed (up to 100 kHz)
//Fast Speed (up to 400 kHz)
//to configure clock before enable the peripheral
//I2C_CR2 -> Bits 5:0FREQ[5:0]: Peripheral clock frequency
//•Configure the clock control registers
//    Thigh = CCR * TPCLK1
//•Configure the rise time register

#define I2C_SCLK_SM_50K         (50000U)
#define I2C_SCLK_SM_100K        (100000U)

//@I2C_StretchMode
//This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until
//it is reset by software.
//0: Clock stretching enabled
//1: Clock stretching disabled

#define I2C_StretchMode_Enable     (0)
#define I2C_StretchMode_Disable    I2C_CR1_NOSTRETCH

// @Mode
//Bit 1SMBUS: SMBus mode
//0: I2C mode
//1: SMBus mode

#define I2C_Mode                (0)
#define SMBus_Mode              I2C_CR1_SMBUS

//@I2C_Addressing_Slave
//I2C_OAR1.ADDMODE
//Bit15 ADDMODE Addressing mode (slave mode)
//0: 7-bit slave address (10-bit address not acknowledged)
//1: 10-bit slave address (7-bit address not acknowledged)

#define I2C_Addressing_Slave_Mode_7Bit        (0)
#define I2C_Addressing_Slave_Mode_10Bit       I2C_OAR1_ADDMODE

//@I2C_Ack
//Bit 10 ACK: Acknowledge enable
//This bit is set and cleared by software and cleared by hardware when PE=0.
//0: No acknowledge returned
//1: Acknowledge returned after a byte is received (matched address or data)

#define I2C_Ack_Enable       (I2C_CR1_ACK)
#define I2C_Ack_Disable      ((u16)0x0000)

//#define I2C_EVENT_MASTER_BYTE_TRANSMITTING     ((u32)0x00070080) /* TRA, BUSY, MSL, TXE */

typedef enum{
	With_Stop,
	Without_Stop
}StopCondition;

typedef enum{
	Start,
	repeated_start
}Repeated_Start;

typedef enum{
	DISABLE=0,
	ENABLE=1
}FunctionalState;

typedef enum{
	RESET=0,
	SET=1
}FlagStatus;

typedef enum{
	Direction_TX=0,
	Direction_RX=1
}I2C_Direction;


typedef enum{

	I2C_FLAG_BUSY=0,
	EV5,  //EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	EV6,  //EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	EV8,  //EV8: TxE=1, shift register not empty,. data register empty, cleared by writing DR register
	EV8_1,//TxE=1, shift register empty, data register empty, write Data1 in DR.
	EV7,  //RXNE=1  CLEARED BY READING DR REGISTER
	MASTER_BYTE_TRANSMITTING = ((u32)0x00070080) /* TRA, BUSY, MSL, TXE */

}Status;

/*
 * =======================================================================================
 * 							APIs Supported by "MCAL I2C DRIVER"
 * =======================================================================================
 */

void I2C_Init(I2C_t* I2Cx , I2C_Config* I2C_config);
void I2C_DeInit(I2C_t* I2Cx);
void I2C_GPIO_SetPins(I2C_t* I2Cx);

//Master polling Mechanism
void I2C_Master_TX(I2C_t* I2Cx , u16 devAdd , u8* data , u32 dataLen , StopCondition Stop , Repeated_Start Start);
void I2C_Master_RX(I2C_t* I2Cx , u16 devAdd , u8* data , u32 dataLen , StopCondition Stop , Repeated_Start Start);

//Slave Interrupt Mechanism
//void I2C_Slave_TX(I2C_t* I2Cx , u8 data);
//u8   I2C_Slave_RX(I2C_t* I2Cx);

//Generic APIs
void I2C_Generate_START(I2C_t* I2Cx , FunctionalState NewState , Repeated_Start start);
void I2C_Generate_STOP(I2C_t* I2Cx , FunctionalState NewState);
FlagStatus I2C_Get_FlagStatus(I2C_t* I2Cx , Status Flag);
void I2C_SendAddress(I2C_t* I2Cx , u16 Address , I2C_Direction Direction);
void I2C_AcknowledgeConfig(I2C_t* I2Cx , FunctionalState NewState);


#endif /* MCAL_I2C_H_ */
