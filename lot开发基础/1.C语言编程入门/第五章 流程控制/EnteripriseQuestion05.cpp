/**
*模拟 ATM 取款过程：
1. 提示输入密码（最多 3 次，超过则提示 “密码错误，请取卡”）。
2. 密码正确（假设为 111111），提示输入取款金额。
3. 仅支持输出 100 元纸币，金额需在 100~1000 元之间。
4. 金额符合要求则打印取款数，提示 “交易完成，请取卡”；否则提示错误。
*/

#include "stdio.h"

#define PASSWORD 111111 //预设密码
#define MAX_ATTEMPTS 3 // 最大尝试次数
#define MIN_AMOUNT 100 //最小取款金额
#define MAX_AMOUNT 1000 //最大取款金额
#define DENOMINATION 100 //纸币面额

int main() {
    int password_attempt;
    int attempts = 0;

    //密码验证循环
    while (attempts < MAX_AMOUNT) {
        printf("请输入密码:");
        scanf("%d", &password_attempt);
        attempts++;

        if (password_attempt == PASSWORD) {
            int amount;
            printf("密码正确\n");

            //取款金额处理
            printf("请输入取款金额：");
            scanf("%d", &amount);

            //金额验证
            if (amount >= MIN_AMOUNT && amount <= MAX_AMOUNT && amount % DENOMINATION == 0) {
                int notes = amount / DENOMINATION;
                printf("您取了%d张100元\n", notes);
                printf("交易完成，请取卡\n");
            } else {
                printf("金额必须是100的倍数且在100-1000元之间\n");
            }
            return 0;
        } else {
            printf("密码错误，您还有%d次尝试机会\n", MAX_ATTEMPTS - attempts);
        }
    }

    //超过最大尝试次数
    printf("密码错误，请取卡\n");
    return 1;
}