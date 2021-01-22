/*
 * EX3.c
 *
 *  Created on: Jan 16, 2021
 *      Author: Osama Mahmoud
 */

/* c program to add two complex numbers by passing structure to a function */

#include <stdio.h>

struct SAdd
{
	float m_R;
	float m_I;
};

struct SAdd ReadNumbers(char str[])
{
    struct SAdd C;

    printf("%s\n",str);
	printf("Enter real and imaginary respectively: ");
	scanf("%f%f",&C.m_R,&C.m_I);

	return C;

}

struct SAdd AddNumbers(struct SAdd A , struct SAdd B)
{
	struct SAdd S;

	S.m_R = A.m_R + B.m_R;
	S.m_I = A.m_I + B.m_I;

	return S;

}
void printSum(struct SAdd S)
{
	printf("Sum = %0.1f + %0.1fi",S.m_R , S.m_I);
}
int main()
{
	struct SAdd X,Y,Sum;

	X = ReadNumbers("For 1st complex number");
	Y = ReadNumbers("For 2st complex number");

	Sum = AddNumbers(X , Y);

	printSum(Sum);



	return 0;
}


