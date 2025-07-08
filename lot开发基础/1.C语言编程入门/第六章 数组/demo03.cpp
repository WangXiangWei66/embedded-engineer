#include <stdio.h>

int main() {
    char a[] = {1, 2, 3, 4};
    int i;
    for (i = 0; i < 4; i++) {
        printf("%p ", &a[i]);//将对应元素的内存地址以16进制的形式输出
    }
    printf("\n");
    return 0;
}