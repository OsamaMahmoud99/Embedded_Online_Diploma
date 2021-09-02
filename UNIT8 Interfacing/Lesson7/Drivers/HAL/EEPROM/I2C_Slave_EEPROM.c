/*
 * I2C_Slave_EEPROM.c
 *
 *  Created on: Sep 1, 2021
 *      Author: Osama Mahmoud
 */

#include "I2C_Slave_EEPROM.h"

void EEPROM_Init(void)
{
	//===================I2C_Init=========================
	//     PB6 : I2C1_SCL
	//     PB7 : I2C1_SDA

	I2C_Config I2C1CFG;

	I2C1CFG.ACK_Control = I2C_Ack_Enable;
	I2C1CFG.ClockSpeed  = I2C_SCLK_SM_100K;
	I2C1CFG.Mode = I2C_Mode;
	I2C1CFG.P_Slave_Event_CallBack = NULL;
	I2C1CFG.StretchMode = I2C_StretchMode_Enable;

	I2C_GPIO_SetPins(I2C1);
	I2C_Init(I2C1, &I2C1CFG);
}

u8 EEPROM_Write_NBytes(unsigned int Memory_Address , u8* bytes , u8 DataLen)
{
	u8 i = 0 , Buffer[256];

	Buffer[0] = (u8)(Memory_Address >> 8);        //Upper Address Byte
	Buffer[1] = (u8)(Memory_Address);             //Lower Address Byte

	for(i=2; i<(DataLen+2); ++i){
		Buffer[i] = bytes[i - 2];
	}

	I2C_Master_TX(I2C1, EEPROM_Slave_Address, Buffer, (DataLen+2), With_Stop, Start);

	return 0;
}

u8 EEPROM_Read_Byte(unsigned int Address , u8* DataOut , u8 DataLen)
{
	u8 Buffer[2];

	Buffer[0] = (u8)(Address >> 8);        //Upper Address Byte
	Buffer[1] = (u8)(Address);             //Lower Address Byte

	I2C_Master_TX(I2C1, EEPROM_Slave_Address, &Buffer, 2 , Without_Stop, Start);

	I2C_Master_RX(I2C1, EEPROM_Slave_Address, DataOut, DataLen, With_Stop, repeated_start);

	return 0;


}


