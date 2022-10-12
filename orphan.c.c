#include<unistd.h>
#include<stdio.h>
void main()
{
   int pid=fork();
   if(pid==0)
     {
        sleep(15);
        printf("child process\n");
     }
   else
      {
         printf("parent process");
      }
}

