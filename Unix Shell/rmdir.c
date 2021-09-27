#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


char dirname[100];


void rm_dir() /*create directory*/
{
	int check;
	
	check = rmdir(dirname);

	if (!check)
	printf("Directory Deleted\n");
}


int main(int n, char *cmd[])
{
strcpy(dirname,cmd[1]);	
rm_dir();
}
