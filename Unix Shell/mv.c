#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
char filename1[100],filename2[100];

int rm(){
      int status;     
      status = remove(filename1);
     
      if (status == 0)
        printf(" ");
      else
      {
        printf("Unable to delete the file\n");
      }
     
      return 0;
    }


int move() 
{ 
	FILE *fptr1, *fptr2; 
	char c;
	     
	fptr1 = fopen(filename1, "r"); 
	if (fptr1 == NULL) 
	{ 
		printf("cp: %s : No such file or directory \n", filename1); 
		exit(0); 
	} 


	fptr2 = fopen(filename2, "w"); 
	if (fptr2 == NULL) 
	{ 
		printf("cp: %s : No such file or directory \n", filename2); 
		exit(0); 
	} 

	// Read contents from file 
	c = fgetc(fptr1); 
	while (c != EOF) 
	{ 
		fputc(c, fptr2); 
		c = fgetc(fptr1); 
	} 

	printf("\nContents move to %s \n", filename2); 

	fclose(fptr1); 
	fclose(fptr2);

	rm();
	
	fptr1 = fopen(filename1, "w"); 
	if (fptr1 == NULL) 
	{ 
		printf("cp: %s : No such file or directory \n", filename1); 
		exit(0); 
	}
 	fclose(fptr1); 
	return 0; 
}

int main(int n, char *cmd[])
{

	strcpy(filename1,cmd[1]);
	strcpy(filename2,cmd[2]);
	move();

}


