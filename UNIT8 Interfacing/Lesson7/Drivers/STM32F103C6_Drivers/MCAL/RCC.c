/*
 * RCC.c
 *
 *  Created on: Jul 28, 2021
 *      Author: Osama Mahmoud
 */

#include "RCC.h"

/*Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16
*/
const u8 APBPrescaler[8] = {0,0,0,0,1,2,3,4};    // shift right by 1 means divide by 2

/*Bits 7:4 HPRE[3:0]: AHB prescaler
Set and cleared by software to control AHB clock division factor.
0xxx: SYSCLK not divided
1000: SYSCLK divided by 2
1001: SYSCLK divided by 4
1010: SYSCLK divided by 8
1011: SYSCLK divided by 16
1100: SYSCLK divided by 64
1101: SYSCLK divided by 128
1110: SYSCLK divided by 256
1111: SYSCLK divided by 512
*/
const u8 AHBPrescaler[16] = {0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8};




u32 RCC_GetSYCLKFreq(void)
{
	/*Bits 3:2SWS[1:0]: System clock switch status
	Set and cleared by hardware to indicate which clock source is used as system clock.
	00: HSI oscillator used as system clock
	01: HSE oscillator used as system clock
	10: PLL used as system clock
	11: Not applicable
	*/
	u32 CLK;
	switch( (RCC->CFGR >> 2) & 0b11)
	{
	case 0:
		CLK =  HSI_CLK;
		break;
	case 1:
		CLK =  HSE_CLK;
		break;
	}

	return CLK;
}

u32 RCC_GetHCLKFreq(void)
{
	//Bits 7:4 HPRE[3:0]: AHB prescaler
	return (RCC_GetSYCLKFreq() >> AHBPrescaler[(RCC->CFGR >> 4) & 0b1111]);
}

u32 RCC_GetPCLK1Freq(void)
{
	//Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
	return (RCC_GetHCLKFreq() >> APBPrescaler[(RCC->CFGR >> 8) & 0b111]);
}

u32 RCC_GetPCLK2Freq(void)
{
	//Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
	return (RCC_GetHCLKFreq() >> APBPrescaler[(RCC->CFGR >> 11) & 0b111]);
}


