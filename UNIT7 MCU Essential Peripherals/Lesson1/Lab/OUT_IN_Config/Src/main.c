/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Osama Mahmoud
 * @brief          : Input and Output configuration
 ******************************************************************************
 */
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/* Base Address for RCC */
#define RCC_BASE 0x40021000

/* RCC register map */
#define RCC_APB2ENR   (*(volatile unsigned int*)(RCC_BASE+0x018))


/* GPIO register map */
typedef struct{
	volatile unsigned int CRL;
	volatile unsigned int CRH;
	volatile unsigned int IDR;
	volatile unsigned int ODR;
}GPIO;

/* Base Address for GPIO Port A , GPIO Port B */
#define GPIO_PORTA   ((volatile GPIO*)0x40010800)
#define GPIO_PORTB   ((volatile GPIO*)0x40010C00)

void Delay(unsigned int Time){
	unsigned int i = 0 , j = 0;
	for(i=0; i<Time; ++i){
		for(j=0; j<255; ++j);
	}
}

int main(void)
{
	/* Enable PortA Clock */
	RCC_APB2ENR |= 1 << 2;
	/* Enable PortB Clock */
	RCC_APB2ENR |= 1 << 3;

	/* Config PinA1 for input floating mode */
	GPIO_PORTA->CRL &= ~( (0b1111) << 4);
	GPIO_PORTA->CRL |= (0b0100) << 4;
	/* Config PinB1 for output PushPull mode, max speed 2MHZ */
	GPIO_PORTB->CRL &= ~( (0b1111) << 4);
	GPIO_PORTB->CRL |= (0b0010) << 4;
	/* Config PinA1 for input floating mode */
	GPIO_PORTA->CRH &= ~( (0b1111) << 4);
	GPIO_PORTA->CRH |= (0b0100) << 20;
	/* Config PinB13 for output PushPull mode, max speed 2MHZ */
	GPIO_PORTB->CRH &= ~( (0b1111) << 20);
	GPIO_PORTB->CRH |= (0b0010) << 20;


	while(1){
		if(((GPIO_PORTA->IDR &(1 << 1)) >> 1) == 0){
			GPIO_PORTB->ODR ^= 1 << 1;
			while((((GPIO_PORTA->IDR &(1 << 1)) >> 1) == 0)); // single pressing
		}

		if(((GPIO_PORTA->IDR &(1 << 13)) >> 13) == 1){
			GPIO_PORTB->ODR ^= 1 << 13;                // Multi Pressing
		}
		Delay(1);
	}


}
