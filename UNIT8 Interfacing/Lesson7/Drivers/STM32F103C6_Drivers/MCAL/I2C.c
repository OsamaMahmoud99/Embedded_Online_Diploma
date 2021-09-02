/*
 * I2C.c
 *
 *  Created on: Aug 28, 2021
 *      Author: Osama Mahmoud
 */

#include "I2C.h"

/*
 * =================================================================
 *                            Global Variables
 * =================================================================
 */

I2C_Config G_I2C_Config[2];

/*
 * =================================================================
 *                            Generic Macros
 * =================================================================
 */

#define   I2C1_Index      0
#define   I2C2_Index      1



/*
 * =================================================================
 *                            APIS
 * =================================================================
 */

void I2C_Init(I2C_t* I2Cx , I2C_Config* I2C_config)
{
	u16 Temp_Reg , Freq_Range = 0;
	u32 Pclk1 = 8000000;
	u16 Result = 0;

	//Enable RCC Clock
	if(I2Cx == I2C1){
		G_I2C_Config[I2C1_Index] = *I2C_config;
		RCC_I2C1_CLK_EN();
	}
	else{
		G_I2C_Config[I2C2_Index] = *I2C_config;
		RCC_I2C2_CLK_EN();
	}

	if(I2C_config->Mode == I2C_Mode){

		/*********************Init Timing****************************/
		//I2C_CR2 -> Bits 5:0FREQ[5:0]: Peripheral clock frequency
		/* get the I2Cx CR2 Value */
		Temp_Reg = I2Cx->CR2;
		/* Clear FREQ[5:0] bits */
		Temp_Reg &= ~(I2C_CR2_FREQ);
		/* Get Pclk1 Freq Value */
		Pclk1 = RCC_GetPCLK1Freq();
		/* Set Freq bits depending on Pclk1 Value */
		Freq_Range = Pclk1 / 1000000;

		Temp_Reg |= Freq_Range;
		I2Cx->CR2 = Temp_Reg;

		//•Configure the clock control registers
		/* Disable the selected I2C Peripheral to configure time */

		I2Cx->CR1 &= ~(I2C_CR1_PE);

		Temp_Reg = 0;

		/* Configure speed in standard mode */
		if((I2C_config->ClockSpeed == I2C_SCLK_SM_50K) || (I2C_config->ClockSpeed == I2C_SCLK_SM_100K)){

			/* calculate Standard mode speed */
			//    Tclk/2 = CRR * Tpclk1
			//    CRR = Tclk/(2*Tpclk1)
			//    CRR = Fpclk1 / (2 * I2C_ClockFreq)

			Result = (u16)(Pclk1 / (I2C_config->ClockSpeed << 1 ));
			Temp_Reg |= Result;

			/*Write to I2Cx CCR*/
			I2Cx->CCR = Temp_Reg;

			/******************* I2C_TRISE_Configuration**********************/
			/*For instance: in Sm mode, the maximum allowed SCL rise time is 1000 ns.
			If, in the I2C_CR2 register, the value of FREQ[5:0] bits is equal to 0x08 and TPCLK1 = 125 ns
			therefore the TRISE[5:0] bits must be programmed with 09h.
			(1000 ns / 125 ns = 8 + 1)*/

			I2Cx->TRISE = Freq_Range + 1;

		}
		else{
			//Fast mode not supported Yet
		}

		/********************* I2Cx CR1 Configuration***********************/
		/* get the I2Cx CR1 Value */
		Temp_Reg = I2Cx->CR1;

		Temp_Reg |= (u16)(I2C_config->Mode | I2C_config->StretchMode);

		/*Write to I2Cx CR1*/
		I2Cx->CR1 = Temp_Reg;

		/********************* I2Cx OAR1 & I2Cx OAR2 Configuration***********************/
		Temp_Reg = 0;

		if(I2C_config->Slave_Device_Address.Enable_Dual_ADD == 1){

			Temp_Reg = I2C_OAR2_ENDUAL;
			Temp_Reg |= I2C_config->Slave_Device_Address.Secondary_Slave_Address << I2C_OAR2_ADD2_Pos;
			I2Cx->OAR2 = Temp_Reg;
		}
		Temp_Reg = 0;
		Temp_Reg |= I2C_config->Slave_Device_Address.Primary_Slave_Address << I2C_OAR1_ADD_Pos;
		Temp_Reg |= I2C_config->Slave_Device_Address.I2C_Addressing_Slave_Mode;
		I2Cx->OAR1 = Temp_Reg;

	}
	else{
		//SMBs not supported Yet
	}

	//Interrupt Mode(Slave_Mode)
	if(I2C_config->P_Slave_Event_CallBack != NULL){

		//Enable IRQ
		I2Cx->CR2 |= I2C_CR2_ITERREN;
		I2Cx->CR2 |= I2C_CR2_ITEVTEN;
		I2Cx->CR2 |= I2C_CR2_ITBUFEN;

		if(I2Cx == I2C1){
			NVIC_IRQ_I2C_Enable(I2C1_EV_IRQn);
			NVIC_IRQ_I2C_Enable(I2C1_ER_IRQn);
		}
		else if(I2Cx == I2C2){
			NVIC_IRQ_I2C_Enable(I2C2_EV_IRQn);
			NVIC_IRQ_I2C_Enable(I2C2_ER_IRQn);
		}

		I2Cx->SR1 = 0;
		I2Cx->SR2 = 0;
	}

	/* Enable the selected I2C peripheral */
	I2Cx->CR1 |= I2C_CR1_PE;
}

