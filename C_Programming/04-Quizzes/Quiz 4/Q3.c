/*
 * Q3.c
 *
 *  Created on: Jan 5, 2021
 *      Author: Osama Mahmoud
 */

/* check if a given number is a power of 3
 *
 */

#include <stdio.h>

void Reverse(int arr[], int len);

int main()
{
	int arr[6];

	printf("Input: ");
	for(int i=0; i<6; i++)
	{
		fflush(stdin); fflush(stdout);
		scanf("%d",&arr[i]);
	}

	Reverse(arr , 6);


	return 0;
}

void Reverse(int arr[],int len)
{

	int first = 0 , last = len -1;

	while(first < last)
	{
		int Temp = arr[first];
		arr[first] = arr[last];
		arr[last] = Temp;

		first++;
		last--;
	}

	for(int i=0; i<len; ++i)
	{
		printf("%d ",arr[i]);
	}
}
