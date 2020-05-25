#include <stdio.h>

int main(void)
{
	//variable declarations
	int a;
	int b;
	int x;

	//code
	printf("\n\n");
	printf("Enter A Number : ");
	scanf("%d", &a);

	printf("\n\n");
	printf("Enter Another Number : ");
	scanf("%d", &b);

	printf("\n\n");

	//Since, In All The Following 5 Cases, The Operand on The Left 'a' Is Getting Repeated Immeiately On The Right (e.g : a = a + b or a = a -b),
	//We Are Using Compound Assignment Operators +=, -=, *=, /= and %=

	//Since, 'a' Will Be Assigned The Value Of (a + b) At The Expression (a += b), We Must Save The Original Value Of 'a' To Another Variable (x)
	x = a;
	a += b; // a = a + b
	printf("Addition Of A = %d And B = %d Gives %d.\n", x, b, a);

	//Value Of 'a' Altered In The Above Expression Is Used Here...
	//Since, 'a' Will Be Assigned The Value Of (a - b) At The Expression (a -= b), We Must Save The Original Value Of 'a' To Another Variable (x)
	x = a;
	a -= b; // a = a - b
	printf("Subtraction Of A = %d And B = %d Gives %d.\n", x, b, a);

	//Value Of 'a' Altered In The Above Expression Is Used Here...
	//Since, 'a' Will Be Assigned The Value Of (a * b) At The Expression (a *= b), We Must Save The Original Value Of 'a' To Another Variable (x)
	x = a;
	a *= b; // a = a * b
	printf("Multiplication Of A = %d And B = %d Gives %d.\n", x, b, a);

	//Value Of 'a' Altered In The Above Expression Is Used Here...
	//Since, 'a' Will Be Assigned The Value Of (a / b) At The Expression (a /= b), We Must Save The Original Value Of 'a' To Another Variable (x)
	x = a;
	a /= b; // a = a / b 
	printf("Division Of A = %d And B = %d Gives Quotient %d.\n", x, b, a);

	//Value Of 'a' Altered In The Above Expression Is Used Here...
	//Since, 'a' Will Be Assigned The Value Of (a % b) At The Expression (a %= b), We Must Save The Original Value Of 'a' To Another Variable (x)
	x = a;
	a %= b; // a = a % b
	printf("Division Of A = %d And B = %d Gives Remainder %d.\n", x, b, a);

	printf("\n\n");
	getch();

	return(0);
}
