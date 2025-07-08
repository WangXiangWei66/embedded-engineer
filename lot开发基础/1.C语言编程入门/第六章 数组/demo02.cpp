#include <stdio.h>

int main() {
    char ch[] = {'A', 'B', 'C', 'D'};
    int i;
    for (i = 0; i < 4; i++) {
        printf("%p ", &ch[i]);//将对应元素的内存地址以16进制的形式输出
    }
    printf("\n");
    return 0;
}