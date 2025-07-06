#include <stdio.h>

int main() {
    unsigned int a;
    scanf("%u", &a);

    if (a < 10) {
        printf("个位\n");
    } else if (a < 100) {
        printf("十位\n");
    } else if (a < 1000) {
        printf("百位\n");
    } else {
        printf("超过了四位数\n");
    }
    return 0;
}