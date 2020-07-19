#include <stdio.h>

int main(void) 
{ 
    //variable declarations 
    int a, b; 
    int p, q; 
    char ch_result_01, ch_result_02; 
    int i_result_01, i_result_02;
 
    //code 
    printf("\n\n");
    a = 7; b = 5; 
    ch_result_01 = (a > b) ? 'A' : 'B'; 
    i_result_01 = (a > b) ? a : b;
    printf("Ternary Operator Answer 1 ----- %c and %d.\n\n", ch_result_01, i_result_01);

    p = 30; 
    q = 30; 
    ch_result_02 = (p != q) ? 'P' : 'Q'; 
    i_result_02 = (p != q) ? p : q; printf("Ternary Operator Answer 2 ----- %c and %d.\n\n", ch_result_02, i_result_02);
   
    printf("\n\n");

    return(0);

}
