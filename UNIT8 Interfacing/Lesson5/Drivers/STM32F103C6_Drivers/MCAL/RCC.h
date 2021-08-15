/*
 * RCC.h
 *
 *  Created on: Jul 28, 2021
 *      Author: Osama Mahmoud
 */

#ifndef MCAL_RCC_H_
#define MCAL_RCC_H_

#include "STM32F103C6.h"


#define HSI_CLK         (u32)8000000
#define HSE_CLK         (u32)16000000

u32 RCC_GetSYCLKFreq(void);
u32 RCC_GetHCLKFreq(void);
u32 RCC_GetPCLK1Freq(void);
u32 RCC_GetPCLK2Freq(void);




#endif /* MCAL_RCC_H_ */
