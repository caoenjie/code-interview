/* 输入整数数组 arr ，找出其中最小的 k 个数。
例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]

限制：
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(void *a, void *b)
{
    return *((int *)a) - *((int *)b);
}

int *getLeastNumbers(int *arr, int arrSize, int k, int *returnSize)
{
    if(arrSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    qsort(arr, arrSize, sizeof(int), cmp);
    int *res = (int *)malloc(sizeof(int) * k);
    *returnSize = k;
    memcpy(res, arr, sizeof(int )*k);
    return res;
}

int main()
{
    int arr[3] = {2, 3, 1};
    int size;
    getLeastNumbers(arr, 3, 2, &size);

    return 0;
}