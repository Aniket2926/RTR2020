#include <stdio.h> //'stdio.h' contains declaration of 'printf()'

// ****** USER DEFINED FUNCTIONS : METHOD OF CALLING FUNCTION 2 ****** 
// ****** CALLING ONLY TWO FUNCTIONS DIRECTLY IN main(), REST OF THE FUNCTIONS TRACE THEIR CALL INDIRECTLY TO main() ******

int main(int argc, char* argv[], char* envp[])
{ 
    //function prototypes 
    void display_information(void); 
    void Function_Country(void);
 
    //code 
    display_information(); //function call 
    Function_Country(); //function call
    return(0);
}

// ****** User-Defined Functions' Definitions... *** 
void display_information(void) //function definition 
{ 
    //function prototypes
    void Function_My(void);
    void Function_Name(void); 
    void Function_Is(void); 
    void Function_FirstName(void);
    void Function_MiddleName(void); 
    void Function_Surname(void); 
    void Function_OfAMC(void);
 
    //code
 // *** FUNCTION CALLS *** 
    Function_My();
    Function_Name();
    Function_Is();
    Function_FirstName();
    Function_MiddleName();
    Function_Surname();
    Function_OfAMC(); 
}

void Function_My(void) //function definition 
{ 
    //code 
    printf("\n\n");

    printf("My"); 
}
void Function_Name(void) //function definition
{
    //code 
    printf("\n\n");
    printf("Name");
}
void Function_Is(void) //function definition 
{ 
    //code 
   
    printf("\n\n");

    printf("Is"); 
}

void Function_FirstName(void) //function definition
{ 
    printf("\n\n");

    printf("ANIKET"); 
}

void Function_MiddleName(void) //function definition 
{
    printf("\n\n");

    printf("MAHESH");
}

void Function_Surname(void) //function definition 
{
    printf("\n\n");

    printf("KADAMe"); 
}

void Function_OfAMC(void) //function definition
{ 
    printf("\n\n");

    printf("Of DOTA");
}
void Function_Country(void) //function definition 
{
    printf("\n\n");

    printf("I LOVE DOTA.");


    printf("\n\n");
}

