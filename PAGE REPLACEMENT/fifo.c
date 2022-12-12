#include <stdio.h>
int main()
{
    int A[100];
    int n, hit = 0, miss = 0;
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    printf("Enter the incoming stream\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    int f;
    printf("Enter the number of frames");
    scanf("%d", &f);

    int temp[100] = {-1};               //frame array
    int ind = 0;                              
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < f; j++)
        {
            if (A[i] == temp[j])       //if stream found in frame
            {
                flag = 1;
                hit++;                //increment hit
            }
        }
        if (flag == 0)
        {
            miss++;                 //miss increment
            temp[ind] = A[i];         // if not found then add in frame
            ind = (ind + 1) % f;
        }
        printf("\n");
        for (int k = 0; k < f; k++)
        {
            if (temp[k] != -1)
                printf("%d ", temp[k]);
            else
                printf("-- ");
        }
    }
    printf("\nTotal page fault: %d", miss);
    printf("\nTotal page hit: %d", hit);
    printf("\n");
}
