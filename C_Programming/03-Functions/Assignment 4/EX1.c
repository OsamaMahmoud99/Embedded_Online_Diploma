/*
 * EX1.c
 *
 *  Created on: Jan 5, 2021
 *      Author: OsamaMahmoud
 */

/* prime Numbers between two intervals by making user defined function */

#include <stdio.h>

int Prime(int num);

int main()
{
	int Num1 , Num2 , i;

	printf("Enter two numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%d%d",&Num1,&Num2);

	printf("prime numbers between %d and %d are:",Num1,Num2);

	for(i = Num1+1; i<Num2; i++)
	{
		int flag = Prime(i);     // calling 

		if(flag == 0)            // if flag =0 the number is prime
		{
			printf("%d ",i);
		}
	}

	return 0;
}


int Prime(int num)
{
	int j, flag=0;

	for(j=2; j<=(num/2); ++j)
	{
		if(num%j==0)
		{
			flag=1;
			break;
		}
	}


	return flag;
}
