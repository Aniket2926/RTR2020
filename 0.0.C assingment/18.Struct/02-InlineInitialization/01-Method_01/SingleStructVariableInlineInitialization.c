#include <stdio.h>

// DEFINING STRUCT
struct MyData
{ 
    int iValue; 

    float fValue;

    double dValue; 

    char cValue; 
} 
data = { 30, 4.5f, 11.451995, 'A' }; //Inline initialization of struct variable 'data' of type 'struct MyData' 

int main(void)
{ 
    //code
    //Displaying Values Of The Data Members Of 'struct MyData'
    printf("\n\n"); 
  
    printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
  
    printf("iValue = %d\n", data.iValue);
    printf("fValude = %f\n", data.fValue);
    printf("dValue = %lf\n", data.dValue); 
    printf("cValue = %c\n\n", data.cValue);

    getch();
    return(0);
}
