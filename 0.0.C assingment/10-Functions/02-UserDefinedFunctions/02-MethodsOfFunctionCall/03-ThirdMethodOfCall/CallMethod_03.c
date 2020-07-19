#include <stdio.h> //'stdio.h' contains declaration of 'printf()'

// ****** USER DEFINED FUNCTIONS : METHOD OF CALLING FUNCTION 3 ****** 
// ****** CALLING ONLY ONE FUNCTION DIRECTLY IN main(), REST OF THE FUNCTIONS TRACE THEIR CALL INDIRECTLY TO main() ******

int main(int argc, char* argv[], char* envp[]) 
{ 
    //function prototypes   
    void Function_Country();    
    //code   
    Function_Country();
    return(0); }
    void Function_Country(void) //function definition
    {    
        // fucntion declarations   
        void Function_OfAMC(void);
        
        // code    
        Function_OfAMC();      
        printf("\n\n");
        printf("I live In India.");
    
        printf("\n\n");
}
void Function_OfAMC(void) //function definition 
{    // function declarations   
    void Function_Surname(void);
    // code  
    Function_Surname();
    printf("\n\n");

    printf("Of ASTROMEDICOMP"); }

void Function_Surname(void) //function definition
{    // function declarations   
    void Function_MiddleName(void);
    // code 
    Function_MiddleName();
    printf("\n\n");
    printf("KADAM");
}

void Function_MiddleName(void) //function definition 
{   
    // function declarations   
    void Function_FirstName(void);
    
    // code  
    Function_FirstName();
    
    printf("\n\n");

    printf("MAHESh"); 
}
void Function_FirstName(void) //function definition
{    // function declarations  
    void Function_Is(void);
    // code    
    Function_Is();
    printf("\n\n");

    printf("KADAM"); 
}

void Function_Is(void) //function definition 
{    // function declarations    
    void Function_Name(void);
    //code    
    Function_Name();
    printf("\n\n");

    printf("Is"); }

void Function_Name(void) //function definition
{    // function declarations   
    void Function_My(void);
    //code   
    Function_My();
    printf("\n\n");

    printf("Name");
}

// ****** User-Defined Functions' Definitions... *** 
void Function_My(void) //function definition 
{ 
    //code
    printf("\n\n");

    printf("My");
}
        