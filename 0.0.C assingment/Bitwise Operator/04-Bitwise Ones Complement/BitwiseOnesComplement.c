#include <stdio.h>

int main(void)
{ 
    //function prototypes 
    void PrintBinaryFormOfNumber(unsigned int);

    //variable declarations
    unsigned int dota; 
    unsigned int result;

    //code
    printf("\n\n"); 
    printf("Enter An Integer = ");
    scanf("%u", &dota);
   
    printf("\n\n\n\n");
    result = ~dota;   
    printf("Bitwise COMPLEMENTING Of \ndota = %d (Decimal) gives result %d (Decimal). \n\n", dota, result);
   
    PrintBinaryFormOfNumber(dota);
    PrintBinaryFormOfNumber(result);

    getch();


    return(0);

}
void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
    //variable declarations
    unsigned int quotient, remainder;
    unsigned int num;
    unsigned int binary_array[8];
    int i;
 
    //code
    for (i = 0; i < 8; i++)  binary_array[i] = 0;
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
