#include <stdio.h>
#include <conio.h>
int main(void)
{ 
	//variable declarations
	int i; char ch;

	//code 
	printf("\n\n");

	printf("Printing Even Numbers From 1 to 100 For Every User Input. Exitting the Loop When User Enters Character 'Q' or 'q' : \n\n");
	printf("Enter Character 'Q' or 'q' To Exit Loop : \n\n");

	for (i = 1; i <= 100; i++)
	{ 
		printf("\t%d\n", i);  ch = getch();  if (ch == 'Q' || ch == 'q')
		{
			break;
		} 
	}

	printf("\n\n"); 
	printf("EXITTING LOOP..."); 
	printf("\n\n");

	return(0);
}
