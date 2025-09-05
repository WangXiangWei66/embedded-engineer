#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE -1

typedef unsigned int uint;
typedef char ElemType;

typedef struct StackNode
{
    ElemType data; //数据域
    struct StackNode *next;
}StackNode, *LinkStack;

/*
 * @brief 初始化一个链式栈
 * @return 返回链式栈的栈顶指针
 * */
LinkStack stack_init()
{
    LinkStack s;
    //因为没有头结点，因此初始化链式栈时因为栈为空，所以栈顶指针赋值为NULL
    s = NULL;
    return s;
}

//每次入栈都需要改变 栈顶指针的值，因为栈顶指针永远指向链表上的第一个数据节点
int push(LinkStack *s, ElemType data)
{
    if (NULL == s)
    {
        printf("[%s %d] s is NULL \n", __FUNCTION__ ,__LINE__);
        return FALSE;
    }

    //创建一个新的节点
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = data;

    p->next = *s;
    //让栈顶指针指向新的结点，因为新的节点是链表上的第一个结点了
    *s = p;
    return TRUE;
}

int print_stack(LinkStack s)
{
    if (NULL == s)
    {
        printf("[%s %d] s is NULL \n", __FUNCTION__ ,__LINE__);
        return FALSE;
    }

    StackNode *t = s;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
    return TRUE;
}

/*
 * @brief 出栈
 * @param s 栈顶指针的地址
 * @param data 需要出栈的元素
 * @return 成功返回TRUE，失败返回FALSE
 * */
int pop(LinkStack *s, ElemType *data)
{
    if (NULL == s || NULL == data)
    {
        printf("[%s %d] s is NULL \n", __FUNCTION__ ,__LINE__);
        return FALSE;
    }

    //1、去除栈顶的元素
    *data = (*s)->data;

    //2、记住栈顶指针
    StackNode *t = *s;

    //3、栈顶指针指向新的栈顶
    *s = (*s)->next;

    //4、释放原来的栈顶元素
    free(t);

    return FALSE;
}

/*
 * @brief  销毁链式栈
 * @param s 栈顶指针的地址
 * @return 成功返回TRUE，失败返回FALSE
 * */
int stack_destroy(LinkStack *s)
{
    if (NULL == s || NULL == *s)
    {
        printf("[%s %d] s is NULL \n", __FUNCTION__ ,__LINE__);
        return FALSE;
    }

    StackNode *t = *s;
    while (t != NULL)
    {
        //栈顶指针指向需要销毁的结点的下一一个结点
        *s = (*s)->next;
        //释放原来的栈顶元素
        free(t);
        //t 指向新的栈顶
        t = *s;
    }
    *s = NULL;

    return TRUE;
}

//数值转换
void conversion()
{
    LinkStack s = stack_init();

    uint num; //需要转换的十进制数字
    uint N; //进制

    printf("plz input A num: ");
    scanf("%d", &num);

    printf("plz input decimal(2 8 16): ");
    scanf("%d", &N);

    uint ret;
    while (num)
    {
        //计算num和N取模的结果，并且将结果入栈
        ret = num % N;
        if (ret >= 0 && ret <= 9)
            push(&s, ret+'0');
        else if (ret >= 10 && ret <= 15)
            push(&s, ret-10+'A');

        num = num / N;
    }

    char data;
    while (s)
    {
        pop(&s, &data);
        printf("%c", data);
    }
    printf("\n");
}

//括号匹配
int brackets_match()
{
    char *str = (char *)malloc(100);

    //初始化一个栈
    LinkStack s = stack_init();

    printf("plz input A expression: ");
    scanf("%s", str);

    //遍历整个表达式
    int i = 0;
    char f;
    while (str[i] != '\0')
    {
        //如果是左括号就直接入栈
        if (str[i] == '(' || str[i] == '[')
        {
            push(&s, str[i]);
            i++;
            continue;
        }

        //如果是右括号 出栈
        if (str[i] == ')')
        {
            pop(&s, &f);
            if (f == '(')
            {
                i++;
                continue;
            } else
                return FALSE;
        }

        if (str[i] == ']')
        {
            pop(&s, &f);
            if (f == '[')
            {
                i++;
                continue;
            } else
                return FALSE;
        }

        i++;
    }

    if (s == NULL)
        return TRUE;
    else
        return FALSE;
}

int main() {

    //conversion();
    int ret;
    ret = brackets_match();

    if (ret == TRUE)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}
