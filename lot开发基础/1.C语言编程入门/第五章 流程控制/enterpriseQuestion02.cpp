//在坐标系中，以 (400,240) 为圆心、50 为半径，编程打印圆内所有点的坐标。
#include <stdio.h>

int main() {
    //定义圆心坐标和半径
    int center_x = 400;
    int center_y = 240;
    int radius = 50;

    //计算坐标范围（圆心+-半径）
    int min_x = center_x - radius;
    int max_x = center_x + radius;
    int min_y = center_y - radius;
    int max_y = center_y + radius;

    int count = 0;//用于统计点的数量

    //遍历所有可能的点
    for (int x = min_x; x <= max_x; x++) {
        for (int y = min_y; y <= max_y; y++) {
            //计算点到圆心的距离的平方（避免浮点数的运算）
            int dx = x - center_x;
            int dy = y - center_y;
            int distance_squared = dx * dx + dy * dy;

            //判断是否在圆内(包括圆上)
            if (distance_squared <= radius * radius) {
                printf("(%d,%d)", x, y);
                count++;

                //每打印十个点换行，便于阅读
                if (count % 10 == 0) {
                    printf("\n");
                }
            }
        }
    }

    printf("\n\n圆内（包括圆上）共有%d个点\n", count);
    return 0;
}