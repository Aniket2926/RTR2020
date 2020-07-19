#include <stdio.h> //'stdio.h' contains declaration of 'printf()'

// Entry-Point Function => main() => Valid Return Type (int) and 2 Parameters (int argc, char *argv[]) 
int main(int argc, char *argv[]) 
{ 
    //variable declarations 
    int i;
 
    //code 
    printf("\n\n");
    printf("Hello World !!!\n\n"); //Library function 
    printf("Number Of Command Line Arguments = %d\n\n", argc);


    printf("Command Line Arguments Passed To This Program Are : \n\n"); for (i = 0; i < argc; i++) 
    {
        printf("Command Line Argument Number %d = %s\n", (i + 1), argv[i]);
    }
    printf("\n\n"); 
    return(0);
}