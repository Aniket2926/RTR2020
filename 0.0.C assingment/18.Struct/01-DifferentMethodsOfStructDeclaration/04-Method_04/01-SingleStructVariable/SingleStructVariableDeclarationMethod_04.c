#include <stdio.h>

// DEFINING STRUCT

struct MyData
{ int i;
float f; 
double d;
};


int main(void) 
{ 
    //variable declarations 
    struct MyData Mydata;  //declaring a single struct variable of type 'struct MyData' locally... 
    
    int i_size;
    int f_size; 
    int d_size; 
    int struct_MyData_size;
 
    //code 
    //Assigning Data Values To The Data Members Of 'struct MyData'
    Mydata.i = 30; 
    Mydata.f = 11.45f; 
    Mydata.d = 1.2995;

 
    //Displaying Values Of The Data Members Of 'struct MyData'

    printf("\n\n"); 

    printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");

    printf("i = %d\n", Mydata.i);

    printf("f = %f\n", Mydata.f); 

    printf("d = %lf\n", Mydata.d);

 //Calculating Sizes (In Bytes) Of The Data Members Of 'struct MyData'
    i_size = sizeof(Mydata.i); 

    f_size = sizeof(Mydata.f); 

    d_size = sizeof(Mydata.d);
 
    //Displaying Sizes (In Bytes) Of The Data Members Of 'struct MyData' 
    printf("\n\n");

    printf("SIZES (in bytes) OF DATA MEMBERS OF 'struct MyData' ARE : \n\n");

    printf("Size of 'i' = %d bytes\n", i_size);

    printf("Size of 'f' = %d bytes\n", f_size);

    printf("Size of 'd' = %d bytes\n", d_size);

 
    //Calculating Size (In Bytes) Of the entire 'struct Mydata'

    struct_MyData_size = sizeof(struct MyData); //can also give struct name -> sizeof(MyData)

   //Displaying Sizes (In Bytes) Of the entire 'struct Mydata'

    printf("\n\n");
    printf("Size of 'struct MyData' : %d bytes\n\n", struct_MyData_size);
    
    getch();
    return(0);
}

