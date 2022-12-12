#include<stdio.h>

void optimal_page_replacement(int n,int m,int a[])
{
    int i,j,k,page_fault=0,flag=0;
    int frame[m];
    for(i=0;i<m;i++)
        frame[i]=-1;
        
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<m;j++)
        {
            if(frame[j]==a[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            page_fault++;
            for(j=0;j<m;j++)
            {
                if(frame[j]==-1)
                {
                    frame[j]=a[i];
                    break;
                }
            }
            if(j==m)
            {
                int max=-1;
                for(j=0;j<m;j++)
                {
                    int temp=0;
                    for(k=i+1;k<n;k++)
                    {
                        if(frame[j]==a[k])
                            break;
                        temp++;
                    }
                    if(temp>max)
                    {
                        max=temp;
                        j=j;
                    }
                }
                frame[j]=a[i];
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
    int a[n];
    printf("Enter the page numbers: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the number of frames: ");
    scanf("%d",&m);
    optimal_page_replacement(n,m,a);
    return 0;
}




