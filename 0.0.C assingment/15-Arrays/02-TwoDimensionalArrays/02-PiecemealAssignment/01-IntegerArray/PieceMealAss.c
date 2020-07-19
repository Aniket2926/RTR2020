#include <stdio.h>
int main(void) 
{ 
	//variable declaraions 
	int akArray[3][5];    //iarray chnage akarray

	// 3 ROWS(0, 1, 2) AND 5 COLUMNS (0, 1, 2, 3, 4) 

	int int_size;
	int myArray_size; //iArray change to myarray
	int iArray_num_elements, iArray_num_rows, iArray_num_columns; 
	int i, j;

	//code 
	printf("\n\n");

	int_size = sizeof(int);

	myArray_size = sizeof(akArray); 
	printf("Size Of Two Dimensional ( 2D ) Integer Array Is = %d\n\n", myArray_size);


	iArray_num_rows = myArray_size / sizeof(akArray[0]);
	printf("Number of Rows In Two Dimensional ( 2D ) Integer Array Is = %d\n\n", iArray_num_rows);

	iArray_num_columns = sizeof(akArray[0]) / int_size; 
	printf("Number of Columns In Two Dimensional ( 2D ) Integer Array Is = %d\n \n", iArray_num_columns);

	iArray_num_elements = iArray_num_rows * iArray_num_columns; 
	printf("Number of Elements In Two Dimensional ( 2D ) Integer Array Is = %d\n \n", iArray_num_elements);

	printf("\n\n"); printf("Elements In The 2D Array : \n\n");

// ****** PIECE-MEAL ASSIGNMENT ****** 
// ****** ROW 1 ****** 
	akArray[0][0] = 21;
	akArray[0][1] = 42; 
	akArray[0][2] = 63;
	akArray[0][3] = 84;
	akArray[0][4] = 105;

// ****** ROW 2 ****** 
	akArray[1][0] = 22;
	akArray[1][1] = 44; 
	akArray[1][2] = 66;
	akArray[1][3] = 88;
	akArray[1][4] = 110;

// ****** ROW 3 ****** 
	akArray[2][0] = 23;
	akArray[2][1] = 46;
	akArray[2][2] = 69; 
	akArray[2][3] = 92; 
	akArray[2][4] = 115;

	// *** DISPLAY *** 
	for (i = 0; i < iArray_num_rows; i++) 
	{  
		printf("****** ROW %d ******\n", (i + 1));  for (j = 0; j < iArray_num_columns; j++) 
		{  
			printf("iArray[%d][%d] = %d\n", i, j, akArray[i][j]); 
		} 
		printf("\n\n"); 
	}
	getch();

	return(0);
}
