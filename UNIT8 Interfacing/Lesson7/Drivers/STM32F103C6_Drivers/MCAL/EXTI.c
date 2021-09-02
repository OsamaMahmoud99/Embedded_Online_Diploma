/*
 * EXTI.c
 *
 *  Created on: Jul 18, 2021
 *      Author: Osama Mahmoud
 */

#include "EXTI.h"
#include "GPIO.h"


/*
 * =================================================================
 *                            Global Variables
 * =================================================================
 */

// Array of Pointer to function take no thing and return no thing
void(*GP_IRQ_CallBack[15])(void);

/*
 * =================================================================
 *                            Generic Macros
 * =================================================================
 */

/* 0000: PA[x] pin
   0001: PB[x] pin
   0010: PC[x] pin
   0011: PD[x] pin
 *
 */
#define AFIO_GPIO_EXTI_Mapping(X) (  (X == GPIOA)?0:\
		(X == GPIOB)?1:\
				(X == GPIOC)?2:\
						(X == GPIOD)?3:0  )

/*
 * =================================================================
 *                            Generic Functions
 * =================================================================
 */

void NVIC_Enable_IRQ(u16 IRQ)
{
	switch(IRQ)
	{
	case EXTI_LINE0:
		NVIC_IRQ_EXTI_Enable(EXTI0IRQn);
		break;
	case EXTI_LINE1:
		NVIC_IRQ_EXTI_Enable(EXTI1IRQn);
		break;
	case EXTI_LINE2:
		NVIC_IRQ_EXTI_Enable(EXTI2IRQn);
		break;
	case EXTI_LINE3:
		NVIC_IRQ_EXTI_Enable(EXTI3IRQn);
		break;
	case EXTI_LINE4:
		NVIC_IRQ_EXTI_Enable(EXTI4IRQn);
		break;
	case EXTI_LINE5:
	case EXTI_LINE6:
	case EXTI_LINE7:
	case EXTI_LINE8:
	case EXTI_LINE9:
		NVIC_IRQ_EXTI_Enable(EXTI5IRQn);
		break;
	case EXTI_LINE10:
	case EXTI_LINE11:
	case EXTI_LINE12:
	case EXTI_LINE13:
	case EXTI_LINE14:
	case EXTI_LINE15:
		NVIC_IRQ_EXTI_Enable(EXTI10IRQn);
		break;
	}
}

void NVIC_Disable_IRQ(u16 IRQ)
{
	switch(IRQ)
	{
	case EXTI_LINE0:
		NVIC_IRQ_EXTI_Disable(EXTI0IRQn);
		break;
	case EXTI_LINE1:
		NVIC_IRQ_EXTI_Disable(EXTI1IRQn);
		break;
	case EXTI_LINE2:
		NVIC_IRQ_EXTI_Disable(EXTI2IRQn);
		break;
	case EXTI_LINE3:
		NVIC_IRQ_EXTI_Disable(EXTI3IRQn);
		break;
	case EXTI_LINE4:
		NVIC_IRQ_EXTI_Disable(EXTI4IRQn);
		break;
	case EXTI_LINE5:
	case EXTI_LINE6:
	case EXTI_LINE7:
	case EXTI_LINE8:
	case EXTI_LINE9:
		NVIC_IRQ_EXTI_Disable(EXTI5IRQn);
		break;
	case EXTI_LINE10:
	case EXTI_LINE11:
	case EXTI_LINE12:
	case EXTI_LINE13:
	case EXTI_LINE14:
	case EXTI_LINE15:
		NVIC_IRQ_EXTI_Disable(EXTI10IRQn);
		break;
	}
}

void Update_EXTI(EXTI_PinConfig_t* EXTI_Config)
{
	//1- Configure GPIO to the AF Input -> Floating Input
	GPIO_SetPinDirection(EXTI_Config->EXTI_PIN.GPIO_Port, EXTI_Config->EXTI_PIN.GPIO_PIN, INPUT_FLOATING);

	//===================================================================================
	//2- Update AFIO to Route between EXTI Line With Port A,B,C,D
	u8 AFIO_EXTICRx_Index = EXTI_Config->EXTI_PIN.EXTI_Line_Number / 4;  // EXTICR[0] ---> EXTICR[3]
	u8 AFIO_EXTICRx_Position = ((EXTI_Config->EXTI_PIN.EXTI_Line_Number%4)*4);

	// Clear the four bits
	AFIO->EXTICRx[AFIO_EXTICRx_Index] &= ~((0b1111) << AFIO_EXTICRx_Position);
	AFIO->EXTICRx[AFIO_EXTICRx_Index] |=  ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port) & 0xF) << AFIO_EXTICRx_Position);

	//====================================================================================
	//3- Update Rising or Falling Edge
	CLEAR_BIT(EXTI->RTSR , EXTI_Config->EXTI_PIN.EXTI_Line_Number);
	CLEAR_BIT(EXTI->FTSR , EXTI_Config->EXTI_PIN.EXTI_Line_Number);

	if(EXTI_Config->EXTI_Mode == EXTI_RISING_EDGE)
	{
		SET_BIT(EXTI->RTSR , EXTI_Config->EXTI_PIN.EXTI_Line_Number);
	}
	else if(EXTI_Config->EXTI_Mode == EXTI_FALLING_EDGE)
	{
		SET_BIT(EXTI->FTSR , EXTI_Config->EXTI_PIN.EXTI_Line_Number);
	}
	else if(EXTI_Config->EXTI_Mode == EXTI_ON_CHANGE)
	{
		SET_BIT(EXTI->RTSR , EXTI_Config->EXTI_PIN.EXTI_Line_Number);
		SET_BIT(EXTI->FTSR , EXTI_Config->EXTI_PIN.EXTI_Line_Number);
	}

	//====================================================================================
	//4- Update IRQ Handling CallBack

	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_Line_Number] = EXTI_Config->P_IRQ_CallBack;

	//====================================================================================
	//5- Enable/Disable IRQ & NVIC

	if(EXTI_Config->IRQ_EN == EXTI_IRQ_Enable)
	{
		SET_BIT(EXTI->IMR , EXTI_Config->EXTI_PIN.EXTI_Line_Number);
		NVIC_Enable_IRQ(EXTI_Config->EXTI_PIN.EXTI_Line_Number);
	}
	else if(EXTI_Config->IRQ_EN == EXTI_IRQ_Disable)
	{
		CLEAR_BIT(EXTI->IMR , EXTI_Config->EXTI_PIN.EXTI_Line_Number);
		NVIC_Disable_IRQ(EXTI_Config->EXTI_PIN.EXTI_Line_Number);
	}
}

