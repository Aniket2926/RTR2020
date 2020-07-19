#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void) 
{
    //variable declarations 

    int akArray[NUM_ELEMENTS];  //int iarray changed to int akArray
    int i, num, sum = 0;

 
    //code
    printf("\n\n");

    printf("Enter Integer Elememts For Array : \n\n"); 
    for (i = 0; i < NUM_ELEMENTS; i++)
    {  
        scanf("%d", &num);  
        akArray[i] = num; 
    }
    for (i = 0; i < NUM_ELEMENTS; i++)
    { 
        sum = sum + akArray[i]; 
    }
    printf("\n\n"); 

    printf("Sum Of ALL Elements Of Array = %d\n\n", sum);

    getch();

    return(0);
}