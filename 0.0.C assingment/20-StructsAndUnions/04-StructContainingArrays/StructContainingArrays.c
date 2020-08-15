#include <stdio.h>

#define INT_ARRAY_SIZE 10 

#define FLOAT_ARRAY_SIZE 5 

#define CHAR_ARRAY_SIZE 26

#define NUM_STRINGS 10 

#define MAX_CHARACTERS_PER_STRING 20

#define ALPHABET_BEGINNING 65 // 'A'

struct MyDataOne 
{ 
	int iArray[INT_ARRAY_SIZE]; 
	float fArray[FLOAT_ARRAY_SIZE];
};

struct MyDataTwo 
{ 
	char cArray[CHAR_ARRAY_SIZE]; 
	char strArray[NUM_STRINGS][MAX_CHARACTERS_PER_STRING];
};

int main(void) 
{ 
	//variable declarations 
	struct MyDataOne data_one; 
	struct MyDataTwo data_two;
	int ak;

 
	//code 
	// *** PIECE-MEAL ASSIGNMENT (HARD-CODED) *** 
	data_one.fArray[0] = 0.1f;
	
	data_one.fArray[1] = 1.2f; 
	
	data_one.fArray[2] = 2.3f; 
	
	data_one.fArray[3] = 3.4f; 
	
	data_one.fArray[4] = 4.5f;
 
	// *** LOOP ASSIGNMENT (USER INPUT) *** 
	
	printf("\n\n"); 
	
	printf("Enter %d Integers : \n\n",INT_ARRAY_SIZE); 
	
	for (ak = 0; ak < INT_ARRAY_SIZE; ak++)  
		scanf("%d", &data_one.iArray[ak]);
 
	// *** LOOP ASSIGNMENT (HARD-CODED) *** 
	
	for (ak = 0; ak < CHAR_ARRAY_SIZE; ak++) 
		data_two.cArray[ak] = (char)(ak + ALPHABET_BEGINNING);

 
	// *** PIECE-MEAL ASSIGNMENT (HARD-CODED) *** 
	strcpy(data_two.strArray[0], "Welcome !!!"); 
	strcpy(data_two.strArray[1], "This");
	strcpy(data_two.strArray[2], "Is");
	strcpy(data_two.strArray[3], "ASTROMEDICOMP'S"); 
	strcpy(data_two.strArray[4], "Real");
	strcpy(data_two.strArray[5], "Time"); 
	strcpy(data_two.strArray[6], "Rendering");
	strcpy(data_two.strArray[7], "Batch");
	strcpy(data_two.strArray[8], "Of");
	strcpy(data_two.strArray[9], "2020-2021 !!!");

	// *** DISPLAYING DATA MEMBERS OF 'struct DataOne' AND THEIR VALUES ***
	
	printf("\n\n"); 
	
	printf("Members Of 'struct DataOne' Alongwith Their Assigned Values Are : \n \n");

	printf("\n\n"); 
	
	printf("Integer Array (data_one.iArray[]) : \n\n");
	
	for (ak = 0; ak < INT_ARRAY_SIZE; ak++) 
		
		printf("data_one.iArray[%d] = %d\n", ak, data_one.iArray[ak]);

	
	
	printf("\n\n"); 
	
	printf("Floating-Point Array (data_one.fArray[]) : \n\n"); 
	
	for (ak = 0; ak < FLOAT_ARRAY_SIZE; ak++) 
		
		printf("data_one.fArray[%d] = %f\n", ak, data_one.fArray[ak]);

	// *** DISPLAYING DATA MEMBERS OF 'struct DataTwo' AND THEIR VALUES *** 
	
	printf("\n\n"); 
	
	printf("Members Of 'struct DataTwo' Alongwith Their Assigned Values Are : \n \n");
	
	printf("\n\n"); 
	
	printf("Character Array (data_two.cArray[]) : \n\n"); 
	for (ak = 0; ak < CHAR_ARRAY_SIZE; ak++)  
		printf("data_two.cArray[%d] = %c\n", ak, data_two.cArray[ak]);
	
	printf("\n\n"); 
	
	printf("String Array (data_two.strArray[]) : \n\n"); 
	
	for (ak = 0; ak < NUM_STRINGS; ak++) 
		
		printf("%s ", data_two.strArray[ak]);
	
	printf("\n\n");
	
	getch();
	return(0);
}