/*
 * ==================================================================
 *                            APIS Functions Definitions
 * ==================================================================
 */

void EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}
void EXTI_GPIO_DeInit(void)
{
	EXTI->IMR   =  0x00000000;
	EXTI->EMR   =  0x00000000;
	EXTI->RTSR  =  0x00000000;
	EXTI->FTSR  =  0x00000000;
	EXTI->SWIER =  0x00000000;

	//This bit is cleared by writing a ‘1’ into the bit.
	EXTI->PR    =  0xFFFFFFFF;

	NVIC_IRQ_EXTI_Disable(EXTI0IRQn);
	NVIC_IRQ_EXTI_Disable(EXTI1IRQn);
	NVIC_IRQ_EXTI_Disable(EXTI2IRQn);
	NVIC_IRQ_EXTI_Disable(EXTI3IRQn);
	NVIC_IRQ_EXTI_Disable(EXTI4IRQn);
	NVIC_IRQ_EXTI_Disable(EXTI5IRQn);   // 5 - 9
	NVIC_IRQ_EXTI_Disable(EXTI10IRQn);  // 10 - 15

}

void EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}

/*
 * ==================================================================
 *                            ISR Functions Definitions
 * ==================================================================
 */

void EXTI0_IRQHandler(void)
{
	if (EXTI->PR & 1<<0)  { EXTI->PR |= 1<<0  ; GP_IRQ_CallBack[0]()  ; }
}

void EXTI1_IRQHandler(void)
{
	if (EXTI->PR & 1<<1)  { EXTI->PR |= 1<<1  ; GP_IRQ_CallBack[1]()  ; }
}

void EXTI2_IRQHandler(void)
{
	if (EXTI->PR & 1<<2)  { EXTI->PR |= 1<<2  ; GP_IRQ_CallBack[2]() ; }
}

void EXTI3_IRQHandler(void)
{
	if (EXTI->PR & 1<<3)  { EXTI->PR |= 1<<3  ; GP_IRQ_CallBack[3]() ; }
}

void EXTI4_IRQHandler(void)
{
	if (EXTI->PR & 1<<4)  { EXTI->PR |= 1<<4  ; GP_IRQ_CallBack[4]() ; }
}

void EXTI5_9_IRQHandler(void)
{
	if (EXTI->PR & 1<<5)  { EXTI->PR |= 1<<5  ; GP_IRQ_CallBack[5]()  ; }
	if (EXTI->PR & 1<<6)  { EXTI->PR |= 1<<6  ; GP_IRQ_CallBack[6]()  ; }
	if (EXTI->PR & 1<<7)  { EXTI->PR |= 1<<7  ; GP_IRQ_CallBack[7]()  ; }
	if (EXTI->PR & 1<<8)  { EXTI->PR |= 1<<8  ; GP_IRQ_CallBack[8]()  ; }
	if (EXTI->PR & 1<<9)  { EXTI->PR |= 1<<9  ; GP_IRQ_CallBack[9]()  ; }
}

void EXTI10_15_IRQHandler(void)
{

	if (EXTI->PR & 1<<10) { EXTI->PR |= 1<<10 ; GP_IRQ_CallBack[10]() ; }
	if (EXTI->PR & 1<<11) { EXTI->PR |= 1<<11 ; GP_IRQ_CallBack[11]() ; }
	if (EXTI->PR & 1<<12) { EXTI->PR |= 1<<12 ; GP_IRQ_CallBack[12]() ; }
	if (EXTI->PR & 1<<13) { EXTI->PR |= 1<<13 ; GP_IRQ_CallBack[13]() ; }
	if (EXTI->PR & 1<<14) { EXTI->PR |= 1<<14 ; GP_IRQ_CallBack[14]() ; }
	if (EXTI->PR & 1<<15) { EXTI->PR |= 1<<15 ; GP_IRQ_CallBack[15]() ; }
}

