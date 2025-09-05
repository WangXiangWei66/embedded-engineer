#include <stdio.h>

#define TRUE 0
#define FALSE -1

/*
 * @brief 对一个数组进行冒泡法排序,升序排序
 * @param arr 接收需要排序的数组的首地址
 * @param len 数组的长度
 * @return 成功返回TRUE 失败返回FALSE
 * */
int bubble_sort(int *arr, int len)
{
    if (NULL == arr)
        return FALSE;

    int i, j;
    //比较 len-1趟
    for (i = 0; i < len-1; i++)
    {
        //每趟比较 len-1-i次
        for (j = 0; j < len-1-i; j++)
        {
            //每趟比较都从数组的第0个元素开始，相邻的两个元素比较大小，如果前面的比后面的大，则叫唤这两个元素
            if (arr[j] > arr[j+1])
            {
                int t;
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
    return TRUE;
}

/*
 * @brief 对一个数组进行选择排序,升序排序
 * @param arr 接收需要排序的数组的首地址
 * @param len 数组的长度
 * @return 成功返回TRUE 失败返回FALSE
 * */
int select_sort(int *arr, int len)
{
    if (NULL == arr)
        return FALSE;

    int i, j;
    int min; //保存最小值所在的位置
    //选择的趟数 len-1， i
    for (i = 0; i < len-1; i++)
    {
        min = i;
        //每趟从 下标为趟数的位置开始 遍历，一直遍历到数组的末尾  j
        for (j = i; j <= len-1; j++)
        {
            //每趟选择出一个最小值：假设 j位置的元素是最小，然后拿遍历到的每一个元素和最小值比较大小
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        //内循环结束，min指向了最小值所在的位置
        //交换最小值 和 a[i]
        int t;
        t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;
    }

    return TRUE;
}

/*
 * @brief 对一个数组进行插入排序,升序排序
 * @param arr 接收需要排序的数组的首地址
 * @param len 数组的长度
 * @return 成功返回TRUE 失败返回FALSE
 * */
int insert_sort(int *arr, int len)
{
    if (NULL == arr)
        return FALSE;

    int i, j, key;
    //将无序的序列中的元素依次插入到前面有序的序列中 , i
    for (i = 1; i <= len-1; i++)
    {
        //将 a[i]的值赋值给 key，拿key和前面升序序列中的元素进行比较（从右往左）
        key = arr[i];
        j = i - 1;

        //如果key比遍历到的元素要小则交换位置，直到遍历到一个 <= key元素或者将前面的有序序列遍历完毕，插入a[i]结束
        while (j>=0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    return TRUE;
}

/*
 * @brief 使用快速排序法对一个数组进行排序，升序
 * @param arr 接收需要排序的数组的首地址
 * @param start 需要排序的部分的最坐标的下标
 * @param end 需要排序的部分的的最右边的下标
 *  @return 成功返回TRUE 失败返回FALSE
 * */
int quick_sort(int *arr, int start, int end)
{
    if (NULL == arr)
        return FALSE;

    if (start >= end)
        return TRUE;

    //找基准值：将需要排序的部分的最左边的值当作基准值
    int key = arr[start];
    int i = start, j = end;

    while (i < j)
    {
        //从右边往左边找一个比基准值要小的填前面的坑
        while (i < j && arr[j] > key)
        {
            j--;
        }
        if (i < j)
        {
            arr[i] = arr[j]; //arr[j]找到的比基准值要小的，arr[j]变成了一个新的坑
        }

        //从左边往右边找一个比基准值要大的填后面的坑
        while (i < j && arr[i] < key)
        {
            i++;
        }
        if (i < j)
        {
            arr[j] = arr[i]; //arr[i]找到的比基准值要大的，来填arr[j]这个坑，arr[i]变成了一个新的坑
        }
    }
    //将基准值填到 i 和 j相遇的地方
    arr[i] = key;
    //一轮快排（挖坑填坑法）结束，无序的序列就被基准值分成了两部分，左边的比基准值小，右边的比基准值大
    //对左边部分进行快排
    quick_sort(arr, start, i - 1);
    //对右边部分进行快排
    quick_sort(arr, i+1, end);
}

#define PPP "sfsfslflslfslfslflsflslfslflsflslfsfsfsfs "

int main() {

    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };

   // bubble_sort(arr, sizeof(arr)/sizeof(arr[0]));
    //select_sort(arr, sizeof(arr)/sizeof(arr[0]));

    //insert_sort(arr, sizeof(arr)/sizeof(arr[0]));

    quick_sort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);

    int i;
    for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
