#include <stdio.h>
int main(void) 
{ 
    //variable declarations
    int i, j, c;

    //code 
    printf("\n\n");

    i = 0; 
    while (i < 64) 
    {
    j = 0; 
    while (j < 64)
    {
        c = ((i & 0x8) == 0) ^ ((j & 0x8) == 0);
        if (c == 0)  
            printf("  ");
        if (c == 1)    
            printf("* ");
        
        j++;
    }  
    printf("\n\n");i++;
    } 
    
    return(0);
}
