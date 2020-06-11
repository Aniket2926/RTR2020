#include <stdio.h>

int main(void) 

{
    //variable declarations 
    int i, j;



    //code 
    printf("\n\n"); for (i = 1; i <= 10; i++) 
    {  
        printf("i = %d\n", i);
        printf("--------\n\n");  for (j = 1; j <= 5; j++)  
        {  
            printf("\tj = %d\n", j);  
        }  printf("\n\n");
    }

    return(0); 

}
