#include <stdio.h>
int main(void)
{ 
	//variable declarations
	int i, j;

	//code
	printf("\n\n");


	i = 1; while (i <= 10) 
	{ 
		printf("i = %d\n", i);
		printf("--------\n\n");    j = 1;  while (j <= 5)
		{ 
			printf("\tj = %d\n", j);   j++;
		} 
		i++;
		printf("\n\n"); 
	} 
	
	return(0);
}
