/*
 * EX8.c
 *
 *  Created on: Dec 29, 2020
 *      Author: OsamaMahmoud
 */

/*
 * write c program to make a simple calculator  to Add ,subtract,multiply, or Divide using switch ..case
 */

#include <stdio.h>

int main()
{
	char Operator;
	float Num1 , Num2;

	printf("Enter Operator: ");
	scanf("%c",&Operator);

	printf("Enter two operands: ");
	scanf("%f%f",&Num1,&Num2);

	switch(Operator)
	{
	case '+' : printf("%0.2f + %0.2f = %0.2f\n",Num1,Num2,(Num1+Num2)); break;
	case '-' : printf("%0.2f - %0.2f = %0.2f\n",Num1,Num2,(Num1-Num2)); break;
	case '*' : printf("%0.2f * %0.2f = %0.2f\n",Num1,Num2,(Num1*Num2)); break;
	case '/' :
		if(Num2 != 0)
			printf("%0.2f / %0.2f = %0.2f",Num1,Num2,(Num1/Num2));
		else
			printf("infinity\n");
		break;
	}



	return 0;
}
