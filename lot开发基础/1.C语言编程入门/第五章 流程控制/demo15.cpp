#include<stdio.h>
#include<stdbool.h> //为了使用bool类型

int main() {
    const int n = 100;
    bool is_prime[n + 1];//数组索引对应数字,is_prime表示i是否为质数
    //初始化，假设所有的数都是质数
    for (int i = 2; i <= n; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;

    //埃拉托四尼筛法
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            //将i的倍数标记为非质数
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    printf("2-100的质数有：\n");
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            printf("%d\n", i);
        }
    }
    printf("\n");
    return 0;
}