#include <stdio.h>

int main(void)
{
	//code
    printf("\n\n");
    
    printf("Size of 'int'          = %ld bytes\n", sizeof(int));
    printf("Size of 'unsigned int' = %ld bytes\n", sizeof(unsigned int));
    printf("Size of 'long'         = %ld bytes\n", sizeof(long));
    printf("Size of 'long long'    = %ld bytes\n", sizeof(long long));

    printf("Size of 'float'        = %ld bytes\n", sizeof(float));
    printf("Size of 'double'       = %ld bytes\n", sizeof(double));
    printf("Size of 'long double'  = %ld bytes\n", sizeof(long double));

    printf("\n\n");

    getch();

    return(0);
}






