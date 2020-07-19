#include <stdio.h> 
int main(void)
{
    //variable declarations
    int i_num, num, i;

    //code 
    printf("\n\n");

    printf("Enter An Integer Value From Which Iteration Must Begin : "); 
    scanf("%d", &i_num);


    printf("How Many Digits Do You Want To Print From %d Onwards ? : ", i_num);
    scanf("%d", &num);

    printf("Printing Digits %d to %d : \n\n", i_num, (i_num + num));

    for (i = i_num; i <= (i_num + num); i++) 

    {
    printf("\t%d\n", i); 
    
    }


    printf("\n\n");


    return(0);
}
