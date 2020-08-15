#include <stdio.h>

int main(void)
{ 
	//variable declarations 
	int length, breadth, area;
	
	struct Rectangle 
	{
		struct MyPoint
		{
			int a;   
			int k; 
		
		} point_01, point_02;
	
	} rect;
	
	//code 
	
	printf("\n\n"); 
	
	printf("Enter Leftmost A-Coordinate Of Rectangle : "); 
	
	scanf("%d", &rect.point_01.a);

	printf("\n\n");
	
	printf("Enter Bottommost K-Coordinate Of Rectangle : ");
	
	scanf("%d", &rect.point_01.k);

	printf("\n\n"); 
	
	printf("Enter Rightmost A-Coordinate Of Rectangle : "); 
	
	scanf("%d", &rect.point_02.a);

	printf("\n\n");
	
	printf("Enter Topmost K-Coordinate Of Rectangle : ");
	
	scanf("%d", &rect.point_02.k);

	length = rect.point_02.k - rect.point_01.k; 
	
	if (length < 0) 
		length = length * -1;
	
	breadth = rect.point_02.a - rect.point_01.a; 
	
	if (breadth < 0) 
		breadth = breadth * -1;
	
	area = length * breadth;
	
	printf("\n\n"); 
	
	printf("Length Of Rectangle = %d\n\n", length); 
	
	printf("Breadth Of Rectangle = %d\n\n", breadth);
	
	printf("Area Of Rectangle = %d\n\n", area);

	getch();
	return(0);
}


