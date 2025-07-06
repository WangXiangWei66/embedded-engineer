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
    printf("������1�еĸ�����%d\n", countOnes(num));
    return 0;
}