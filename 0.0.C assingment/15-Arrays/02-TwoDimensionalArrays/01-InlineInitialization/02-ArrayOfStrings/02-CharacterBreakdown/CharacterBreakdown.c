#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void) 

{ 
    //function prototype 

    int MyStrlen(char[]);

    //variable declaraions
 
    // *** A 'STRING' IS AN ARRAY OF CHARACTERS ... so char[] IS A char ARRAY AND HENCE, char[] IS A 'STRING' *** 

    // *** AN ARRAY OF char ARRAYS IS AN ARRAY OF STRINGS !!! *** 
    // *** HENCE, char[] IS ONE char ARRAY AND HENCE, IS ONE STRING *** 
    // *** HENCE, char[][] IS AN ARRAY OF char ARRAYS AND HENCE, IS AN ARRAY OF STRINGS ***

    //Here, the string array can allow a maximum number of 10 strings (10 rows) and each of these
    //10 strings can have only upto 15 characters maximum (15 columns)

     char strArray[10][15] = { "Hello!", "Aniket", "Welcome", "To", "Best", "Rendering", "Batch", "(2020-21)", "Of", "ASTROMEDICOMP." }; 

    
   
   //IN-LINE INITIALIZATION 

    int iStrLengths[10];   //1D Integer Array - Stores lengths of those strings at corressponding indices in 'strArray[]' e.g: iStrLengths[0] will be the length of string at strArray[0], iStrLengths[1] will be the length of string at strArray[1]...10 strings, 10 lengths... 
    int strArray_size; int strArray_num_rows; int i, j;
 
        //code 

    strArray_size = sizeof(strArray); strArray_num_rows = strArray_size / sizeof(strArray[0]);

    //Storing in lengths of all the strings...

    for (i = 0; i < strArray_num_rows; i++) 
        iStrLengths[i] = MyStrlen(strArray[i]);
   
    printf("\n\n"); 
    printf("The Entire String Array : \n\n"); 
    for (i = 0; i < strArray_num_rows; i++)
        printf("%s ", strArray[i]);
   
    printf("\n\n");
    printf("Strings In The 2D Array : \n\n");

    //Since, char[][] is an array of strings, referencing only by the row number (first []) will give the row or the string
    //The Column Number (second []) is the particular character in that string / row

        for (i = 0; i < strArray_num_rows; i++)
        {
            printf("String Number %d => %s\n\n", (i + 1), strArray[i]);  
            for (j = 0; j < iStrLengths[i]; j++)
            { 
                printf("Character %d = %c\n", (j + 1), strArray[i][j]); 
            } 
            printf("\n\n"); 
        } 
        return(0);
}

int MyStrlen(char str[]

) {
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

