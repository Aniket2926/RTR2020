#include <stdio.h>

int main(void) 
{ 
    //function prototypes
    void PrintBinaryFormOfNumber(unsigned int);
 
    //variable declarations 
    unsigned int ga;
    unsigned int num_bits;
    unsigned int result;
 
    //code 
    printf("\n\n"); 
    printf("Enter An Integer = "); 
    scanf("%u", &ga);

    printf("\n\n"); printf("By How Many Bits Do You Want To Shift A = %d To The Right ? ", ga); scanf("%u", &num_bits);
    printf("\n\n\n\n"); result = ga >> num_bits; printf("Bitwise RIGHT-SHIFTing A = %d By %d Bits \nGives The Result = %d (Decimal).\n\n", ga, num_bits, result);
    
    PrintBinaryFormOfNumber(ga);
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
