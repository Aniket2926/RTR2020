#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{ 
    //variable declarations  
    char mychArray_One[MAX_STRING_LENGTH], mychArray_Two[MAX_STRING_LENGTH]; // A Character Array Is A String
 
   //code
 
   // *** STRING INPUT *** 
    printf("\n\n"); 
    printf("Enter First String : \n\n"); 
    gets_s(mychArray_One, MAX_STRING_LENGTH);

    printf("\n\n");
    printf("Enter Second String : \n\n");
    gets_s(mychArray_Two, MAX_STRING_LENGTH);
   
    // *** STRING CONCAT *** 
    printf("\n\n"); 
    printf("****** BEFORE CONCATENATION ******");
    printf("\n\n"); printf("The Original First String Entered By You (i.e : 'mychArray_One[]') Is : \n\n");
    printf("%s\n", mychArray_One);

    printf("\n\n"); 
    printf("The Original Second String Entered By You (i.e : 'mychArray_Two[]') Is : \n\n");
    printf("%s\n", mychArray_Two);

    strcat(mychArray_One, mychArray_Two);

    printf("\n\n"); 
    printf("****** AFTER CONCATENATION ******"); 
    printf("\n\n"); 
    printf("'mychArray_One[]' Is : \n\n"); 
    printf("%s\n", mychArray_One);
    printf("\n\n");
    printf("'mychArray_Two[]' Is : \n\n");
    printf("%s\n", mychArray_Two);

    getch();
    return(0);
}