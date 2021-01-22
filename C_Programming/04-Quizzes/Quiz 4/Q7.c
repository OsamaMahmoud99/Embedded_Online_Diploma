/*
 * Q7.c
 *
 *  Created on: Jan 5, 2021
 *      Author: Osama Mahmoud
 */

/* check if a given number is a power of 3
 *
 */

#include <stdio.h>
#include <string.h>

int power(int Num);

int main()
{
	int Num;

	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&Num);


    int Val = power(Num);

    printf("%d",Val);

	return 0;
}

int power(int Num)
{
	if(Num % 3 == 0 && Num != 3)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
