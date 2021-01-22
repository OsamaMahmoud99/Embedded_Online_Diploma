/*
 * EX1.c
 *
 *  Created on: Jan 1, 2021
 *      Author: OsamaMahmoud
 */

/* write c program to find sum of two matrix of order 2*2 using multidimensional arrays where
   elements of matrix are entered by user */
   
#include <stdio.h>

int main()
{
	float arr1[2][2],arr2[2][2],Sum[2][2];

	printf("Enter the elements of 1st matrix\n");

	for(int r=0; r<=1; r++)
	{
		for(int c=0; c<=1; c++)
		{
			printf("Enter a%d%d:",r+1,c+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&arr1[r][c]);
		}
	}
	printf("Enter the elements of 2st matrix\n");
	for(int r=0; r<=1; r++)
	{
		for(int c=0; c<=1; c++)
		{
			printf("Enter b%d%d:",r+1,c+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&arr2[r][c]);
		}
	}

	for(int r=0; r<=1; r++)
	{
		for(int c=0; c<=1; c++)
		{
			Sum[r][c] = arr1[r][c] + arr2[r][c];
		}
	}
	printf("Sum of Matrix:\n");
	for(int r=0; r<=1; r++)
	{
		for(int c=0; c<=1; c++)
		{
			printf("%0.1f ",Sum[r][c]);
		}
		printf("\n");
	}



	return 0;
}


