#include "stdio.h"

int main() {
    int a, b, c;

    // ��ȷд��
    printf("����������������");  // ��printf�����ʾ
    scanf("%d %d %d", &a, &b, &c);  // ��scanf��ȡ���루ֻ��%d��

    // �Ƚ��߼������ֲ��䣩
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;

    // ������������Format:��
    printf("���ֵ�ǣ�%d\n", max);

    return 0;
}