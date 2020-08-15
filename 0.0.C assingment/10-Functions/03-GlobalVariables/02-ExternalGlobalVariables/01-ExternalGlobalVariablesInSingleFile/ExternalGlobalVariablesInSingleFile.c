#include <stdio.h>
// *** GLOBAL SCOPE ***

int main(void)
{ 
    //function prototypes 
    void change_count(void);
 
    //variable declarations extern 
    extern int global_count;

 
    //code
    printf("\n"); 
    printf("Value Of global_count before change_count() = %d\n", global_count); 
    change_count();    
    printf("Value Of global_count after change_count()  = %d\n", global_count);   
    printf("\n"); return(0);
}
// *** GLOBAL SCOPE *** 
// global_count is a global variable. // Since, it is declared before change_count(), it can be accssed and used as any ordinary global variable in change_count()
// Since, it is declared after main(), it must be firest re-declared in main() as an external global variable by means of the 'extern' keyword and the type of the variable. 
// Once this is done, it can be used as an ordinary global variable in main as well. 
int global_count = 0;
    
void change_count(void)
{
    //code 
    global_count = 5;
    printf("Value Of global_count in change_count() = %d\n", global_count);
}
