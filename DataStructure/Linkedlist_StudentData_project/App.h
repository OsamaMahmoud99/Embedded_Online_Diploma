/*
 * App.h
 *
 *  Created on: Mar 26, 2021
 *      Author: Osama Mahmoud
 */

#ifndef APP_H_
#define APP_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

/* there is a bug in   eclipse so I define this macro without needing to put fflush before each printf */
#define DPRINTF(...)      {fflush(stdout);\
	                       fflush(stdin);\
	                       printf(__VA_ARGS__);\
	                       fflush(stdout);\
                           fflush(stdin);}

/* Information of students */
struct SData{
	int   ID;
	char  Name[40];
	float Height;
};

struct SStudent{
	struct SData Student;
	struct SStudent* PNextStudent; // points to the next node
};


/*
	Function Name        : Fill_TheRecord
	Function Returns     : void
	Function Arguments   : Pointer to struct New_Student
	Function Description : Fill the information of a student.
 */
void Fill_vTheRecord(struct SStudent* New_Student);

/*
	Function Name        : Add_vStudent
	Function Returns     : void
	Function Arguments   : void
	Function Description : Add the Node of student
 */
void Add_vStudent(void);

/*
	Function Name        : Delete_intStudent
	Function Returns     : int
	Function Arguments   : void
	Function Description : Delete the Node of student
 */
int  Delete_intStudent(void);

/*
	Function Name        : Delete_intStudent
	Function Returns     : void
	Function Arguments   : void
	Function Description : View the information of  students
 */
void  View_vStudent(void);

/*
	Function Name        : Delete_vAllStudents
	Function Returns     : void
	Function Arguments   : void
	Function Description : Delete All the students
 */
void  Delete_vAllStudents(void);

/*
	Function Name        : GetNth
	Function Returns     : pointer to struct SStudent
	Function Arguments   : Index
	Function Description : take the index of the Node to Get the Data of a student
 */
struct SStudent* GetNth(int Index);

/*
	Function Name        : Find_intLength
	Function Returns     : int
	Function Arguments   : void
	Function Description : find the number of student is existed iterative
 */
int Find_intLength(void);

/*
	Function Name        : Find_intLength
	Function Returns     : int
	Function Arguments   : void
	Function Description : find the number of student is existed recursive
 */
int Find_intLength_Recursive(void);

/*
	Function Name        : GetN_FromEnd
	Function Returns     : pointer to struct struct SStudent
	Function Arguments   : int N
	Function Description : Get the data of the node from the end by N index
 */
struct SStudent* GetN_FromEnd(int N);

/*
	Function Name        : GetN_FromEnd2
	Function Returns     : pointer to struct struct SStudent
	Function Arguments   : int N
	Function Description : Get the data of the node from the end by N index  Another Method
 */
struct SStudent* GetN_FromEnd2(int N);

/*
	Function Name        : Find_MiddleList
	Function Returns     : pointer to struct struct SStudent
	Function Arguments   : void
	Function Description : Find the Middle Node if the Num of nodes odd.
 */
struct SStudent* Find_MiddleList(void);

/*
	Function Name        : Reverse_List
	Function Returns     : void
	Function Arguments   : void
	Function Description : Reverse The List.
 */
void Reverse_List(void);

#endif /* APP_H_ */
