#include <stdio.h>

int main() 
{
    int i, j, k;
    int sn;
    int st[20];
    char op;

    printf("\nHow many stations: ");
    scanf("%d", &sn);

    do 
    {
        printf("\nEnter status of stations:\n");
        for (i = 0; i < sn; i++) 
        {
            printf("Enter status of station %d: ", i + 1);
            scanf("%d", &st[i]);
        }

        // Print ready stations
        for (i = 0; i < sn; i++) 
        {
            if (st[i] == 1) 
            {
                printf("Station %d is ready to transmit\n", i + 1);
            }
        }

        printf("Repeat? Press Y: ");
        scanf(" %c", &op); // Space before %c to consume any newline

    } while (op == 'y' || op == 'Y');

    return 0;
}
