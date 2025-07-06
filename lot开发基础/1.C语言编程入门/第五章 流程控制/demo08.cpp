#include<stdio.h>

int main() {
    int sum = 0;
    int i = 1;
    do {
        sum += i;
        i++;
    } while (i <= 100);
    printf("%d,%d\n", sum, i);
    return 0;
}