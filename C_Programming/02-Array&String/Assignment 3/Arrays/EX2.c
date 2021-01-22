/*
 * EX2.c
 *
 *  Created on: Jan 1, 2021
 *      Author: OsamaMahmoud
 */
 
/* this program takes n number of element from user (where, n is specified by user),stores data in array 
   and calculates the average of those numbers.  */
   
#include <stdio.h>

int main()
{
	int n;
	float Sum=0.0,Average;

	printf("Enter the numbers of data: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	float data[n];

	for(int i=0; i<n; i++)
	{
		printf("%d. Enter number: ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%f",&data[i]);

	}

	for(int i=0; i<n; i++)
	{
		Sum+=data[i];
	}
	Average = Sum / n;

	printf("Average=%0.2f\n",Average);


	return 0;
}


