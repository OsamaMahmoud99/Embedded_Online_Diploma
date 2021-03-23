/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Osama Mahmoud
 * @brief          : Toggle Led using TM4C123
 ******************************************************************************
 */


#define SYSCTL_RCGC2_R             (*(volatile unsigned long *)(0x400FE108))
#define GPIO_PORTF_DIR_R           (*(volatile unsigned long *)(0x40025400))
#define GPIO_PORTF_DEN_R           (*(volatile unsigned long *)(0x4002551C))
#define GPIO_PORTF_DATA_R          (*(volatile unsigned long *)(0x400253FC))


int main(void)
{
	volatile unsigned long  Delay_Counter;    // volatile to prevent optimization 
    SYSCTL_RCGC2_R = 0x00000020;                   // set clock
	for( Delay_Counter=0; Delay_Counter<10000; ++Delay_Counter); //wait after set clock
	
	GPIO_PORTF_DIR_R |= 1<<3;
	GPIO_PORTF_DEN_R |= 1<<3;

	while(1)
	{
		GPIO_PORTF_DATA_R |= 1 << 3;      // set bit 3 
		for(Delay_Counter=0; Delay_Counter<200000; ++Delay_Counter);
		GPIO_PORTF_DATA_R &= ~(1 << 3);   // clear bit 3
		for(Delay_Counter=0; Delay_Counter<200000; ++Delay_Counter);
	}
    
	return 0;
}
