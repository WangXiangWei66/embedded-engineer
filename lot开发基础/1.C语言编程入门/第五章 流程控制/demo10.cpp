#include <stdio.h>

int countOnes(int num) {
    int count = 0;
    while (num != 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int num = 15;
    printf("二进制1中的个数：%d\n", countOnes(num));
    return 0;
}