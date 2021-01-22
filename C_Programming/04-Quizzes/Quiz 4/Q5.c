/*
 * Q5.c
 *
 *  Created on: Jan 9, 2021
 *      Author: Osama Mahmoud
 */

/*
 * Clear a specified bit in a given number
 */

#include <stdio.h>


int Clear(int Number , int Bit);

int main()
{
	int Number , Bit;

	printf("Enter the Number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&Number);

	printf("Enter position of bit: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&Bit);

	int NewNumber = Clear(Number , Bit);

	printf("NewNumber = %d",NewNumber);

	return 0;
}

int Clear(int Number , int Bit)
{
	int Local_NewNumber;

	Local_NewNumber = Number & (~(1<<Bit));
	return Local_NewNumber;
}

