/*
 * Q6.c
 *
 *  Created on: Jan 9, 2021
 *      Author: Osama Mahmoud
 */

/*
 * C program to know the value of the 4th least significant bit in binary
 */

#include <stdio.h>



int main()
{
	int n,c,k;

	printf("Enter an integer in a decimal number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	printf("%d in binary number system is: ",n);

	for(c=31; c>=0; c--)
	{
    	k = n >> c;

		if(k&1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	k = n>>3;
	if(k&1)
		printf("4th least significant bit is 1");
	else
		printf("4th least significant bit is 0");

	return 0;
}

