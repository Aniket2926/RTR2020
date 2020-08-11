#include <stdio.h>

#include <stdlib.h>

#define MAX_STRING_LENGTH 512


int main(void)
{ 
	//function prototype 

	int MyStrlen(char *);

 
	//variable declarations 
	
	char *chArray = NULL; //Character Array Can Be Represented By A char pointer to Mark The Base Address (char *)
	
	int iStringLength = 0;

 
	//code 
	
	printf("\n\n"); 
	
	chArray = (char *)malloc(MAX_STRING_LENGTH * sizeof(char)); 
	
	if (chArray == NULL) 
	
	{  
		printf("MEMORY ALOCATION TO CHARACTER ARRAY FAILED !!! EXITTING NOW... \n\n");  
		
		exit(0);
	}

 
	// *** STRING INPUT *** 
	
	printf("Enter A String : \n\n"); 

	gets_s(chArray, MAX_STRING_LENGTH);

 
	// *** STRING OUTPUT *** 
	
	printf("\n\n"); 
	
	printf("String Entered By You Is : \n\n");
	
	printf("%s\n", chArray);

 
	// *** STRING LENGTH *** 
	
	printf("\n\n");
	
	iStringLength = MyStrlen(chArray); 
	
	printf("Length Of String Is = %d Characters !!!\n\n", iStringLength);
	
	
	if (chArray) 
	{ 
		free(chArray); 
		chArray = NULL;
	}


	getch();
	return(0);
}

int MyStrlen(char* str)

{
	//variable declarations
	
	int a;
	
	int string_length = 0;

 
	//code 
	
	// *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL - TERMINATING CHARACTER(\0) * **
	
	for (a = 0; a < MAX_STRING_LENGTH; a++)
	
	{ 
		if (*(str + a) == '\0')  
			
			break;  
		else   string_length++; 
	} 
	


	return(string_length);
}

