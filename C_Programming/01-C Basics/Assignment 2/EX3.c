/*
 * EX3.c
 *
 *  Created on: Dec 28, 2020
 *      Author: OsamaMahmoud
 */

/*
 * write c program to find the Largest Number Among three Numbers
 */

#include <stdio.h>

int main()
{
	float Num1 , Num2 , Num3;

	printf("Enter three Numbers: ");
	scanf("%f%f%f",&Num1,&Num2,&Num3);

	if(Num1 > Num2)
	{
		if(Num1 > Num3)
		{
			printf("Largest Number = %0.2f",Num1);
		}
		else
		{
			printf("Largest Number = %0.2f",Num3);
		}
	}
	else
	{
		if(Num2 > Num3)
		{
			printf("Largest Number = %0.2f",Num2);
		}
		else
		{
			printf("Largest Number = %0.2f",Num3);
		}
	}
	return 0;
}
