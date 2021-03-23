/* startup_cortexm4.c
Eng.Osama Mahmoud
*/

#include <stdint.h>

void Reset_Handler();

extern int main(void);

extern unsigned int _E_text;
extern unsigned int _S_Data;
extern unsigned int _E_Data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Default_Handler(void)
{
	Reset_Handler();
}

void NMI_Handler() __attribute__ ((weak, alias ("Default_Handler")));;
void H_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));;

static unsigned long Stack_Top[256]; // 256*4 = 1024 byte 


/*uint32_t vectors[] __attribute__((section(".vectors")))= {
	(uint32_t) (&Stack_Top[0] + sizeof(Stack_Top)),
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_Fault_Handler
};*/

void (*const g_p_fn_vectors[])() __attribute__((section(".vectors"))) = //array of const pointer to function take and return nothing
{
	(void(*)()) ((unsigned long)Stack_Top + sizeof(Stack_Top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler
};



void Reset_Handler()
{
	int i , j;
	//Copy data section from flash to ram
	unsigned int Data_Size = (unsigned char*)&_E_Data - (unsigned char*)&_S_Data;
	unsigned char* P_src = (unsigned char*)&_E_text;
	unsigned char* P_dst = (unsigned char*)&_S_Data;
	
	for(i=0; i<Data_Size; ++i)
	{
		*((unsigned char *)P_dst++) = *((unsigned char *)P_src++);
	}
	
	unsigned int bss_Size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss;
	
	for(j=0; j<bss_Size; ++j)
	{
		*((unsigned char *)P_dst++) = (unsigned char)0;
	}
	
	// Jump to main
	
	main();
}



