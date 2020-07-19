#include <stdio.h>
#define MAX_STRING_LENGTH 512

int main(void)
{ 
    //variable declarations  
    char mychArray_Original[MAX_STRING_LENGTH], mychArray_Copy[MAX_STRING_LENGTH];  // A Character Array Is A String
 
    //code
 
    // *** STRING INPUT *** 
    printf("\n\n");
    printf("Enter A String : \n\n");
    gets_s(mychArray_Original, MAX_STRING_LENGTH);
 
    // *** STRING COPY *** 
    strcpy(mychArray_Copy, mychArray_Original);
 
    // *** STRING OUTPUT *** 
    printf("\n\n"); 
    printf("The Original String Entered By You (i.e : 'mychArray_Original[]') Is : \n\n"); 
    printf("%s\n", mychArray_Original);

    printf("\n\n");
    printf("The Copied String (i.e : 'mychArray_Copy[]') Is : \n\n");
    printf("%s\n", mychArray_Copy);

    getch();

    return(0);
}
