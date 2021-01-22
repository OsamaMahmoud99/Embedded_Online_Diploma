/*
 * EX4.c
 *
 *  Created on: Jan 7, 2021
 *      Author: OsamaMahmoud
 */

/* C program to calculate the power of a number using recursion */

#include <stdio.h>

int power(int base_number , int power_number);

int main()
{
	int base_number , power_number , Result;

	printf("Enter base number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&base_number);
	printf("Enter power number(positive number): ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&power_number);

	Result = power(base_number , power_number);
	printf("%d^%d = %d",base_number,power_number,Result);

	return 0;
}

int power(int base_number , int power_number)
{
	int Result;
	if(power_number != 0)
	{
		Result = (base_number * power(base_number , power_number - 1));
	}
	else
	{
		Result = 1;
	}
	return Result;
}



