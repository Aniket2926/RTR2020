#include <stdio.h> 
int main(void) 
{ 
    //variable declarations 
    int num;

    //code 
    printf("\n\n");

    printf("Enter Value For 'num' : ");
    scanf("%d", &num);

    // IF - ELSE - IF LADDER BEGINS FROM HERE... 
    if (num < 0)  
        printf("Num = %d Is Less Than 0 (NEGATIVE) !!!\n\n", num);
 
    else if ((num > 0) && (num <= 100))  
        printf("Num = %d Is Between 0 And 100 !!!\n\n", num);
 
    else if ((num > 100) && (num <= 200))  
        printf("Num = %d Is Between 100 And 200 !!!\n\n", num);
 
    else if ((num > 200) && (num <= 300))  
        printf("Num = %d Is Between 200 And 300 !!!\n\n", num);
 
    else if ((num > 300) && (num <= 400)) 
        printf("Num = %d Is Between 300 And 400 !!!\n\n", num);
 
    else if ((num > 400) && (num <= 500)) 
        printf("Num = %d Is Between 400 And 500 !!!\n\n", num);
 
    else if (num > 500) 
        printf("Num = %d Is Greater Than 500 !!!\n\n", num);
 
    else // *** THIS IS THE TERMINATING 'ELSE' OF THIS 'IF - ELSE IF - ELSE' LADDER !!! *** 

        printf("Invalid Value Entered !!!\n\n");

    getch();

 return(0);
}

