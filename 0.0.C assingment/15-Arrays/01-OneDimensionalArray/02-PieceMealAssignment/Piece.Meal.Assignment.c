#include <stdio.h> 
int main(void)
{
    //variable declaraions
    int iArrayOne[10];    //int i+ak
    int iArrayTwo[10];

    //code

    // ****** iArrayOne[] ****** 
    iArrayOne[0] = 3; 
    iArrayOne[1] = 6; 
    iArrayOne[2] = 9; 
    iArrayOne[3] = 12;
    iArrayOne[4] = 15;
    iArrayOne[5] = 18; 
    iArrayOne[6] = 21;
    iArrayOne[7] = 24; 
    iArrayOne[8] = 27; 
    iArrayOne[9] = 30;

printf("\n\n");
printf("Piece-meal (Hard-coded) Assignment And Display Of Elements to Array 'iArrayOne[]': \n\n");
printf("1st Element Of Array 'iArrayOne[]' Or Element At 0th Index Of Array 'iArrayOne[]' = %d\n", iArrayOne[0]);
printf("2nd Element Of Array 'iArrayOne[]' Or Element At 1st Index Of Array 'iArrayOne[]' = %d\n", iArrayOne[1]); 
printf("3rd Element Of Array 'iArrayOne[]' Or Element At 2nd Index Of Array 'iArrayOne[]' = %d\n", iArrayOne[2]);
printf("4th Element Of Array 'iArrayOne[]' Or Element At 3rd Index Of Array 'iArrayOne[]' = %d\n", iArrayOne[3]); 
printf("5th Element Of Array 'iArrayOne[]' Or Element At 4th Index Of Array 'iArrayOne[]' = %d\n", iArrayOne[4]);
printf("6th Element Of Array 'iArrayOne[]' Or Element At 5th Index Of Array 'iArrayOne[]' = %d\n", iArrayOne[5]); 
printf("7th Element Of Array 'iArrayOne[]' Or Element At 6th Index Of Array 'iArrayOne[]' = %d\n", iArrayOne[6]); 
printf("8th Element Of Array 'iArrayOne[]' Or Element At 7th Index Of Array 'iArrayOne[]' = %d\n", iArrayOne[7]); 
printf("9th Element Of Array 'iArrayOne[]' Or Element At 8th Index Of Array 'iArrayOne[]' = %d\n", iArrayOne[8]);
printf("10th Element Of Array 'iArrayOne[]' Or Element At 9th Index Of Array 'iArrayOne[]' = %d\n\n", iArrayOne[9]);

// ****** iArrayTwo[] ****** printf("\n\n");

printf("Enter 1st Element Of Array 'iArrayTwo[]' : "); 
scanf("%d", &iArrayTwo[0]);

printf("Enter 2nd Element Of Array 'iArrayTwo[]' : "); 
scanf("%d", &iArrayTwo[1]);

printf("Enter 3rd Element Of Array 'iArrayTwo[]' : "); 
scanf("%d", &iArrayTwo[2]);

printf("Enter 4th Element Of Array 'iArrayTwo[]' : ");
scanf("%d", &iArrayTwo[3]);

printf("Enter 5th Element Of Array 'iArrayTwo[]' : "); 
scanf("%d", &iArrayTwo[4]);

printf("Enter 6th Element Of Array 'iArrayTwo[]' : ");
scanf("%d", &iArrayTwo[5]);

printf("Enter 7th Element Of Array 'iArrayTwo[]' : ");
scanf("%d", &iArrayTwo[6]); 

printf("Enter 8th Element Of Array 'iArrayTwo[]' : ");
scanf("%d", &iArrayTwo[7]); 

printf("Enter 9th Element Of Array 'iArrayTwo[]' : "); 
scanf("%d", &iArrayTwo[8]); 
printf("Enter 10th Element Of Array 'iArrayTwo[]' : "); 
scanf("%d", &iArrayTwo[9]);

printf("\n\n");

printf("Piece-meal (User Input) Assignment And Display Of Elements to Array 'iArrayTwo[]' : \n\n");
printf("1st Element Of Array 'iArrayTwo[]' Or Element At 0th Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo[0]);
printf("2nd Element Of Array 'iArrayTwo[]' Or Element At 1st Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo[1]);
printf("3rd Element Of Array 'iArrayTwo[]' Or Element At 2nd Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo[2]);
printf("4th Element Of Array 'iArrayTwo[]' Or Element At 3rd Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo[3]); 
printf("5th Element Of Array 'iArrayTwo[]' Or Element At 4th Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo[4]);
printf("6th Element Of Array 'iArrayTwo[]' Or Element At 5th Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo[5]); 
printf("7th Element Of Array 'iArrayTwo[]' Or Element At 6th Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo[6]); 
printf("8th Element Of Array 'iArrayTwo[]' Or Element At 7th Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo[7]); 
printf("9th Element Of Array 'iArrayTwo[]' Or Element At 8th Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo[8]); 
printf("10th Element Of Array 'iArrayTwo[]' Or Element At 9th Index Of Array 'iArrayTwo[]' = %d\n\n", iArrayTwo[9]);

getch();
return(0);

}