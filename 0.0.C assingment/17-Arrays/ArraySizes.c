#include <stdio.h>
int main(void)
{ 
    // variable declaration
    int MyArray_One[5]; 
    int MyArray_Two[5][3];
    int MyArray_Three[100][100][5];

    int num_rows_2D;
    int num_columns_2D;
    int num_rows_3D; 
    int num_columns_3D; 
    int depth_3D;

    // code 
    printf("\n\n");
    printf("Size of 1-D integer array iArray_One = %lu\n", sizeof(MyArray_One)); 
    printf("Number of elements in 1-D integer array iArray_One = %lu\n", (sizeof (MyArray_One) / sizeof(int)));
    printf("\n\n"); 

    printf("Size of 2-D integer array iArray_Two = %lu\n", sizeof(MyArray_Two));
    printf("Number rows in 2-D integer array iArray_Two = %lu\n", (sizeof(MyArray_Two) / sizeof(MyArray_Two[0]))); num_rows_2D = (sizeof(MyArray_Two) / sizeof(MyArray_Two[0]));
    printf("Number of elements (columns) in each row in 2-D integer array iArray_Two = %lu\n", (sizeof(MyArray_Two[0]) / sizeof(MyArray_Two[0][0]))); num_columns_2D = (sizeof(MyArray_Two[0]) / sizeof(MyArray_Two[0][0]));
    printf("Number of elements in total in 2-D Array iArray_Two = %d\n", (num_rows_2D * num_columns_2D));
    printf("\n\n");

    printf("\n\n");
    printf("Size of 3-D integer array iArray_Three = %lu\n", sizeof(MyArray_Three));
    printf("Number rows in 3-D integer array iArray_Three = %lu\n", (sizeof(MyArray_Three) / sizeof(MyArray_Three[0]))); num_rows_3D = (sizeof(MyArray_Three) / sizeof(MyArray_Three[0]));
    printf("Number of elements (columns) in one row in 3-D integer array iArray_Three = %lu\n", (sizeof(MyArray_Three[0]) / sizeof(MyArray_Three[0][0]))); num_columns_3D = (sizeof(MyArray_Three[0]) / sizeof(MyArray_Three[0][0]));
    printf("Number of elements (depth) in one column in one row in 3-D integer array iArray_Three = %lu\n", (sizeof(MyArray_Three[0][0]) / sizeof(MyArray_Three[0][0][0]))); depth_3D = (sizeof(MyArray_Three[0][0]) / sizeof(MyArray_Three[0][0][0]));
    printf("Number of elements in total in 3-D Array iArray_Three = %d\n", (num_rows_3D * num_columns_3D * depth_3D));
    
    printf("\n\n");

    getch();

    return(0);


}

