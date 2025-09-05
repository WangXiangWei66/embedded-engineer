#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE -1

typedef unsigned int uint;
typedef int ElemType;

#define STACK_INIT_LEN 10
#define STACKINCREMENT 10

typedef struct SqStack{
    ElemType *top; //栈顶指针
    ElemType *base; //栈底指针，指向存储栈的空间的首地址
    uint stackLen; //栈能够存储的最大的元素的个数
    uint len; //保存实际存储的元素的个数
}SqStack;

/*
 * @brief 初始化一个顺序栈
 * @param 初始顺序栈的长度
 * @return 返回初始化后的栈的指针
 * */
SqStack *stack_init(uint size)
{
    //创建一个栈
    SqStack *s = (SqStack *)malloc(sizeof(SqStack));

    //栈分配存储空间
    s->base = (ElemType *)malloc(size * sizeof(ElemType));
    s->top = s->base;

    s->stackLen = size;
    s->len = 0;

    return s;
}

/*
 * @brief 对栈进行扩容
 * @param s 需要扩容的栈指针
 * @return 成功返回TRUE， 失败返回FALSE
 */
int expand(SqStack *s)
{
    printf("[%s %d] SqStack expand ...\n", __FUNCTION__ , __LINE__);
    if (NULL == s)
    {
        printf("[%s %d] stack pointer is NULL ...\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //为栈的存储空间重新分配空间
    s->base = (ElemType *)realloc(s->base, (s->stackLen + STACKINCREMENT)*sizeof(ElemType));

    s->top = s->base + s->stackLen;

    s->stackLen += STACKINCREMENT;

    return TRUE;
}

/*
 * @brief 入栈
 * @param s 栈指针
 * @param data 需要入栈的元素
 * @return 成功返回TRUE， 失败返回FALSE
 * */
int push(SqStack *s, ElemType data)
{
    if (NULL == s)
    {
        printf("[%s %d] stack pointer is NULL ...\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //先判断栈是否为满
    if (s->top-s->base==s->stackLen)
    {
        printf("[%s %d] SqStack is FULL ..\n", __FUNCTION__ , __LINE__);
        //对顺序栈进行扩容
        expand(s);
    }
    //入栈
    *(s->top) = data;
    s->top++;
    //s->len++;
    return TRUE;
}

/*
 * @brief 出栈
 * @param s 栈指针
 * @param data 存放栈顶元素的指针
 * @return 成功返回TRUE， 失败返回FALSE
 * */
int pop(SqStack *s, ElemType *data)
{
    if (NULL == s || NULL == data)
    {
        printf("[%s %d] stack pointer is NULL ...\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //先让栈顶指针--，指向栈顶的元素
    s->top--;
    *data = *(s->top);

    return TRUE;
}


//遍历整个栈
int print_stack(SqStack *s)
{
    ElemType *t = s->top;
    while (t != s->base)
    {
       t--;
       printf("%d ", *t);
    }

    printf("\n");
}

//判断栈是否为空，如果为空返回TRUE，如果不为空返回FALSE
int is_empty(SqStack *s)
{
    if (s->top == s->base)
        return TRUE;
    return FALSE;
}

/*
 * @brief 清除一个栈
 * @param s 栈指针
 * @return 成功返回TRUE， 失败返回FALSE
 * */
int stack_clear(SqStack *s)
{
    if (NULL == s)
    {
        printf("[%s %d] stack pointer is NULL ...\n");
        return FALSE;
    }
    s->top = s->base;
    return TRUE;
}

/*
 * @brief 获得栈顶元素
 * @param s 栈指针
 * @param data 存放栈顶元素的指针
 * @return 成功返回TRUE， 失败返回FALSE
 * */
int get_top_elem(SqStack *s, ElemType *data) {
    if (NULL == s || NULL == data)
        return FALSE;

    //获取栈顶元素
    *data = *(s->top-1);
    return TRUE;
}
int main() {
    SqStack *s = stack_init(STACK_INIT_LEN);

    int i;
    for (i= 0; i < 20; i++)
        push(s, 100+i*2);

    print_stack(s);

    ElemType data;
    pop(s, &data);
    printf("%d\n", data);

#if 0
    //使用循环方式出栈
   // while (s->top != s->base)
   while (is_empty(s) != TRUE)
    {
        pop(s, &data);
        printf("%d\n", data);
    }
#endif

   int loop = s->top-s->base;
   //for (i = 0; i < loop; i++)
   for (i = 0; i < s->top-s->base; i++)
   {
       pop(s, &data);
       printf("%d\n", data);
   }

   return 0;
}
