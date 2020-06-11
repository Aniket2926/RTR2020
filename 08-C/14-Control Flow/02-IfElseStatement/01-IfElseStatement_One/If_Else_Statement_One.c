#include <stdio.h> 
int main(void) 
{ 
	//variable declarations 
	int a, b, p;

	//code
	a = 9; b = 30; p = 30;

	// *** FIRST if-else PAIR *** 
	printf("\n\n"); 
	if (a < b) 
	{  
		printf("Entering First if-block...\n\n");  printf("A Is Less Than B !!!\n\n"); }
	else 
	{ 
		printf("Entering First else-block...\n\n");  printf("A Is NOT Less Than B !!!\n\n");
	}

	printf("First if-else Pair Done !!!\n\n");


	// *** SECOND if-else PAIR ***
	printf("\n\n"); 
	if (b != p)
	{ 
		printf("Entering Second if-block...\n\n"); 
		printf("B Is NOT Equal To P !!!\n\n"); 
	}
	else
	{ 
		printf("Entering Second else-block...\n\n"); 
		printf("B Is Equal To P !!!\n\n");
	} 

	printf("Second if-else Pair Done !!!\n\n");

	getch();

	return(0); 
}
