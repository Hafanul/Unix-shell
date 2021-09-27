#include<stdio.h>
#include<string.h>
#include <dirent.h>
int ls()
{
  DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  return(0);
}


int main(int n, char *cmd[])
{
	ls();
}


