#include<stdio.h>
int n;
void print(int arr[n])       //for printong array values
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int i,j;
    printf("Enter the number of processes : ");
    scanf("%d",&n);

    int arrival[n+1],burst[n+1];
    
    printf("Enter Arrival Time : ");
    for(i=0;i<n;i++)
        scanf("%d",&arrival[i]);

    printf("Enter Burst Time : ");    
    for(i=0;i<n;i++)
        scanf("%d",&burst[i]);

        //sort according to arrival
        int temp;
for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arrival[j]<arrival[i])
            {
                temp=arrival[j];
                arrival[j]=arrival[i];
                arrival[i]=temp;
        
                temp=burst[j];	
                burst[j]=burst[i];
                burst[i]=temp;
            }
        }
    }


    int completion[n+1],turnaround[n+1],waiting[n+1];

    completion[0]=burst[0]+arrival[0];

    for(i=0;i<n;i++)
        completion[i+1]=burst[i+1]+completion[i];

    printf("Completion Time : ");
    print(completion);

    for(i=0;i<n;i++)
        turnaround[i]=completion[i]-arrival[i];

    printf("Turnaround Time : ");
    print(turnaround);
    
    for(i=0;i<n;i++)
        waiting[i]=turnaround[i]-burst[i];
    printf("Waiting Time : ");
    print(waiting);
    
    int totTurn=0,totWait=0;
    for(i=0;i<n;i++)
    {
        totTurn+=turnaround[i];
        totWait+=waiting[i];
    }

    printf("Average Turnaround time is : %f\n",(1.0*totTurn)/n);
    printf("Average Waiting time is : %f",(1.0*totWait)/n);
return 0;
}