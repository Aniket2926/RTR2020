#include <stdio.h> 
#include <stdlib.h>

#define NUM_ROWS 5 

#define NUM_COLUMNS_ONE 3

#define NUM_COLUMNS_TWO 8


int main(void)
{
	//variable declarations
	
	int *iArray[NUM_ROWS]; //A 2D Array which will have 5 rows and number of columns can be decided later on ...  
	
	int a, k;

 
	//code
 
	// ********** ONE (ALLOCATING MEMORY FOR AN ARRAY OF 3 INTEGERS PER ROW) **********
	
	printf("\n\n");
	printf("********** FIRST MEMORY ALLOCATION TO 2D INTEGER ARRAY ********** \n\n"); 
	
	for (a = 0; a < NUM_ROWS; a++)
	{
		iArray[a] = (int *)malloc(NUM_COLUMNS_ONE * sizeof(int));  
		
		if (iArray[a] == NULL)  
		{  
			printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXITTING NOW...\n\n", a); 
			
			exit(0);
		} 
		
		else  
			
			printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", a); 

	}

	//ASSIGNING VALUES TO 2D ARRAY ... 
	
	for (a = 0; a < NUM_ROWS; a++) 
	{ 
		
		for (k = 0; k < NUM_COLUMNS_ONE; k++)
		
		{   
			
			iArray[a][k] = (a + 1) * (k + 1);
		}
	}

 //DISPLAYING 2D ARRAY ... 
	
	printf("\n\n"); 
	
	printf("DISPLAYING 2D ARRAY : \n\n"); 
	
	for (a = 0; a < NUM_ROWS; a++)
	{ 
		for (k = 0; k < NUM_COLUMNS_ONE; k++) 
		
		{  
			
			printf("iArray[%d][%d] = %d\n", a, k, iArray[a][k]);
		} 
		printf("\n\n");
	}

	printf("\n\n");

		
	//FREEING MEMORY ASSIGNED TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER)
	
	for (a = (NUM_ROWS - 1); a >= 0; a--)
	{ 
		free(iArray[a]); 
		iArray[a] = NULL; 
		printf("MEMORY ALLOCATED TO ROW %d Of 2D INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n", a);
	}
		
	// ********** TWO (ALLOCATING MEMORY FOR AN ARRAY OF 8 INTEGERS PER ROW) ********** 
	
	printf("\n\n"); 
	
	printf("********** SECOND MEMORY ALLOCATION TO 2D INTEGER ARRAY ********** \n\n");
	
	for (a = 0; a < NUM_ROWS; a++)
	
	{  
		iArray[a] = (int *)malloc(NUM_COLUMNS_TWO * sizeof(int));  
		if (iArray[a] == NULL) 
		
		{  
			printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXITTING NOW...\n\n", a);
			
			
			exit(0); 
		}  
		
		else  
			
			printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", a); 
	
	}
		
	//ASSIGNING VALUES TO 2D ARRAY ...
	
	for (a = 0; a < NUM_ROWS; a++)
	{ 
		for (k = 0; k < NUM_COLUMNS_TWO; k++) 
		{ 
			
			iArray[a][k] = (a + 1) * (k + 1); 
		}
	
	}
		
	//DISPLAYING 2D ARRAY ... 
	
	printf("\n\n");
	
	printf("DISPLAYING 2D ARRAY : \n\n");
	
	for (a = 0; a < NUM_ROWS; a++) 
	{  
		for (k = 0; k < NUM_COLUMNS_TWO; k++) 
		{  
			
			printf("iArray[%d][%d] = %d\n", a, k, iArray[a][k]);  
		}  
		
		printf("\n\n");
	} 
	
	printf("\n\n");
		
	//FREEING MEMORY ASSIGNED TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER) 
	
	for (a = (NUM_ROWS - 1); a >= 0; a--) 
	{ 
		free(iArray[a]); 

		iArray[a] = NULL;
		
		printf("MEMORY ALLOCATED TO ROW %d Of 2D INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n", a);

	}


	getch();
	return(0);

 }


		