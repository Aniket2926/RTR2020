#include <stdio.h>

union MyUnion
{ 
    int i;
    float f;
    double d;
    char c;
};

int main(void)
{ 
    //variable declarations
    
    union MyUnion ua1, uk2;
 
    //code 
    // *** MyUnion u2 *** 
    
    printf("\n\n"); 
    
    printf("Members Of Union u1 Are : \n\n");
    
    ua1.i = 6; ua1.f = 1.2f;
    ua1.d = 8.333333;    ua1.c = 'S';

    printf("ua1.i = %d\n\n", ua1.i); 
    
    printf("ua1.f = %f\n\n", ua1.f);
    
    printf("ua1.d = %lf\n\n", ua1.d); 
    
    printf("ua1.c = %c\n\n", ua1.c);

    printf("Addresses Of Members Of Union u1 Are : \n\n");
    
    printf("ua1.i = %p\n\n", &ua1.i);
    
    printf("ua1.f = %p\n\n", &ua1.f); 
    
    printf("ua1.d = %p\n\n", &ua1.d); 
    
    printf("ua1.c = %p\n\n", &ua1.c);
    printf("MyUnion ua1 = %p\n\n", &ua1);
   
    // *** MyUnion u2 ***
    
    printf("\n\n"); 
    
    printf("Members Of Union u2 Are : \n\n");

    uk2.i = 3; 
    printf("uk2.i = %d\n\n", uk2.i);

    uk2.f = 4.5f; 
    printf("uk2.f = %f\n\n", uk2.f);

    uk2.d = 5.12764;
    printf("uk2.d = %lf\n\n", uk2.d);

    uk2.c = 'A';
    printf("u2.c = %c\n\n", uk2.c); 
    
    printf("Addresses Of Members Of Union u2 Are : \n\n"); 
    
    printf("uk2.i = %p\n\n", &uk2.i);
    
    printf("uk2.f = %p\n\n", &uk2.f);
   
    printf("uk2.d = %p\n\n", &uk2.d); 
    
    printf("uk2.c = %p\n\n", &uk2.c);
    
    printf("MyUnion uk2 = %p\n\n", &uk2); 
    


    getch();
    return(0);
}

