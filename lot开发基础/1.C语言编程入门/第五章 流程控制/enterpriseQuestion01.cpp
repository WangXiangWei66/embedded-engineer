//��һֻ���ܣ����� h �ף������� m �ף����ϵ� n �ף��Ӱ��쿪ʼ��������������������
#include <stdio.h>

int main() {
    int h, m, n;
    printf("�����뾮��h���������ľ�����m,�����»��ľ���n(�ÿո�ָ�)��");
    scanf("%d %d %d", &h, &m, &n);

    if (m <= n && h > m) {
        printf("�����޷�������\n");
        return 1;
    }

    int days = 0;
    int current_height = 0;
    while (1) {
        days++;
        current_height += m;
        if (current_height >= h) {
            printf("������Ҫ%d�����������\n", days);
            break;
        }
        current_height -= n;
    }
    return 0;
}