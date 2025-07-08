//����һ�����֣������������������� 6=2��3��20=2��2��5����
#include <stdio.h>

int main() {
    int n;
    printf("������һ����������");
    scanf("%d", &n);

    if (n <= 1) {
        printf("%d��û��������\n", n);
        return 0;
    }

    printf("%d=", n);
    int is_first = 1;//����Ƿ�Ϊ��һ���������������������Ƿ�����˺�

    //����������2�����,�ȿ��ٴ�������ż�����
    while (n % 2 == 0) {
        //���׸�����ʱ����˺�
        if (!is_first)
            printf("x");
        printf("2");
        is_first = 0;
        n /= 2;
    }

    //�����3��ʼ������������
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            if (!is_first)
                printf("x");
            printf("%d", i);
            is_first = 0;
            n /= i;
        }
    }

    //��ʣ���n�Ǵ���2������
    if (n > 2) {
        if (!is_first)
            printf("x");
        printf("%d", n);
    }

    printf("\n");
    return 0;
}