#include <stdio.h>

int main() {
    int a[10]; // 定义了一个数组，名字叫a,有10个成员，每个成员都是int类型
    int i = 0;
    for (i = 0; i < 10; i++) {
        a[i] = i; // 给数组赋值
    }

    //遍历数组  并输出每个成员的值
    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}