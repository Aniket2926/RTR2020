#include <stdio.h>

struct MyNumber
{
	int num; 
	int num_table[10]; 
};

struct NumTables
{ 
	struct MyNumber a; 
	struct MyNumber b; 
	struct MyNumber c; 
};

int main(void) 
{ 
	//variable declarations 
	
	struct NumTables tables;
	int i;
 
	//code 
	
	tables.a.num = 2; 
	for (i = 0; i < 10; i++)
		tables.a.num_table[i] = tables.a.num * (i + 1);
	
	printf("\n\n"); 
	
	printf("Table Of %d : \n\n", tables.a.num); 
	
	for (i = 0; i < 10; i++) 
		printf("%d * %d = %d\n", tables.a.num, (i + 1), tables.a.num_table[i]);

	tables.b.num = 3;
	
	for (i = 0; i < 10; i++) 
		tables.b.num_table[i] = tables.b.num * (i + 1); 
	
	printf("\n\n"); 
	
	printf("Table Of %d : \n\n", tables.b.num);
	
	for (i = 0; i < 10; i++) 
		printf("%d * %d = %d\n", tables.b.num, (i + 1), tables.b.num_table[i]);
	
	tables.c.num = 4;
	
	for (i = 0; i < 10; i++)  tables.c.num_table[i] = tables.c.num * (i + 1); 
	
	printf("\n\n"); printf("Table Of %d : \n\n", tables.c.num); 
	
	for (i = 0; i < 10; i++) 
		printf("%d * %d = %d\n", tables.c.num, (i + 1), tables.c.num_table[i]);
	
	getch();
	return(0);
}


