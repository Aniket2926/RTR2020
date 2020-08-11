#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{ 
	//variable declarations 
	
	int iArray[NUM_ROWS][NUM_COLUMNS]; 
	
	int a, k;

 
	//code 
	// *** EVERY ROW OF A 2D ARRAY IS AN INTEGER ARRAY ITSELF COMPRISING OF 'NUM_COLUMNS' INTEGER ELEMENTS ***
	// *** THERE ARE 5 ROWS AND 3 COLUMNS IN A 2D INTEGER ARRAY. EACH OF THE 5 ROWS IS A 1D ARRAY OF 3 INTEGERS.  
	// *** HENCE, EACH OF THESE 5 ROWS THEMSELVES BEING ARRAYS, WILL BE THE BASE ADDRESSES OF THEIR RESPECTIVE ROWS ***

	for (a = 0; a < NUM_ROWS; a++) 
	{

		for (k = 0; k < NUM_COLUMNS; k++)   
			*(iArray[a] + k) = (a + 1) * (k + 1); // 'iArray[i]' Can Be Treated As 1D Array Using Pointers ...
	
	}
		
	printf("\n\n"); 
	
	printf("2D Integer Array Elements Along With Addresses : \n\n"); 
	
	
	for (a = 0; a < NUM_ROWS; a++)
	
	{ 
		for (k = 0; k < NUM_COLUMNS; k++)
	
		{ 
			printf("*(iArray[%d] + %d)= %d \t \t At Address (iArray[i] + j) : % p\n", a, k, *(iArray[a] + k), (iArray[a] + k)); 
		} 

		printf("\n\n");
	}
		
	getch();

	return(0);
	
}


