#include <stdio.h>

#include <stdlib.h>


#define MAX_STRING_LENGTH 512

int main(void) 
{ 
	//function declarations
	
	char* ReplaceVowelsWithHashSymbol(char *);

 
	//variable declaration
	
	char string[MAX_STRING_LENGTH];
	
	char *replaced_string = NULL;

 
	//code
	
	printf("\n\n");
	
	printf("Enter String : ");
	
	gets_s(string, MAX_STRING_LENGTH);

	replaced_string = ReplaceVowelsWithHashSymbol(string); 
	
	if (replaced_string == NULL) 
	
	{ 
		printf("ReplaceVowelsWithHashSymbol() Function Has Failed !!! Exitiing Now...\n\n"); 
		
		exit(0); 
	}
	
	printf("\n\n");
	
	printf("Replaced String Is : \n\n");
	
	printf("%s\n\n", replaced_string);

	if (replaced_string) 
	{
		free(replaced_string);
		replaced_string = NULL; 
	}
	
	getch();
	return(0);
}

char* ReplaceVowelsWithHashSymbol(char* s)

{ 
	//function prototype
	
	void MyStrcpy(char *, char *);
	
	int MyStrlen(char *);


 
	//varibale declarations 
	
	char *new_string = NULL;
	int a;

 
	//code 
	
	new_string = (char *)malloc(MyStrlen(s) * sizeof(char)); 
	
	if (new_string == NULL) 
	{ 
		printf("COULD NOT ALLOCATE MEMORY FOR NEW STRING !!!\n\n"); 
		return(NULL);

	

	}
	
	
	MyStrcpy(new_string, s); 
	
	for (a = 0; a < MyStrlen(new_string); a++)
	{
		switch (new_string[a])
		{
		case 'A':
		case 'a': 
		case 'E': 
		case 'e':
		case 'I':
		case 'i': 
		case 'O': 
		case 'o':  
		case 'U':
		
		case 'u':   
			
			new_string[a] = '#'; 
		
		
			break; 
		
		
		default:  
			
			break;
		}
	}
																										
	return(new_string);
}
																									
void MyStrcpy(char* str_destination, char* str_source)
{ 
	//function prototype 
	
	int MyStrlen(char *);
																									
	//variable declarations 
	
	int iStringLength = 0; 
	int k;
																									
	//code
	
	iStringLength = MyStrlen(str_source);
	
	for (k = 0; k < iStringLength; k++)  *(str_destination + k) = *(str_source + k);

																										
	*(str_destination + k) = '\0';
																									
}
																									
int MyStrlen(char* str)
{ 
	//variable declarations 
	
	int ak;
	int string_length = 0;
																										
						  
						 
	//code 
						 
	// *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) ***
	
	for (ak = 0; ak < MAX_STRING_LENGTH; ak++)
	{
		if (str[ak] == '\0')
			break; 
		else  
			string_length++;
	} 
	
	return(string_length);
}


																											
	