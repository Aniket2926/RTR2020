#include <stdio.h>
int main(void)
{ 
	//variable declarations
	int i, j;

	//code
	printf("\n\n");

	printf("Printing Digits 10 to 1 and 100 to 10 : \n\n");

	for (i = 10, j = 100; i >= 1, j >= 10; i--, j -= 10) 
	{
		printf("\t %d \t %d\n", i, j);
	}

	printf("\n\n");

return(0); 

}
