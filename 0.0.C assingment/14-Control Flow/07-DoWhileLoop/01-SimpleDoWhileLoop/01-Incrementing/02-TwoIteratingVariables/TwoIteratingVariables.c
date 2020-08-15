#include <stdio.h> 

int main(void) 
{ 
	//variable declarations
	
	int a, k;

	//code 
	
	printf("\n\n");

	printf("Printing Digits 1 to 10 and 10 to 100: \n\n");


	a = 1; 
	k = 10;
	
	do 
	{
		printf("\t %d \t %d\n", a, k); 
		
		a++;  k = k + 10;
	} 
	while (a <= 10, k <= 100);

	printf("\n\n");


	getch();

	return(0);

}


