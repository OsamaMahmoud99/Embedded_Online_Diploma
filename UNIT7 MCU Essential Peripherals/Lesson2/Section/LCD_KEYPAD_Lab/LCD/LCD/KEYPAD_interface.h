#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include <avr/io.h>
#include <util/delay.h>


/****** keypad4X4_KIT 
        keypad4X4_PROTEUS
        Design
                            ******/		
#define  keypad4X4_PROTEUS

#define   COL_NUM  4

#define   R0  0
#define   R1  1
#define   R2  2
#define   R3  3
#define   C0  4
#define   C1  5
#define   C2  6
#define   C3  7


#define   KEYPAD_PORT        PORTC
#define   KEYPAD_PIN         PINC
#define   KEYPAD_DDR         DDRC 
  
  
   
void KEYPAD_voidInit(void);
u8   kEYPAD_u8GetChar(void);






#endif 
