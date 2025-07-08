//一维数组版本
#include <stdio.h>

int main() {
    int a[] = {10, 5, 8, 12, 3, 7};
    int len = sizeof(a) / sizeof(a[0]);
    int max = a[0], min = a[0];
    float sum = 0, avg;

    //遍历数组计算最大值、最小值和总和
    for (int i = 0; i < len; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
        sum += a[i];
    }
    avg = sum / len;
    printf("最大值：%d\n", max);
    printf("最小值:%d\n", min);
    printf("平均值：%.2f\n", avg);

    return 0;
}