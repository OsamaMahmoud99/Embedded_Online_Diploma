/*
 * EX_break.c
 *
 *  Created on: Jan 1, 2021
 *      Author: OsamaMahmoud
 */

#include <stdio.h>

int main()
{
	float Num,Average,Sum = 0.0;
	int n,i;

	printf("Enter n of Numbers:\n ");
	fflush(stdin); 	fflush(stdout);
	scanf("%d",&n);

	for(i=1; i<=n; i++)
	{
		printf("Number[%d] : ",i);
		fflush(stdin); 	fflush(stdout);
		scanf("%f",&Num);

		if(Num < 0.0)
			break;

		Sum = Sum + Num;
	}
	Average = Sum/(i-1);

	printf("Average = %0.2f\n",Average);

	return 0;
}


