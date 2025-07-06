#include "stdio.h"

int main() {
    int a, b, c;

    // 正确写法
    printf("请输入三个整数：");  // 用printf输出提示
    scanf("%d %d %d", &a, &b, &c);  // 用scanf读取输入（只含%d）

    // 比较逻辑（保持不变）
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;

    // 输出结果（不含Format:）
    printf("最大值是：%d\n", max);

    return 0;
}