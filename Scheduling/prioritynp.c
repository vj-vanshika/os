#include <stdio.h>
void sort(int a[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][2] < a[j][2])
            {
                int t = a[i][0];
                int k = a[i][1];
                int l = a[i][2];
                a[i][0] = a[j][0];
                a[i][1] = a[j][1];
                a[i][2] = a[j][2];
                a[j][0] = t;
                a[j][1] = k;
                a[j][2] = l;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter the no. of process");
    scanf("%d", &n);
    int arr[n][3];
    for (int i = 0; i < n; i++)
    {
        printf("\n enter the arrival,burst time and priority number for the %dth process\t", i + 1);
        scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    sort(arr, n);
    int wait[n], tat[n], averageWait = 0, averageTAT = 0;
    wait[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wait[i] = wait[i - 1] + arr[i - 1][1];
        averageWait += wait[i];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = wait[i] + arr[i][1];
        averageTAT += tat[i];
    }
    double a = averageTAT / (1.0 * n), b = averageWait / (1.0 * n);
    printf("Process no.\t Arrival time \t Burst Time\t Priority_no \t Waiting Time \t Turn around Time\n");
    for (int i = 0; i < n; i++)
    {
        printf(“% d\t\t % d\t\t % d\t\t % d\t\t % d\t\t % d\n”, i + 1, arr[i][0], arr[i][1], arr[i][2], wait[i], tat[i]);
    }
    printf("The average wait time is: %lf and the average turn around time is: %lf", b, a);
    return 0;
}
