#include <stdio.h>

void main() 
{
    int ts, bt1[10], wt[10], tat[10], i, j = 0, n, bt[10], ttat = 0, twt = 0, tot = 0;
    float awt, atat;

    printf("Enter the number of Processes:\n");
    scanf("%d", &n);

    printf("\nEnter the Time Slice:\n");
    scanf("%d", &ts);

    printf("\nEnter the Burst Time for the processes:\n");
    for (i = 1; i <= n; i++) 
    {
        scanf("%d", &bt1[i]);
        bt[i] = bt1[i];
    }

    while (j < n) 
    {
        for (i = 1; i <= n; i++) 
        {
            if (bt[i] > 0) 
            {
                if (bt[i] >= ts) 
                {
                    tot += ts;
                    bt[i] -= ts;
                    if (bt[i] == 0) 
                    {
                        j++;
                        tat[i] = tot;
                    }
                } 
                else 
                {
                    tot += bt[i];
                    bt[i] = 0;
                    j++;
                    tat[i] = tot;
                }
            }
        }
    }

    for (i = 1; i <= n; i++) 
    {
        wt[i] = tat[i] - bt1[i];
        twt += wt[i];
        ttat += tat[i];
    }

    awt = (float)twt / n;
    atat = (float)ttat / n;

    printf("\nPID\tBT\tWT\tTAT\n");
    for (i = 1; i <= n; i++) 
    {
        printf("%d\t%d\t%d\t%d\n", i, bt1[i], wt[i], tat[i]);
    }

    printf("\nThe Average Waiting Time = %f", awt);
    printf("\nThe Average Turn Around Time = %f", atat);
}
