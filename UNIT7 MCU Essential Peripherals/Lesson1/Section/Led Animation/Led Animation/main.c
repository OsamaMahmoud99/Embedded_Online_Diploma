/*
 * Led Animation.c
 *
 * Created: 7/1/2021 8:09:06 AM
 * Author : Osama Mahmoud
 */ 

#include <util/delay.h>
#define  F_CPU 8000000UL

/* Address of DDRD , POTTD */
#define GPIO_PORTD   (*(volatile unsigned char *)0x32)
#define GPIO_DDRD    (*(volatile unsigned char *)0x31)

int main(void)
{   
	/* config DDRD for output mode */
    GPIO_DDRD = 0xff;
	/* Reset PORTD */
	GPIO_PORTD = 0x00;
    while (1) 
    {
		for (int i=0; i<=255; i=i*2+1)
		{
			GPIO_PORTD = i;
			_delay_ms(1000);
		}
		for (int i=255; i>=1; i=i/2)
		{
			GPIO_PORTD = i;
			_delay_ms(1000);
		}
    }
}

