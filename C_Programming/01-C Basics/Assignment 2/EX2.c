/*
 * EX2.c
 *
 *  Created on: Dec 28, 2020
 *      Author: OsamaMahmoud
 */

/*
 * write c program to check Vowel or constant
 */

#include <stdio.h>

int main()
{
	char character;

	printf("Enter an alphabet: ");
	scanf("%c",&character);

	switch(character)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		printf("%c is a vowel\n",character);
		break;
	default:
		printf("%c is a constant\n",character);
		break;
	}
	return 0;
}
