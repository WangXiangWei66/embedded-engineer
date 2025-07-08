#include <stdio.h>

int main() {
    int a[] = {1, 3, 5, 7, 9};
    int len = sizeof(a) / sizeof(a[0]);

    int is_ascending = 1; //标记是否升序，初始为1

    //遍历数组检查是否升序
    for (int i = 0; i < len - 1; i++) {
        if (a[i] > a[i + 1]) {
            is_ascending = 0;
            break;
        }
    }

    if (is_ascending) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}