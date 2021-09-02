/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Osama Mahmoud
 * @brief          : Main program body
 ******************************************************************************
 */


#include "STM32F103C6.h"
#include "GPIO.h"
#include "I2C.h"
#include "EEPROM/I2C_Slave_EEPROM.h"



int main()
{

	//Test case 1
	u8 ch1[] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7};
	u8 ch2[7]= {0};

	EEPROM_Init();
	EEPROM_Write_NBytes(0xAF, ch1, 7);
	EEPROM_Read_Byte(0xAF, ch2, 7);


	//Test case 2
	ch1[0] = 0xA;
	ch1[1] = 0xB;
	ch1[2] = 0xC;
	ch1[3] = 0xD;

	EEPROM_Write_NBytes(0xFFF, ch1, 4);
	EEPROM_Read_Byte(0xFFF, ch2, 4);

	while(1)
	{

	}
}
