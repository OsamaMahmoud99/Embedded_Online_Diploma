/*
 * main.c
 *
 *  Created on: Jan 14, 2021
 *      Author: OsamaMahmoud
 */

#include <stdio.h>
#include <string.h>
#include <conio.h>


struct SDate
{
	int m_Day;
	int m_Month;
	int m_Year;
};


struct SEmployee
{
	char m_name[50];
	struct SDate m_GraduatioDate;
	struct SDate m_BirthDate;
	int  m_Salary;
};

struct SDate ReadDate(char dateName[])
{
	struct SDate date;
	printf("Enter %s (day/month/year):",dateName);

	scanf("%d%d%d",&date.m_Day,&date.m_Month,&date.m_Year);

	return date;

}
struct SEmployee ReadEmployee()
{
	struct SEmployee employee;
	char firstname[50] , lastname[50];

	printf("Enter Employee first Name:");
	scanf("%s",firstname);

	printf("Enter Employee last Name:");
	scanf("%s",lastname);

	strcpy(employee.m_name , firstname);
	strcat(employee.m_name , " ");
	strcat(employee.m_name , lastname);

	employee.m_BirthDate = ReadDate("Employee Birth Date");
	employee.m_GraduatioDate = ReadDate("Employee Graduation Date");

	printf("Enter Employee Salary:");
	scanf("%d",&employee.m_Salary);

	return employee;


}

void printEmployee(struct SEmployee employee)
{
	printf("%s\t%d/%d/%d\t%d/%d/%d\t%d\r\n",employee.m_name,
			                                employee.m_BirthDate.m_Day,
										    employee.m_BirthDate.m_Month,
											employee.m_BirthDate.m_Year,
											employee.m_GraduatioDate.m_Day,
											employee.m_GraduatioDate.m_Month,
											employee.m_GraduatioDate.m_Year,
											employee.m_Salary);

}
int main(void)
{

	struct SEmployee X = ReadEmployee();

    printEmployee(X);

    return 0;
}


