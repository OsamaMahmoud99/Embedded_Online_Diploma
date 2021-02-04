/*
 * Q2.c
 *
 *  Created on: Feb 4, 2021
 *      Author: Osama Mahmoud
 */

#include <stdio.h>

int main()
{
	char Arr[27];

	char*ptr = Arr;

	for(int i=0; i<26; ++i)
	{
		*ptr = i+'A';
		ptr++;
	}

	ptr = Arr;

	printf("The Alphabets are:\n");

	for(int i=0; i<26; ++i)
	{2
		printf("%c ",*ptr);
		ptr++;

	}

	return 0;
}


