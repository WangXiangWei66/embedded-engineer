//һά����Ԫ�����
#include <stdio.h>

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int sum = 0;
    int len = sizeof(a) / sizeof(a[0]); // ��������ĳ���

    //�������飬���ۼ�Ԫ��
    for (int i = 0; i < len; i++) {
        sum += a[i];
    }

    printf("һά����Ԫ�صĺ�Ϊ��%d\n", sum);
    return 0;
}