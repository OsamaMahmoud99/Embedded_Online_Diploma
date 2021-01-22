/*
 * EX1.c
 *
 *  Created on: Jan 2, 2021
 *      Author: OsamaMahmoud
 */

/* c program to find the frequency of characters in a string  */

#include <stdio.h>

int main()
{
	char str[50],character;
	int i=0 , count = 0;

	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	printf("Enter a character to find a frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&character);

	while(str[i] != '\0')
	{
		if(str[i] == character)
		{
			count++;
		}
		i++;
	}

	printf("frequency of %c = %d",character,count);



	return 0;
}


