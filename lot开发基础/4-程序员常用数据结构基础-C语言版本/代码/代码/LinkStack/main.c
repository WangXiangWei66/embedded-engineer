#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE -1

typedef unsigned int uint;
typedef int ElemType;

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

int main() {
    LinkStack s = stack_init(); //s是个指针类型  栈顶指针  代表一个链式栈

    int i;
    for (i = 0; i < 10; i++)
        push(&s, 100 + 2*i);

    print_stack(s);

    int data;
    pop(&s, &data);
    printf("%d\n", data);

    pop(&s, &data);
    printf("%d\n", data);

    while (s != NULL) {
        pop(&s, &data);
        printf("%d\n", data);
    }

    return 0;
}
