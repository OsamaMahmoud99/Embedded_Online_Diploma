/*
 * Student.c
 *
 *  Created on: Apr 16, 2021
 *      Author: Osama Mahmoud
 */

#include "Student.h"

void FIFO_ECreate(FIFO_Buf_t* FIFO_BUf , Sinfo* Buffer , int Length){

	FIFO_BUf->Base   = Buffer;
	FIFO_BUf->Head   = FIFO_BUf->Base;
	FIFO_BUf->Tail   = FIFO_BUf->Base;
	FIFO_BUf->Length = Length;
	FIFO_BUf->Count  = 0;
}
FIFO_Buf_s FIFO_EIsFull(FIFO_Buf_t* FIFO_BUf){

	if(FIFO_BUf->Base == NULL || FIFO_BUf->Head == NULL || FIFO_BUf->Tail == NULL)
		return FIFO_NULL;
	if(FIFO_BUf->Count == FIFO_BUf->Length)
		return FIFO_FULL;
	else
		return FIFO_NOT_FULL;
}

FIFO_Buf_s FIFO_EIsEmpty(FIFO_Buf_t* FIFO_BUf){

	if(FIFO_BUf->Base == NULL || FIFO_BUf->Head == NULL || FIFO_BUf->Tail == NULL)
		return FIFO_NULL;
	if(FIFO_BUf->Count == 0)
		return FIFO_EMPTY;
	else
		return FIFO_NOT_EMPTY;
}

int Check_RollNum(FIFO_Buf_t* FIFOBuf , int Num){

	Sinfo* ptr= FIFOBuf->Base;
	int flag = 1;

	for(int i=0; i<FIFOBuf->Count; ++i){

		if(ptr->Roll == Num){
			flag = 0;
		}
		ptr++;
	}
	return flag;
}

void Add_Student_File(FIFO_Buf_t* FIFOBuf){

	FILE* fp = fopen("Add Student.txt","r");

	int Rec_no = 0 , Field_no = 0 , Student_Count = 0;
	char Line[50];
	const char* Taken;


	while(fgets(Line,sizeof Line,fp) != NULL){
		Rec_no++;
		Taken = strtok(Line,",");
		Field_no = 0;
		while(Taken != NULL){
			Field_no++;
			if(Field_no == 1){
				if(Check_RollNum(FIFOBuf, atoi(Taken)) == 0){
					DPRINTF("[ERROR] Roll Number %d is already Taken\n",atoi(Taken));
					Student_Count++;
					break;
				}
				else{
					FIFOBuf->Head->Roll = atoi(Taken);
					DPRINTF("[INFO] Roll Number %d is saved successfully\n",atoi(Taken));
				}
			}
			else if(Field_no == 2){
				strcpy(FIFOBuf->Head->Fname , Taken);
			}
			else if(Field_no == 3){
				strcpy(FIFOBuf->Head->Lname , Taken);
			}
			else if(Field_no == 4){
				FIFOBuf->Head->GPA = atof(Taken);
			}
			else if(Field_no == 5){
				FIFOBuf->Head->CourseID[0] = atoi(Taken);
			}
			else if(Field_no == 6){
				FIFOBuf->Head->CourseID[1] = atoi(Taken);
			}
			else if(Field_no == 7){
				FIFOBuf->Head->CourseID[2] = atoi(Taken);
			}
			else if(Field_no == 8){
				FIFOBuf->Head->CourseID[3] = atoi(Taken);
			}
			else if(Field_no == 9){
				FIFOBuf->Head->CourseID[4] = atoi(Taken);
			}

			Taken = strtok(NULL,",\n");
		}
		if(Check_RollNum(FIFOBuf, atoi(Taken)) == 0){
			continue;
		}
		FIFOBuf->Count++;

		/* For circular Queue */
		if(FIFOBuf->Head == (Sinfo*)(FIFOBuf->Length * sizeof(Sinfo))){
			FIFOBuf->Head = FIFOBuf->Base;
		}
		else{
			FIFOBuf->Head++;
		}
	}
	fclose(fp);
	DPRINTF("\n[INFO] students Details is added successfully");
	DPRINTF("\n--------------------------------");
	DPRINTF("\n[INFO] The total number of students is %d ",Rec_no - Student_Count);
	DPRINTF("\n[INFO] You can add up to 50 students");
	DPRINTF("\n[INFO] You can add %d more students\n",50-(Rec_no-Student_Count));
}

