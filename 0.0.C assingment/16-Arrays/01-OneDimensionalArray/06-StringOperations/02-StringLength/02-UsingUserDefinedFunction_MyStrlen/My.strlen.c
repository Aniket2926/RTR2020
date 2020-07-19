#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{ 
    //function prototype 
    int MyStrlen(char[]);
 
    //variable declarations  
    char chArray[MAX_STRING_LENGTH]; // A Character Array Is A String 
    int iStringLength = 0;
    //code
 
 
    // *** STRING INPUT ***
    printf("\n\n");

    printf("Enter A String : \n\n");

    gets_s(chArray, MAX_STRING_LENGTH);
 
    // *** STRING OUTPUT *** 
    printf("\n\n"); 
    printf("String Entered By You Is : \n\n");
    printf("%s\n", chArray);
 
    // *** STRING LENGTH ***

    printf("\n\n"); iStringLength = MyStrlen(chArray); 
    printf("Length Of String Is = %d Characters !!!\n\n", iStringLength);
    return(0);
}
int MyStrlen(char str[])
{ 
    //variable declarations 
    int j; 
    int string_length = 0;
 
    //code 
    // *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) ***
    for (j = 0; j < MAX_STRING_LENGTH; j++) 
    { 
        if (str[j] == '\0')  
            break;
        
        else  
            string_length++;
    }
    return(string_length);
}