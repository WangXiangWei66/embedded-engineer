#include <stdio.h>

int main() {
    int year, month;
    //������ݺ��·�
    printf("��������ݺ��·ݣ��ÿո�ָ��");
    if (scanf("%d %d", &year, &month) != 2) { //��֤������������
        printf("�����ʽ����\n");
        return 1;
    }

    //�ж��·���Ч��
    if (month < 1 || month > 12) {
        printf("�·��������������1~12������\n");
        return 1;
    }

    //�ж�����
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
            // �ж�����
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                days = 29;  // ����2��29��
            } else {
                days = 28;  // ƽ��2��28��
            }
            break;
    }

    // ������
    printf("%d��%d����%d�졣\n", year, month, days);
    return 0;
}
