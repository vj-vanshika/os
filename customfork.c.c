#include <stdio.h> #include <sys/types.h> #include <unistd.h>

int main()
{
int sumOdd=0, sumEven=0; int n;
printf("Enter the size of array: "); scanf("%d",&n);
int a[n];
printf("\nEnter the elements of array: "); for(int i=0; i<n; i++)
{
scanf("%d",&a[i]);
}
int pid=fork(); if(pid==0)
{
for(int i=0; i<n; i++)
{
if(i%2!=0)
sumOdd+=a[i];
}
 


}
else
{
 
printf("Child Process\n");
printf("Sum of odd places: %d\n",sumOdd);



for(int i=0; i<n; i++)
{
 
if(i%2==0)
sumEven+=a[i];
}
printf("Parent Process\n");
printf("Sum of even places: %d\n",sumEven);
}
return 0;
}
