/*
 * Student.h
 *
 *  Created on: Apr 16, 2021
 *      Author: Osama Mahmoud
 */

#ifndef STUDENT_H_
#define STUDENT_H_

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

/* create a struct type contains the information of student */
typedef struct{
	char Fname[50];
	char Lname[50];
	int  Roll;
	float GPA;
	int CourseID[10];
}Sinfo;

Sinfo ST[50];  // Array of structure

typedef struct{
	int Length;
	int Count;
	Sinfo* Base;
	Sinfo* Head;
    Sinfo* Tail;
}FIFO_Buf_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_NOT_FULL,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_NULL
}FIFO_Buf_s;

/*
	Function Name        : FIFO_ECreate
	Function Returns     : void
	Function Arguments   : Pointer to struct FIFO_BUf , pointer to struct Buffer , int Length
	Function Description : create a queue at Add the information of student in it.
 */
void FIFO_ECreate(FIFO_Buf_t* FIFO_BUf , Sinfo* Buffer , int Length);

/*
	Function Name        : FIFO_EIsFull
	Function Returns     : FIFO_Buf_s
	Function Arguments   : Pointer to struct FIFO_BUf
	Function Description : Check if the FIFO full or not.
 */
FIFO_Buf_s FIFO_EIsFull(FIFO_Buf_t* FIFO_BUf);

/*
	Function Name        : FIFO_EIsEmpty
	Function Returns     : FIFO_Buf_s
	Function Arguments   : Pointer to struct FIFO_BUf
	Function Description : Check if the FIFO empty or not.
 */
FIFO_Buf_s FIFO_EIsEmpty(FIFO_Buf_t* FIFO_BUf);

/*
	Function Name        : Check_RollNum
	Function Returns     : int
	Function Arguments   : pointer to struct FIFOBuf , int Num
	Function Description : Check if the roll number is taken or not.
 */
int Check_RollNum(FIFO_Buf_t* FIFOBuf , int Num);
/*
	Function Name        : Add_Student_File
	Function Returns     : FIFO_Buf_s
	Function Arguments   : void
	Function Description : Add student information from file.
 */
void Add_Student_File(FIFO_Buf_t* FIFOBuf);

/*
	Function Name        : Add_Student_Manually
	Function Returns     : void
	Function Arguments   : Pointer to struct FIFO_BUf
	Function Description : Add student information by user.
 */
void Add_Student_Manually(FIFO_Buf_t* FIFOBuf);

/*
	Function Name        : Find_r1
	Function Returns     : void
	Function Arguments   : Pointer to struct FIFO_BUf
	Function Description : find student information by roll number.
 */
void Find_r1(FIFO_Buf_t* FIFOBuf);

/*
	Function Name        : Find_fn
	Function Returns     : void
	Function Arguments   : Pointer to struct FIFO_BUf
	Function Description : find student information by first name.
 */
void Find_fn(FIFO_Buf_t* FIFOBuf);

/*
	Function Name        : Find_c
	Function Returns     : void
	Function Arguments   : Pointer to struct FIFO_BUf
	Function Description : find all the students who have registered for a given course.
 */
void Find_c(FIFO_Buf_t* FIFOBuf);

/*
	Function Name        : Tot_s
	Function Returns     : void
	Function Arguments   : Pointer to struct FIFO_BUf
	Function Description : find the number of student in buffer.
 */
void Tot_s(FIFO_Buf_t* FIFOBuf);

/*
	Function Name        : Del_s
	Function Returns     : void
	Function Arguments   : Pointer to struct FIFO_BUf
	Function Description : Delete student from buffer.
 */
void Del_s(FIFO_Buf_t* FIFOBuf);

/*
	Function Name        : Up_s
	Function Returns     : void
	Function Arguments   : Pointer to struct FIFO_BUf
	Function Description : Update the student information.
 */
void Up_s(FIFO_Buf_t* FIFOBuf);

/*
	Function Name        : Show_s
	Function Returns     : void
	Function Arguments   : Pointer to struct FIFO_BUf
	Function Description : Show the student information.
 */
void Show_s(FIFO_Buf_t* FIFOBuf);


#endif /* STUDENT_H_ */
