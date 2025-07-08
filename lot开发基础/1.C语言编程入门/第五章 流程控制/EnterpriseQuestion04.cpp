//某人有 100,000 现金，每次经过路口需交费：现金 > 50,000 时交 5%，≤50,000 时交 5,000，求可经过多少次路口。
#include <stdio.h>

int main() {
    double cash = 100000.0; //初始现金
    int count = 0; //经过路口次数

    //只要现金足够支付当前费用，就继续经过路口
    while (1) {
        double fee;
        if (cash > 50000) {
            fee = cash * 0.05; //5%的费用
        } else {
            fee = 5000; //固定5000费用
        }

        if (cash < fee) {
            break;  // 现金不足，跳出循环
        }
        cash -= fee;  //扣除费用
        count++;   //次数加1
    }

    printf("可经过%d次路口，剩余现金: %.2f元\n", count, cash);
    return 0;
}