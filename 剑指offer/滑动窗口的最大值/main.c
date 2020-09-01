/* 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7]
解释:

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

提示：
你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{
    if(numsSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int *res = (int *)malloc(sizeof(int) * numsSize-k);
    *returnSize = numsSize-k;
    int i = 0, j = k;
    for(; i <= numsSize - k && j <= numsSize; i++, j++)
    {
        int tmp = i;
        res[i] = nums[i];
        for(;tmp < j; tmp++)
        {
            if(res[i] < nums[tmp])
                res[i] = nums[tmp];
        }
    }
    return res;
}

int main()
{
    int arr[] = {1,3,-1,-3,5,3,6,7};
    int size;
    maxSlidingWindow(arr, sizeof(arr)/sizeof(arr[0]), 3, &size);
    return 0;
}