/*
 * Q1.c
 *
 *  Created on: Feb 4, 2021
 *      Author: Osama Mahmoud
 */

#include <stdio.h>

int main()
{
    int m = 29;

	printf("Address of m : %x\n",(int)&m);
	printf("Value of m : %d\n",m);

	int *ab = &m;
	printf("Address of pointer ab : %x\n",(int)ab);
	printf("Content of pointer ab : %d\n",*ab);

	m = 34;
	printf("Address of pointer ab : %x\n",(int)ab);
	printf("Content of pointer ab : %d\n",*ab);

	*ab = 7;
	printf("Address of m : %x\n",(int)&m);
	printf("Value of m : %d\n",m);


	return 0;
}


