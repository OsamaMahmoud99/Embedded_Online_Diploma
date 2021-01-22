/*
 * EX2.c
 *
 *  Created on: Jan 5, 2021
 *      Author: OsamaMahmoud
 */

/* Calculate Factorial of a Number Using recursion */

#include <stdio.h>

int Factorial(int num);

int main()
{
	int Num;

	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&Num);


	int Fact = Factorial(Num);
	printf("factorial of %d = %d",Num,Fact);

	return 0;
}


int Factorial(int num)
{
	 int fact;
	if(num != 1)
	{
	    fact = num* (Factorial(num-1));
	    return fact;
	}



}
