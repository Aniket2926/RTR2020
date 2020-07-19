#include <stdio.h>

#define MAX_STRING_LENGTH 512


int main(void) 
{ 
    //function prototype
    int MyStrlen(char[]);
    void MyStrcpy(char[], char[]);
    
    //variable declarations
    char MychArray[MAX_STRING_LENGTH], chArray_SpacesRemoved[MAX_STRING_LENGTH]; // A Character Array Is A String 
    int MyiStringLength; 
    int i, j;
 
    //code

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String : \n\n"); 
    gets_s(MychArray, MAX_STRING_LENGTH);

    MyiStringLength = MyStrlen(MychArray); j = 0;
    for (i = 0; i < MyiStringLength; i++) 
    { 
        if (MychArray[i] == ' ') 
            continue; 
    
        else 
        { 
            chArray_SpacesRemoved[j] = MychArray[i];   j++;
        } 
    }
    chArray_SpacesRemoved[j] = '\0';

    // *** STRING OUTPUT *** 
    printf("\n\n");
    printf("String Entered By You Is : \n\n");
    printf("%s\n", MychArray);
    printf("\n\n");
    printf("String After Removal Of Spaces Is : \n\n");
    printf("%s\n", chArray_SpacesRemoved);

    getch();
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
        else   string_length++; 
    } 
    return(string_length); 
}
