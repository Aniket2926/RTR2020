#include <stdio.h> 
#include <stdlib.h>

#define INT_SIZE sizeof(int)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#define CHAR_SIZE sizeof(char)

int main(void)
{ 
	//variable declarations 
	int *ptr_iArray = NULL; 

	unsigned int intArrayLength = 0;

	float* ptr_fArray = NULL;
	
	unsigned int floatArrayLength = 0;
	double* ptr_dArray = NULL; 
	
	unsigned int doubleArrayLength = 0;

	char* ptr_cArray = NULL;

	unsigned int charArrayLength = 0;

	int i;
	
	//code

	// ****** INTEGER ARRAY ******* 
	
	printf("\n\n"); 
	printf("Enter The Number Of Elements You Want In The Integer Array : ");
	scanf("%u", &intArrayLength);

	ptr_iArray = (int*)malloc(INT_SIZE * intArrayLength);
	
	if (ptr_iArray == NULL) 
	{ 
		printf("\n\n");  
	
		printf("MEMORY ALLOCATION FOR INTEGER ARRAY FAILED !!! EXITTING NOW... \n\n"); 
		exit(0);
	}
	
	else 
	{ 
		printf("\n\n"); 
		printf("MEMORY ALLOCATION FOR INTEGER ARRAY SUCCEEDED !!!\n\n");
	}

	printf("\n\n"); 
	
	printf("Enter The %d Integer Elements To Fill Up The Integer Array : \n \n", intArrayLength);
	
	
	for (i = 0; i < intArrayLength; i++) 
		scanf("%d", (ptr_iArray + i));

	// ****** FLOAT ARRAY *******
	
	
	printf("\n\n"); 
	
	printf("Enter The Number Of Elements You Want In The 'float' Array : "); 
	
	scanf("%u", &floatArrayLength);

	ptr_fArray = (float*)malloc(FLOAT_SIZE * floatArrayLength); 
	
	
	
	
	if (ptr_fArray == NULL)
	
	{
		printf("\n\n");  
		printf("MEMORY ALLOCATION FOR FLOATING-POINT ARRAY FAILED !!! EXITTING NOW...\n\n"); 
		exit(0);
	}
		
	else
	{ 
		printf("\n\n");
		
		printf("MEMORY ALLOCATION FOR FLOATING-POINT ARRAY SUCCEEDED !!!\n \n");
	
	}
	
	
	printf("\n\n"); 
	
	printf("Enter The %d Floating-Point Elements To Fill Up The 'float' Array : \n\n", floatArrayLength); 
	
	
	for (i = 0; i < floatArrayLength; i++)  
		scanf("%f", (ptr_fArray + i));

	// ****** DOUBLE ARRAY ******* 
	
	printf("\n\n"); 
	
	printf("Enter The Number Of Elements You Want In The 'double' Array : "); 
	
	scanf("%u", &doubleArrayLength);

	ptr_dArray = (double*)malloc(DOUBLE_SIZE * doubleArrayLength); 
	
	
	
	if (ptr_dArray == NULL)
	{
		printf("\n\n"); 

	
		printf("MEMORY ALLOCATION FOR 'DOUBLE' ARRAY FAILED !!! EXITTING NOW...\n\n"); 
		exit(0);
	}
	
	
	else
	{
		printf("\n\n");
		
		printf("MEMORY ALLOCATION FOR 'DOUBLE' ARRAY SUCCEEDED !!!\n\n"); 
	}

	printf("\n\n"); 
	
	printf("Enter The %d Double Elements To Fill Up The 'double' Array : \n \n", doubleArrayLength); 
	
	for (i = 0; i < doubleArrayLength; i++) 
		scanf("%lf", (ptr_dArray + i));


	// ****** CHAR ARRAY *******
	
	printf("\n\n");
	
	
	printf("Enter The Number Of Elements You Want In The Character Array : ");
	
	
	scanf("%u", &charArrayLength);

	ptr_cArray = (char*)malloc(CHAR_SIZE * charArrayLength);
	
	
	if (ptr_cArray == NULL)
	
	{
		printf("\n\n");
		
		printf("MEMORY ALLOCATION FOR CHARACTER ARRAY FAILED !!! EXITTING NOW...\n\n");  
		
		exit(0);

	}
	else 
	
	{ 
		printf("\n\n");  
		
		printf("MEMORY ALLOCATION FOR CHARACTER ARRAY SUCCEEDED !!!\n\n");
	}
	
	printf("\n\n"); 
	
	printf("Enter The %d Character Elements To Fill Up The Character Array : \n\n", charArrayLength);
	
	
	
	for (i = 0; i < charArrayLength; i++)
	{ 
		*(ptr_cArray + i) = getch();
	
	
		printf("%c\n", *(ptr_cArray + i)); 
	}

	// ********** DISPLAY OF ARRAYS **********

	// ****** INTEGER ARRAY ****** 
	
	printf("\n\n");
	
	printf("The Integer Array Entered By You And Consisting Of %d Elements Is As Follows : \n\n", intArrayLength); 
	
	for (i = 0; i < intArrayLength; i++)  
		printf(" %d \t \t At Address : %p\n", *(ptr_iArray + i), (ptr_iArray + i));

	// ****** FLOAT ARRAY ******
	printf("\n\n"); 
	
	printf("The Float Array Entered By You And Consisting Of %d Elements Is As Follows : \n\n", floatArrayLength);
	
	for (i = 0; i < floatArrayLength; i++)
		printf(" %f \t \t At Address : %p\n", *(ptr_fArray + i), (ptr_fArray + i));


	// ****** DOUBLE ARRAY ******
	
	printf("\n\n"); 
	
	printf("The Double Array Entered By You And Consisting Of %d Elements Is As Follows : \n\n", doubleArrayLength); 
	
	for (i = 0; i < doubleArrayLength; i++)  
		printf(" %lf \t \t At Address : %p\n", *(ptr_dArray + i), (ptr_dArray + i));

	
	// ****** CHARACTER ARRAY ****** 
	printf("\n\n"); 
	
	printf("The Character Array Entered By You And Consisting Of %d Elements Is As Follows : \n\n", charArrayLength); 
	
	for (i = 0; i < charArrayLength; i++)
		printf(" %c \t \t At Address : %p\n", *(ptr_cArray + i), (ptr_cArray + i));

	// ****** FREEING MEMORY OCCUPIED BY ARRAYS (IN REVERSE ORDER OF ALLOCATION)****** 
	
	if (ptr_cArray)
	{
		free(ptr_cArray); 
		ptr_cArray = NULL;
		
		printf("\n\n"); 
		
		printf("MEMORY OCCUPIED BY CHARACTER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");

	}
	
	
	
	if (ptr_dArray)
	{
		free(ptr_dArray); 

		ptr_dArray = NULL;
		
		printf("\n\n");  
		
		printf("MEMORY OCCUPIED BY 'DOUBLE' ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}
	
	
	if (ptr_fArray)
	{
	
		free(ptr_fArray); 
		
		ptr_fArray = NULL;
		
		printf("\n\n");  
		
		printf("MEMORY OCCUPIED BY FLOATING-POINT ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}



	if (ptr_iArray) 
	{
		free(ptr_iArray);  
		
		ptr_iArray = NULL;
		
		printf("\n\n");  
		
		printf("MEMORY OCCUPIED BY INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}




	getch();
	return(0);
}


