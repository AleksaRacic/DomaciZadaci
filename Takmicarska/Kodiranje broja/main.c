#include <stdlib.h>
#include <stdio.h>

int t, n,i;
int length = 0;
int output[120];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n == 0) {
            puts("10");
            continue;
        }
        length = 0;
        for (i = 9; i > 1; i --) {
            while (n % i == 0) {
                output[length ++] = i;
                n /= i;
            }
        }
        if (n != 1) {
            puts("-1");
        }
        else {
            for (i = length - 1; i >= 0; i --) {
                printf("%d", output[i]);
            }
            putchar('\n');
        }
    }
    
    return 0;
}

