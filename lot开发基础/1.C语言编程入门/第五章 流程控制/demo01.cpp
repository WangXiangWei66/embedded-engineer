#include <stdio.h>

int main() {
    int a;
    printf("Plz Input a Integer Number:");
    scanf("%d", &a);
    if (a > 10) {
        printf("a > 10\n");
    } else {
        printf("a<=10\n");
    }
    return 0;
}