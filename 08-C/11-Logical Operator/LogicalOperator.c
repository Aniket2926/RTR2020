#include <stdio.h>
int main(void)
{
    //variable declarations 
    int a;
    int n;
    int i;
    int result;
    //code
    printf("\n\n");
    printf("Enter First Integer : ");
    scanf("%d", &a);

    printf("\n\n");
    printf("Enter Second Integer : ");
    scanf("%d", &n);

    printf("\n\n");
    printf("Enter Third Integer : ");
    scanf("%d", &i);

    printf("\n\n");
    printf("If Answer = 0, It Is 'FALSE'.\n");
    printf("If Answer = 1, It Is 'TRUE'.\n\n");

    result = (a <= n) && (n != i);
    printf("LOGICAL AND (&&) : Answer is TRUE (1) If And Only If BOTH Conditions Are True. The Answer is FALSE (0), If Any One Or Both Conditions Are False. \n\n");
    printf("A = %d Is Less Than Or Equal To B = %d AND B = %d Is NOT Equal To C = %d      \t Answer = %d\n\n", a, n, n, i, result);

    result = (n >= a) || (a == 1);
    printf("LOGICAL OR (||) : Answer is FALSE (0) If And Only If BOTH Conditions Are False. The Answer is TRUE (1), If Any One Or Both Conditions Are True.\n \n");
    printf("Either B = %d Is Greater Than Or Equal To A = %d OR A = %d Is Equal To C = %d \t Answer = %d\n\n", n, a, a, i, result);

    result = !a; printf("A = %d And Using Logical NOT (!) Operator on A Gives Result = %d\n\n", a, result);

    result = !n; printf("B = %d And Using Logical NOT (!) Operator on B Gives Result = %d\n\n", n, result);

    result = !i; printf("C = %d And Using Logical NOT (!) Operator on C Gives Result = %d\n\n", i, result);

    result = (!(a <= n) && !(n != 1));

    printf("Using Logical NOT (!) On (a <= n) And Also On (n != i) And then ANDing Them Afterwards Gives Result = %d\n", result);

    printf("\n\n");

    result = !((n >= a) || (a == i));

    printf("Using Logical NOT (!) On Entire Logical Expression (b >= a) || (a == c) Gives Result = %d\n", result);
    printf("\n\n");

    getch();

    return(0);
}
