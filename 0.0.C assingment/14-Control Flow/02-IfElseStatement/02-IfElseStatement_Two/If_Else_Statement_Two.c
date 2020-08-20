#include <stdio.h>


int main(void) 

{ 
	//variable declarations
	
	int age;

	//code 
	
	printf("\n\n");
	
	printf("Enter Age : "); 
	
	scanf("%d", &age); 
	
	printf("\n\n"); 
	
	if (age >= 18) 
	{ 
		printf("Entering if-block...\n\n");
		
		printf("You Are Eligible For Voting Welcome !!!\n\n"); 
	
	}
	else
	
	{ 
		printf("Entering else-block...\n\n"); 
		printf("You Are NOT Eligible For Voting  Welcome Back At Right Age!!!\n\n"); 
	}
	
	printf("Bye Takecare !!!\n\n");
	

	getch();
	return(0); 

}


