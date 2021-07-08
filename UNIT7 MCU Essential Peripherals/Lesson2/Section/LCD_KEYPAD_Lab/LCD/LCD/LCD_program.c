#include "LCD_interface.h"
/************************************* 8 BIT Mode functions********************************************/
#if (LCD_MODE==M_8BIT)

static void LCD_WriteCommand(u8 Command)
{
	LCD_PORT_ControlData &= ~((1 << RS) | (1 << RW)); 
	LCD_PORT_Data = Command;
	LCD_PORT_ControlData |= 1 << EN;
	_delay_ms(2);
	LCD_PORT_ControlData &= ~(1 << EN);
	_delay_ms(2);
}

void LCD_Init(void)
{
	
	_delay_ms(50);          // said in Data sheet to delay after power on for 1st time
	
	LCD_PORT_ControlDirection |= ((1 << EN) | (1 << RS) | (1 << RW));
	LCD_PORT_ControlData &= ~((1 << EN) | (1 << RS) | (1 << RW));
	
    LCD_PORT_Direction = 0xff;	
	
	LCD_WriteCommand(LCD_FUNCTION_8BIT_2LINES); //N=1 , F=0
	_delay_ms(1);           //delay 1ms a must delay as said in Data sheet
	LCD_WriteCommand(LCD_DISP_ON); //D=1(LCD itself on or off) C=0, B=0
	_delay_ms(1);    //delay 1ms
	LCD_WriteCommand(LCD_CLEAR_SCREEN); //clear LCD
	_delay_ms(20);
	LCD_WriteCommand(LCD_ENTRY_MODE); //Entry Mode
	LCD_WriteCommand(LCD_BEGIN_AT_FIRST_ROW);
}

static void LCD_WriteData(u8 Data)
{
	LCD_PORT_ControlData |= 1 << RS;
	LCD_PORT_ControlData &= ~(1 << RW);
	LCD_PORT_Data = Data;
	LCD_PORT_ControlData |= 1 << EN;
	_delay_ms(2);
	LCD_PORT_ControlData &= ~(1 << EN);
	_delay_ms(2);
}
/************************************* 4 BIT Mode functions********************************************/
#elif (LCD_MODE==M_4BIT_SAMEPORT)



static void LCD_WriteCommand(u8 Command)
{
	LCD_PORT_ControlData &= ~((1 << RS) | (1 << RW));

	LCD_PORT_Data = (LCD_PORT_Data & 0x0f) | (Command & 0xf0);
	LCD_PORT_ControlData |= 1 << EN;
	_delay_ms(2);
	LCD_PORT_ControlData &= ~(1 << EN);
	_delay_ms(2);
	
	LCD_PORT_Data = (LCD_PORT_Data & 0x0f) | (Command << 4);
	LCD_PORT_ControlData |= 1 << EN;
	_delay_ms(2);
	LCD_PORT_ControlData &= ~(1 << EN);
	_delay_ms(2);
}

 static void LCD_WriteData(u8 Data)
{
	LCD_PORT_ControlData |= 1 << RS;
	LCD_PORT_ControlData &= ~(1 << RW);
	
	LCD_PORT_Data = (LCD_PORT_Data & 0x0f) | (Data & 0xf0);
	LCD_PORT_ControlData |= 1 << EN;
	_delay_ms(2);
	LCD_PORT_ControlData &= ~(1 << EN);
	_delay_ms(2);
	
	LCD_PORT_Data = (LCD_PORT_Data & 0x0f) | (Data << 4);
	LCD_PORT_ControlData |= 1 << EN;
	_delay_ms(2);
	LCD_PORT_ControlData &= ~(1 << EN);
	_delay_ms(2);
}
void LCD_Init(void)
{
	
	_delay_ms(50);          // said in Data sheet to delay after power on for 1st time
	
	LCD_PORT_ControlDirection |= ((1 << EN) | (1 << RS) | (1 << RW));
	LCD_PORT_ControlData &= ~((1 << EN) | (1 << RS) | (1 << RW));
	
	LCD_PORT_Direction = 0xff;
	
	LCD_WriteCommand(0x02);//4 bit mode only
	_delay_ms(1); 
	LCD_WriteCommand(LCD_FUNCTION_4BIT_2LINES); //N=1 , F=0
	_delay_ms(1);           //delay 1ms a must delay as said in Data sheet
	LCD_WriteCommand(LCD_DISP_ON); //D=1(LCD itself on or off) C=0, B=0
	_delay_ms(1);    //delay 1ms
	LCD_WriteCommand(LCD_CLEAR_SCREEN); //clear LCD
	_delay_ms(20);
	LCD_WriteCommand(LCD_ENTRY_MODE);
	LCD_WriteCommand(LCD_BEGIN_AT_FIRST_ROW);
}

#endif

/*************************** service functions*****************************************************/

void LCD_WriteChar(u8 character)
{
	LCD_WriteData(character);
}
void LCD_Clear(void)
{
	LCD_WriteCommand(LCD_CLEAR_SCREEN);
}
void LCD_GoTo(u8 Line, u8 x)
{
	if(0 == Line)
	{
		if ( x <=15)
		{
			LCD_WriteCommand(0x80 + x);
		}
	}
	else if (1 == Line)
	{
		if ( x <=15)
		{
			LCD_WriteCommand(0xC0 + x);
		}
	}
}
void LCD_WriteSentence(u8 *PtrSentance)
{
	u8 Count=0;
	
	while(*PtrSentance > 0){
		
		Count++;
		LCD_WriteChar(*PtrSentance++);
		if(Count == 16){       // go to the second line
			LCD_GoTo(1 , 0);   // line 1 position 0
		}
		else if(Count == 32  || Count == 33){
			LCD_Clear();
			LCD_GoTo(0 , 0);   // line 0 position 0
			Count = 0;
		}
	}

}
void LCD_WriteNumber(u64 Number)
{
	u8 i=0,arr[10],j;
	if(Number==0)
	LCD_WriteData('0');
	else{
			while(Number)
			{
				arr[i]=Number%10+'0';
				Number/=10;
				i++;
			}
			for(j=i;j>0;j--)
			{
				LCD_WriteData(arr[j-1]);
			}
	   }
}
void LCD_WriteNumber3(u16 Number)
{
	LCD_WriteData(Number%1000/100+'0');
	LCD_WriteData(Number%100/10+'0');
	LCD_WriteData(Number%10/1+'0');
	
}
void LCD_WriteNumber4(u16 Number)
{
	LCD_WriteData(Number%10000/1000+'0');
	LCD_WriteData(Number%1000/100+'0');
	LCD_WriteData(Number%100/10+'0');
	LCD_WriteData(Number%10/1+'0');
}
void LCD_WriteRealNumber(double Number)
{
	char Str[16];
	
	char *TmpSign = (Number < 0) ? "-" : "";
	float TmpVal  = (Number < 0) ? -Number : Number;
	
	int TmpInt1 = TmpVal;
	float TmpFrac = TmpVal - TmpInt1;
	int TmpInt2 = TmpFrac * 1000;
	
	sprintf(Str, "%s%d.%04d", TmpSign , TmpInt1 , TmpInt2);
	
	LCD_WriteSentence(Str);
}
void Create_Character(u8 *Pattern,u8 Location) {

	u8 iLoop=0;

	LCD_WriteCommand(0x40+(Location*8)); //Send the Address of CGRAM
	for(iLoop=0;iLoop<8;iLoop++)
	LCD_WriteData(Pattern[iLoop]); //Pass the bytes of pattern on LCD

}


	

