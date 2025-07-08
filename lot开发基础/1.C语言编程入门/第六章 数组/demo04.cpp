//一维数组元素求和
#include <stdio.h>

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int sum = 0;
    int len = sizeof(a) / sizeof(a[0]); // 计算数组的长度

    //遍历数组，并累加元素
    for (int i = 0; i < len; i++) {
        sum += a[i];
    }

    printf("一维数组元素的和为：%d\n", sum);
    return 0;
}