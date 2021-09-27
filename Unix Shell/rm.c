#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
char filename1[100];

int rm(){
      int status;     
      status = remove(filename1);
     
      if (status == 0)
        printf("%s file deleted successfully.\n", filename1);
      else
      {
        printf("Unable to delete the file\n");
      }
     
      return 0;
    }



int main(int n, char *cmd[])
{
	strcpy(filename1,cmd[1]);
	rm();
}

