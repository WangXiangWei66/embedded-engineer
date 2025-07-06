#include <stdio.h>

int main() {
    int a, n;
    long long sum = 0, term = 0;// sum存储总和，term存储当前项的值

    printf("请输入a和n（用空格分割）:");
    scanf("%d %d", &a, &n);

    for (int i = 0; i < n; i++) {
        term = term * 10 + a;
        sum += term;
    }
    printf("表达式的和为：%lld", sum);
    return 0;
}