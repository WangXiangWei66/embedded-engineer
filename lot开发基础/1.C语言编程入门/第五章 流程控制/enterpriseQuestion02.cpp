//������ϵ�У��� (400,240) ΪԲ�ġ�50 Ϊ�뾶����̴�ӡԲ�����е�����ꡣ
#include <stdio.h>

int main() {
    //����Բ������Ͱ뾶
    int center_x = 400;
    int center_y = 240;
    int radius = 50;

    //�������귶Χ��Բ��+-�뾶��
    int min_x = center_x - radius;
    int max_x = center_x + radius;
    int min_y = center_y - radius;
    int max_y = center_y + radius;

    int count = 0;//����ͳ�Ƶ������

    //�������п��ܵĵ�
    for (int x = min_x; x <= max_x; x++) {
        for (int y = min_y; y <= max_y; y++) {
            //����㵽Բ�ĵľ����ƽ�������⸡���������㣩
            int dx = x - center_x;
            int dy = y - center_y;
            int distance_squared = dx * dx + dy * dy;

            //�ж��Ƿ���Բ��(����Բ��)
            if (distance_squared <= radius * radius) {
                printf("(%d,%d)", x, y);
                count++;

                //ÿ��ӡʮ���㻻�У������Ķ�
                if (count % 10 == 0) {
                    printf("\n");
                }
            }
        }
    }

    printf("\n\nԲ�ڣ�����Բ�ϣ�����%d����\n", count);
    return 0;
}