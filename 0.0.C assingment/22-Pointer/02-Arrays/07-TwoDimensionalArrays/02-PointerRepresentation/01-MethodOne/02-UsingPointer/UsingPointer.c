#include <stdio.h>

#define NUM_ROWS 5 
#define NUM_COLUMNS 3

int main(void)
{
	//variable declarations

	int iArray[NUM_ROWS][NUM_COLUMNS];

	int i, j;

	int* ptr_iArray_Row = NULL;

	//code

	// *** EVERY ROW OF A 2D ARRAY IS AN INTEGER ARRAY ITSELF COMPRISING OF 'NUM_COLUMNS' INTEGER ELEMENTS *** 

	// *** THERE ARE 5 ROWS AND 3 COLUMNS IN A 2D INTEGER ARRAY. EACH OF THE 5 ROWS IS A 1D ARRAY OF 3 INTEGERS.  

	// *** HENCE, EACH OF THESE 5 ROWS THEMSELVES BEING ARRAYS, WILL BE THE BASE ADDRESSES OF THEIR RESPECTIVE ROWS ***

	for (i = 0; i < NUM_ROWS; i++)
	{
		ptr_iArray_Row = iArray[i]; // 'iArray[i]' IS THE BASE ADDRESS OF ith ROW ... 

		for (j = 0; j < NUM_COLUMNS; j++)
			*(ptr_iArray_Row + j) = (i + 1) * (j + 1); // 'ptr_iArray_Row' (That is, 'iArray[i]' Can Be Treated As 1D Array Using Pointers) ... 

		printf("\n\n");
	}


		
	printf("2D Integer Array Elements Along With Addresses : \n\n");

		
	for (i = 0; i < NUM_ROWS; i++)
		
	{
			
		ptr_iArray_Row = iArray[i];

			
		for (j = 0; j < NUM_COLUMNS; j++)
		{
				
			printf("*(ptr_iArray_Row + %d)= %d \t \t At Address (ptr_iArray_Row + j) : %p\n", j, *(ptr_iArray_Row + j),
					(ptr_iArray_Row + j));
			
		}

			
		printf("\n\n");
		
	}
	getch();
	
	return(0);

}

