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
	
	for (a = 0; a < NUM_ROWS; a++) 
	{ 
		for (k = 0; k < NUM_COLUMNS; k++)  
			iArray[a][k] = (a + 1) * (k + 1);
	}

	printf("\n\n"); 
	
	printf("2D Integer Array Elements Along With Addresses : \n\n"); 
	
	for (a = 0; a < NUM_ROWS; a++)
	{ 
		for (k = 0; k < NUM_COLUMNS; k++)
	
	
		{ 
		
			printf("iArray[%d][%d] = %d \t \t At Address : %p\n", a, k, iArray[a][k], &iArray[a][k]);
	
	
		}
	
	
	
		printf("\n\n");
	
	
	}
	
	getch();
	return(0);
}

