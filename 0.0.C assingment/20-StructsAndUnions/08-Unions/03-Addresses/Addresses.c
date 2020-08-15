#include <stdio.h>

struct MyStruct
{ 
	int i;
	float f;
	double d;
	char c; 
};

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
	
	struct MyStruct s;
	union MyUnion u;

 
	//code 
	
	printf("\n\n");
	
	printf("Members Of Struct Are : \n\n");

	s.i = 9; 
	s.f = 8.7f; 
	s.d = 1.233422; 
	s.c = 'A';

	printf("s.i = %d\n\n", s.i); 
	
	printf("s.f = %f\n\n", s.f);
	
	printf("s.d = %lf\n\n", s.d); 
	
	printf("s.c = %c\n\n", s.c);
	
	printf("Addresses Of Members Of Struct Are : \n\n"); 
	
	printf("s.i = %p\n\n", &s.i);
	
	printf("s.f = %p\n\n", &s.f); 
	
	printf("s.d = %p\n\n", &s.d); 
	
	printf("s.c = %p\n\n", &s.c);
	
	printf("MyStruct s = %p\n\n", &s);
	
	printf("\n\n"); 
	
	printf("Members Of Union Are : \n\n");

	u.i = 3; 
	
	printf("u.i = %d\n\n", u.i);
	
	u.f = 4.5f; 
	
	printf("u.f = %f\n\n", u.f);
	
	u.d = 5.12764; 
	printf("u.d = %lf\n\n", u.d);
	
	u.c = 'A'; 
	printf("u.c = %c\n\n", u.c); 
	
	printf("Addresses Of Members Of Union Are : \n\n"); 
	
	printf("u.i = %p\n\n", &u.i);
	
	printf("u.f = %p\n\n", &u.f); 
	
	printf("u.d = %p\n\n", &u.d); 
	
	printf("u.c = %p\n\n", &u.c); 
	
	printf("MyUnion u = %p\n\n", &u); 
	
	getch();
	return(0);
}

