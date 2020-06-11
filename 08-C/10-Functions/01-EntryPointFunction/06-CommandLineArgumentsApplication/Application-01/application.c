#include <stdio.h> //'stdio.h' contains declaration of 'printf()' 
#include <ctype.h> //'ctype.h' contains declaration of 'atoi()' 
#include <stdlib.h> // 'stdlib.h' contains declaration of 'exit()'

int main(int argc, char* argv[], char* envp[]) 
{ 
    //variable declarations 
    int i; int num; int sum = 0;
 
    //code    
    if(argc == 1)    
    {       
        printf("\n\n");      
        printf("No Numbers Given For Addition !!! Exitting now ...\n\n");      
        printf("Usage : CommandLineArgumentsApplication <first number> <second number> ...\n\n");        
        exit(0);  
    }    
    // *** THIS PROGRAMS ADDS ALL COMMAND LINE ARGUMENTS GIVEN IN INTEGER FORM ONLY AND OUTPUTS THE SUM *** // *** DUE TO USE OF atoi(), ALL COMMAND LINE ARGUMENTS OF TYPES OTHER THAN 'int' ARE IGNORED *** 
    printf("\n\n"); printf("Sum Of All Integer Command Line Arguments Is : \n\n"); for (i = 1; i < argc; i++) //loop starts from i = 1 because, i = 0 will result in 'argv[i]' = 'argv[0]' which is the name of the program itself i.e : 'CommandLineArgumentsApplication.exe' 
    {  
        num = atoi(argv[i]);  sum = sum + num; 
    }
    
    printf("Sum = %d\n\n", sum);
   
    return(0);
}