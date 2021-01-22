/*
 * EX4.c
 *
 *  Created on: Jan 1, 2021
 *      Author: OsamaMahmoud
 */

/* c program to insert an element in an array */

#include <stdio.h>

int main()
{
	int arr[20], n,element,location;

	printf("Enter no of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);


	for(int i=0; i<n; i++)
	{
		fflush(stdin); fflush(stdout);
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be inserted : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&element);

	printf("Enter the location : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&location);

	for(int i=n; i>=location; i--)
	{
		arr[i] = arr[i-1];
	}
    n++;
    arr[location - 1] = element;

	for(int i=0; i<=n; i++)
	{
		printf("%d ",arr[i]);
	}


	return 0;
}


