#include <stdio.h>

int main(void)
{
	//variable declarations
	int a;
	int b;
	int result;

	//code
	printf("\n\n");
	printf("Enter A Number : ");
	scanf("%d", &a);

	printf("\n\n");
	printf("Enter Another Number : ");
	scanf("%d", &b);

	printf("\n\n");

	// *** The Following Are The 5 Arithmetic Operators +, -, *, / and % ***
	// *** Also, The Resultants Of The Arithmetic Operations In All The Below Five Cases Have Been Assigned To The Variable 'result' Using the Assignment Operator (=) ***
	result = a + b;
	printf("Addition Of A = %d And B = %d Gives %d.\n", a, b, result);

	result = a - b;
	printf("Subtraction Of A = %d And B = %d Gives %d.\n", a, b, result);

	result = a * b;
	printf("Multiplication Of A = %d And B = %d Gives %d.\n", a, b, result);

	result = a / b;
	printf("Division Of A = %d And B = %d Gives Quotient %d.\n", a, b, result);

	result = a % b;
	printf("Division Of A = %d And B = %d Gives Remainder %d.\n", a, b, result);

	printf("\n\n");
	getch();

	return(0);
}
