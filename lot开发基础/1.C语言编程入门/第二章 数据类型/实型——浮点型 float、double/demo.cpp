#include <stdio.h>

int main() {
    //传统方式赋值
    float a = 3.14f;
    double b = 3.14;
    printf("a = %f\n", a);
    printf("b = %lf\n", b);

    //科学法赋值
    a = 3.2e3f;
    printf("al = %f\n", a);

    a = 100e-3f;
    printf("a2 = %f\n", a);//默认保留6位小数

    a = 3.1415926f;
    printf("a3 = %f\n", a);

    return 0;
}