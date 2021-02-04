/*
 * Q4.c
 *
 *  Created on: Feb 4, 2021
 *      Author: Osama Mahmoud
 */

#include <stdio.h>

int main()
{
	int n;

	printf("Input the number of element : ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);
	printf("Input %d mumber of elements:\n",n);

	int arr[n];
	int *ptr = arr;

	for(int i=0; i<n; ++i)
	{
		printf("element- %d: ",i+1);
		fflush(stdout); fflush(stdin);
		scanf("%d",&arr[i]);
	}

	ptr = &arr[n-1];
	printf("The elements of array in reverse order are : \n");

	for(int i=n; i>0; i--)
	{
		printf("element- %d : %d\n",i,*ptr);
		ptr--;
	}


	return 0;
}


