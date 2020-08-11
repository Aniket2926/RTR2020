#include <stdio.h>

struct MyPoint
{
    int xa; 
    int yk; 
};

int main(void)
{ 
    //variable declarations
    
    struct MyPoint point_A, point_B, point_C, point_D, point_E;  //declaring a 5 struct variables

 
    //code
    //User Input For The Data Members Of 'struct MyPoint' variable 'point_A' 
    
    printf("\n\n"); 

    printf("Enter Xa-Coordinate For Point 'A' : ");
    scanf("%d", &point_A.xa);

    printf("Enter Yk-Coordinate For Point 'A' : ");
    scanf("%d", &point_A.yk);

 
    //User Input For The Data Members Of 'struct MyPoint' variable 'point_B' 
    
    printf("\n\n");

    printf("Enter Xa-Coordinate For Point 'B' : "); 
    scanf("%d", &point_B.xa);
    
    printf("Enter Yk-Coordinate For Point 'B' : "); 
    scanf("%d", &point_B.yk);

 
    //User Input For The Data Members Of 'struct MyPoint' variable 'point_C' 
    
    printf("\n\n"); 

    printf("Enter Xa-Coordinate For Point 'C' : "); 
    scanf("%d", &point_C.xa);
    
    printf("Enter Yk-Coordinate For Point 'C' : "); 
    scanf("%d", &point_C.yk);
 
    //User Input For The Data Members Of 'struct MyPoint' variable 'point_D'
    
    printf("\n\n");

    printf("Enter Xa-Coordinate For Point 'D' : "); 
    scanf("%d", &point_D.xa); 
    
    printf("Enter Yk-Coordinate For Point 'D' : "); 
    scanf("%d", &point_D.yk);

 
    //User Input For The Data Members Of 'struct MyPoint' variable 'point_E'
    
    printf("\n\n");

    printf("Enter Xa-Coordinate For Point 'E' : ");
    scanf("%d", &point_E.xa); 
    
    printf("Enter Yk-Coordinate For Point 'E' : ");
    scanf("%d", &point_E.yk);

 //Displaying Values Of The Data Members Of 'struct MyPoint' (all variables) 
    
    printf("\n\n");

    printf("Co-ordinates (xa, yk) Of Point 'A' Are : (%d, %d)\n\n", point_A.xa, point_A.yk); 
    
    printf("Co-ordinates (xa, yk) Of Point 'B' Are : (%d, %d)\n\n", point_B.xa, point_B.yk); 
    
    printf("Co-ordinates (xa, yk) Of Point 'C' Are : (%d, %d)\n\n", point_C.xa, point_C.yk);

    printf("Co-ordinates (xa, yk) Of Point 'D' Are : (%d, %d)\n\n", point_D.xa, point_D.yk); 

    printf("Co-ordinates (xa, yk) Of Point 'E' Are : (%d, %d)\n\n", point_E.xa, point_E.yk);

    getch();
    return(0);
}

