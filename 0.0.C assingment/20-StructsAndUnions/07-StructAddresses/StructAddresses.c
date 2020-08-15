#include <stdio.h>

struct MyData 
{ 
	int ak; 

	float f;
	
	double d;
	
	char c;
};

int main(void)
{
	//variable declarations
	
	struct MyData data;

 
	//code 
	
	//Assigning Data Values To The Data Members Of 'struct MyData'
	
	data.ak = 30; 
	
	data.f = 11.45f; 
	
	data.d = 1.2995;
	
	data.c = 'A';
 
	//Displaying Values Of The Data Members Of 'struct MyData' 
	
	printf("\n\n"); 
	
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	
	printf("ak = %d\n", data.ak);
	
	printf("f = %f\n", data.f);
	
	printf("d = %lf\n", data.d); 
	
	printf("c = %c\n\n", data.c);
	
	printf("\n\n"); 
	
	printf("ADDRESSES OF DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	
	printf("'ak' Occupies Addresses From %p\n", &data.ak);
	
	printf("'f' Occupies Addresses From %p\n", &data.f); 
	
	printf("'d' Occupies Addresses From %p\n", &data.d); 
	
	printf("'c' Occupies Address %p\n\n", &data.c);
	
	printf("Starting Address Of 'struct MyData' variable 'data' = %p\n\n", &data);
	


	getch();
	
	return(0);
}

