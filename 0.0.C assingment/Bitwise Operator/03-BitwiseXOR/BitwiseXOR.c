#include <stdio.h>

int main(void)
{
    //function prototypes
    void PrintBinaryFormOfNumber(unsigned int);
    
    //variable declarations
    unsigned int x; 
    unsigned int y;
    unsigned int result;
    
    //code 
    printf("\n\n"); 
    printf("Enter An Integer = ");
    scanf("%u", &x);
    
    printf("\n\n");
    printf("Enter Another Integer = ");
    scanf("%u", &y);
   
    printf("\n\n\n\n"); 
    result = x ^ y;    
    printf("Bitwise XOR-ing Of \nX = %d (Decimal) and Y = %d (Decimal) gives result %d (Decimal).\n\n", x, y, result);
    PrintBinaryFormOfNumber(x); PrintBinaryFormOfNumber(y); PrintBinaryFormOfNumber(result);

    getch();

    return(0);
}

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{ 
    //variable declarations
    unsigned int quotient,remainder;
    unsigned int num; 
    unsigned int binary_array[8];
    int i;
    
    //code 
    for (i = 0; i < 8; i++)
        
        binary_array[i] = 0;

    printf("The Binary Form Of The Decimal Integer %d Is\t=\t", decimal_number);
    num = decimal_number; 
    i = 7;
    while (num != 0)
    {
        quotient = num / 2; 
        remainder = num % 2;  
        binary_array[i] = remainder;
        num = quotient; 
        i--;
    }
    for (i = 0; i < 8; i++) 
        printf("%u", binary_array[i]);
    printf("\n\n");
}
