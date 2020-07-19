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

 
    //Here, the string array can allow a maximum number of 10 strings (10 rows) and each of these 10 strings can have only upto 15 characters maximum (15 columns) 
    char strArray[10][15] = { "My", "Name", "is", "Aniket", "from", "Rendering", "Batch", "(2020-21)", "Of", "ASTROMEDICOMP." };
    
    //IN-LINE INITIALIZATION

    int char_size;
    int strArray_size;
    int strArray_num_elements, strArray_num_rows, strArray_num_columns;
    int strActual_num_chars = 0; 
    int i;
 
    //code printf("\n\n");

    char_size = sizeof(char);
    strArray_size = sizeof(strArray);
    printf("Size Of Two Dimensional ( 2D ) Character Array (String Array) Is = %d \n\n", strArray_size);
    strArray_num_rows = strArray_size / sizeof(strArray[0]);
    
    printf("Number of Rows (Strings) In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_num_rows);
    strArray_num_columns = sizeof(strArray[0]) / char_size;
   
    printf("Number of Columns In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_num_columns);
    strArray_num_elements = strArray_num_rows * strArray_num_columns;
   
    printf("Maximum Number of Elements (Characters) In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_num_elements);
    for (i = 0; i < strArray_num_rows; i++)
    { 
        strActual_num_chars = strActual_num_chars + MyStrlen(strArray[i]);
    } 
    printf("Actual Number of Elements (Characters) In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strActual_num_chars);
   
    printf("\n\n"); 
    printf("Strings In The 2D Array : \n\n");

    //Since, char[][] is an array of strings, referencing only by the row number (first []) will give the row or the string //The Column Number (second []) is the particular character in that string / row
    
    printf("%s ", strArray[0]);
    printf("%s ", strArray[1]);
    printf("%s ", strArray[2]); 
    printf("%s ", strArray[3]); 
    printf("%s ", strArray[4]); 
    printf("%s ", strArray[5]);
    printf("%s ", strArray[6]);
    printf("%s ", strArray[7]); 
    printf("%s ", strArray[8]); 
    printf("%s\n\n", strArray[9]);
    return(0);
}

int MyStrlen(char str[])
{ 
    //variable declarations

    int j; int string_length = 0;
 
    //code // *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) *** 
    for (j = 0; j < MAX_STRING_LENGTH; j++)
    {  
        if (str[j] == '\0')
            break; 
        else  
            string_length++;
    }

    getch(string_length);

    return(string_length);
}
