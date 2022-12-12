#include<stdio.h>

void least_recently_used(int n,int m,int a[])
{
    int i,j,k,page_fault=0,flag=0;         //n=no. of pages total, m=no. of frames
    int frame[m],recent[m];

    for(i=0;i<m;i++)
    {
        frame[i]=-1;
        recent[i]=0;
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<m;j++)
        {                                                         
            if(frame[j]==a[i])                             //if found then hit, update recent w index i
            {
                flag=1;
                recent[j]=i;
                break;
            }
        }
        if(flag==0)
        {
            page_fault++;
            for(j=0;j<m;j++)
            {                                                   //if not found, miss++
                if(frame[j]==-1)
                {                                               // if any frame empty, update the frame with string ref
                    frame[j]=a[i];
                    recent[j]=i;
                    break;
                }
            }
            if(j==m)                                       //if frames all full ie j==m(no. of frames then lru)
            { 
                int min=recent[0],min_index=0;
                for(j=1;j<m;j++)
                {
                    if(recent[j]<min)            //checking indexes of recent arrray , finding the min index entered
                    {
                        min=recent[j];
                        min_index=j;
                    }
                }
                frame[min_index]=a[i];
                recent[min_index]=i;
            }
        }
    }
    printf("Number of page faults: %d",page_fault);
}

int main()
{
    int n,m,i;
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    printf("Enter the number of frames: ");
    scanf("%d",&m);
    int a[n];
    printf("Enter the page reference string: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    least_recently_used(n,m,a);
    return 0;
}

