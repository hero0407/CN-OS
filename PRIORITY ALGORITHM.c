#include <stdio.h>

void main() 
{
    int pid[10], bt[10], pr[10], wt[10], tat[10], n, twt = 0, ttat = 0;
    int i, j, t;
    float awt, atat;

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    printf("\nEnter burst times: ");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("\nEnter PID: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pid[i]);

    printf("\nEnter Priorities: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pr[i]);

    // Sorting based on priority (lower value = higher priority)
    for (i = 0; i < n; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (pr[i] > pr[j]) 
            {
                // Swap priority
                t = pr[i];
                pr[i] = pr[j];
                pr[j] = t;

                // Swap burst time
                t = bt[i];
                bt[i] = bt[j];
                bt[j] = t;

                // Swap PID
                t = pid[i];
                pid[i] = pid[j];
                pid[j] = t;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < n; i++) 
    {
        wt[i] = tat[i - 1];
        tat[i] = bt[i] + wt[i];
    }

    for (i = 0; i < n; i++) 
    {
        ttat += tat[i];
        twt += wt[i];
    }

    printf("\nPID\tPRIORITY\tBT\tWT\tTAT");
    for (i = 0; i < n; i++)
        printf("\n%d\t%d\t\t%d\t%d\t%d", pid[i], pr[i], bt[i], wt[i], tat[i]);

    awt = (float)twt / n;
    atat = (float)ttat / n;

    printf("\nAvg. Waiting Time = %f", awt);
    printf("\nAvg. Turn Around Time = %f", atat);
}
