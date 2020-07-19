#include <stdio.h>
int main(void)
{ 
    //variable declarations
    char option, ch = '\0';


    //code 
    printf("\n\n"); 
    printf("Once The Infinite Loop Begins, Enter 'Q' or 'q' To Quit The Infinite For Loop : \n\n"); 
    printf("Enter 'Y' oy 'y' To Initiate User Controlled Infinite Loop : "); 
    printf("\n\n"); option = getch(); if (option == 'Y' || option == 'y') 
    { 
        while (1) //Infinite Loop
        {  
            printf("In Loop...\n");   ch = getch(); 
            if (ch == 'Q' || ch == 'q')    
                break; //User Controlled Exitting From Infinite Loop
        }

        printf("\n\n");
        printf("EXITTING USER CONTROLLED INFINITE LOOP...");
        printf("\n\n");
    }
 
    else  
        printf("You Must Press 'Y' or 'y' To Initiate The User Controlled Infinite Loop....Please Try Again...\n\n");


    return(0); 
}
