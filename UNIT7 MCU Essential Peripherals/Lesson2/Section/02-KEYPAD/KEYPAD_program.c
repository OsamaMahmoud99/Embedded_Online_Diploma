#include "STD_TYPES.h"
#include "KEYPAD_interface.h"



#ifdef keypad4X4_KIT
static u8  keypadchars[4][4] = {       {'1','2','3','a'},
                                       {'4','5','6','b'},
                                       {'7','8','9','c'},
                                       {'*','0','#','d'}
                                     };
#elif defined(keypad4X4_PROTEUS)
static u8   keypadchars[4][4] = {     {'7','8','9','/'},
                                      {'4','5','6','*'},
                                      {'1','2','3','-'},
                                      {'a','0','=','+'}};
#elif defined (Design)
static u8   keypadchars[4][3] = {       {'1','2','3'},
                                        {'4','5','6'},
                                        {'7','8','9'},
                                        {'*','0','#'}};
                                    
#endif

u8 Kepad_Row[] = {R0 , R1 , R2 , R3};
u8 Kepad_Col[] = {C0 , C1 , C2 , C3};

void KEYPAD_voidInit(void)
{
	
	KEYPAD_DDR &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3)); // the upper part(Rows) Input
	KEYPAD_DDR |=  ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3)); // the lower part(Columns) Output
	KYPAD_PORT = 0xFF; // Row and Columns High
}

u8 KEYPAD_u8GetChar(void)
{
	u8 col = 0;      //counter for loop
	u8 row = 0;      //get value of row
	u8 key = 'N' ;
	
	for (col=0; col<COL_NUM; ++col)
	{
		KEYPAD_PORT |= ((1<<Kepad_Col[0]) | (1<<Kepad_Col[1]) | (1<<Kepad_Col[2]) | (1<<Kepad_Col[3]));
		KEYPAD_PORT &= ~((1<<Kepad_Col[col]); 
		_delay_ms(10);
		
		for(row=0; row < COL_NUM; ++row)
		{
			if(!(KEYPAD_PIN & (1<<Kepad_Row[row])))    // Check if key is pressed
			{
				while( !(KEYPAD_PIN & (1<<Kepad_Row[row])));  // wait for key to be released
				
				switch(col)
				{
					case 0:
					    if(row == 0) key = '7';
					    else if(row == 1) key = '4';
					    else if(row == 2) key = '1';
					    else if(row == 3) key = 'a';
					    break;
				    case 1:
					    if(row == 0) key = '8';
					    else if(row == 1) key = '5';
					    else if(row == 2) key = '2';
					    else if(row == 3) key = '0';
					    break;
					case 2:
					    if(row == 0) key = '9';
					    else if(row == 1) key = '6';
					    else if(row == 2) key = '3';
					    else if(row == 3) key = '=';
					    break;
					case 3:
					    if(row == 0) key = '/';
					    else if(row == 1) key = '*';
					    else if(row == 2) key = '-';
					    else if(row == 3) key = '+';
					    break;
				}
			}
		}
	}
	return key;
}

	
	
	
	 
	 
	 

