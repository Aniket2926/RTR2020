#include <stdio.h> //'stdio.h' contains declaration of 'printf()'

// Entry-Point Function => main() => Valid Return Type (int) and 3 Parameters (int argc, char *argv[], char *envp[]) 
int main(int argc, char *argv[], char *envp[]) 
{
    //function prototype / declaration / signature 
    void MyAddition(int, int);
 
    //variable declarations : local variables to main()
    int a, b;
 
    //code 
    printf("\n\n"); 
    printf("Enter Integer Value For 'A' : ");
    scanf("%d", &a);

    printf("\n\n"); 
    printf("Enter Integer Value For 'B' : "); scanf("%d", &b);

    MyAddition(a, b); //function call

    return(0);
}
// ****** USER DEFINED FUNCTION : METHOD OF DEFINITION 3 ****** 
// ****** NO RETURN VALUE, VALID PARAMETERS (int, int) ******

void MyAddition(int a, int b) //function definition
{ 
    //variable declarations : local variables to MyAddition() 
    int sum;
 
    //code 
    sum = a + b; 
    printf("\n\n");
    printf("Sum Of %d And %d = %d\n\n", a, b, sum);
}