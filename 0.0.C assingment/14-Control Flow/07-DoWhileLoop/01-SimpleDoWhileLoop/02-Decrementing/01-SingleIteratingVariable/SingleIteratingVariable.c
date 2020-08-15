#include <stdio.h> 

int main(void) 
{ 
	//variable declarations
	int a;

	//code
	
	printf("\n\n");

	printf("Printing Digits 10 to 1 : \n\n");

	a = 10; 
	do
	{ 
		printf("\t%d\n", a); 
		a--; 
	}
	while (a >= 1);

	printf("\n\n");


	getch();
	return(0);
}


