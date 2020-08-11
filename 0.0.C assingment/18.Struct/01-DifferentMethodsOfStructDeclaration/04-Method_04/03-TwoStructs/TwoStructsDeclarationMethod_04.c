#include <stdio.h>

//DEFINING STRUCT
struct MyPoint
{ 
    int x;      // no chnage 

    int y; 
};

//DEFINING STRUCT
struct MyPointProperties 
{ 
    int quadrant;
    char axis_location[10];
};

int main(void)
{ 
    //variable declarations
    struct MyPoint point;  //declaring a single variable of type 'struct MyPoint' locally... 
    
    struct MyPointProperties point_properties;     //declaring a single variable of type 'struct MyPointProperties' locally...
 
    //code
    //User Input For The Data Members Of 'struct MyPoint' variable 'point_A'

    printf("\n\n"); 
    printf("Enter X-Coordinate For A Point : "); scanf("%d", &point.x);
   
    printf("Enter Y-Coordinate For A Point : "); scanf("%d", &point.y);
    
    printf("\n\n");
    
    printf("Point Co-ordinates (x, y) Are : (%d, %d) !!!\n\n", point.x, point.y);
    
    if (point.x == 0 && point.y == 0)
        printf("The Point Is The Origin (%d, %d) !!!\n", point.x, point.y);
   
    else     // Atleast One of the two values (either 'X' or 'Y' or BOTH) is a nonzero value...
    {  
        if (point.x == 0)          // If 'X' IS ZERO...OBVIOUSLY 'Y' IS THE NON-ZERO VALUE  
        {   
            if (point.y < 0)      // If 'Y' IS -ve    
                strcpy(point_properties.axis_location, "Negative Y");
       
                if (point.y > 0)      // If 'Y' IS +ve   
                    strcpy(point_properties.axis_location, "Positive Y");

            
                point_properties.quadrant = 0; // A Point Lying On Any Of The Coordinate Axes Is NOT A Part Of ANY Quadrant...   
                
                printf("The Point Lies On The %s Axis !!!\n\n", point_properties.axis_location);

    

        }
  
        else
            if (point.y == 0) // If 'Y' IS ZERO...OBVIOUSLY 'X' IS THE NON-ZERO VALUE
       
            {   
                if (point.x < 0)   // If 'X' IS -ve 
           
                strcpy(point_properties.axis_location, "Negative X");
        
                if (point.x > 0) // If 'X' IS +ve   
            
                    strcpy(point_properties.axis_location, "Positive X");

      
        
                point_properties.quadrant = 0; // A Point Lying On Any Of The Coordinate Axes Is NOT A Part Of ANY Quadrant...  
        
        
       
                printf("The Point Lies On The %s Axis !!!\n\n", point_properties.axis_location); 
       
            } 
       
            else // BOTH 'X' AND 'Y' ARE NON-ZERO  
        
            {  
          
                point_properties.axis_location[0] = '\0'; // A Point Lying In ANY Of The 4 Quadrants Cannot Be Lying On Any Of The Co-ordinate Axes...
      
           
                if (point.x > 0 && point.y > 0)      // 'X' IS +ve AND 'Y' IS +ve   
                point_properties.quadrant = 1;
      
           
                else if (point.x < 0 && point.y > 0) // 'X' IS -ve AND 'Y' IS +ve  

                    point_properties.quadrant = 2;
      
            
                else if (point.x < 0 && point.y < 0) // 'X' IS -ve AND 'Y' IS -ve  
                point_properties.quadrant = 3;
     
            
                else                                 // 'X' IS +ve AND 'Y' IS -ve  
                point_properties.quadrant = 4;
        
            
                printf("The Point Lies In Quadrant Number %d !!!\n\n", point_properties.quadrant); 
        
            } 
    }
          
    getch();
    return(0);
}

