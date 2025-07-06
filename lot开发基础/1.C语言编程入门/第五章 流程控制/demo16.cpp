#include <stdio.h>

int main() {
    int year, month;
    //输入年份和月份
    printf("请输入年份和月份（用空格分割）：");
    if (scanf("%d %d", &year, &month) != 2) { //保证输入了两个数
        printf("输入格式错误！\n");
        return 1;
    }

    //判断月份有效性
    if (month < 1 || month > 12) {
        printf("月份输入错误！请输入1~12的数字\n");
        return 1;
    }

    //判断天数
    int days;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            // 判断闰年
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                days = 29;  // 闰年2月29天
            } else {
                days = 28;  // 平年2月28天
            }
            break;
    }

    // 输出结果
    printf("%d年%d月有%d天。\n", year, month, days);
    return 0;
}
