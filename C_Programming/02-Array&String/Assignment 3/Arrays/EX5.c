/*
 * EX5.c
 *
 *  Created on: Jan 2, 2021
 *      Author: OsamaMahmoud
 */

/* c program to search an element in array */

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
	printf("Enter the element to be searched : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&element);

	int flag =0;

	for(int i=0; i<n; i++)
	{
		if(element == arr[i] && flag ==0)
		{
			location = i+1;
			flag = 1;
			break;
		}

	}
	if(flag == 1)
		printf("Number found at location = %d",location);
	else if(flag == 0)
		printf("Number not found\n");

	return 0;
}


