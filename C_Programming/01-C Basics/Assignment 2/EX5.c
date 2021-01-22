/*
 * EX5.c
 *
 *  Created on: Dec 29, 2020
 *      Author: OsamaMahmoud
 */

/*
 * write c program to check whether a character is an alphabet or not
 */

#include <stdio.h>

int main()
{
	char character;

	printf("Enter a character: ");
	scanf("%c",&character);

	if( (character >= 'A' && character <='Z') || (character >='a' && character <='z'))
	{
		printf("%c is an alphabet\n",character);
	}
	else
	{
		printf("%c is not an alphabet\n",character);
	}
	return 0;
}