void Add_Student_Manually(FIFO_Buf_t* FIFOBuf){

	char Temp[50];
	int RollNum = 0;

	/* check if the buffer created or not */
	if(FIFOBuf->Base == NULL || FIFOBuf->Head == NULL || FIFOBuf->Tail == NULL)
		DPRINTF("FIF Not Found\n");
	/* Check if FIFO is full or not */
	if(FIFO_EIsFull(FIFOBuf) == FIFO_FULL)
		DPRINTF("FIFO Is Full\n");
	/* get the Roll Number of Student */
	DPRINTF("Enter the Roll Number: ");
	gets(Temp);
	RollNum = atoi(Temp);
	/* Check if it is already taken from another student or not */
	if( Check_RollNum(FIFOBuf, RollNum) == 0 ){
		DPRINTF("Roll Number is taken before\n");
		DPRINTF("Enter the Roll Number: ");
		gets(Temp);
	}
	/* Store it in Roll member of struct */
	FIFOBuf->Head->Roll = atoi(Temp);

	DPRINTF("Enter the first Name of Student:");
	gets(FIFOBuf->Head->Fname);
	DPRINTF("Enter the Last Name of Student:");
	gets(FIFOBuf->Head->Lname);
	DPRINTF("Enter the GPA you obtained:");
	gets(Temp);
	FIFOBuf->Head->GPA = atof(Temp);

	DPRINTF("Enter the Course ID of each course:\n");
	for(int i=0; i<5; ++i){
		DPRINTF("Course %d ID: ",i+1);
		gets(Temp);
		FIFOBuf->Head->CourseID[i] = atoi(Temp);
	}
	FIFOBuf->Count++;
	/* For circular Queue */
	if(FIFOBuf->Head == (Sinfo*)(FIFOBuf->Length * sizeof(Sinfo))){
		FIFOBuf->Head = FIFOBuf->Base;
	}
	else{
		FIFOBuf->Head++;
	}

	DPRINTF("\n[INFO] students Details is added successfully");
	DPRINTF("\n--------------------------------");
	DPRINTF("\n[INFO] The total number of students is %d ",FIFOBuf->Count);
	DPRINTF("\n[INFO] You can add up to 50 students");
	DPRINTF("\n[INFO] You can add %d more students\n",50-FIFOBuf->Count);

}

void Find_r1(FIFO_Buf_t* FIFOBuf){

	int Roll_Num = 0 , flag = 0;
	Sinfo* ptr= FIFOBuf->Base;

	DPRINTF("Enter the roll number of the student: ");
	scanf("%d",&Roll_Num);

	for(int i=0; i<FIFOBuf->Count; ++i){
		/* If Roll_Num is found then break from the loop and put flag = 0 else flag = 1 and that show the Roll _Num not found */
		if(ptr->Roll == Roll_Num){
			DPRINTF("The students Details are\n");
			DPRINTF("The First name is   :%s\n",ptr->Fname);
			DPRINTF("Student last  name  : %s\n",ptr->Lname);
			DPRINTF("Student roll  number: %d\n",ptr->Roll);
			DPRINTF("Student GPA         : %0.2f\n",ptr->GPA);
			DPRINTF("Enter the course ID of each course\n");
			for(int j=0 ;j < 5; ++j){
				DPRINTF("The course ID are: %d\n",ptr->CourseID[j]);
			}
			flag = 0;
			break;
		}
		else{
			flag = 1;
		}
		ptr++;
	}

	if(flag == 1){
		DPRINTF("[ERROR] Roll Number %d not found\n",Roll_Num);
	}

}

void Find_fn(FIFO_Buf_t* FIFOBuf){

	char Fname_Temp[50];
	Sinfo* Ptr = FIFOBuf->Base;
	int Count = 0;

	DPRINTF("Enter the First Name of the student: ");
	gets(Fname_Temp);

	for(int i=0; i<FIFOBuf->Count; ++i){

		if(strcmp(Ptr->Fname , Fname_Temp) == 0){
			DPRINTF("The students Details are\n");
			DPRINTF("The First name is   : %s\n",Ptr->Fname);
			DPRINTF("Student last  name  : %s\n",Ptr->Lname);
			DPRINTF("Student roll  number: %d\n",Ptr->Roll);
			DPRINTF("Student GPA         : %0.2f\n",Ptr->GPA);
			DPRINTF("Enter the course ID of each course\n");
			for(int j=0 ;j < 5; ++j){
				DPRINTF("The course ID are: %d\n",Ptr->CourseID[j]);
			}
		}
		else{
			Count++;
		}
		Ptr++;
	}
	if(FIFOBuf->Count == Count){
		DPRINTF("[ERROR] First Name %s not found\n",Fname_Temp);
	}
}

