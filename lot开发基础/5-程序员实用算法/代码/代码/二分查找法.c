#include <stdio.h>

/*
 * @brief 使用递归方式二分查找法
 * @param arr 需要查找的数组的首地址
 * @param start 需要查找部分的最左边元素的下标
 * @param end 需要查找部分的最右边元素的下标
 * @param key 需要查找的元素
 * @return 成功返回查找到的元素的下标，失败返回-1
 * */
int binary_search(int *arr, int start, int end, int key)
{
    if (NULL == arr)
        return -1;

    if (start > end)
        return -1;

    //找到需要查找部分的中间元素
    int mid = (start + end) / 2;
    //将需要查找的元素和中间元素比较大小，如果比中间元素小，在左半部分继续查找
    if (key < arr[mid])
    {
        binary_search(arr, start, mid-1, key);
    }
    //如果比中间元素大，在右半部分继续查找
    else if (key > arr[mid])
    {
        binary_search(arr, mid + 1, end, key);
    }
    else
        return mid; //如果找到了就返回下标
}

/*
 * @brief 使用非递归方式二分查找法
 * @param arr 需要查找的数组的首地址
 * @param start 需要查找部分的最左边元素的下标
 * @param end 需要查找部分的最右边元素的下标
 * @param key 需要查找的元素
 * @return 成功返回查找到的元素的下标，失败返回-1
 * */
int binary_search1(int *arr, int start, int end, int key)
{
    if (NULL == arr)
        return -1;
    while (start <= end)
    {
        int mid = (start + end)/2;

        if (key == arr[mid])
            return mid;

        if (key < arr[mid])
        {
            end = mid-1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
    }
    if (start > end)
        return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int ret;

    ret = binary_search1(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 10);
    printf("ret: %d\n", ret);
    return 0;
}
