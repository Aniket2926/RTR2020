#include <stdio.h> 
int main(void)
{ 
    //variable declarations 
    int i, j, c;

    //code 
    printf("\n\n");

    i = 0;
    do
    {
    
        j = 0; 
    
        do
    
        {
        
            c = ((i & 0x8) == 0) ^ ((j & 0x8) == 0);
        
            if (c == 0)  
                printf("  ");
        
       
            if (c == 1)    
                printf("* ");
        
            j++;
    
        } 
        while (j < 64);  
        printf("\n\n");  i++;

    } 
    while (i < 64); 
    return(0);
}
