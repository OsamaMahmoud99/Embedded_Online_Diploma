/*
 * main.c
 *
 *  Created on: Jan 14, 2021
 *      Author: OsamaMahmoud
 */

#include <stdio.h>
#include <string.h>
#include <conio.h>


struct SComplex
{
	double m_R;
	double m_I;
};

struct SComplex ReadComplex(char name[])
{
	struct SComplex C;
	printf("Enter %s Complex Value:",name);
	scanf("%lf , %lf",&C.m_R,&C.m_I);

	return C;

}

struct SComplex AddComplex(struct SComplex A , struct SComplex B)
{
	struct SComplex C;

	C.m_R = A.m_R + B.m_R;
	C.m_I = A.m_I + B.m_I;

	return C;
}

void PrintComplex(char name[] , struct SComplex C)
{
	printf("%s = (%lf) + j (%lf)\r\n",name , C.m_R , C.m_I);
}

int main(void)
{

	struct SComplex X ,Y,Z;

	X = ReadComplex("X");
	Y = ReadComplex("Y");
	Z = AddComplex(X , Y);

	PrintComplex("Z", Z);


    return 0;
}


