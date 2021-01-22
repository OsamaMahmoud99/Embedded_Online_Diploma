/*
 * Q1.c
 *
 *  Created on: Jan 5, 2021
 *      Author: Osama Mahmoud
 */

/* Write a C program takes string from the user and check if it the same USERNAME or not. *
 *
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char arr[]="Osama";
	char str[50];
	int i=0,j=0,flag=0;

	gets(str);

	while(str[i] != '\0')
	{
		if(str[i] == arr[j] && flag == 0)
		{
            flag =0;
		}
		else
		{
			flag = 1;
		}
		i++;
		j++;
	}

	if(flag == 0)
	{
		printf("same\n");
	}
	else if(flag == 1)
	{
		printf("not same\n");
	}


	return 0;
}

