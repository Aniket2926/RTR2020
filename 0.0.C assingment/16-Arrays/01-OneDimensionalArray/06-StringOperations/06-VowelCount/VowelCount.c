#include <stdio.h>
#define MAX_STRING_LENGTH 512

int main(void)
{ 
    //function prototype
    int MyStrlen(char[]);

 
    //variable declarations
    char mychArray[MAX_STRING_LENGTH];  // A Character Array Is A String 

    int iStringLength; 
    int count_A = 0, count_E = 0, count_I = 0, count_O = 0, count_U = 0;
    
    // Initial Counts = 0 
    int i;
   
    //code
 
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String : \n\n");
    gets_s(mychArray, MAX_STRING_LENGTH);

 
    // *** STRING OUTPUT *** 
    printf("\n\n");
    printf("String Entered By You Is : \n\n");
    printf("%s\n", mychArray);

    iStringLength = MyStrlen(mychArray);
    for (i = 0; i < iStringLength; i++)
    {
        switch (mychArray[i])
        {
        case 'A': 
        case 'a':   
            count_A++; 
       
            break; 
        case 'E':  
        case 'e':
            count_E++;  
            break;  
        case 'I':  
        case 'i':   
            count_I++;   
            break; 
        case 'O': 
        case 'o':   
        
            count_O++;   
        
            break;  
        case 'U':  
        case 'u':
            count_U++;
            break; 
        default:   
            break;
        }
    }
    printf("\n\n");

    printf("In The String Entered By You, The Vowels And The Number Of Their Occurences Are Are Follows : \n\n"); 
    printf("'A' Has Occured = %d Times !!!\n\n", count_A);
    printf("'E' Has Occured = %d Times !!!\n\n", count_E);
    printf("'I' Has Occured = %d Times !!!\n\n", count_I);
    printf("'O' Has Occured = %d Times !!!\n\n", count_O);
    printf("'U' Has Occured = %d Times !!!\n\n", count_U);


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
