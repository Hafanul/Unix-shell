#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
char filename1[100],filename2[100];


int crt() 
{ 
	FILE *fptr1; 
	char c;
	     
	fptr1 = fopen(filename1, "w"); 
	if (fptr1 == NULL) 
	{ 
		printf(" %s : No such file or directory \n", filename1); 
		exit(0); 
	}
 	fclose(fptr1); 
	return 0; 
}

int main(int n, char *cmd[])
{
	strcpy(filename1,cmd[1]);
	crt();
}


