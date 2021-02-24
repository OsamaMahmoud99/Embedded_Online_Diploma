/*
 * Platform_Types.h
 *
 *  Created on: Feb 13, 2021
 *      Author: Osama Mahmoud
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/**** Symbols ****/
#define CPU_TYPE            CPU_TYPE_32
#define CPU_BIT_ORDER       LSB_FIRST
#define CPU_BYTE_ORDER      LOW_BYTE_FIRST

/**** Types ****/
typedef unsigned long       boolean;
typedef signed char         sint8;
typedef unsigned char       uint8;
typedef signed short        sint16;
typedef unsigned short      uint16;
typedef signed long         sint32;
typedef unsigned long       uint32;
typedef unsigned long       uint8_least;
typedef unsigned long       uint16_least;
typedef unsigned long       uint32_least;
typedef signed long         sint8_least;
typedef signed long         sint16_least;
typedef signed long         sint32_least;
typedef float               float32;
typedef double              float64;


#endif /* PLATFORM_TYPES_H_ */
