#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

char filename[100];
char fname[100];


int cat()
{
char c;  
 FILE *fptr;

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("cat: %s : No such file or directory \n",filename);
    }
    else
	{
 // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
	}
}



int main(int n, char *cmd[])
{

strcpy(filename,cmd[1]);	
cat();

}

