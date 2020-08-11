#include <stdio.h>

//DEFINING STRUCT 

struct MyPoint 
{ 
    int a;

    int k; 
};

int main(void)
{ 
    //variable declarations
    struct MyPoint 

        point_A, point_B, point_C, point_D, point_E; //declaring 5 struct variables of type 'struct MyPoint' locally...
 
    //code
    //Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_A' 
    point_A.a = 3;
    point_A.k = 0;
 
    //Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_B'
    point_B.a = 1; 
    point_B.k = 2;
 
    //Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_C'
    point_C.a = 9;
    point_C.k = 6;
 
    //Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_D'
    point_D.a = 8; 
    point_D.k = 2;
 
    //Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_E' 
    point_E.a = 11;
    point_E.k = 8;
 
    //Displaying Values Of The Data Members Of 'struct MyPoint' (all variables)

    printf("\n\n");
    printf("Co-ordinates (a, k) Of Point 'A' Are : (%d, %d)\n\n", point_A.a, point_A.k);

    printf("Co-ordinates (a, k) Of Point 'B' Are : (%d, %d)\n\n", point_B.a, point_B.k); 

    printf("Co-ordinates (a, k) Of Point 'C' Are : (%d, %d)\n\n", point_C.a, point_C.k); 

    printf("Co-ordinates (a, k) Of Point 'D' Are : (%d, %d)\n\n", point_D.a, point_D.k); 

    printf("Co-ordinates (a, k) Of Point 'E' Are : (%d, %d)\n\n", point_E.a,point_E.k);
       
    getch();
        
    return(0);
}

