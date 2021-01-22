/*
 * EX4.c
 *
 *  Created on: Dec 28, 2020
 *      Author: OsamaMahmoud
 */

#include <stdio.h>

int main()
{
	float Num1 , Num2;
    float Product;

	printf("Enter two numbers: ");
	scanf("%f %f",&Num1,&Num2);

	Product = Num1 * Num2;

	printf("Product: %f",Product);

	return 0;
}


