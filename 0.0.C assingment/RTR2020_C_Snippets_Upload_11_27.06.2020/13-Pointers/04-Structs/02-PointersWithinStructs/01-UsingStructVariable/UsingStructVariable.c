#include <stdio.h>


// DEFINING STRUCT

struct MyData
{
	int *ptr_i;
	int ak;


	float* ptr_f;
	float f;


	double* ptr_d; 
	double d; 
};

int main(void)
{ 
	//variable declarations

	struct MyData data;
 
	//code  
	
	data.ak = 9;
	
	data.ptr_i = &data.ak;

	data.f = 11.45f;
	
	data.ptr_f = &data.f;

	data.d = 30.121995; 
	
	data.ptr_d = &data.d;
	
	printf("\n\n");
	
	printf("ak = %d\n", *(data.ptr_i)); 
	
	printf("Adress Of 'ak' = %p\n", data.ptr_i);
	
	printf("\n\n"); 
	
	printf("f = %f\n", *(data.ptr_f)); 
	
	printf("Adress Of 'f' = %p\n", data.ptr_f);

	printf("\n\n");
	
	printf("d = %lf\n", *(data.ptr_d)); 
	
	printf("Adress Of 'd' = %p\n", data.ptr_d);
	

	getch();
	return(0);

}

