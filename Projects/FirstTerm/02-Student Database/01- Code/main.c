/*
 * main.c
 *
 *  Created on: Apr 16, 2021
 *      Author: Osama Mahmoud
 */

#include "Student.h"

int main()
{
	int Choice;
	FIFO_Buf_t FIFOStudent;

	FIFO_ECreate(&FIFOStudent ,ST , 50);



	DPRINTF("welcome to the student Mangement System\n");
	while(1)
	{
		DPRINTF("\nChoose The Task that you want to perform\n");
		DPRINTF("1. Add the student Details Manually\n");
		DPRINTF("2. Add the student Details From Text File\n");
		DPRINTF("3. Find the Student Details by Roll Number\n");
		DPRINTF("4. Find the Student Details by First Name\n");
		DPRINTF("5. Find the student Details by Course ID\n");
		DPRINTF("6. Find the Total number of Students\n");
		DPRINTF("7. Delete the Students Details by Roll Number\n");
		DPRINTF("8. Update the Students Details by Roll Number\n");
		DPRINTF("9. Show all information\n");
		DPRINTF("10. To Exit\n");
		DPRINTF("Enter your choice to perform the task: ");

		scanf("%d",&Choice);
		switch(Choice)
		{
		case 1:
			DPRINTF("==============================\n");
			DPRINTF("Add the student Details\n");
			DPRINTF("==============================\n");
			Add_Student_Manually(&FIFOStudent);
			break;
		case 2:
			Add_Student_File(&FIFOStudent);
			break;
		case 3:
			DPRINTF("----------------------------\n");
			Find_r1(&FIFOStudent);
			break;
		case 4:
			DPRINTF("----------------------------\n");
			Find_fn(&FIFOStudent);
			break;
		case 5:
			DPRINTF("----------------------------\n");
			Find_c(&FIFOStudent);
			break;
		case 6:
			DPRINTF("----------------------------\n");
			Tot_s(&FIFOStudent);
			break;
		case 7:
			DPRINTF("----------------------------\n");
			Del_s(&FIFOStudent);
			break;
		case 8:
			DPRINTF("----------------------------\n");
			Up_s(&FIFOStudent);
			break;
		case 9:
			DPRINTF("----------------------------\n");
			Show_s(&FIFOStudent);
			break;
		case 10:
			exit(1);
		}
	}
	return 0;
}


