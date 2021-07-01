/*
 * LedAnimation by switch.c
 *
 * Created: 7/1/2021 9:33:39 AM
 * Author : Osama Mahmoud
 */ 

#include <util/delay.h>
#define  F_CPU 8000000UL

/* Address of DDRD , POTTD , DDRA , PINA */
#define GPIO_PORTD   (*(volatile unsigned char *)0x32)
#define GPIO_DDRD    (*(volatile unsigned char *)0x31)
#define GPIO_DDRA    (*(volatile unsigned char *)0x3A)
#define GPIO_PINA    (*(volatile unsigned char *)0x39)

/* Macro to check bit if it 1 or 0 */
#define  READ_BIT(REG, BIT)        ((REG>>BIT) & 1) 

int main(void)
{
    /* config DDRD for output mode */
    GPIO_DDRD = 0xff;
    /* Reset PORTD */
    GPIO_PORTD = 0x00;
	/* Config PinA1 for input mode */
	GPIO_DDRA &= ~(1 << 1);
	
	int i = 0;
    while (1) 
    {
		if ( READ_BIT(GPIO_PINA , 1) == 1)
		{
			i = i*2+1;
			GPIO_PORTD = i;
			while(READ_BIT(GPIO_PINA , 1) == 1); /*polling for single pressing because the processor is faster than my pressing in switch so 
			                                       it executes the sequence of code by one pressing */
		}
    }
}

