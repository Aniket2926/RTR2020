#include <stdio.h>
#define MAX_STRING_LENGTH 512

int main(void)
{ 
    //function prototype 
    void MyStrcpy(char[], char[]);

    //variable declarations  
    char chArray_Original[MAX_STRING_LENGTH], chArray_Copy[MAX_STRING_LENGTH]; // A Character Array Is A String
 

    //code
 
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String : \n\n"); 
    gets_s(chArray_Original, MAX_STRING_LENGTH);

 
    // *** STRING COPY *** 
    MyStrcpy(chArray_Copy, chArray_Original);

 
    // *** STRING OUTPUT ***
    printf("\n\n"); 
    printf("The Original String Entered By You (i.e : 'chArray_Original[]') Is : \n\n");
    printf("%s\n", chArray_Original);

    printf("\n\n"); 
    printf("The Copied String (i.e : 'chArray_Copy[]') Is : \n\n"); 
    printf("%s\n", chArray_Copy);
    return(0);
}
void MyStrcpy(char str_destination[], char str_source[])
{ 
    //function prototype
    int MyStrlen(char[]);
 
    //variable declarations  
    int iStringLength = 0; int j;
 
    //code
    iStringLength = MyStrlen(str_source);
    for (j = 0; j < iStringLength; j++)  str_destination[j] = str_source[j];
    str_destination[j] = '\0';

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
            string_length++; } 
    return(string_length);
}

