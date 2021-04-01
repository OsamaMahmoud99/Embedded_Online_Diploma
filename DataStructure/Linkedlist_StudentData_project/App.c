/*
 * App.c
 *
 *  Created on: Mar 26, 2021
 *      Author: Osama Mahmoud
 */

#include "App.h"

struct SStudent* gpFirstStudent = NULL; // points to NULL indicate that there is no student added


void Fill_vTheRecord(struct SStudent* New_Student)
{
	char Temp_Text[40];

	DPRINTF("\n Enter the ID: ");
	gets(Temp_Text);
	New_Student->Student.ID = atoi(Temp_Text);

	DPRINTF("\n Enter the StudentName: ");
	gets(New_Student->Student.Name);

	DPRINTF("\n Enter the Height: ");
	gets(Temp_Text);
	New_Student->Student.Height = atof(Temp_Text);
}

void Add_vStudent(void)
{
	struct SStudent* pLastStudent;
	struct SStudent* pNewStudent;

	/* Check if list is empty or not */
	if(gpFirstStudent == NULL){
		/* create first record */
		pNewStudent = (struct SStudent*)malloc(sizeof(struct SStudent));
		/* Assign gpFirstStudent to it */
		gpFirstStudent = pNewStudent;
	}
	else{
		pLastStudent = gpFirstStudent;
		/* navigate until reach to the last record */
		while(pLastStudent->PNextStudent != NULL){
			pLastStudent = pLastStudent->PNextStudent;
		}
		/* Create New Record to Assign pnext to it */
		pNewStudent = (struct SStudent*)malloc(sizeof(struct SStudent));
		pLastStudent->PNextStudent = pNewStudent;
	}
	/* Fill the Record */
	Fill_vTheRecord(pNewStudent);
	/* Set the next record to NULL */
	pNewStudent->PNextStudent = NULL;
}

int  Delete_intStudent(void)
{
	char Temp_Text[40];
	int Selected_ID;

	/* Get the Selected ID from user */
	DPRINTF("\n Enter the ID Selected: ");
	gets(Temp_Text);
	Selected_ID = atoi(Temp_Text);

	if(gpFirstStudent != NULL){

		struct SStudent* pPreviousStudent = NULL;
		struct SStudent* pSelectedStudent = gpFirstStudent;
		/* Loop on all records starting from gpFirstStudent */
		while(pSelectedStudent != NULL){

			/* Compare the record ID with Selected ID */
			if(pSelectedStudent->Student.ID == Selected_ID){

				if(pPreviousStudent != NULL){
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;
				}
				else{
					gpFirstStudent = pSelectedStudent->PNextStudent;
				}

				free(pSelectedStudent);
				return 1; // find it
			}
			/* Store previous record pointer */
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;

		}

	}
	DPRINTF("\n cannot find the Student ID. ");
	return 0;
}

void  View_vStudent(void)
{
	int Count = 0;
	struct SStudent* pCurrentStudent = gpFirstStudent;

	if(gpFirstStudent == NULL){
		DPRINTF("\n List is Empty ");
	}
	else{
		while(pCurrentStudent){

			DPRINTF("\n Record Number %d",Count+1);
			DPRINTF("\n ID = %d ",pCurrentStudent->Student.ID);
			DPRINTF("\n Name: %s ",pCurrentStudent->Student.Name);
			DPRINTF("\n Height: %0.2f ",pCurrentStudent->Student.Height);
			pCurrentStudent = pCurrentStudent->PNextStudent;
			Count++;
		}
	}


}

void  Delete_vAllStudents(void)
{
	struct SStudent* pCurrentStudent = gpFirstStudent;

	if(gpFirstStudent == NULL){
		DPRINTF("\n List is Empty ");
	}

	while(pCurrentStudent != NULL){

		struct SStudent* pTempStudent = pCurrentStudent;
		pCurrentStudent = pCurrentStudent->PNextStudent;
		free(pTempStudent);
	}
	gpFirstStudent = NULL;
}

struct SStudent* GetNth(int index)
{
	int Count = 0;
	struct SStudent* pStudent = gpFirstStudent;

	while(pStudent){
		if(Count == index){
			return pStudent;
		}
		Count++;
		pStudent = pStudent->PNextStudent;
	}
}

int Find_intLength(void)
{
	int Count = 0;
	struct SStudent* pCurrentStudent = gpFirstStudent;

	while(pCurrentStudent){
		pCurrentStudent = pCurrentStudent->PNextStudent;
		Count++;
	}
	return Count;
}

int Find_intLength_Recursive(void)
{
	struct SStudent* pCurrentStudent = gpFirstStudent;

	if(pCurrentStudent == NULL){
		return 0;
	}
	pCurrentStudent = pCurrentStudent->PNextStudent;
	return 1+Find_intLength_Recursive();

}

struct SStudent* GetN_FromEnd(int N)
{
	int Len = Find_intLength();
	int Count = 0;
	struct SStudent* pCurrent = gpFirstStudent;

	while(pCurrent){
		if(Count == (Len-N)){
			return pCurrent;
		}
		Count++;
		pCurrent = pCurrent->PNextStudent;
	}
}

struct SStudent* GetN_FromEnd2(int N)
{
	int Count = 0;
	struct SStudent* main_ptr = gpFirstStudent; // move if N equal Count until ref_ptr reach to Null then it points to the node we need
	struct SStudent* ref_ptr  = gpFirstStudent; // move until reach to the Null

	while(ref_ptr){
		if(N == Count){
			main_ptr = main_ptr->PNextStudent;
		}
		Count++;
		ref_ptr = ref_ptr->PNextStudent;
	}
	return main_ptr;
}

struct SStudent* Find_MiddleList(void)
{
	struct SStudent* Middle_ptr = gpFirstStudent;
	int Count = 0;
	int Len = Find_intLength();
	while(Middle_ptr){
		if(Count == (Len/2)){
			return Middle_ptr;
		}
		Count++;
		Middle_ptr = Middle_ptr->PNextStudent;
	}
}

void Reverse_List(void)
{
	struct SStudent* PCurrent = gpFirstStudent->PNextStudent;
	struct SStudent* PPrev    = gpFirstStudent;
	struct SStudent* PNext    = PCurrent;
	while(PCurrent != NULL){
		PNext = PCurrent->PNextStudent;
		PCurrent->PNextStudent = PPrev;
		PPrev = PCurrent;
		PCurrent = PNext;
	}
	gpFirstStudent = PPrev;

}
