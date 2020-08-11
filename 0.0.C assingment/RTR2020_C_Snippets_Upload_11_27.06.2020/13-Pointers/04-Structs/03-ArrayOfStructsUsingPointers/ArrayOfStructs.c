#include <stdio.h> 
#include <ctype.h>

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

struct Employee
{ 
	char name[NAME_LENGTH]; 
	int age; char sex;
	float salary; 
	char marital_status;
};

int main(void)

{ 
	//function prototype 
	
	void MyGetString(char[], int);

 
	//variable delarations 
	
	struct Employee *pEmployeeRecord = NULL;
	int num_employees, a;

 
	//code
	
	printf("\n\n"); 
	
	printf("Enter Number Of Employees Whose Details You Want To Record : ");
	scanf("%d", &num_employees);

	printf("\n\n");
	
	pEmployeeRecord = (struct Employee*)malloc(sizeof(struct Employee) * num_employees);
	
	if (pEmployeeRecord == NULL) 
	
	{ 
		printf("FAILED TO ALLOCATED MEMORY FOR %d EMPLOYEES !!! EXITTING NOW ... \n\n", num_employees);  
		exit(0); 
	}
	else 
		printf("SUCCESSFULLY ALLOCATED MEMORY FOR %d EMPLOYEES !!!\n\n", num_employees);

	// ****** USER INPUT INITIALIZATION OF ARRAY OF 'struct Employee' ******
	
	for (a = 0; a < num_employees; a++)
	{ 
		printf("\n\n\n\n"); 
		
		printf("********** DATA ENTRY FOR EMPLOYEE NUMBER %d **********\n", (a + 1));

	printf("\n\n");
	
	printf("Enter Employee Name : "); 
	
	MyGetString(pEmployeeRecord[a].name, NAME_LENGTH);

	printf("\n\n\n");  
	
	printf("Enter Employee's Age (in years) : ");
	scanf("%d", &pEmployeeRecord[a].age);

	printf("\n\n"); 
	
	printf("Enter Employee's Sex (M/m For Male, F/f For Female) : "); 
	pEmployeeRecord[a].sex = getch(); 
	
	printf("%c", pEmployeeRecord[a].sex); 
	pEmployeeRecord[a].sex = toupper(pEmployeeRecord[a].sex);

	printf("\n\n\n");
	
	printf("Enter Employee's Salary (in Indian Rupees) : ");
	
	scanf("%f", &pEmployeeRecord[a].salary);

	printf("\n\n");
	
	printf("Is The Employee Married? (Y/y For Yes, N/n For No) : ");  
	
	pEmployeeRecord[a].marital_status = getch();
	
	printf("%c", pEmployeeRecord[a].marital_status); 
	
	pEmployeeRecord[a].marital_status = toupper(pEmployeeRecord[a].marital_status);


	}

	// *** DISPLAY *** 
	
	printf("\n\n\n\n"); 
	
	printf("********** DISPLAYING EMPLOYEE RECORDS **********\n\n");
	
	for (a = 0; a < num_employees; a++) 
	{ 
		printf("*********** EMPLOYEE NUMBER %d **********\n\n", (a + 1)); 
		
		printf("Name           : %s\n", pEmployeeRecord[a].name);  
		
		printf("Age            : %d years\n", pEmployeeRecord[a].age);


		if (pEmployeeRecord[a].sex == 'M')  
			
			printf("Sex            : Male\n"); 
		else if (pEmployeeRecord[a].sex == 'F') 
			
			printf("Sex            : Female\n"); 
		else  
			printf("Sex            : Invalid Data Entered\n");


		printf("Salary         : Rs. %f\n", pEmployeeRecord[a].salary);


		if (pEmployeeRecord[a].marital_status == 'Y') 
			printf("Marital Status : Married\n"); 
		
		else if (pEmployeeRecord[a].marital_status == 'N')  
			printf("Marital Status : Unmarried\n");
		else   
			printf("Marital Status : Invalid Data Entered\n");


		printf("\n\n");
	}
 
	if (pEmployeeRecord) { free(pEmployeeRecord);  pEmployeeRecord = NULL; 
	printf("MEMORY ALLOCATED TO %d EMPLOYEES HAS BEEN SUCCESSFULLY FREED !!! \n\n", num_employees); 
	}
 
	return(0);
 }

 // *** SIMPLE RUDIMENTARY IMPLEMENTATION OF gets_s() *** 
 
 // *** IMPLEMENTED DUE TO DIFFERENT BEHAVIOUR OF gets_s() / fgets() / fscanf() ON DIFFERENT PLATFORMS *** 
 // *** BACKSPACE / CHARACTER DELETION AND ARROW KEY CURSOR MOVEMENT NOT IMPLEMENTED ***
 
 void MyGetString(char str[], int str_size) 
 { 
	 //variable declarations
	 int ak;
	 
	 char ch = '\0';
  
	 //code 
	 
	 ak = 0;
	 do
	 {  
		 ch = getch(); 
		 str[ak] = ch; 
		
		 printf("%c", str[ak]);  ak++; 
	 }
	 while ((ch != '\r') && (ak < str_size));
	 
	 if (ak == str_size) 
		 str[ak - 1] = '\0';
	 
	 else  
		 str[ak] = '\0';


 }

