#include <stdio.h>

int main() {
    int result = 1;
    int i;
    for (i = 1; i <= 5; i++) {
        result *= i;
    }
    printf("5µÄ½×³ËÎª:%d\n", result);
    return 0;
}