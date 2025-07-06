#include <stdio.h>
#include <math.h>

int main() {
    int num, hundreds, tens, ones;
    printf("100-999之间的水仙花数有：\n");

    //遍历100-999的所有三位数
    for (num = 100; num <= 999; num++) {
        //分解出百位，十位，个位
        hundreds = num / 100;
        tens = (num / 10) % 10;
        ones = num % 10;

        //判断是否为水仙花数
        if (pow(hundreds, 3) + pow(tens, 3) + pow(ones, 3) == num) {
            printf("%d\n", num);
        }
    }
}