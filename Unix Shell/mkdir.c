#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


char dirname[100];


void mk_dir() /*create directory*/
{
	int check;
	
	check = mkdir(dirname,0777);

	if (!check)
	printf("Directory created\n");
}


int main(int n, char *cmd[])
{
strcpy(dirname,cmd[1]);	
mk_dir();
}
