#include<unistd.h>
#include<stdio.h>
void main()
{
   int pid=fork();
   if(pid==0)
     {
        printf("child process");
     }
   else
      {
         sleep(15);
         printf("parent process");
      }
}
