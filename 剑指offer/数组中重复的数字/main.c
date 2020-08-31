/* 找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3
 
限制：
2 <= n <= 100000
 */

#include <stdio.h>
#include <stdlib.h>

int findRepeatNumber(int *nums, int numsSize)
{
    int *hash = (int *)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        if (hash[nums[i]] == 1)
        {
            return nums[i];
        }
        else
        {
            hash[nums[i]]++;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    printf("%d\n", findRepeatNumber(arr, sizeof(arr) / sizeof(arr[0])));

    return 0;
}