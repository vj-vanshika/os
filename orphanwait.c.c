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
          wait(NULL);
         printf("Parent process\n");
        }
   printf("hello\n");
   return 0; 
}
  
