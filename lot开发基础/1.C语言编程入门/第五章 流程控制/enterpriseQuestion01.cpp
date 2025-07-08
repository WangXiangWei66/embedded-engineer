//有一只青蛙，井深 h 米，白天爬 m 米，晚上掉 n 米，从白天开始爬，求多少天可以爬出来
#include <stdio.h>

int main() {
    int h, m, n;
    printf("请输入井深h，白天爬的距离是m,晚上下滑的距离n(用空格分隔)：");
    scanf("%d %d %d", &h, &m, &n);

    if (m <= n && h > m) {
        printf("青蛙无法爬出井\n");
        return 1;
    }

    int days = 0;
    int current_height = 0;
    while (1) {
        days++;
        current_height += m;
        if (current_height >= h) {
            printf("青蛙需要%d天才能爬出井\n", days);
            break;
        }
        current_height -= n;
    }
    return 0;
}