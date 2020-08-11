#include <stdio.h>

// DEFINING STRUCT 

struct MyData 
{
	int a;
	
	float f; 
	
	double d; 
};


int main(void) 
{ 
	//variable declarations
	
	int i_size; 
	
	int f_size; 
	
	int d_size; 
	
	int struct_MyData_size; 
	
	int pointer_to_struct_MyData_size;

	struct MyData* pData = NULL;

	//code 
	
	printf("\n\n");

	pData = (struct MyData*)malloc(sizeof(struct MyData)); 
	
	if (pData == NULL)
	
	{ 
		printf("FAILED TO ALLOCATE MEMORY TO 'sturct MyData' !!! EXITTING NOW ... \n\n"); 
	
	
		exit(0); 
	}
	
	else 
		
		printf("SUCCESSFULLY ALLOCATED MEMORY TO 'sturct MyData' !!!\n\n");

	
	
	//Assigning Data Values To The Data Members Of 'struct MyData' 
	
	pData->a = 30; 

	pData->f = 11.45f;

	pData->d = 1.2995;

	//Displaying Values Of The Data Members Of 'struct MyData'
	
	printf("\n\n"); 
	
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n"); 
	
	printf("a = %d\n", pData->a);
	
	printf("f = %f\n", pData->f); 
	
	printf("d = %lf\n", pData->d);

	//Calculating Sizes (In Bytes) Of The Data Members Of 'struct MyData'
	
	i_size = sizeof(pData->a);
	
	f_size = sizeof(pData->f); 
	
	d_size = sizeof(pData->d);

	//Displaying Sizes (In Bytes) Of The Data Members Of 'struct MyData'
	
	printf("\n\n");
	
	printf("SIZES (in bytes) OF DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	
	printf("Size of 'a' = %d bytes\n", i_size); 
	
	printf("Size of 'f' = %d bytes\n", f_size); 
	
	printf("Size of 'd' = %d bytes\n", d_size);
		
	//Calculating Size (In Bytes) Of the entire 'struct Mydata' 
	
	struct_MyData_size = sizeof(struct MyData);
	
	pointer_to_struct_MyData_size = sizeof(struct MyData *);

		  
	//Displaying Sizes (In Bytes) Of the entire 'struct Mydata' 
	
	printf("\n\n"); 
	
	printf("Size of 'struct MyData' : %d bytes\n\n", struct_MyData_size); 
	
	printf("Size of pointer to 'struct MyData' : %d bytes\n\n", pointer_to_struct_MyData_size);
		
	if (pData)
	{ 
		
		free(pData);  pData = NULL;
		
	
		printf("MEMORY ALLOCATED TO 'struct MyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");

	}



	getch();
	return(0);
}


