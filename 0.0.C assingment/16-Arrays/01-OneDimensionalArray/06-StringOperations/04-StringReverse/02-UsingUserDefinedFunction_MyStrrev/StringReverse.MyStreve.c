#include <stdio.h>
#define MAX_STRING_LENGTH 512

int main(void) 
{ 
    //function prototype
   
    void  MyStrrev(char[], char[]);

 
    //variable declarations 
    char mychArray_Original[MAX_STRING_LENGTH], 
        mychArray_Reversed [MAX_STRING_LENGTH]; // A Character Array Is A String
 
    //code
 
    // *** STRING INPUT *** 
    printf("\n\n");
    printf("Enter A String : \n\n");
    gets_s(mychArray_Original, MAX_STRING_LENGTH);

 
    // *** STRING REVERSE ***
    MyStrrev(mychArray_Reversed, mychArray_Original);

 
    // *** STRING OUTPUT *** 
    printf("\n\n");
    printf("The Original String Entered By You (i.e : 'mychArray_Original[]') Is : \n\n"); 
    printf("%s\n", mychArray_Original);

    printf("\n\n"); 
    printf("The Reversed String (i.e : 'mychArray_Reversed[]') Is : \n\n"); 
    printf("%s\n", mychArray_Reversed);
    return(0);
}
void MyStrrev(char str_destination[], char str_source[])
{
    //function prototype 
    int MyStrlen(char[]);
 
    //variable declarations 
    int iStringLength = 0; int i, j, len;
 
    //code 
    iStringLength = MyStrlen(str_source);
 
    // ARRAY INDICES BEGIN FROM 0, HENCE, LAST INDEX WILL ALWAYS BE (LENGTH - 1) 
    len = iStringLength - 1;
 
    // WE NEED TO PUT THE CHARACTER WHICH IS AT LAST INDEX OF 'str_source' TO THE FIRST INDEX OF 'str_destination'
    // AND SECOND-LAST CHARACTER OF 'str_source' TO THE SECOND CHARACTER OF 'str_destination' and so on...
    for (i = 0, j = len; i < iStringLength, j >= 0; i++, j--)
    { 
        str_destination[i] = str_source[j];
    }
    str_destination[i] = '\0';
}
int MyStrlen(char str[]) 
{
    //variable declarations 
    int j; int string_length = 0;

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