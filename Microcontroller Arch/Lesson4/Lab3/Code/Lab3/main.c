/*
 * Lab3.c
 *
 * Created: 5/10/2021 4:56:47 PM
 * Author : Osama Mahmoud
 */ 

#define  F_CPU  8000000UL

#include <avr/interrupt.h>
#include <util/delay.h>

/* Registers for GPIO */
#define GPIO_PORTD   (*(volatile unsigned char *)0x32)
#define GPIO_DDRD    (*(volatile unsigned char *)0x31)
#define GPIO_DDRB    (*(volatile unsigned char *)0x37)

/* Registers for interrupt */
#define INT_GICR     (*(volatile unsigned char *)0x5B) // GICR – General Interrupt Control Register
#define INT_SREG     (*(volatile unsigned char *)0x5F) // SREG – AVR Status Register
#define INT_MCUCR    (*(volatile unsigned char *)0x55) // MCUCR – MCU Control Register
#define INT_MCUCSR   (*(volatile unsigned char *)0x54) // MCUCSR – MCU Control and Status Register
#define INT_GIFR     (*(volatile unsigned char *)0x5A) // GIFR – General Interrupt Flag Register


void GPIO_init(void){
	/* Config Pin 5 , 6 , 7 Output */
	GPIO_DDRD |= 1 << 5 | 1<< 6 | 1 << 7;
	/* Config Pin 2 , 3 Input */
	GPIO_DDRD &= ~(1 << 2);
	GPIO_DDRD &= ~(1 << 3);
	/* Config pin 2 input */
	GPIO_DDRB &= ~(1 << 2);
}

void INTERRUPT_init(void){
	/* Enable Global Interrupt */
	INT_SREG |= 1 << 7;
	/* Enable bit 5 , 6 , 7 in GICR */
	INT_GICR |= 1 << 5 | 1 << 6 | 1 << 7;
	/* Any logical change for INT0 */
	INT_MCUCR |= (0b01) << 0;
	/* rising edge for INT1 */
	INT_MCUCR |= (0b11) << 2;
	/* Falling edge for INT2 */
	INT_MCUCSR &= ~(1 << 6); // Bit 6 – ISC2: Interrupt Sense Control 2
	
}

int main(void)
{
    GPIO_init();
	INTERRUPT_init();
	
    while (1) 
    {
		/* All leds off */
		GPIO_PORTD &= ~(1 << 5);
		GPIO_PORTD &= ~(1 << 6);
		GPIO_PORTD &= ~(1 << 7);
    }
}

ISR(INT0_vect){
	GPIO_PORTD |= 1 << 5;
	_delay_ms(1000);
}

ISR(INT1_vect){
	GPIO_PORTD |= 1 << 6;
	_delay_ms(1000);
}

ISR(INT2_vect){
	GPIO_PORTD |= 1 << 7;
	_delay_ms(1000);
}