void Find_c(FIFO_Buf_t* FIFOBuf){

	int CID , Count = 0;
	Sinfo* Ptr = FIFOBuf->Base;

	DPRINTF("Enter the course ID: ");
	scanf("%d",&CID);

	for(int i=0; i<FIFOBuf->Count; ++i){

		for(int j=0; j<5; ++j){
			if(Ptr->CourseID[j] == CID){
				Count++;
				DPRINTF("The students Details are\n");
				DPRINTF("The First name is   : %s\n",Ptr->Fname);
				DPRINTF("Student last  name  : %s\n",Ptr->Lname);
				DPRINTF("Student roll  number: %d\n",Ptr->Roll);
				DPRINTF("Student GPA         : %0.2f\n",Ptr->GPA);
			}
		}
		Ptr++;
	}
	if(Count == 0){
		DPRINTF("[ERROR] Course ID %d not found\n",CID);
	}
	DPRINTF("[INFO] Total Number of Students Enrolled: %d\n",Count);
}

void Tot_s(FIFO_Buf_t* FIFOBuf){

	DPRINTF("[INFO] The total number of student is %d\n",FIFOBuf->Count);
	DPRINTF("[INFO] You can add up to 50 students\n");
	DPRINTF("[INFO] You can add %d more students\n",50-FIFOBuf->Count);
}

void Del_s(FIFO_Buf_t* FIFOBuf){
	int Num , flag = 0;
	Sinfo* Ptr = FIFOBuf->Base;

	DPRINTF("Enter the Roll Number which you want to delete: ");
	scanf("%d",&Num);

	for(int i=0; i<FIFOBuf->Count; ++i){
		if(Ptr->Roll == Num){
			*Ptr = *(FIFOBuf->Tail);
			FIFOBuf->Count--;
			/* For circular Queue */
			if(FIFOBuf->Tail == (Sinfo*)(FIFOBuf->Length * sizeof(Sinfo))){
				FIFOBuf->Tail = FIFOBuf->Base;
			}
			else{
				FIFOBuf->Tail++;
			}
			flag = 0;
			break;
		}
		else{
			flag = 1;
		}
		Ptr++;
	}
	if(flag == 0){
		DPRINTF("[INFO] The Roll Number is removed successfully\n");
	}
	else{
		DPRINTF("[ERROR] This Roll Number %d not found\n",Num);
	}
}

void Up_s(FIFO_Buf_t* FIFOBuf){

	int Roll_Num , Choice , flag = 0;
	char Temp[50];
	Sinfo* Ptr = FIFOBuf->Base;

	DPRINTF("Enter the roll number to update the entry: ");
	scanf("%d",&Roll_Num);

	for(int i=0; i<FIFOBuf->Count && flag == 0; ++i){
		if(Ptr->Roll == Roll_Num){
            flag = 1;
			DPRINTF("1.first name\n");
			DPRINTF("2.last name\n");
			DPRINTF("3.roll no\n");
			DPRINTF("4. GPA\n");
			DPRINTF("5. courses\n");

			scanf("%d",&Choice);
			switch(Choice)
			{
			case 1:
				DPRINTF("Enter the new first name: ");
				gets(Ptr->Fname);
				break;
			case 2:
				DPRINTF("Enter the new last name: ");
				gets(Ptr->Lname);
				break;
			case 3:
				DPRINTF("Enter the new roll number: ");
				gets(Temp);
				Ptr->Roll = atoi(Temp);
				break;
			case 4:
				DPRINTF("Enter the new GPA: ");
				gets(Temp);
				Ptr->GPA = atof(Temp);
				break;
			case 5:
				DPRINTF("Enter the Course ID of each course:\n");
				for(int i=0; i<5; ++i){
					DPRINTF("Course %d ID: ",i+1);
					gets(Temp);
					FIFOBuf->Head->CourseID[i] = atoi(Temp);
				}
			}
			//break;
		}
		Ptr++;
	}
	DPRINTF("[INFO] UPDATED SUCCESSFULLY.\n");
}

void Show_s(FIFO_Buf_t* FIFOBuf){
	Sinfo* Ptr;

	if(FIFO_EIsEmpty(FIFOBuf) == FIFO_EMPTY){
		printf("FIFO is Empty\n");
	}
	else{
		Ptr = FIFOBuf->Tail;
	}

	for(int i=0; i<FIFOBuf->Count; ++i){
		DPRINTF("Student first name  : %s\n",Ptr->Fname);
		DPRINTF("Student last  name  : %s\n",Ptr->Lname);
		DPRINTF("Student roll  number: %d\n",Ptr->Roll);
		DPRINTF("Student GPA         : %0.2f\n",Ptr->GPA);
		for(int j=0 ;j < 5; ++j){
			DPRINTF("The course ID are: %d\n",Ptr->CourseID[j]);
		}
		Ptr++;
		DPRINTF("-------------------------\n");
	}

}


