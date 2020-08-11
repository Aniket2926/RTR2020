#include <stdio.h> 
#include <conio.h>

struct MyData 
{ 
    int i;
    float f;
    double d; 
    char ch;
};


int main(void) 
{
    //variable declarations
    struct MyData Mydata;  //declaring a single struct variable
 
    //code 
    //User Input For Values Of Data Members Of 'struct MyData'
    printf("\n\n");

    printf("Enter Integer Value For Data Member 'i' Of 'struct MyData' : \n");
    scanf("%d", &Mydata.i);
   
  
    printf("Enter Floating-Point Value For Data Member 'f' Of 'struct MyData' : \n"); 
    scanf("%f", &Mydata.f);


    printf("Enter 'Double' Value For Data Member 'd' Of 'struct MyData' : \n");
    scanf("%lf", &Mydata.d);


    printf("Enter Character Value For Data Member 'c' Of 'struct MyData' : \n"); 
    Mydata.ch = getch();
    
    //Display Values Of Data Members Of 'struct MyData' 
    
    printf("\n\n");

    printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n"); 
    printf("i = %d\n", Mydata.i);
    printf("f = %f\n", Mydata.f);
    printf("d = %lf\n", Mydata.d); 
    printf("c = %c\n\n", Mydata.ch);
    
   
    return(0);
}

