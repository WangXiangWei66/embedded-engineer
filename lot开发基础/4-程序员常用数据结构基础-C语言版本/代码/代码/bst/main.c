#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE -1

typedef unsigned int uint;
typedef int ElemType ;

int sum = 0;
ElemType datas[1024];

//描述二分查找树的一个节点
typedef struct Node
{
    ElemType data; //数据域
    struct Node *lChild; //指向左子树的指针
    struct Node *rChild; //指向右子树的指针

    //记录结点被入栈的次数
    int cntFlag;
}Node;

typedef Node * ElemType1;

#define QUEUE_INIT_LEN 10
#define QUEUEINCREMENT 10
typedef struct SqQueue
{
    ElemType1 *base; //存储堆上元素的地址空间的首地址
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
    s.base = (ElemType1 *)malloc(len * sizeof(ElemType1));

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
int is_empty_queue(SqQueue s)
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
    if (is_empty_queue(s) == TRUE)
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
    if (is_empty_queue(s) == TRUE)
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
int EnQueue(SqQueue *s, ElemType1 data)
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
int DeQueue(SqQueue *s, ElemType1 *data)
{
    if (NULL == s)
        return FALSE;
    if (is_empty_queue(*s) == TRUE)
    {
        printf("[%s %d] queue is empty ...\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    *data = s->base[s->front];
    s->front = (s->front + 1) % QUEUE_INIT_LEN; //队首指针往后移动

    return TRUE;
}


#define STACK_INIT_LEN 10
#define STACKINCREMENT 10

typedef struct SqStack{
    ElemType1 *top; //栈顶指针
    ElemType1 *base; //栈底指针，指向存储栈的空间的首地址
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
    s->base = (ElemType1 *)malloc(size * sizeof(ElemType1));
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
    s->base = (ElemType1 *)realloc(s->base, (s->stackLen + STACKINCREMENT)*sizeof(ElemType1));

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
int push(SqStack *s, ElemType1 data)
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
int pop(SqStack *s, ElemType1 *data)
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
    ElemType1 *t = s->top;
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
int get_top_elem(SqStack *s, ElemType1 *data) {
    if (NULL == s || NULL == data)
        return FALSE;

    //获取栈顶元素
    *data = *(s->top-1);
    return TRUE;
}

//描述一棵二分查找树
typedef struct Tree
{
    Node *root; //指向二分查找树的根节点的指针
}Tree;

/*
 * @brief 初始化一棵二分查找树
 * @return 返回二分查找树的指针
 * */
Tree* tree_init()
{
    Tree *t;
    t = (Tree *)malloc(sizeof(Tree));

    t->root = NULL;

    return t;
}

/*
 * @brief 创建一个新的结点
 * @param data 结点的数据域的值
 * @return 返回新创建的结点的地址
 * */
Node *create_node(ElemType data)
{
    Node *t = (Node *)malloc(sizeof(Node));

    t->data = data;
    t->lChild = NULL;
    t->rChild = NULL;
    t->cntFlag = 0;
    return t;
}

/*
 * @brief 插入一个结点，保持插入后的二分查找树依然是一棵二分查找树
 * @param root 二分查找树的根节点指针的地址（二级指针）
 * @param data 插入的结点上数据域的值
 * @return 成功返回TRUE， 失败返回FALSE
 * */
int bst_tree(Node **root, ElemType data)
{
    if (NULL == root)
    {
        printf("[%s %d] root is NULL\n", __FUNCTION__ , __LINE__);
        return FALSE;
    }

    //创建一个新的结点
    Node *t = create_node(data);

    //判断树是否为一棵空树，如果是一颗空树，新插入的结点就是树的根节点
    if (NULL == *root)
    {
        *root = t; //根节点指针指向新的结点
        return TRUE;
    }
#if 0
    //和根节点比较大小，如果比根节点小，插入到根节点的左子树中
    if (data < (*root)->data)
    {
        bst_tree(&((*root)->lChild), data);
    }
    else if (data > (*root)->data) //和根节点比较大小，如果比根节点大，插入到根节点的右子树中
    {
        bst_tree(&((*root)->rChild), data);
    } else
        return FALSE;
#endif

    //定义一个临时变量用来遍历二分查找树
    Node *tmp = *root;

    while (1)
    {
        //如果比遍历到的结点要小
        if (data < tmp->data)
        {
            //如果该结点恰好没有左子树，将新的结点当作该节点的左子树
            if (NULL == tmp->lChild)
            {
                tmp->lChild = t;
                break;
            }
            else//如果该结点有左子树，继续遍历该结点的左子树
            {
                tmp = tmp->lChild;
                continue;
            }
        }
        else if (data > tmp->data)//如果比遍历到的结点要大
        {
            //如果该结点恰好没有右子树，将新的结点当作该节点的右子树
            if (NULL == tmp->rChild)
            {
                tmp->rChild = t;
                break;
            }
            else//如果该结点有右子树，继续遍历该结点的右子树
            {
                tmp = tmp->rChild;
                continue;
            }
        } //如果与遍历到的结点相等
        else
        {
            return FALSE;  //退出遍历
        }

    }
    return TRUE;
}

//以先序的方式遍历一棵树
void pre_traversal(Node *root)
{
    if (NULL == root)
        return ;

    printf("%d\n", root->data); //打印根结点上的数据
    datas[sum] = root->data;
    sum++;
    pre_traversal(root->lChild);
    pre_traversal(root->rChild);

    return ;
}

//以非递归方式，先序的方式遍历一棵树
void pre_traversal1(Node *root)
{
    if (NULL == root)
        return ;

    //初始化一个栈
    SqStack *s = stack_init(STACK_INIT_LEN);

    //定义一个临时指针 遍历
    Node *tmp = root;
    while (1)
    {
        //如果栈为空并且出栈的结点的左子树和右子树全部为空 结束遍历
        if (is_empty(s)==TRUE && tmp->lChild==NULL && tmp->rChild==NULL)
        {
            printf("%d ", tmp->data);
            break;
        }

        //先将根节点的数据域打印出来
        printf("%d ", tmp->data);
        //将结点的右子树入栈
        if (tmp->rChild != NULL)
            push(s, tmp->rChild);
        //将结点的左子树入栈
        if (tmp->lChild != NULL)
            push(s, tmp->lChild);

        //出栈一个结点
        pop(s, &tmp);
    }
    printf("\n");
}

//中序的方式遍历一棵树 左根右
void infix_traversal(Node *root)
{
    if (NULL == root)
        return ;

    infix_traversal(root->lChild);
    printf("%d\n", root->data);
    datas[sum] = root->data;
    sum++;
    infix_traversal(root->rChild);
    return ;
}

//非递归方式 中序的方式遍历一棵树 左根右
void infix_traversal1(Node *root)
{
    if (NULL == root)
        return ;

    //初始化一个栈
    SqStack *s = stack_init(STACK_INIT_LEN);

    //定义一个临时指针 遍历
    Node *tmp = root;
    while (1)
    {
        //一直往左边遍历，只要遍历到的结点的左子树不为空，入栈
        while (tmp)
        {
            push(s, tmp);
            tmp = tmp->lChild;
        }

        if (is_empty(s) != TRUE)
        {
            //出栈
            pop(s, &tmp);
            printf("%d ", tmp->data);
            tmp = tmp->rChild;
        } else
        {
            break;
        }
    }
    printf("\n");
}

//后序的方式遍历一棵树
void epilogue_traversal(Node *root)
{
    if (NULL == root)
        return ;

    epilogue_traversal(root->lChild);
    epilogue_traversal(root->rChild);
    printf("%d\n", root->data);
    datas[sum] = root->data;
    sum++;
    return ;
}

//后序的方式遍历一棵树
void epilogue_traversal1(Node *root)
{
    if (NULL == root)
        return ;

    //初始化一个栈
    SqStack *s = stack_init(STACK_INIT_LEN);

    //定义一个临时指针 遍历
    Node *tmp = root;
    while (1)
    {
        //一直往左边遍历，只要遍历到的结点的左子树不为空，入栈
        while (tmp)
        {
            tmp->cntFlag++;
            push(s, tmp);
            tmp = tmp->lChild;
        }

        if (is_empty(s) != TRUE)
        {
            //出栈
            pop(s, &tmp);
            //判断该结点是否被入栈了两次
            if (tmp->cntFlag < 2)
            {
                tmp->cntFlag++;
                push(s, tmp); //重新入栈
                //遍历这个结点的右子树
                tmp = tmp->rChild;
            } else
            {
                tmp->cntFlag = 0;
                printf("%d ", tmp->data);
                tmp = NULL;
            }
        } else
            break;
    }
    printf("\n");
}

/*
 * @brief 查找二分查找树的最小值
 * @param root 树的根节点指针
 * @return 最小值
 * */
ElemType find_min(Node *root)
{
    if (NULL == root)
        return -1;

    //从根节点开始遍历，一直遍历左子树，直到某个结点的左子树为空
#if 0
    //非递归方式
    Node *tmp = root;
    while (tmp->lChild != NULL)
    {
        tmp = tmp->lChild;
    }
    return tmp->data;
#endif
    if (NULL == root->lChild)
        return root->data;
    find_min(root->lChild);
}

/*
 * @brief 查找二分查找树的最大值
 * @param root 树的根节点指针
 * @return 最大值
 * */
ElemType find_max(Node *root)
{
    if (NULL == root)
        return -1;

    //从根节点开始遍历，一直遍历右子树，直到某个结点的右子树为空
#if 1
    //非递归方式
    Node *tmp = root;
    while (tmp->rChild != NULL)
    {
        tmp = tmp->rChild;
    }
    return tmp->data;
#endif
#if 0
    if (NULL == root->rChild)
        return root->data;
    find_max(root->rChild);
#endif
}

/*
 * @brief 查找二分查找树中指定的结点
 * @param root 根节点
 * @param data 需要查找的结点的值
 * @return 成功返回查找到的结点的地址，失败返回NULL
 * */
Node *find_elem(Node *root, ElemType data)
{
    if (NULL == root)
    {
        printf("[%s %d] can not find element: %d\n", __FUNCTION__ , __LINE__, data);
        return NULL;
    }

#if 0
    Node *tmp = root;
    while (1)
    {
        //从根节点开始遍历，如果比遍历到的节点小
        if (data < tmp->data)
        {
            if (tmp->lChild == NULL) //并且该该节点没有左子树，认为结点不在树上
            {
                printf("[%s %d] can not find element: %d\n", __FUNCTION__ , __LINE__, data);
                return NULL;
            }
            else  //如果比遍历到的节点小并且该该节点有左子树，继续遍历左子树
            {
                tmp = tmp->lChild;
                continue;
            }
        }
        else if (data > tmp->data)//如果比遍历到的节点大
        {
            if (NULL == tmp->rChild) //并且该节点没有右子树，认为结点不在树上
            {
                printf("[%s %d] can not find element: %d\n", __FUNCTION__ , __LINE__, data);
                return NULL;
            }
            else   //如果比遍历到的节点大并且该节点有右子树，继续遍历右子树
            {
                tmp = tmp->rChild;
                continue;
            }
        } else  //如果跟遍历到的结点相等，找到
        {
            return tmp;
        }
    }
#endif

    if (data == root->data)
        return root;
    if (data < root->data)
        find_elem(root->lChild, data);
    else if (data > root->data)
        find_elem(root->rChild, data);
}

//使用队列对二分查找树进行按层次遍历
void level_travel(Node *root)
{
    if (NULL == root)
        return ;

    //初始化队列
    SqQueue s = sqQueue_init(QUEUE_INIT_LEN);

    Node *tmp = root;

    while (1)
    {
        //打印遍历到的结点
        printf("%d ", tmp->data);
        //将结点的左子树入队
        if (tmp->lChild != NULL)
            EnQueue(&s, tmp->lChild);
        //将结点的右子树入队
        if (tmp->rChild != NULL)
            EnQueue(&s, tmp->rChild);

        if (is_empty_queue(s) == TRUE)
            break;
        //出队
        DeQueue(&s, &tmp);
    }
    printf("\n");

}

int main() {
    //初始化一颗二分查找树
    Tree *t;
    t = tree_init();

    bst_tree(&(t->root), 9);
    bst_tree(&(t->root), 5);
    bst_tree(&(t->root), 13);
    bst_tree(&(t->root), 2);
    bst_tree(&(t->root), 7);
    bst_tree(&(t->root), 12);
    bst_tree(&(t->root), 15);
    bst_tree(&(t->root), 14);
    bst_tree(&(t->root), 4);
#if 0
    infix_traversal(t->root);

    int i;
    for (i = 0; i < sum; i++)
        printf("%d ", datas[i]);
    printf("\n");

    sum = 0;

    printf("min: %d\n", find_min(t->root));

    printf("max: %d\n", find_max(t->root));

    Node *tmp;
    tmp = find_elem(t->root, 13);
    if (tmp != NULL)
        printf("yes\n");
    else
        printf("no\n");
#endif

    //使用非递归的方式先序遍历
    pre_traversal1(t->root);
    infix_traversal1(t->root);
    epilogue_traversal1(t->root);

    level_travel(t->root);
    return 0;
}