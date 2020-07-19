#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{ 
    //variable declarations  

    char mychArray[MAX_STRING_LENGTH]; // A Character Array Is A String
    int iStringLength = 0;
 
    //code
 
    // *** STRING INPUT *** 
    printf("\n\n"); printf("Enter A String : \n\n");
    gets_s(mychArray, MAX_STRING_LENGTH);
 
    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("String Entered By You Is : \n\n"); 
    printf("%s\n", mychArray);
 
    // *** STRING LENGTH ***
    printf("\n\n"); 

    iStringLength = strlen(mychArray); 

    printf("Length Of String Is = %d Characters !!!\n\n", iStringLength);

    getch();

    return(0);
}