void I2C_DeInit(I2C_t* I2Cx)
{
	if(I2Cx == I2C1){
		NVIC_IRQ_I2C_Disable(I2C1_EV_IRQn);
		NVIC_IRQ_I2C_Disable(I2C1_ER_IRQn);
		RCC_I2C1_CLK_DIS();
	}
	else if(I2Cx == I2C2){
		NVIC_IRQ_I2C_Disable(I2C2_EV_IRQn);
		NVIC_IRQ_I2C_Disable(I2C2_ER_IRQn);
		RCC_I2C2_CLK_DIS();
	}
}

void I2C_GPIO_SetPins(I2C_t* I2Cx)
{
	if(I2Cx == I2C1){

		//PB6   I2C1_SCL
		//PB7   I2C1_SDA

		GPIO_SetPinDirection(GPIOB, PIN6, OUTPUT_SPEED_10MHZ_AFOD);
		GPIO_SetPinDirection(GPIOB, PIN7, OUTPUT_SPEED_10MHZ_AFOD);
	}
	else if(I2Cx == I2C2){

		//PB10   I2C2_SCL
		//PB11   I2C2_SDA

		GPIO_SetPinDirection(GPIOB, PIN10, OUTPUT_SPEED_10MHZ_AFOD);
		GPIO_SetPinDirection(GPIOB, PIN11, OUTPUT_SPEED_10MHZ_AFOD);
	}
}

