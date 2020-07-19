#include <stdio.h>
int main(void)
{ 
	//variable declarations 
	int age;

	//code 
	printf("\n\n"); 
	printf("Enter Age : "); 
	scanf("%d", &age); 
	if (age >= 18) 
	{ 
		printf("You Are Eligible For Voting !!!\n\n");
	} 

	printf("You Are NOT Eligible For Voting !!!\n\n"); 

	getch();

	return(0);

}
