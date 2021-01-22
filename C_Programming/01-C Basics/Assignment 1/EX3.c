/*
 * EX3.c
 *
 *  Created on: Dec 28, 2020
 *      Author: OsamaMahmoud
 */

#include <stdio.h>

int main()
{

	int Num1 , Num2;
	int Sum = 0;

	printf("Enter two integers: ");
	scanf("%d%d",&Num1,&Num2);

	Sum = Num1 + Num2;

	printf("Sum: %d",Sum);

	return 0;
}

