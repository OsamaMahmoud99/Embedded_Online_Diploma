/*
 * EX1.c
 *
 *  Created on: Dec 28, 2020
 *      Author: OsamaMahmoud
 */

/*
 * write c program to check whether a Number is odd or Even
 */

#include <stdio.h>

int main()
{
	int Num;

	printf("Enter an integer you want to check: ");
	scanf("%d",&Num);

	if(Num%2 == 0)
	{
		printf("%d is even\n",Num);
	}
	else
	{
		printf("%d is odd\n",Num);
	}
	return 0;
}
