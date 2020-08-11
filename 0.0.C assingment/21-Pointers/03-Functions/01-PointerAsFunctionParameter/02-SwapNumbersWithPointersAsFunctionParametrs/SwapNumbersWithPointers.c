#include <stdio.h>

int main(void)

{ 
	//function declarations
	
	void SwapNumbers(int *, int *);

 
	//variable declaration 
	
	int a;
	int k;
 
	//code 
	
	printf("\n\n");
	printf("Enter Value For 'A' : ");
	scanf("%d", &a);

	printf("\n\n");
	
	printf("Enter Value For 'K' : ");
	scanf("%d", &k);

	printf("\n\n");
	
	printf("****** BEFORE SWAPPING ******\n\n");
	
	printf("Value Of 'A' = %d\n\n", a); 
	
	printf("Value Of 'K' = %d\n\n", k);

	SwapNumbers(&a, &k); // ****** ARGUMENTS PASSED 'BY REFERENCE / ADDRESS' ... ******
	
	printf("\n\n"); 
	
	printf("****** AFTER SWAPPING ******\n\n");
	
	printf("Value Of 'A' = %d\n\n", a); 
	
	printf("Value Of 'K' = %d\n\n", k);


	getch();

	return(0);
}


// Address Of 'a' is copied into 'x' and Address of 'b' is copied into 'y' ... So, '&a' and 'x' are pointing to ONE and the SAME address and '&b' and 'y' are pointing to ONE and the SAME address ... 
// Swapping takes place between 'value at address of x' (value at &a i.e : 'a') and 'value at address of y' (value at &b i.e : 'b') ...
// Hence, Swapping in this case takes place between '*x' and '*y' AS WELL AS BETWEEN 'a' and 'b' ...
void SwapNumbers(int* x, int* y)

{ 
	//varibale declarations
	
	int temp;
 
	//code 
	
	printf("\n\n"); 
	printf("****** BEFORE SWAPPING ******\n\n");

	printf("Value Of 'X' = %d\n\n", *x); 
	printf("Value Of 'Y' = %d\n\n", *y); temp = *x; *x = *y; *y = temp; 
	
	printf("\n\n"); printf("****** AFTER SWAPPING ******\n\n");
	printf("Value Of 'X' = %d\n\n", *x); 
	printf("Value Of 'Y' = %d\n\n", *y);
}

