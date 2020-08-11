#include <stdio.h>

int main(void)
{ 
	//variable declarations 
	
	double dArray[10];
	
	double *ptr_dArray = NULL; 
	
	int i;

 
	//code 
	for (i = 0; i < 10; i++)  
		dArray[i] = (float)(i + 1) * 1.333333f;

 
	// *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
	// *** HENCE, 'dArray' IS THE BASE ADDRESS OF ARRAY dArray[] OR 'dArray' IS THE ADDRESS OF ELEMENT dArray[0] *** 
	// *** ASSIGNING BASE ADDRESS OF ARRAY 'dArray[]' TO DOUBLE POINTER 'ptr_dArray'
	
	ptr_dArray = dArray; // ptr_dArray = &dArray[0];

	printf("\n\n"); printf("Elements Of The 'double' Array : \n\n"); 
	
	for (i = 0; i < 10; i++) 
		printf("dArray[%d] = %lf\n", i, *(ptr_dArray + i));

	printf("\n\n");

	printf("Elements Of The 'double' Array : \n\n");
	
	for (i = 0; i < 10; i++) 
		printf("dArray[%d] = %lf \t \t Address = %p\n", i, *(ptr_dArray + i), (ptr_dArray + i));

	
	printf("\n\n");


	getch();
	return(0);
}

