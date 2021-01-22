/*
 * Q2.c
 *
 *  Created on: Jan 9, 2021
 *      Author: Osama Mahmoud
 */

/*
 * write a c program for swapping two arrays with different length
 */

#include <stdio.h>



int main()
{
	int A[5],B[5],i;

	printf("Enter the first array: ");
	for(i=0; i<5; i++)
	{
		fflush(stdin); fflush(stdout);
		scanf("%d",&A[i]);
	}
	printf("Enter the second array: ");
	for(i=0; i<3; i++)
	{
		fflush(stdin); fflush(stdout);
		scanf("%d",&B[i]);
	}

	printf("before Swapping:\n");
	printf("First Array:");
	for(i=0; i<5; i++)
	{
		printf("%d\t",A[i]);fflush(stdout);
	}
	printf("\nSecond Array:");
	for(i=0; i<3; i++)
	{
		printf("%d\t",B[i]);fflush(stdout);
	}

	/* logic of swapping */
	for(i=0; i<5; i++)
	{
		A[i]^=B[i];
		B[i]^=A[i];
		A[i]^=B[i];
	}

	printf("\nAfter Swapping:\n");
	printf("First Array:");
	for(i=0; i<3; i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\nSecond Array:");
	for(i=0; i<5; i++)
	{
		printf("%d\t",B[i]);
	}




	return 0;
}


