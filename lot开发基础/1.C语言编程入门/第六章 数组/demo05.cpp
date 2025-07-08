//二维数组求和
#include <stdio.h>

int main() {
    int a[2][3] = {{1, 2, 3},
                   {4, 5, 6}};
    int sum = 0;
    int rows = 2;
    int cols = 3;


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += a[i][j];
        }
    }

    printf("二维数组的和为：%d\n", sum);
    return 0;
}