/*
 * I2C_Slave_EEPROM.h
 *
 *  Created on: Sep 1, 2021
 *      Author: Osama Mahmoud
 */

#ifndef EEPROM_I2C_SLAVE_EEPROM_H_
#define EEPROM_I2C_SLAVE_EEPROM_H_

#include "I2C.h"



#define EEPROM_Slave_Address    0x2A


void EEPROM_Init(void);
u8 EEPROM_Write_NBytes(unsigned int Memory_Address , u8* bytes , u8 DataLen);
u8 EEPROM_Read_Byte(unsigned int Address , u8* DataOut , u8 DataLen);

#endif /* EEPROM_I2C_SLAVE_EEPROM_H_ */
