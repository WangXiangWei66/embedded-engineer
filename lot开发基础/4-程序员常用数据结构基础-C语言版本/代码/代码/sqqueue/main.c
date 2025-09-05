#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE -1

typedef int ElemType;

typedef unsigned int uint;

#define QUEUE_INIT_LEN 10
#define QUEUEINCREMENT 10
typedef struct SqQueue
{
    ElemType *base; //存储堆上元素的地址空间的首地址
    uint front; //队首指针
    uint rear; //队尾指针
}SqQueue;

/*
 * @brief 初始化一个顺序队列
 * @param len 顺序队列的初始化长度（可以存储的元素的最大个数）
 * @return 返回初始化的顺序队列
 * */
SqQueue sqQueue_init(uint len)
{
    SqQueue s;
    s.base = (ElemType *)malloc(len * sizeof(ElemType));

    s.front = s.rear = 0;

    return s;
}

/*
 * @brief 获取顺序队列的长度
 * @param s 顺序队列
 * @return 顺序队列的长度
 * */
int sqQueue_length(SqQueue s)
{
    return s.rear - s.front;
}

/*
 * @brief 判断顺序队列是否为空
 * @param 顺序队列
 * @return 为空返回TRUE，不为空返回FALSE
 * */
int is_empty(SqQueue s)
{
    if (s.front == s.rear)
        return TRUE;
    else
        return FALSE;
}

/*
 * @brief 判断顺序队列是否为满
 * @param 顺序队列
 * @return 为满返回TRUE，不为满返回FALSE
 * */
int is_full(SqQueue s)
{
    if ((s.rear + 1) % QUEUE_INIT_LEN == s.front)
        return TRUE;
    else
        return FALSE;
}

/* @brief 输出顺序队列中的所有的元素
 * @param s 需要输出的队列的结构体
 * @return 成功返回TRUE，失败返回FALSE
 * */
int print_queue(SqQueue s)
{
    if (is_empty(s) == TRUE)
        return FALSE;

    int i = s.front;
    while (i%QUEUE_INIT_LEN != s.rear)
    {
        printf("%d ", s.base[i]);
        i++;
    }
    printf("\n");
    return TRUE;
}

/*
 * @brief 输出顺序队列中的元素
 * @param s 需要输出顺序队列
 * @return 成功返回TRUE，失败返回FALSE
 * */
int print_SqQueue(SqQueue s)
{
    if (is_empty(s) == TRUE)
    {
        printf("[%s %d] SqQueue is empty\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }
    int i = s.front;
    while (i != s.rear)
    {
        printf("%d ", s.base[i]);
        //i 指向下一个位置
        i = (i+1)%QUEUE_INIT_LEN;
    }
    printf("\n");
    return TRUE;
}

/*  @brief 循环顺序队列入队
 *  @param data 需要入队得元素
 *  @return 成功返回TRUE， 失败返回FALS
*/
int EnQueue(SqQueue *s, ElemType data)
{
    if (NULL == s)
    {
        printf("[%s %d] s is NULL\n", __FUNCTION__ ,__LINE__);
        return FALSE;
    }

    //将需要入队的元素保存在队尾指针rear所指向的空间中
    s->base[s->rear] = data;
    //队尾指针rear 往后移动一个位置
    s->rear = (s->rear + 1) % QUEUE_INIT_LEN;

    return TRUE;
}

/*
 * @brief 循环顺序队列出队
 * @param data 存储出队元素的指针
 * @return 成功返回TRUE， 失败返回FALSE
 * */
int DeQueue(SqQueue *s, ElemType *data)
{
    if (NULL == s)
        return FALSE;
    if (is_empty(*s) == TRUE)
    {
        printf("[%s %d] queue is empty ...\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    *data = s->base[s->front];
    s->front = (s->front + 1) % QUEUE_INIT_LEN; //队首指针往后移动

    return TRUE;
}

int main() {

    //初始化/创建一个顺序队列
    SqQueue  s;
    s = sqQueue_init(QUEUE_INIT_LEN);

    if (is_empty(s) == TRUE)
        printf("empty\n");
    else
        printf("No\n");

    int i = 0;
    for (i = 0; i < 5; i++)
        EnQueue(&s, i); // 0 1 2 3 4
    print_queue(s);

    return 0;
}
