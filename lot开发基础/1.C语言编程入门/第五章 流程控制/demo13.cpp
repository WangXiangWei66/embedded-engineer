#include <stdio.h>

int main() {
    int a, n;
    long long sum = 0, term = 0;// sum�洢�ܺͣ�term�洢��ǰ���ֵ

    printf("������a��n���ÿո�ָ:");
    scanf("%d %d", &a, &n);

    for (int i = 0; i < n; i++) {
        term = term * 10 + a;
        sum += term;
    }
    printf("���ʽ�ĺ�Ϊ��%lld", sum);
    return 0;
}