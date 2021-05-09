/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Osama Mahmoud
 * @brief          : Clock Configuration
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


typedef volatile unsigned int vuint32_t;
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>


#define RCC_BASE       0x40021000
#define RCC_CFGR       *(vuint32_t *)(RCC_BASE + 0x04)
#define RCC_CR         *(vuint32_t *)(RCC_BASE + 0x00)

void Clock_Init(){

	/*Configure Board to run with the
	Following rates:
	 APB1 Bus frequency 4MHZ
	 APB2 Bus frequency 2MHZ
	 AHB frequency 8 MHZ
	 SysClk 8 MHZ
	 Use only internal HSI_RC*/

	/*Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
		Set and cleared by software to control the division factor of the APB low-speed clock
		(PCLK1).
		Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
		0xx: HCLK not divided
		100: HCLK divided by 2
		101: HCLK divided by 4
		110: HCLK divided by 8
		111: HCLK divided by 16*/
	//RCC_CFGR |= (0b100) << 8;

	/*Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
		Set and cleared by software to control the division factor of the APB high-speed clock
		(PCLK2).
		0xx: HCLK not divided
		100: HCLK divided by 2
		101: HCLK divided by 4
		110: HCLK divided by 8
		111: HCLK divided by 16*/
	//RCC_CFGR |= (0b101) << 11;
/***********************************************************************************************/
	/* Configure Board to run with the
	Following rates:
	 APB1 Bus frequency 16MHZ
	 APB2 Bus frequency 8MHZ
	 AHB frequency 32 MHZ
	 SysClk 32 MHZ
	 Use only internal HSI_RC*/

	/*Bits 1:0 SW: System clock switch
	Set and cleared by software to select SYSCLK source.
	Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
	failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
	System is enabled).
	00: HSI selected as system clock
	01: HSE selected as system clock
	10: PLL selected as system clock
	11: not allowed*/
	RCC_CFGR |= (0b10) << 0;

	/*Bit 16 PLLSRC: PLL entry clock source
	Set and cleared by software to select PLL clock source. This bit can be written only when
	PLL is disabled.
	0: HSI oscillator clock / 2 selected as PLL input clock
	1: HSE oscillator clock selected as PLL input clock*/
	RCC_CFGR &= ~(1 << 16);

	/*Bits 21:18 PLLMUL: PLL multiplication factor
	These bits are written by software to define the PLL multiplication factor. These bits can be
	written only when PLL is disabled.
	Caution: The PLL output frequency must not exceed 72 MHz.
	0000: PLL input clock x 2
	0001: PLL input clock x 3
	0010: PLL input clock x 4
	0011: PLL input clock x 5
	0100: PLL input clock x 6
	0101: PLL input clock x 7
	0110: PLL input clock x 8*/
	RCC_CFGR |= (0b0110) << 18;

	/*Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	Set and cleared by software to control the division factor of the APB low-speed clock
	(PCLK1).
	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/
	RCC_CFGR |= (0b100) << 8;


	/*Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	Set and cleared by software to control the division factor of the APB high-speed clock
	(PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/
	RCC_CFGR |= (0b101) << 11;

	/*Bit 24 PLLON: PLL enable
	Set and cleared by software to enable PLL.
	Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
	PLL clock is used as system clock or is selected to become the system clock.
	0: PLL OFF
	1: PLL ON*/
	RCC_CR |= 1 << 24;

}
int main(void)
{
	Clock_Init();

	while(1)
	{

	}
}
