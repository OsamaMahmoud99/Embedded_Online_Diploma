/*
 * EX3.c
 *
 *  Created on: Jan 7, 2021
 *      Author: OsamaMahmoud
 */

/* C program to reverse a sentence  using recursion*/

#include <stdio.h>

void Reverse();

int main()
{
	printf("Enter a sentence: ");

	Reverse();

	return 0;
}

void Reverse()
{
	char c;
	fflush(stdin); fflush(stdout);
	scanf("%c",&c);

	if(c !='\n')
	{
		Reverse();
		printf("%c",c);
	}
}


