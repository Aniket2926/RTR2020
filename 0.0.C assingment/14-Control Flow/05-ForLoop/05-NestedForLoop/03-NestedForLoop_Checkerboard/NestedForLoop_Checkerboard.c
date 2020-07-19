#include <stdio.h>
int main(void)
{ 
    //variable declarations
    int i, j, c;

    //code
    printf("\n\n"); for (i = 0; i < 64; i++) 
    { 
        for (j = 0; j < 64; j++) 
        {  
            c = ((i & 0x8) == 0) ^ ((j & 0x8) == 0);

            if (c == 0)    printf("  ");

            if (c == 1)    printf("* ");
  
        } 
        printf("\n\n");
    } 
    return(0); 

}

