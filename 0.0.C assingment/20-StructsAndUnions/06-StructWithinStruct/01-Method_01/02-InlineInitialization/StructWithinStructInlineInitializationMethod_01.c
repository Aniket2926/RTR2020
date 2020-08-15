#include <stdio.h>

struct Rectangle 
{
	struct MyPoint 
	{
		int a;
		int k;
	
	} point_01, point_02;

} rect = { {2, 3}, {5, 6} };

int main(void) 
{ 
	//variable declarations
	
	int length, breadth, area;

 
	//code
	
	length = rect.point_02.k - rect.point_01.k; 
	
	if (length < 0)  length = length * -1;

	breadth = rect.point_02.a - rect.point_01.a; 
	if (breadth < 0)  breadth = breadth * -1;
	
	area = length * breadth;
	
	printf("\n\n");
	
	printf("Length Of Rectangle = %d\n\n", length); 
	
	printf("Breadth Of Rectangle = %d\n\n", breadth);
	
	printf("Area Of Rectangle = %d\n\n", area);
	
	

	getch();
	return(0);


}