void I2C_Master_TX(I2C_t* I2Cx , u16 devAdd , u8* data , u32 dataLen , StopCondition Stop , Repeated_Start Start)
{
	int i = 0;

	//1.Set the Start bit in the I2C_CR1 to generate a start condition */
	I2C_Generate_START(I2Cx, ENABLE, Start);

	//2.Wait for EV5
	//EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(!I2C_Get_FlagStatus(I2Cx, EV5));

	//3.Send Address
	I2C_SendAddress(I2Cx, devAdd, Direction_TX);

	//4.Wait for EV6
	//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	while(!I2C_Get_FlagStatus(I2Cx, EV6));

	//5. TRA, BUSY, MSL, TXE
	while(!I2C_Get_FlagStatus(I2Cx, MASTER_BYTE_TRANSMITTING));

	for(i=0; i<dataLen; ++i){

		//6.EV8_1: TxE=1, shift register empty, data register empty, write Data1 in DR.
		while(!I2C_Get_FlagStatus(I2Cx, EV8_1));
		//Write Data to DR register
		I2Cx->DR = data[i];
		//7.EV8: TxE=1, shift register not empty,. data register empty, cleared by writing DR register
		while(!I2C_Get_FlagStatus(I2Cx, EV8));
	}

	//8.Generate stop condition
	if(Stop == With_Stop){
		I2C_Generate_STOP(I2Cx, ENABLE);
	}
	else{
		I2C_Generate_STOP(I2Cx, DISABLE);
	}


}
void I2C_Master_RX(I2C_t* I2Cx , u16 devAdd , u8* data , u32 dataLen , StopCondition Stop , Repeated_Start Start)
{
	int i = 0;

	u8 index = I2Cx==I2C1 ? I2C1_Index : I2C2_Index;

	//1.Set the Start bit in the I2C_CR1 to generate a start condition */
	I2C_Generate_START(I2Cx, ENABLE, Start);

	//2.Wait for EV5
	//EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(!I2C_Get_FlagStatus(I2Cx, EV5));

	//3.Send Address
	I2C_SendAddress(I2Cx, devAdd, Direction_RX);

	//4.Wait for EV6
	//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	while(!I2C_Get_FlagStatus(I2Cx, EV6));

	I2C_AcknowledgeConfig(I2Cx, ENABLE);

	if(dataLen){

		for(i=dataLen; i>1; i--){

			//wait till RXNE becomes 1
			while(!I2C_Get_FlagStatus(I2Cx, EV7));
			//read the data from the data register
			*data = I2Cx->DR;
			//increment to read the next byte
			data++;
		}

		I2C_AcknowledgeConfig(I2Cx, DISABLE);

	}

	if(Stop == With_Stop){
		//Generate stop condition
		I2C_Generate_STOP(I2Cx, ENABLE);
	}

	//re-enable Ack
	if(G_I2C_Config[index].ACK_Control == I2C_Ack_Enable){
		I2C_AcknowledgeConfig(I2Cx, ENABLE);
	}

}

void I2C_Generate_START(I2C_t* I2Cx , FunctionalState NewState , Repeated_Start start)
{
	if(start != repeated_start){
		//Check if Bus is Idle
		while(I2C_Get_FlagStatus(I2Cx, I2C_FLAG_BUSY));
	}

	/*Bit 8START: Start generation
	This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
	In Master Mode:
	0: No Start generation
	1: Repeated start generation
	In Slave mode:
	0: No Start generation
	1: Start generation when the bus is free*/
	if(NewState != DISABLE){
		/* Generate a Start Condition */
		I2Cx->CR1 |= I2C_CR1_START;
	}
	else{
		/* Disable the start condition generation */
		I2Cx->CR1 &= ~(I2C_CR1_START);
	}

}

void I2C_Generate_STOP(I2C_t* I2Cx , FunctionalState NewState)
{
	/*Bit 9STOP: Stop generation
	The bit is set and cleared by software, cleared by hardware when a Stop condition is
	detected, set by hardware when a timeout error is detected.
	In Master Mode:
	0: No Stop generation.
	1: Stop generation after the current byte transfer or after the current Start condition is sent.*/

	if(NewState != DISABLE){
		/* Generate a Stop Condition */
		I2Cx->CR1 |= I2C_CR1_STOP;
	}
	else{
		/*  No Stop generation. */
		I2Cx->CR1 &= ~(I2C_CR1_STOP);
	}
}

