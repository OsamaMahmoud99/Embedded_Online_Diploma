/*
 * EX1.c
 *
 *  Created on: Jan 16, 2021
 *      Author: Osama Mahmoud
 */
 
/* C program to store information (name , roll , mark) of a student using structure */

#include <stdio.h>

struct SStudent
{
	char  m_name[50];
	int   m_roll;
	float m_mark;
};

struct SStudent  ReadData()
{
	struct SStudent C;
	printf("Enter name: ");
	scanf("%s",&C.m_name);
	printf("Enter roll number: ");
	scanf("%d",&C.m_roll);
	printf("Enter marks:" );
	scanf("%f",&C.m_mark);

	return C;

}
void printData(struct SStudent Data)
{
	printf("Displaying Information\n");
	printf("name: %s\nRoll: %d\nMarks: %0.2f\r\n",Data.m_name , Data.m_roll , Data.m_mark);
}

int main()
{

	struct SStudent X;

	X = ReadData();

	printData(X);

	return 0;
}


