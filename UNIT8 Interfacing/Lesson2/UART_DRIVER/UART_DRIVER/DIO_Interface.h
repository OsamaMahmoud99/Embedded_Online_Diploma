#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Lcfg.h"
#include "Mem_Map32.h"

typedef enum
{
	PA=0,
	PB,
	PC,
	PD,
	}Port_type;
	
typedef enum
{
	LOW=0,
	HIGH=1,
	}VoltageLevel_type;

extern void DIO_Init(void);
extern void DIO_WritePort(Port_type Port, u8 Value);
extern void DIO_WriteBitsInPort(Port_type Port,u8 Value,u8 Mask);
extern u8 DIO_ReadPort(Port_type Port);
extern void DIO_WritePin(PinNum_type Pin,VoltageLevel_type Value);
extern void DIO_TogglePin(PinNum_type Pin);
extern VoltageLevel_type DIO_ReadPin(PinNum_type Pin);
void DIO_setpinDirection( Port_type port, PinNum_type pin,PinStatus_type Direction);
void DIO_setpinvalue(Port_type port,PinNum_type pin,VoltageLevel_type value);
u8	 DIO_readpin(Port_type port,PinNum_type pin);
void DIO_higher_nibble_Direction(Port_type portNumber);
void DIO_lower_nibble_Direction(Port_type  portNumber);
void DIO_higher_nibble_Value(Port_type portNumber,u8 value);
void DIO_lower_nibble_value(Port_type  portNumber,u8 value);
u8   DIO_get_lower_nibble(Port_type port);
u8   DIO_get_higher_nibble(Port_type port);

#endif
