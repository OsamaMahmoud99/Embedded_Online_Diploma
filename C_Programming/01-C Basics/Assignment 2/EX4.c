/*
 * EX4.c
 *
 *  Created on: Dec 28, 2020
 *      Author: OsamaMahmoud
 */

/*
 * write c program to check whether a Number is positive or Negative
 */

#include <stdio.h>

int main()
{
	float  Num;

	printf("Enter a Number: ");
	scanf("%f",&Num);

	if(Num > 0)
	{
		printf("%0.2f is positive\n",Num);
	}
	else if(Num < 0)
	{
		printf("%0.2f is negative",Num);
	}
	else
	{
		printf("You entered Zero\n");
	}
	return 0;
}
