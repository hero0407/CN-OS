#include <stdio.h>

main() 
{
    int n, i, j, b[20], sb[20], t[20], x, c[20][20];

    printf("Enter no. of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        printf("Enter no. of blocks occupied by file%d: ", i + 1);
        scanf("%d", &b[i]);

        printf("Enter the starting block of file%d: ", i + 1);
        scanf("%d", &sb[i]);

        t[i] = sb[i];

        for (j = 0; j < b[i]; j++) 
        {
            c[i][j] = sb[i]++;
        }
    }

    printf("\nFilename\tStart block\tLength\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t\t%d\t\t%d\n", i + 1, t[i], b[i]);
    }

    printf("\nEnter file name (number) to view blocks: ");
    scanf("%d", &x);

    printf("\nFile name is: %d", x);
    printf("\nLength is: %d", b[x - 1]);
    printf("\nBlocks occupied: ");
    
    for (i = 0; i < b[x - 1]; i++) 
    {
        printf("%4d", c[x - 1][i]);
    }

    printf("\n");
}
