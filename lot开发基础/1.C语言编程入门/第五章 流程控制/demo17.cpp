#include <stdio.h>

int main() {
    int m, n;
    for (m = 0; m < 10; m++) {
        for (n = 0; n < 10; n++) {
            if (n == 3)
                continue;
        }
        printf("%d\n", n);
        return 0;
    }
}