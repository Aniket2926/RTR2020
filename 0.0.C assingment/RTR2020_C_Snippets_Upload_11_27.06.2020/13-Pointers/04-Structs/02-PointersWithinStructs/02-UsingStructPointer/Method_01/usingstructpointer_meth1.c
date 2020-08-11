#include <stdio.h>


// DEFINING STRUCT

struct MyData
{
	int *ptr_a;
	int a;


	float* ptr_f;
	float f;

	double* ptr_d; 
	double d;
};

int main(void)
{ 
	//variable declarations 
	struct MyData *pData = NULL;

 
	//code 
	
	printf("\n\n"); 
	
	pData = (struct MyData *)malloc(sizeof(struct MyData)); 
	
	if (pData == NULL)
	{
		printf("FAILED TO ALLOCATE MEMORY TO 'struct MyData' !!! EXITTING NOW ... \n\n");  
		
		exit(0); 
	}
	else 
		printf("SUCCESSFULLY ALLOCATED MEMORY TO 'struct MyData' !!!\n\n");
	
	(*pData).a = 9;
	
	(*pData).ptr_a = &(*pData).a;

	(*pData).f = 11.45f;
	
	(*pData).ptr_f = &(*pData).f;

	(*pData).d = 30.121995;
	
	(*pData).ptr_d = &(*pData).d;

	printf("\n\n"); 
	
	printf("a = %d\n", *((*pData).ptr_a)); 
	
	printf("Adress Of 'a' = %p\n", (*pData).ptr_a);

	printf("\n\n"); 
	
	printf("f = %f\n", *((*pData).ptr_f)); 
	
	printf("Adress Of 'f' = %p\n", (*pData).ptr_f);
	
	printf("\n\n"); 
	
	printf("d = %lf\n", *((*pData).ptr_d));
	
	printf("Adress Of 'd' = %p\n", (*pData).ptr_d);
	
		
	if (pData) 
	{
		free(pData);  pData = NULL; 
		
		printf("MEMORY ALLOCATED TO 'struct MyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}
	

	getch();
	return(0);
}

