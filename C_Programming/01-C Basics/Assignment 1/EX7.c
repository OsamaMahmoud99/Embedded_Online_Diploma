/*
 * EX7.c
 *
 *  Created on: Dec 28, 2020
 *      Author: OsamaMahmoud
 */

#include <stdio.h>

int main()
{
	int Num1 , Num2;

	printf("Enter value of Num1: ");
	scanf("%d",&Num1);
	printf("Enter value of Num2: ");
	scanf("%d",&Num2);

	Num1 = Num1 + Num2;
	Num2 = Num1 - Num2;
	Num1 = Num1 - Num2;

	printf("\n");
	printf("After swapping Num1 = %d\n",Num1);
	printf("After swapping Num2 = %d\n",Num2);

	return 0;
}


