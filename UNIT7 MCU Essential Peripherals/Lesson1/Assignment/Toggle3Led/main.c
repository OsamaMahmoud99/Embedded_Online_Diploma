/*
 * Toggle3Led.c
 *
 * Created: 6/30/2021 9:46:29 AM
 * Author : Osama Mahmoud
 */ 

#define  F_CPU 8000000UL

/* Base Address of DDRD , POTTD */
#define GPIO_PORTD   (*(volatile unsigned char *)0x32)
#define GPIO_DDRD    (*(volatile unsigned char *)0x31)

void Delay(unsigned int Time){
	unsigned int i = 0;
	for(i=0; i< ((F_CPU/(12000))*Time); ++i){
         __asm("NOP");          // No Operation by Assembly
	}
}


int main(void){
	
    /* PortD pin 5 , 6 , 7 Output(Led) */
	GPIO_DDRD |= 1 << 5;
	GPIO_DDRD |= 1 << 6;
	GPIO_DDRD |= 1 << 7;
	
	/* PortD pin 4 Output(Buzzer) */
	GPIO_DDRD |= 1 << 4;
	
    while (1) {
		
		for (int i=5; i<=7; ++i){
			GPIO_PORTD |= 1 << i;     //Set Bit 
			Delay(95);
			GPIO_PORTD &= ~(1 << i);  //Clear Bit
			Delay(95);
		}
		GPIO_PORTD |= 1 << 4;
		Delay(95);
		GPIO_PORTD &= ~(1 << 4);
		Delay(95);
    }
}

