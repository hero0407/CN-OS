#include <stdio.h>

int main() {
    int a[50]; 
    int i, j, k, n, c = 0, pos = 0;

    printf("Enter the number of bits: ");
    scanf("%d", &n);

    printf("Enter the bits (0 or 1):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        if (a[i] == 1) {
            c++;
            if (c == 5) {
                pos = i + 1;
                c = 0;
                for (j = n; j >= pos; j--) {
                    a[j + 1] = a[j];
                }
                a[pos] = 0;
                n++;
                i++; 
            }
        } else {
            c = 0;
        }
    }

    printf("\nData after bit stuffing:\n");
    printf("01111110");  

    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
    }

    printf("01111110\n"); 

    return 0;
}
