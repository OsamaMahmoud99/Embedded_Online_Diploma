/*
 * Q3.c
 *
 *  Created on: Feb 4, 2021
 *      Author: Osama Mahmoud
 */

#include <stdio.h>

int main()
{
	char str[50];
    char rvstr[50];

    char *p1 = str;
    char *p2 = rvstr;
    int i = -1;

    printf("Input String: ");
	fflush(stdout); fflush(stdin);
	scanf("%s",str);

	while(*p1 != '\0')
	{
		p1++;
		++i;
	}

	while(i>=0)
	{
		p1--;
		*p2 = *p1;
		p2++;
		--i;
	}
	*p2 = '\0';

	printf("Reverse of the string is: %s\n",rvstr);


	return 0;
}


