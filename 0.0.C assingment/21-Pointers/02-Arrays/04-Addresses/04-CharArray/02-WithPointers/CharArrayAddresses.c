#include <stdio.h>

int main(void) 

{ 
	//variable declarations
	
	char cArray[10]; 

	char *ptr_cArray = NULL;
	
	int i;
 
	//code
	
	for (i = 0; i < 10; i++)
		cArray[i] = (char)(i + 65);

 
	// *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
	// *** HENCE, 'cArray' IS THE BASE ADDRESS OF ARRAY cArray[] OR 'cArray' IS THE ADDRESS OF ELEMENT cArray[0] *** 
	// *** ASSIGNING BASE ADDRESS OF ARRAY 'cArray[]' TO CHAR POINTER 'ptr_cArray'

	ptr_cArray = cArray; // ptr_cArray = &cArray[0];

	printf("\n\n"); 
	
	printf("Elements Of The Character Array : \n\n"); 
	
	for (i = 0; i < 10; i++)  
		printf("cArray[%d] = %c\n", i, *(ptr_cArray + i));

	printf("\n\n");
	
	printf("Elements Of The Character Array : \n\n");
	
	for (i = 0; i < 10; i++)  
		printf("cArray[%d] = %c \t \t Address = %p\n", i, *(ptr_cArray + i), (ptr_cArray + i));
	
	printf("\n\n");


	getch();
	return(0);

}

