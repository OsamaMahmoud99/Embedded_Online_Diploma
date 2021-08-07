#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_


#define  keypad4X4_PROTEUS

#define  NOT_PRESSED               0x0f      
#define  COL_NUM                    4

#define  R0     PINA0
#define  R1     PINA1
#define  R2     PINA2
#define  R3     PINA3
#define  C0     PINA4
#define  C1     PINA5
#define  C2     PINA6
#define  C3     PINA7 



void KEYPAD_voidInit(void);
u8   KEYPAD_u8GetChar(void);
u8   KEYPAD_u8GetPressed(void);





#endif 
