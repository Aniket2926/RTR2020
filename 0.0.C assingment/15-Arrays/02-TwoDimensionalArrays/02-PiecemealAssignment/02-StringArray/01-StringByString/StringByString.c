#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void) 
{ 
    //function prototype 
    void MyStrcpy(char[], char[]);

 
    //variable declaraions
 
    // *** A 'STRING' IS AN ARRAY OF CHARACTERS ... so char[] IS A char ARRAY AND HENCE, char[] IS A 'STRING' ***
    // *** AN ARRAY OF char ARRAYS IS AN ARRAY OF STRINGS !!! *** 
    // *** HENCE, char[] IS ONE char ARRAY AND HENCE, IS ONE STRING *** 
    // *** HENCE, char[][] IS AN ARRAY OF char ARRAYS AND HENCE, IS AN ARRAY OF STRINGS ***
 
    //Here, the string array can allow a maximum number of 5 strings (5 rows) and each of these 5 strings can have only upto 10 characters maximum (10 columns)
    
    char strArray[5][10]; // 5 ROWS (0, 1, 2, 3, 4) -> 5 STRINGS (EACH STRING CAN HAVE A MAXIMUM OF 10 CHARACTERS)
   
    int char_size; 
    int strArray_size;
    int strArray_num_elements, strArray_num_rows, strArray_num_columns;
    int i;
 
    //code 
    printf("\n\n");
    char_size = sizeof(char);
    strArray_size = sizeof(strArray);
   
    printf("Size Of Two Dimensional ( 2D ) Character Array (String Array) Is = %d \n\n", strArray_size);
    strArray_num_rows = strArray_size / sizeof(strArray[0]);
   
    printf("Number of Rows (Strings) In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_num_rows);
    strArray_num_columns = sizeof(strArray[0]) / char_size;
   
    printf("Number of Columns In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_num_columns);
    strArray_num_elements = strArray_num_rows * strArray_num_columns; 
    
    printf("Maximum Number of Elements (Characters) In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_num_elements);
    // *** PIECE-MEAL ASSIGNMENT ***

    MyStrcpy(strArray[0], "My");

    MyStrcpy(strArray[1], "Name");

    MyStrcpy(strArray[2], "Is"); 
   
    MyStrcpy(strArray[3], "Aniket");

    MyStrcpy(strArray[4], "Kadam");
    
    printf("\n\n"); 

    printf("The Strings In the 2D Character Array Are : \n\n");

    for (i = 0; i < strArray_num_rows; i++)  printf("%s ", strArray[i]);

    printf("\n\n");

    return(0);
}

void MyStrcpy(char str_destination[], char str_source[]) 
{ 
    //function prototype
    int MyStrlen(char[]);

 
    //variable declarations  
    int iStringLength = 0;
    int j;


 //code 
    iStringLength = MyStrlen(str_source); 
    for (j = 0; j < iStringLength; j++)  
        str_destination[j] = str_source[j];
   
    str_destination[j] = '\0';
}
int MyStrlen(char str[])
{ 
    //variable declarations 
    int j; int string_length = 0;

 //code 
 // *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) *** 
    for (j = 0; j < MAX_STRING_LENGTH; j++) 
    {  
        if (str[j] == '\0')   break;
    
        else 
        string_length++; 
    }
    return(string_length);
}

