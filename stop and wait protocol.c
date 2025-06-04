#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>  

void main() {
    int i, j, noframes, x, x1 = 10, x2;

    for (i = 0; i < 200; i++) 
        rand();

    noframes = rand() / 200;
    noframes = noframes / 8;

    printf("\nNumber of frames is %d", noframes);

    i = 1;
    j = 1;

    while (noframes > 0) {
        printf("\nSending frame %d", i);
        srand(x1++);
        x = rand() % 10;

        if (x % 2 == 0) {
            for (x2 = 1; x2 < 2; x2++) {
                printf("Waiting for %d seconds\n", x2);
                sleep(x2);
            }
            printf("\nResending frame %d", i);
            srand(x1++);
            x = rand() % 10;
        }

        printf("\nAcknowledgment for frame %d", j);
        noframes -= 1;
        i++;
        j++;
    }

    printf("\nEnd of Stop and Wait Protocol");
    getch();
}
