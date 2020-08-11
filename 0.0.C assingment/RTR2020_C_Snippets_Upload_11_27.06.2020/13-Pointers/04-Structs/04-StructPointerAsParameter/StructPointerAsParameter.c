#include <stdio.h>

// DEFINING STRUCT

struct MyData 
{
	int ak; 
	float f; 
	double d;
};

int main(void)
{
	//function prototypes
	void ChangeValues(struct MyData *);


	//variable declarations 
	struct MyData *pData = NULL;
 
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
	
	pData->ak = 30; pData->f = 11.45f; pData->d = 1.2995;

	//Displaying Values Of The Data Members Of 'struct MyData'
	
	printf("\n\n");
	
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	
	printf("ak = %d\n", pData->ak);
	
	printf("f = %f\n", pData->f); 
	
	printf("d = %lf\n", pData->d);
	
	ChangeValues(pData);

	//Displaying Values Of The Data Members Of 'struct MyData'
	
	printf("\n\n");
	
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	
	printf("ak = %d\n", pData->ak); 
	
	printf("f = %f\n", pData->f); 
	
	printf("d = %lf\n", pData->d);
		
	if (pData) 
	{ 
		free(pData);  
		pData = NULL;  
		
		printf("MEMORY ALLOCATED TO 'struct MyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}
	getch();
	return(0);
}

void ChangeValues(struct MyData* pParam_Data) 
{ 
	//code
	
	pParam_Data->ak = 9;
	pParam_Data->f = 8.2f; 
	pParam_Data->d = 6.1998;
	
	
	// second way  
	/* 
	(*pParam_Data).i = 9;
	(*pParam_Data).f = 8.2f; 
	(*pParam_Data).d = 6.1998;
	*/


}


