#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR -1
#define OK    0

typedef int ElemType;
typedef unsigned int uint ;

//描述顺序表的结构体
typedef struct
{
    //保存数据元素的容器
    ElemType *elem;

    //实际存储的元素的个数/顺序表的长度
    uint length;

    //顺序表的容量：最多存储数据元素的个数
    uint listSize;
}SqList;

/*
 * @brief 初始化顺序表
 * @param listSize 顺序表容量
 * @return 返回初始化好的顺序表
 * */
SqList SqList_init(uint listSize)
{
    SqList t;

    t.elem = (ElemType *)malloc(listSize*sizeof(ElemType));
    t.length = 0;
    t.listSize = listSize;

    return t;
}

/*
 * @brief 打印顺序表中的所有的元素
 * @param t 需要输出的顺序表
 * @return void
 * */
void print_SqList(SqList t)
{
    int i;
    printf("[%s %d] print_SqList: ", __FUNCTION__, __LINE__);
    //循环的次数：t.length
  //  printf("[%s %d] t.length: %d\n", __FUNCTION__, __LINE__, t.length);

    for (i = 0; i < t.length; i++)
    {
        printf("%d ", t.elem[i]);
    }
    printf("\n");
}

/*
 * @brief 获取顺序表中某个位置的元素
 * @param t 需要操作的顺序表
 * @param index 需要获取的元素的位置/下标
 * @return ElemType 获取到的元素
 * */
ElemType get_elem(SqList t, uint index)
{
    if (index >= t.length)
    {
        printf("[%s %d] index out of range ...\n", __FUNCTION__, __LINE__);
        return -1;
    }

    return t.elem[index];
}

/*
 * @brief 在顺序表中查找指定的元素
 * @param t 需要操作的顺序表
 * @param elem 需要查找的元素
 * @return int 成功返回值元素的下标，失败返回-1
 * */
int find_elem(SqList t, ElemType elem)
{
    int index = -1; //保存查找到的元素的下标， 默认顺序表没有存储需要查找的元素
    int i;
    for (i = 0; i < t.length; i++)
    {
        if (elem == t.elem[i])
        {
            //记录找到的元素的下标
            index = i;
            break; //如果找到了 就不继续往下找
        }
    }

    //如果整个顺序表都遍历一遍还是没有找到元素
   // if (i == t.length)
    //    index = -1;

    if (-1 == index)
        printf("[%s %d] Can not find elem: %d\n", __FUNCTION__ , __LINE__, elem);

    return index;
}

/*
 * @brief 销毁一个顺序表
 * @param t 需要销毁的顺序表指针
 * @return 成功返回OK, 失败返回ERROR
 * */
int SqList_destroy(SqList *t)
{
    if (NULL == t) // if (!t)
    {
        printf("[%s %d] SqList is NULL\n", __FUNCTION__ , __LINE__);
        return ERROR;
    }

    free(t->elem);
    t->length = 0;
    t->listSize = 0;

    return OK;
}

/*
 * @brief 删除指定位置的元素
 * @param t 需要操作的顺序表指针
 * @param index 需要删除的元素的下标
 * */
int locate_elem_delete(SqList *t, uint index)
{
    if (NULL == t)
    {
        printf("[%s %d] SqList is NULL\n", __FUNCTION__ , __LINE__);
        return ERROR;
    }

    if (index >= t->length)
    {
        printf("[%s %d]  index out of range \n", __FUNCTION__ , __LINE__);
        return ERROR;
    }

    // 如果要删除的元素位置为index，那么需要移动的元素的个数是： t->length - (index + 1)
    int i;
    for (i = 0; i < t->length - (index + 1); i++)
    {
        //将 第 index + i + 1 个元素 覆盖掉 第 index + i个元素
        t->elem[index + i] = t->elem[index + i + 1];
    }
    t->length--;

    return OK;
}

