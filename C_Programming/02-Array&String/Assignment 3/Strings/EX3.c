/*
 * EX3.c
 *
 *  Created on: Jan 2, 2021
 *      Author: OsamaMahmoud
 */

/* c program to reverse string  */

#include <stdio.h>
#include <string.h>
int main()
{
	char str[50];
	int i=0 ,temp;

	printf("Enter the string: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	int j =  strlen(str) -1;

	while(i < j)
	{
		temp   = str[i];
		str[i] = str[j];
		str[j] = temp;

		i++;
		j--;
	}
	printf("Reverse string is: %s",str);


	return 0;
}


