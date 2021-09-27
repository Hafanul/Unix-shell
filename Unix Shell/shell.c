#include <sys/types.h>      /* needed to use pid_t, etc. */
#include <sys/wait.h>       /* needed to use wait() */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>         /* LINUX constants and functions (fork(), etc.) */
#include <string.h>

#define cgeen "\x1B[32m"
#define cwhite "\x1B[0m"



int help()
{
printf("'cat *filename' : view file \n");
printf("'ls' : watch list of directory \n");
printf("'cp *filename1 *filename1' : copy \n");
printf("'mv *filename1 *filename1' : move\n");
printf("'rm' : remove file \n");
printf("'gedit *filename with extation': open file  \n");
printf("'mkdir' : create folder \n");
printf("'rmdir' : remove folder \n");
printf("'clear' : clean terminal \n");
}


int main()
{
 pid_t pid;



	while(1){
	printf("\n %sUnix Shell >>:%s ",cgeen,cwhite);
   char str[1000], cmd[30],option[30];

    char x[100],y[100][100],filename1[100],filename2[100];

    gets(x);
    int length=strlen(x);

    int i,j=0,k=0;
    for(i=0; i<=length; i++)
    {
        if(x[i] == ' ' || x[i] == NULL )
        {
            y[j][k]=NULL;
            j++;
            k=0;
        }
        else
        {
            y[j][k]=x[i];
            k++;
        }
    }

		/// tokenize str
		/// seperate command, option and arguments

		 pid = fork();

		 if (pid < 0)
 		 {
   			printf("A fork error has occurred.\n");
   			exit(-1);
  		}
 		else if (pid == 0) /* We are in the child. */
  		 {


			if(strcmp(y[0],"cat")==0){
				execlp("./cat","cat",y[1],(char *) 0);
			}
			else if(strcmp(y[0],"ls")==0){
				execlp("ls","ls",(char *) 0);
			}
			else if(strcmp(y[0],"cp")==0){
				execlp("./cp","cp",y[1],y[2],(char *) 0);
			}
			else if(strcmp(y[0],"mv")==0){
				execlp("./mv","mv",y[1],y[2],(char *) 0);
			}
			else if(strcmp(y[0],"rm")==0){
				execlp("./rm","rm",y[1],(char *) 0);
			}
			else if(strcmp(y[0],"gedit")==0){
				execlp("./gedit","gedit",y[1],(char *) 0);
			}
			else if(strcmp(y[0],"mkdir")==0){
				execlp("./mkdir","mkdir",y[1],(char *) 0);
			}
			else if(strcmp(y[0],"rmdir")==0){
				execlp("./rmdir","rmdir",y[1],(char *) 0);
			}

			else if(strcmp(y[0],"clear")==0){
				execlp("./clear","clear",y[0],(char *) 0);
			}
			else if(strcmp(y[0],"help")==0){
				help();
			}
			else
				printf("command not found, Type 'help' for more info");


    			
   			/*  If execlp() is successful, we should not reach this next line. */
   			 printf("The call to execlp() was not successful.\n");
    			exit(127);
   		}
 		 else  /* We are in the parent. */
   		{
    			wait(0);               /* Wait for the child to terminate. */
    			//printf("I am the parent.  The child just ended.  I will now exit.\n");
    			//exit(0);
   		}

		
	
	}






 return(0);
}
