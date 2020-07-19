#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    //variable declarations 

    int akArray[NUM_ELEMENTS];    //int iArray chnage to akArray
    int i, num, sum = 0;

    //code 

    printf("\n\n");

    // *** ARRAY ELEMENTS INPUT *** 

    printf("Enter Integer Elememts For Array : \n\n");
    for (i = 0; i < NUM_ELEMENTS; i++)
    {
        scanf("%d", &num);  akArray[i] = num;
    }


    // *** SEPARATING OUT EVEN NUMBERS FROM ARRAY ELEMENTS *** 

    printf("\n\n");
    printf("Even Numbers Amongst The Array Elements Are : \n\n");
    for (i = 0; i < NUM_ELEMENTS; i++)
    {
        if ((akArray[i] % 2) == 0)
            printf("%d\n", akArray[i]);
    }

    // *** SEPARATING OUT ODD NUMBERS FROM ARRAY ELEMENTS ***

    printf("\n\n");
    printf("Odd Numbers Amongst The Array Elements Are : \n\n");
    for (i = 0; i < NUM_ELEMENTS; i++)
    {
        if ((akArray[i] % 2) != 0)
            printf("%d\n", akArray[i]);
    }


    getch();


        
    return(0);

}