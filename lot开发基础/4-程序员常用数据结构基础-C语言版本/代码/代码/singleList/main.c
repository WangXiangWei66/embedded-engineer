#include <stdio.h>
#include <stdlib.h>

#define TRUE   0
#define FALSE -1

typedef int ElemType;

typedef unsigned int uint;

//定义链表上的一个结点
typedef struct LNode
{
    ElemType data; //数据域
    struct LNode *next; //指向当前结点的下一个结点的指针（这个指针保存了下一个结点的存储位置）
}LNode, *LinkList; //*P_LNode

/*
 * @brief 初始化一个链表
 * @return 返回链表的头指针
 * */
LinkList list_init()
{
    //创建一个头结点
    /*
    LNode *t;
    t = (LNode *)malloc(sizeof(LNode));

    LinkList L;
    L = t;
    */

    LinkList L;
    L =  (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    return L;
}

/*
 * @brief 头插法插入一个结点
 * @param head 需要插入的链表的头指针
 * @param pTail 保存尾指针的地址
 * @param data 需要插入的数据
 * @return 成功返回TRUE， 失败返回FALSE
 * */
int head_insert(LinkList head, LNode **pTail, ElemType data)
{
    if (NULL == head)
    {
        printf("[%s %d] head pointer is NULL ...\n",  __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //创建一个新的结点p
    LNode *p;
    p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    p->next = NULL;

    //判断链表是否为空
    if (NULL == head->next)
    {
        //新插入的结点就是链表上的第一个结点，也是使用头插法时的最后一个结点
        *pTail = p; //tail = p;
    }
    //将新的结点p的next指向头节点的下一个结点（head->next）
    p->next = head->next;

    //头节点的next指向新的结点p
    head->next = p;

    return TRUE;
}

/*
 * @brief 输出链表中的所有结点
 * @param head 链表的头指针
 * @return 成功返回TRUE，失败返回FALSE
 * */
int print_list(LinkList head)
{
    if (NULL == head)
    {
        printf("[%s %d] head pointer is NULL ...\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //使用临时指针指向链表上的第一个数据结点（就是头节点的下一个结点）
    LNode *tmp;
    tmp = head->next;

    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        //让tmp指针指向下一个结点
        tmp = tmp->next;
    }
    printf("\n");
    return TRUE;
}

/*
 * @brief 使用尾插法插入一个结点
 * @param head 链表的头指针
 * @param pTail 存储尾指针的地址
 * @param data 需要插入的元素
 * @return 成功返回TRUE，失败返回FALSE
 * */
int tail_insert(LinkList head, LNode **pTail, ElemType data)
{
    if (NULL == head)
    {
        printf("[%s %d] head pointer is NULL ...\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //创建一个新的结点
    LNode *p;
    p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    p->next = NULL;

    //如果链表为空，新插入的第一个结点就是尾结点
    if (NULL == head->next)
    {
        *pTail = p;
        head->next = p;
        return TRUE;
    }

    //让尾指针的next 指向新的结点
    (*pTail)->next = p; // *pTail->next
    //让尾指针指向新的结点（新插入的结点就变成了链表上的尾结点）
    *pTail = p;

    return TRUE;
}

/*
 * @brief 获取链表上的指定的元素
 * @param head 链表的头指针
 * @param data 需要获取的元素的值
 * @return 成功返回元素所在的结点的地址，失败返回NULL
 * */
LNode *get_elem(LinkList head, ElemType data)
{
    if (NULL == head)
    {
        printf("[%s %d] head pointer is NULL ...\n", __FUNCTION__ , __LINE__);
        return NULL;
    }

    //使用一个临时指针指向链表上的第一个数据结点
    LNode *t;
    t = head->next;

    while (t != NULL)
    {
        //printf("%d\n", t->data);
        //将遍历到的结点上的数据域和需要查找的数据进行比较
        if (t->data == data)
            return t; //返回遍历到的结点的地址
        t = t->next;
    }

    printf("[%s %d] can not find elem: %d\n", __FUNCTION__ , __LINE__, data);
    return NULL; //return t;
}

/*
 * @brief 根据位置查找链表上的结点
 * @param head 链表的头指针
 * @param index 需要查找的位置
 * @return 成功返回结点的地址，失败返回NULL
 * */
LNode *get_elem_by_index(LinkList head, uint index)
{
    if (NULL == head)
    {
        printf("[%s %d] head pointer is NULL ...\n", __FUNCTION__ , __LINE__);
        return NULL;
    }

    //使用临时变量指向第一个数据结点
    LNode *t;
    t = head->next;

    int i = 1;
    //使用t遍历链表，每遍历一个结点判断遍历的次数是否达到 并且判断是否整个链表遍历完毕
    while (i < index && t != NULL)
    {
        i++;
        t = t->next;
    }

    if (NULL == t) //查找的位置超过了链表的长度
    {
        printf("[%s %d] index out of range ...\n", __FUNCTION__, __LINE__);
        return NULL;
    }

    return t;
}

/*
 * @brief 删除指定位置的结点
 * @param head 需要删除的链表的头指针
 * @param pTail 需要删除的链表的尾指针地址
 * @param index 需要删除的元素的位置
 * @return 成功返回TRUE，失败返回FALSE
 * */
int delete_by_index(LinkList head, LNode **pTail, uint index)
{
    if (NULL == head)
    {
        printf("[%s %d] head pointer is NULL ...\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //使用临时指针t 对链表进行操作
    LNode *t = head->next;
    //使用临时指针p 保存遍历到的结点的前驱结点
    LNode *p = head;

    int i = 1;
    //对链表进行遍历
    while (i < index && t != NULL)
    {
        i++;
        t = t->next;
        p = p->next;
    }

    //如果整个链表都遍历完了
    if (NULL == t)
    {
        printf("[%s %d] index out of range ..\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //如果需要删除的结点恰好是尾结点
    if (NULL == t->next)
    {
        //释放尾结点的空间
        free(t);
        //让尾指针指向前驱结点
        *pTail = p;
        //新的尾结点的next赋值为NULL
        (*pTail)->next = NULL; //p->next = NULL;
        return TRUE;
    }
    //如果要删除的结点时中间结点
    p->next = t->next;
    free(t);

    return TRUE;
}

/*
 * @brief 删除指定元素所在的结点
 * @param head 需要删除的链表的头指针
 * @param pTail 需要删除的链表的尾指针地址
 * @param data 需要删除的元素的值
 * @return 成功返回TRUE，失败返回FALSE
 * */
int delete_by_elem_value(LinkList head, LNode **pTail, ElemType data)
{
    if (NULL == head)
    {
        printf("[%s %d] head pointer is NULL ...\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //使用临时指针t 对链表进行操作
    LNode *t = head->next;
    //使用临时指针p 保存遍历到的结点的前驱结点
    LNode *p = head;

    while (t != NULL)
    {
        //将遍历到的结点 和 需要删除的元素的值比较
        if (t->data != data)
        {
            t = t->next;
            p = p->next;
            continue;
        }

        //判断需要删除的结点是否为尾结点
        if (NULL == t->next)
        {
            free(t);
            *pTail = p;
            (*pTail)->next = NULL;
            break;
        }
        //如果需要删除的结点是中间结点
        p->next = t->next;
        t = p->next;
    }

    return TRUE;
}

/*
 * @brief 在指定位置插入一个元素
 * @param head 需要插入的链表的头指针
 * @param index 需要插入的元素的位置
 * @param data 需要插入的元素的值
 * @return 成功返回TRUE，失败返回FALSE
 * */
int insert_by_index(LinkList head, uint index, ElemType data)
{
    if (NULL == head)
    {
        printf("[%s %d] head pointer is NULL ...\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //使用临时指针t 对链表进行操作
    LNode *t = head->next;
    //使用临时指针p 保存遍历到的结点的前驱结点
    LNode *p = head;

    int i = 1;
    while (i < index && t != NULL)
    {
        i++;
        t = t->next;
        p = p->next;
    }

    //如果将整个链表遍历完毕依然没有遍历到对应的位置
    if (NULL == t)
    {
        printf("[%s %d] index out of range ..\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //创建一个新的结点n
    LNode *n = (LNode *)malloc(sizeof(LNode));
    n->next = NULL;
    n->data = data;
    //将遍历到的结点的前驱结点中的next 赋值为新的结点n
    p->next = n;
    //将新的结点的next指向遍历到的结点
    n->next = t;

    return TRUE;
}

int ascending_insert(LinkList head, LNode **pTail, ElemType data)
{
    if (NULL == head)
    {
        printf("[%s %d] head pointer is NULL ...\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //使用临时指针t 对链表进行操作
    LNode *t = head->next;
    //使用临时指针p 保存遍历到的结点的前驱结点
    LNode *p = head;

    //创建一个新的结点n
    LNode *n = (LNode *)malloc(sizeof(LNode));
    n->next = NULL;
    n->data = data;

    //遍历整个链表
    while (t != NULL)
    {
        //直到找到一个比data要大的结点
        if (t->data <= data)
        {
            t = t->next;
            p = p->next;
            continue;
        }
        //找到了一个比data要大的结点
        p->next = n;
        n->next = t;
        break;
    }
    //如果将整个链表都遍历完毕了依然没有找到比data要大的结点，直接将该结点插入到链表的末尾
    if (NULL == t)
    {
        p->next = n;
        *pTail = n;
    }
    return TRUE;
}

/*
 * @brief 销毁链表
 * @param head 需要销毁的链表的头指针
 * @return 成功返回TRUE， 失败返回FALSE
 * */
int list_destroy(LinkList head)
{
    if (NULL == head)
    {
        printf("[%s %d] head pointer is NULL ...\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    LNode *t = head->next;

    while (t != NULL)
    {
        head->next = t->next;
        free(t);
        t = head->next;
    }
    //把头结点也释放掉
    free(head);
    return TRUE;
}

int main() {

    //创建一个链表 / 初始化一个链表
    LinkList head = list_init();

    //定义一个指针 指向链表的最后一个结点（尾结点）
    LNode *tail = NULL;

    int i;
    for (i = 0; i < 10; i++)
        head_insert(head, &tail, 100+i*2);
    print_list(head);

    printf("tail: %d\n", tail->data);

    for (i = 0; i < 10; i++)
        tail_insert(head, &tail, 100+i*2);
    print_list(head);
    printf("tail: %d\n", tail->data);

    LNode *t;
    t = get_elem(head, 300);
    if (t != NULL)
        printf("t: %d\n", t->data);

    t = get_elem_by_index(head, 30);
    if (t != NULL)
        printf("t: %d\n", t->data);
    else
        printf("index out of range ...\n");

    delete_by_index(head, &tail, 5);
    print_list(head);

    delete_by_index(head, &tail, 19);
    print_list(head);

    delete_by_index(head, &tail, 1);
    print_list(head);

    delete_by_index(head, &tail, 20);
    print_list(head);


    //创建一个链表 / 初始化一个链表
    LinkList head1 = list_init();
    //定义一个指针 指向链表的最后一个结点（尾结点）
    LNode *tail1 = NULL;

  //  head_insert(head1, &tail1, 100);
  //  print_list(head1);
    delete_by_index(head1, &tail1, 1);
    print_list(head1);

    delete_by_elem_value(head, &tail, 100);
    print_list(head);

    delete_by_elem_value(head, &tail, 116);
    print_list(head);

    delete_by_elem_value(head, &tail, 102);
    print_list(head);

    insert_by_index(head, 4, 107);
    print_list(head);

    insert_by_index(head, 1, 200);
    print_list(head);

    //创建一个链表 / 初始化一个链表
    LinkList head2 = list_init();
    //定义一个指针 指向链表的最后一个结点（尾结点）
    LNode *tail2 = NULL;

    ascending_insert(head2, &tail2, 100);
    print_list(head2);

    ascending_insert(head2, &tail2, 200);
    print_list(head2);

    ascending_insert(head2, &tail2, 150);
    print_list(head2);

    return 0;
}
