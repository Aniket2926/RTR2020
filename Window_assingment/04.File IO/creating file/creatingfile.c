#include <stdio.h>

int main(void)
{
	//code
	//Local variable declaration 
	FILE *pfile = NULL; // file is type date
		
	//library
		if (fopen_s(&pfile, "amklog.exe", "w")!=0) 
		{
			printf("can not open desired file\n");
			exit(0);
		}
	//3rd step

	fprintf(pfile,"India is my country.\n");

	//step4

	fclose(pfile);

	//step5
	pfile = NULL;

	getch();
	 
	return(0);

}


