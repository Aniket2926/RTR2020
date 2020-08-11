#include <stdio.h>

int main(void)
{
	//function declarations 
	
	int AddIntegers(int, int);
	
	int SubtractIntegers(int, int); 
	
	float AddFloats(float, float);

 
	//variable declaration 

	typedef int (*AddIntsFnPtr)(int, int); 
	
	AddIntsFnPtr ptrAddTwoIntegers = NULL;
	
	AddIntsFnPtr ptrFunc = NULL;

	typedef float (*AddFloatsFnPtr)(float, float); AddFloatsFnPtr ptrAddTwoFloats = NULL;
	
	int iAnswer = 0;
	
	float fAnswer = 0.0f;
	
	//code 
	
	ptrAddTwoIntegers = AddIntegers;
	
	iAnswer = ptrAddTwoIntegers(9, 30);
	
	printf("\n\n");
	
	printf("Sum Of Integers = %d\n\n", iAnswer);

	ptrFunc = SubtractIntegers;
	
	iAnswer = ptrFunc(9, 30);
	
	printf("\n\n"); 
	
	printf("Subtraction Of Integers = %d\n\n", iAnswer);

	ptrAddTwoFloats = AddFloats;
	
	fAnswer = ptrAddTwoFloats(11.45f, 8.2f); 
	
	printf("\n\n"); 
	
	printf("Sum Of Floating-Point Numbers = %f\n\n", fAnswer);


	getch();
	return(0);

}
int AddIntegers(int a, int k) 

{ 
	//varibale declarations
	
	int m;
 //code
	
	m = a + k; return(m); 
}
	
int SubtractIntegers(int a, int k) 

{
	//varibale declarations
 
	int m; 
		 
 
	//code 
	
	if (a > k)
		m = a - k;
	
	else  
		
		m = k - a;

	return(m); 

}
float AddFloats(float f_num1, float f_num2)

{ 
	//varibale declarations
	
	float ans;
	
	//code
	
	ans = f_num1 + f_num2;
	
	return(ans);
}

