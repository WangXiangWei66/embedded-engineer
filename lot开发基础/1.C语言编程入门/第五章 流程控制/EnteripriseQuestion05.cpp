/**
*ģ�� ATM ȡ����̣�
1. ��ʾ�������루��� 3 �Σ���������ʾ �����������ȡ��������
2. ������ȷ������Ϊ 111111������ʾ����ȡ���
3. ��֧����� 100 Ԫֽ�ң�������� 100~1000 Ԫ֮�䡣
4. ������Ҫ�����ӡȡ��������ʾ ��������ɣ���ȡ������������ʾ����
*/

#include "stdio.h"

#define PASSWORD 111111 //Ԥ������
#define MAX_ATTEMPTS 3 // ����Դ���
#define MIN_AMOUNT 100 //��Сȡ����
#define MAX_AMOUNT 1000 //���ȡ����
#define DENOMINATION 100 //ֽ�����

int main() {
    int password_attempt;
    int attempts = 0;

    //������֤ѭ��
    while (attempts < MAX_AMOUNT) {
        printf("����������:");
        scanf("%d", &password_attempt);
        attempts++;

        if (password_attempt == PASSWORD) {
            int amount;
            printf("������ȷ\n");

            //ȡ�����
            printf("������ȡ���");
            scanf("%d", &amount);

            //�����֤
            if (amount >= MIN_AMOUNT && amount <= MAX_AMOUNT && amount % DENOMINATION == 0) {
                int notes = amount / DENOMINATION;
                printf("��ȡ��%d��100Ԫ\n", notes);
                printf("������ɣ���ȡ��\n");
            } else {
                printf("��������100�ı�������100-1000Ԫ֮��\n");
            }
            return 0;
        } else {
            printf("�������������%d�γ��Ի���\n", MAX_ATTEMPTS - attempts);
        }
    }

    //��������Դ���
    printf("���������ȡ��\n");
    return 1;
}