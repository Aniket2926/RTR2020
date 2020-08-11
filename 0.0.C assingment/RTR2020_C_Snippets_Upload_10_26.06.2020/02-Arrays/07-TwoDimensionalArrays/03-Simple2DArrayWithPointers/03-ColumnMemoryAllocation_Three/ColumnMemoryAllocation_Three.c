#include <stdio.h> 
#include <stdlib.h>

#define NUM_ROWS 5 

#define NUM_COLUMNS 5


int main(void) 

{ 
	//variable declarations 
	int *iArray[NUM_ROWS]; //A 2D Array which will have 5 rows and number of columns can be decided later on ... 
	
	int a, k;

 
	//code
	
	printf("\n\n"); 
	
	printf("********** MEMORY ALLOCATION TO 2D INTEGER ARRAY **********\n\n");
	
	for (a = 0; a < NUM_ROWS; a++) 
	{  
		//ROW 0 WILL HAVE (NUM_COLUMNS - 0) = (5 - 0) = 5 COLUMNS...  
		//ROW 1 WILL HAVE (NUM_COLUMNS - 1) = (5 - 1) = 4 COLUMNS...
		//ROW 2 WILL HAVE (NUM_COLUMNS - 2) = (5 - 2) = 3 COLUMNS... 
		//ROW 3 WILL HAVE (NUM_COLUMNS - 3) = (5 - 3) = 2 COLUMNS...  
		//ROW 4 WILL HAVE (NUM_COLUMNS - 4) = (5 - 4) = 1 COLUMN...
 
		//BEACUSE OF THIS, THERE IS NO CONTIGUOUS MEMORY ALLOCATION ... 
  
		//HENCE, ALTHOUGH WE MAY USE THE DATA AS A 2D ARRAY, IT IS NOT REALLY A 2D ARRAY IN MEMORY ...
	
		iArray[a] = (int*)malloc((NUM_COLUMNS - a) * sizeof(int)); 
		
		if (iArray[a] == NULL)
		{
			printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXITTING NOW...\n\n", a); 
			
			exit(0); 
		}
	
		else   
			printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", a);

	}

	for (a = 0; a < 5; a++)
	{
		for (k = 0; k < (NUM_COLUMNS - a); k++) 
		{ 
			iArray[a][k] = (a * 1) + (k * 1); 
		} 
	}

	for (a = 0; a < 5; a++)
	{
	
		for (k = 0; k < (NUM_COLUMNS - a); k++) 
		{ 
			
			printf("iArray[%d][%d] = %d \t At Address : %p\n", a, k, iArray[a][k], &iArray[a][k]); 
		}  

		printf("\n");
	

	}

	for (a = (NUM_ROWS - 1); a >= 0; a--) 
	{
		if (iArray[a])
		{ 
			free(iArray[a]); 
		
			iArray[a] = NULL;  
			
			printf("MEMORY ALLOCATED TO ROW %d HAS BEEN SUCCESSFULLY FREED !!! \n\n", a);
		
		}
	}

	getch();
	return(0); 
}


