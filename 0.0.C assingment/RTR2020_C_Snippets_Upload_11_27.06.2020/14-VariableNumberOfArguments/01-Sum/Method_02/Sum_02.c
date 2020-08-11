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
   
    getch();
    return(0);

}

int CalculateSum(int num, ...) // VARIADIC FUNCTION
{   
    // function prototype 
    
    int va_CalculateSum(int, va_list);      
    
    // variable declarations   
    
    int sum = 0;    va_list numbers_list;     
    
    // code 
    
    va_start(numbers_list, num);      
    
    sum = va_CalculateSum(num, numbers_list);   
    
    va_end(numbers_list);   
    
    return(sum);

}

int va_CalculateSum(int num, va_list list)

{    
    // variable declaration 
    
    int n;   
    
    int sum_total = 0;
    
    // code    while(num)
      
    {       
        n = va_arg(list, int);   
        
        sum_total = sum_total + n;  
        num--;  
    }  

    return(sum_total);
}


