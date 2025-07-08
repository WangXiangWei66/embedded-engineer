//输入一个数字，求其所有质因数（如 6=2×3，20=2×2×5）。
#include <stdio.h>

int main() {
    int n;
    printf("请输入一个正整数：");
    scanf("%d", &n);

    if (n <= 1) {
        printf("%d们没有质因数\n", n);
        return 0;
    }

    printf("%d=", n);
    int is_first = 1;//标记是否为第一个质因数，它用来控制是否输出乘号

    //处理质因数2的情况,先快速处理所有偶数情况
    while (n % 2 == 0) {
        //非首个因子时输出乘号
        if (!is_first)
            printf("x");
        printf("2");
        is_first = 0;
        n /= 2;
    }

    //处理从3开始的奇数质因数
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            if (!is_first)
                printf("x");
            printf("%d", i);
            is_first = 0;
            n /= i;
        }
    }

    //若剩余的n是大于2的质数
    if (n > 2) {
        if (!is_first)
            printf("x");
        printf("%d", n);
    }

    printf("\n");
    return 0;
}