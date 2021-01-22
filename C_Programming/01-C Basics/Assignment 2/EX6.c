/*
 * EX6.c
 *
 *  Created on: Dec 29, 2020
 *      Author: OsamaMahmoud
 */

/*
 * write c program to calculate sum of natural numbers
 */

#include <stdio.h>

int main()
{
	int n;
	int Sum = 0;

	printf("Enter an integer: ");
	scanf("%d",&n);

	for(int i=1; i<=n; i++)
	{
		Sum+= i;
	}
	printf("Sum = %d\n",Sum);

	return 0;
}
