#include <stdio.h>

int main(void) 

{ 
	//variable declarations 
	
	int MyiArray[10];
	
	int i;
 
	
	//code 

	for (i = 0; i < 10; i++) 
		MyiArray[i] = (i + 1) * 3;

	printf("\n\n"); 
	
	printf("Elements Of The Integer Array : \n\n");
	
	for (i = 0; i < 10; i++) 
		printf("iArray[%d] = %d\n", i, MyiArray[i]);
	
	printf("\n\n"); 

	printf("Elements Of The Integer Array : \n\n"); 
	
	for (i = 0; i < 10; i++) 
		printf("iArray[%d] = %d \t \t Address = %p\n", i, MyiArray[i], &MyiArray[i]);
	
	printf("\n\n");
	
	getch();
	
	return(0);
}