/*
 * @brief 将顺序表中指定的元素删除
 * @param t 需要操作的顺序表指针
 * @param elem 需要删除的元素
 * @return 成功返回OK，失败返回ERROR
 * */
int delete_designated_elem(SqList *t, ElemType elem)
{
    if (NULL == t)
    {
        printf("[%s %d] SqList is NULL\n", __FUNCTION__ , __LINE__);
        return ERROR;
    }

    int i = 0;

    while (i < t->length)
    {
        //将遍历到的元素 和需要删除的元素进行比较，如果不相等则继续往后遍历
        if (t->elem[i] != elem)
        {
            i++;
            continue;
        }

        //如果相等 则删除该元素：将该元素后面的所有的元素往前移动一个位置
        int j = 0;
        for (j = 0; j < t->length - (i+1); j++)
        {
            t->elem[i + j] =t->elem[i + 1 + j]; //将后面赋值给前面的元素
        }
        //一定要记得将顺序表的长度-1
        t->length--;
    }
    return OK;
}

/*
 * @brief 为顺序表扩容
 * @param t 需要扩容的顺序表指针
 * @return 成功返回OK，失败返回ERROR
 * */
int SqList_expand(SqList *t)
{
    if (NULL == t)
    {
        printf("[%s %d] SqList is NULL\n", __FUNCTION__ , __LINE__);
        return ERROR;
    }

    //将顺序表扩容到原来的2倍大小
    t->listSize *= 2;
    t->elem = (ElemType *)realloc(t->elem, t->listSize*sizeof(ElemType));

    return OK;
}

int elem_insert(SqList *t, uint index, ElemType elem)
{
    if (NULL == t)
    {
        printf("[%s %d] SqList is NULL\n", __FUNCTION__ , __LINE__);
        return ERROR;
    }
    //判断插入的位置是否合法
    if (index >= t->listSize)
    {
        printf("[%s %d] index out of range ...\n", __FUNCTION__ , __LINE__);
        return ERROR;
    }
    //判断顺序表是否满了，如果满了则扩容
    if (t->length == t->listSize)
        SqList_expand(t);

    //如果插入的位置超过了顺序表的长度，直接将数据插入到所指定的位置
    if (index >= t->length)
    {
        t->elem[t->length] = elem;
        t->length++;
        return OK;
    }

    //根据插入的位置计算需要移动的元素个数/次数 t->length - index
    int i;
    for (i = 0; i < t->length - index; i++)
    {
        //从最后一个元素开始移动
        t->elem[t->length-i] = t->elem[t->length-1-i];
    }
    //将需要插入的元素放置到插入的位置
    t->elem[index] = elem;

    t->length++;
    return OK;
}

int main() {
    SqList sl;

    sl = SqList_init(10);

    printf("length: %d, liseSize: %d\n", sl.length, sl.listSize);

    int i;
    for (i = 0; i < 10; i++)
    {
        sl.elem[i] = 100 + i;
        sl.length++;
    }
    print_SqList(sl);

    printf("%d\n", get_elem(sl, 10));

    printf("%d\n", find_elem(sl, 120));

  //  SqList_destroy(&sl);
 //   printf("length: %d, size: %d\n", sl.length, sl.listSize);

 //   SqList_destroy(NULL);

 /*
  * //删除指定位置的元素
    int ret;
    ret = locate_elem_delete(&sl, 11); //100 101 102 103
    if (ERROR == ret)
    {
        printf("call locate_elem_delete error\n");
    }
*/

    //删除指定的元素
    /*
    sl.elem[2] = 6;
    sl.elem[3] = 6;
    sl.elem[5] = 6;
    sl.elem[6] = 6;
    sl.elem[8] = 6;

    delete_designated_elem(&sl, 6);
     */

    elem_insert(&sl, 5, 200);

    print_SqList(sl);

    elem_insert(&sl, 15, 300);

    print_SqList(sl);
    return 0;
}
