#include <stdio.h>

int main(void)
{
	//code
	//Local variable declaration 
	FILE *pFile=NULL // file is type date
		
	//library
		if (fopen_s(&pfile, "AMKlog.exe", "w") != ) //w=write
		{
			printf("can not open desired file\n");
			exit(0);
		}
	//3rd step

	fprintf(pfile, "India is my country.\n");

	//step4

	fclose(pfile);

	//step5
	pfile = NULL;

	return(0);

}

