/*
 * EX2.c
 *
 *  Created on: Jan 2, 2021
 *      Author: OsamaMahmoud
 */

/* c program to find the length of a string  */

#include <stdio.h>

int main()
{
	char str[50];
	int len =0;

	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(str);


	while(str[len] != '\0')
	{
		len++;
	}

	printf("length of a string = %d",len);








	return 0;
}