void I2C_AcknowledgeConfig(I2C_t* I2Cx , FunctionalState NewState)
{
	/*Bit 10 ACK: Acknowledge enable
	This bit is set and cleared by software and cleared by hardware when PE=0.
	0: No acknowledge returned
	1: Acknowledge returned after a byte is received (matched address or data)*/

	if(NewState != DISABLE){
		/*Acknowledge returned after a byte is received (matched address or data)*/
		I2Cx->CR1 |= I2C_CR1_ACK;
	}

	else{
		/* No acknowledge returned*/
		I2Cx->CR1 &= ~(I2C_CR1_ACK);
	}
}

void I2C_SendAddress(I2C_t* I2Cx , u16 Address , I2C_Direction Direction)
{
	//Supported only 7Bit Mode
	Address = Address << 1;

	if(Direction != Direction_TX){
		/* set the address bit0 for read */
		Address |= 1<<0;
	}
	else{
		/*Reset the address bit0 for write */
		Address &= ~(1 << 0);
	}

	/* Send Address */
	I2Cx->DR = Address;
}

FlagStatus I2C_Get_FlagStatus(I2C_t* I2Cx , Status Flag)
{
	FlagStatus BitStatus = RESET;
	u32 Flag1 = 0 , Flag2 = 0 , LastEvent = 0;

	switch(Flag)
	{
	case I2C_FLAG_BUSY:
		/*Bit 1 BUSY: Bus busy
		0: No communication on the bus
		1: Communication ongoing on the bus
		– Set by hardware on detection of SDA or SCL low
		– cleared by hardware on detection of a Stop condition.
		It indicates a communication in progress on the bus. This information is still updated when
		the interface is disabled (PE=0).*/

		if(I2Cx->SR2 & I2C_SR2_BUSY){
			BitStatus = SET;
		}
		else{
			BitStatus = RESET;
		}
		break;
	case EV5:
		/*Bit 0SB: Start bit (Master mode)
		0: No Start condition
		1: Start condition generated.
		– Set when a Start condition generated.
		– Cleared by software by reading the SR1 register followed by writing the DR register, or by
		hardware when PE=0*/

		if(I2Cx->SR1 & I2C_SR1_SB){
			BitStatus = SET;
		}
		else{
			BitStatus = RESET;
		}
		break;
	case EV6:
		/*Bit 1ADDR: Address sent (master mode)
		   Address sent (Master)
           0: No end of address transmission
           1: End of address transmission
           – For 7-bit addressing, the bit is set after the ACK of the byte.
		 */
		if(I2Cx->SR1 & I2C_SR1_ADDR){
			BitStatus = SET;
		}
		else{
			BitStatus = RESET;
		}
		break;
	case MASTER_BYTE_TRANSMITTING:
		Flag1 = I2Cx->SR1;
		Flag2 = I2Cx->SR2;
		Flag2 = Flag2 << 16;

		LastEvent = (Flag1 | Flag2) & ((u32)0x00FFFFFF);

		if((LastEvent & Flag) == Flag){
			BitStatus = SET;
		}
		else{
			BitStatus = RESET;
		}
		break;
	case EV8_1:
	case EV8:
		/*Bit 7TxE: Data register empty (transmitters)
		0: Data register not empty
		1: Data register empty
		– Set when DR is empty in transmission. TxE is not set during address phase.
		– Cleared by software writing to the DR register or by hardware after a start or a stop condition
		or when PE=0.*/
		if(I2Cx->SR1 & I2C_SR1_TXE){
			BitStatus = SET;
		}
		else{
			BitStatus = RESET;
		}
		break;
	case EV7:
		/*Bit 6RxNE: Data register not empty (receivers)
		0: Data register empty
		1: Data register not empty
		– Set when data register is not empty in receiver mode. RxNE is not set during address phase.
		– Cleared by software reading or writing the DR register or by hardware when PE=0.*/
		if(I2Cx->SR1 & I2C_SR1_RXNE){
			BitStatus = SET;
		}
		else{
			BitStatus = RESET;
		}
		break;
	}

	return BitStatus;
}

