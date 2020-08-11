#include <stdio.h>

int main(void)
{ 
    //DEFINING STRUCT
    
    struct MyData
    
    {  
        int i; 
        float f;  
        double d; 
        char c;
    } Mydata = { 5, 9.1f, 3.78623, 'N' };

 
    //Displaying Values Of The Data Members Of 'struct MyData' 

    printf("\n\n");

    printf("DATA MEMBERS OF 'struct MyData' ARE: \n\n"); 

    printf("i = %d\n", Mydata.i); 

    printf("f = %f\n", Mydata.f);

    printf("d = %lf\n", Mydata.d); 

    printf("c = %c\n\n", Mydata.c); 

    getch();
    return(0);

}
