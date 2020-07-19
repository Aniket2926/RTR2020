#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{ 
    //function prototype

    void MyStrcat(char[],char[]);

 
    //variable declarations 
    char chArray_One[MAX_STRING_LENGTH], chArray_Two[MAX_STRING_LENGTH];  // A Character Array Is A String
 
    //code
 
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter First String : \n\n");
    gets_s(chArray_One, MAX_STRING_LENGTH);

    printf("\n\n");
    printf("Enter Second String : \n\n"); 
    gets_s(chArray_Two, MAX_STRING_LENGTH);

    // *** STRING CONCAT ***
    printf("\n\n");
    printf("****** BEFORE CONCATENATION ******"); 
    printf("\n\n");
    printf("The Original First String Entered By You (i.e : 'chArray_One[]') Is : \n\n");
    printf("%s\n", chArray_One);

    printf("\n\n");
    printf("The Original Second String Entered By You (i.e : 'chArray_Two[]') Is : \n\n"); 
    printf("%s\n", chArray_Two);
    MyStrcat(chArray_One, chArray_Two);

    printf("\n\n"); 
    printf("****** AFTER CONCATENATION ******");
    printf("\n\n"); 
    printf("'chArray_One[]' Is : \n\n"); 
    printf("%s\n", chArray_One);
   
    printf("\n\n");
    printf("'chArray_Two[]' Is : \n\n"); 
    printf("%s\n", chArray_Two);

    getch();
    return(0);
}
