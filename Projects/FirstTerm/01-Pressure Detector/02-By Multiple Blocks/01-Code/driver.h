#ifndef DRIVER_H
#define DRIVER_H

#include <stdint.h>
#include <stdio.h>

#define SET_BIT(ADDRESS,BIT)     ADDRESS |=  (1<<BIT)
#define RESET_BIT(ADDRESS,BIT)   ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT)  ADDRESS ^=  (1<<BIT)
#define READ_BIT(ADDRESS,BIT)   ((ADDRESS) &   (1<<(BIT)))


#define GPIO_PORTA 0x40010800
#define BASE_RCC   0x40021000

#define APB2ENR   *(volatile uint32_t *)(BASE_RCC + 0x18)

#define GPIOA_CRL *(volatile uint32_t *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH *(volatile uint32_t *)(GPIO_PORTA + 0X04)
#define GPIOA_IDR *(volatile uint32_t *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR *(volatile uint32_t *)(GPIO_PORTA + 0x0C)

typedef enum{
	LOW,
	HIGH
}LED_State;


void Delay(int nCount);
int getPressureVal(void);
void Set_LED(LED_State i);
void GPIO_INITIALIZATION (void);

#endif
