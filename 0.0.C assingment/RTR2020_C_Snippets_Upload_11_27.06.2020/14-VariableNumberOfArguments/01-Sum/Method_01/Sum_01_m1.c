#include <stdio.h>
#include <stdarg.h>

int main(void)
{   
    // function prototypes

    int CalculateSum(int, ...);
    
    // variable declarations   
    
    int answer;      
    
    // code   
     
     printf("\n\n");
     
     answer = CalculateSum(5, 10, 20, 30, 40, 50);   
     
     printf("Answer = %d\n\n", answer);      
     
     answer = CalculateSum(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1); 
     
     printf("Answer = %d\n\n", answer);

    answer = CalculateSum(0);   
    
    printf("Answer = %d\n\n", answer);
    
    
    return(0);
}

int CalculateSum(int num, ...) // VARIADIC FUNCTION
{   
    // variable declarations  
    
    int sum_total = 0;  
   
    int ak;       
    
    va_list numbers_list;    

    // code  
    
    va_start(numbers_list, num);    

    while(num)    
    {       
        ak = va_arg(numbers_list, int);  
        
        sum_total = sum_total + ak;       
        num--;   
    }       
    
    va_end(numbers_list);  
    

    getch();
    return(sum_total);

}

