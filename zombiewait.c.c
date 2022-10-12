#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
   int pid;
   pid =fork();
   if(pid==0)
   {
      printf("Child process\n");
   }
   else
       {
         printf("Parent process\n");22
          wait(NULL);
          printf("Child process has been completed\n");
        }
   printf("hello\n");
   return 0;
  }
