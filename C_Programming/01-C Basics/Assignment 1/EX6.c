/*
 * EX6.c
 *
 *  Created on: Dec 28, 2020
 *      Author: OsamaMahmoud
 */

#include <stdio.h>

int main()
{
	float a , b;
	float Temp;

	printf("Enter value of a: ");
	scanf("%f",&a);
	printf("Enter value of b: ");
	scanf("%f",&b);

    Temp = a;
	a = b;
	b = Temp;
     
	printf("\n");
	printf("After swapping, value of a = %.2f\n",a);
	printf("After swapping, value of b = %.1f\n",b);

	return 0;
}


