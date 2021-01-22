/*
 * EX3.c
 *
 *  Created on: Jan 1, 2021
 *      Author: OsamaMahmoud
 */

#include <stdio.h>

int main()
{
	int rows , columns;

	printf("rows and columns of matrix: ");
	fflush(stdin); fflush(stdout);
	scanf("%d%d",&rows,&columns);

	int arr[rows][columns],arr1[columns][rows];
	printf("Enter elements of matrix:\n");

	for(int r=0; r<rows; r++)
	{
		for(int c=0; c<columns; c++)
		{
			printf("Enter elements a%d%d: ",r+1,c+1);
			fflush(stdin); fflush(stdout);
			scanf("%d",&arr[r][c]);
		}
	}
	printf("\nEntered matrix:\n");
	for(int r=0; r<rows; r++)
	{
		for(int c=0; c<columns; c++)
		{
			printf("%d ",arr[r][c]);
		}
		printf("\n");
	}
	printf("\nTranspose of matrix:\n");

	for(int r=0; r<rows; r++)
	{
		for(int c=0; c<columns; c++)
		{
			arr1[c][r] = arr[r][c];
		}
	}

	for(int c=0; c<columns; c++)
	{
		for(int r=0; r<rows; r++)
		{
			printf("%d ",arr1[c][r]);
		}
		printf("\n");
	}


	return 0;
}


