//二维数组版本
#include <stdio.h>

int main() {
    int a[3][4] = {
            {1, 5, 3, 9},
            {4, 2, 6, 8},
            {7, 0, 11, 5}
    };

    int rows = 3;
    int cols = 4;
    int max = a[0][0];
    int min = a[0][0];

    float sum = 0, avg;
    int total_elements = rows * cols;

    //遍历二维数组计算最大值、最小值和总和
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] > max)
                max = a[i][j];
            if (a[i][j] < min) {
                min = a[i][j];
            }
            sum += a[i][j];
        }
    }
    avg = sum / total_elements;

    printf("最大值:%d\n", max);
    printf("最小值：%d\n", min);
    printf("平均值:%d\n", avg);

    return 0;

}