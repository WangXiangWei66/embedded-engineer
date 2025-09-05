#include <stdio.h>
#include <stdlib.h>

#define TRUE   0
#define FALSE -1

typedef unsigned int uint;

typedef int ElemType;

typedef struct LNode{
    ElemType data;  //数据域
    struct LNode *next; //指针域，指向当前结点的直接后继（下一个结点）
}LNode, *LinkList; //LinkList的类型为 LNode *

LinkList list_init()
{
    LNode *t;
    t = (LNode *)malloc(sizeof(LNode)); //创建一个头结点
    t->next = NULL; //头结点的指针域为空

    LinkList head;  //定义一个头指针
    head = t; //头指针指向头结点
    return head;
}

int head_insert(LinkList head, LNode **pTail, ElemType data)
{
    if (NULL == head || NULL == pTail)
        return FALSE;

    //创建一个新的结点p
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    p->next = NULL;

    //链表为空
    if (NULL == head->next)
    {
        *pTail = p;
        p->next = head;
        head->next = p;
        return TRUE;
    }

    p->next = head->next;
    head->next = p;
    return TRUE;
}

int tail_insert(LinkList head, LNode **pTail, ElemType data)
{
    if (NULL == head || NULL == pTail)
        return FALSE;

    //创建一个新的结点p
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    p->next = NULL;

    //链表为空
    if (NULL == head->next)
    {
        *pTail = p;
        p->next = head;
        head->next = p;
        return TRUE;
    }

    //将原来的尾结点的next指向新的结点
    (*pTail)->next = p;
    //移动尾指针
    *pTail = p;
    (*pTail)->next = head;

    return TRUE;
}

int delete_by_index(LinkList head, LNode **pTail, uint index)
{
    if (NULL == head || NULL == pTail || 0 == index)
        return FALSE;

    int i = 1;
    LNode *t = head->next;
    LNode *pre = head;

    while (i < index && t->next != head)
    {
        i++;
        pre = pre->next;
        t = t->next;
    }

    if (i == index)
    {
        //如果需要删除的结点恰好是中间结点
        pre->next = t->next;
        free(t);

        //如果需要删除的结点恰好是最后一个结点
        if (t->next == head)
        {
            *pTail = pre;
        }
        return TRUE;
    }
    
}

int print_list(LinkList head)
{
    if (NULL == head)
        return FALSE;

    LNode *t = head->next;

    while (t != head)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
    return TRUE;
}

int main() {

    LinkList head;
    head = list_init();

    LNode *tail;
    tail = NULL;

    int i;
    for (i = 0; i < 10; i++)
        head_insert(head, &tail, 100+i*2);

    print_list(head);

    for (i = 0; i < 10; i++)
        tail_insert(head, &tail, 100+i*2);

    print_list(head);
    return 0;
}
