/*
 * main.c
 *
 *  Created on: Mar 26, 2021
 *      Author: Osama Mahmoud
 */

#include "App.h"


int main()
{
	char Temp_Text[40];
	struct SStudent* pData;

	while(1)
	{
		DPRINTF("\n ======================");
		DPRINTF("\n\t Choose on of the follwing options \n");
		DPRINTF("\n 1: Add_Student ");
		DPRINTF("\n 2: Delete_Student ");
		DPRINTF("\n 3: View_Students ");
		DPRINTF("\n 4: Delete_AllStudents ");
		DPRINTF("\n 5: GetNth ");
		DPRINTF("\n 6: Find_Length ");
		DPRINTF("\n 7: GetN_FronEnd ");
		DPRINTF("\n 8: Find_MiddleNode ");
		DPRINTF("\n 9: Rev_Node ");
		DPRINTF("\n Enter Option Number:  ");

		gets(Temp_Text);
		DPRINTF("\n =====================");
		switch(atoi(Temp_Text))
		{
		case 1:
			Add_vStudent();
			break;
		case 2:
			Delete_intStudent();
			break;
		case 3:
			View_vStudent();
			break;
		case 4:
			Delete_vAllStudents();
			break;
		case 5:
		    pData = GetNth(0);
			DPRINTF("\n%d\n%0.2f\n%s",pData->Student.ID,pData->Student.Height,pData->Student.Name);
			break;
		case 6:
			DPRINTF("\n Length = %d ",Find_intLength());
			break;
		case 7:
			pData = GetN_FromEnd2(3);
			DPRINTF("\nID=%d\nName=%s\nHeight=%0.2f",pData->Student.ID,pData->Student.Name,pData->Student.Height);
			break;
		case 8:
			pData = Find_MiddleList();
			DPRINTF("\nID=%d\nName=%s\nHeight=%0.2f",pData->Student.ID,pData->Student.Name,pData->Student.Height);
			break;
		case 9:
			Reverse_List();
			break;
		default:
			DPRINTF("\n Wrong Option ");
			break;
		}
	}

	return 0;
}

