#include <stdio.h>

// MACRO CONSTANT USED AS ARRAY SIZE IN SUBSCRIPT AND AS ARRAY LENGTH. 
// HENCE, THIS PROGRAM'S ARRAYS' SIZES CAN BE SIMPLY CHANGED BY CHANGING THESE FOLLOWING 3 GLOBAL MACRO CONSTANT VALUES, 
//BEFORE COMPILING, LINKING AND EXECUTING THE PROGRAM !!!

#define INT_ARRAY_NUM_ELEMENTS 5
#define FLOAT_ARRAY_NUM_ELEMENTS 3 
#define CHAR_ARRAY_NUM_ELEMENTS 15

int main(void)
{
    //variable declarations  

    int iArray[INT_ARRAY_NUM_ELEMENTS];
    float fArray[FLOAT_ARRAY_NUM_ELEMENTS];
    char cArray[CHAR_ARRAY_NUM_ELEMENTS];
    int a, k;    // int i and num are a and k

 //code

 // ********** ARRAY ELEMENTS INPUT ********** 
    printf("\n\n");
    printf("Enter Elements For 'Integer' Array : \n");
    for (a = 0; a < INT_ARRAY_NUM_ELEMENTS; a++)
        scanf("%d", &iArray[a]);

    printf("\n\n");
    printf("Enter Elements For 'Floating-Point' Array : \n");
    for (a = 0; a < FLOAT_ARRAY_NUM_ELEMENTS; a++)
        scanf("%f", &fArray[a]);

    printf("\n\n");
    printf("Enter Elements For 'Character' Array : \n");
    for (a = 0; a < CHAR_ARRAY_NUM_ELEMENTS; a++)
    {
        cArray[a] = getch();
        printf("%c\n", cArray[a]);
    }

    // ********** ARRAY ELEMENTS OUTPUT ********** 

    printf("\n\n"); printf("Integer Array Entered By You : \n\n");
    for (a = 0; a < INT_ARRAY_NUM_ELEMENTS; a++)
        printf("%d\n", iArray[a]);

    printf("\n\n");
    printf("Floating-Point Array Entered By You : \n\n");
    for (a = 0; a < FLOAT_ARRAY_NUM_ELEMENTS; a++)
        printf("%f\n", fArray[a]);

    printf("\n\n");

    printf("Character Array Entered By You : \n\n");
    for (a = 0; a < CHAR_ARRAY_NUM_ELEMENTS; a++)
        printf("%c\n", cArray[a]);

       getch();

    return(0);
    
}