/*
 * EX7.c
 *
 *  Created on: Dec 29, 2020
 *      Author: OsamaMahmoud
 */

/*
 * write c program to find factorial of a number
 */

#include <stdio.h>

int main()
{
	int Num; 
	int Factorial = 1;

	printf("Enter an integer: ");
	scanf("%d",&Num);

	if(Num < 0)
	{
		printf("Error!!! Factorial of negative number doesn't exist.\n");
	}
	else if(Num > 0)
	{
		while(Num > 0)
		{
			Factorial = Factorial * Num;
			Num--;
		}
		printf("Factorial = %d\n",Factorial);
	}
	else
	{
		printf("Factorial = %d\n",Factorial);
	}



	return 0;
}
