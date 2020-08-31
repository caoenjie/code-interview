/* 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2

限制：
1 <= 数组长度 <= 50000
 */

#include <stdio.h>
#include <stdlib.h>

/* 数组排序法：
将数组 nums 排序，由于众数的数量超过数组长度一半，因此 数组中点的元素 一定为众数。
此方法时间复杂度 O(N log_2 N) O(NlogN)。

摩尔投票法：
核心理念为 “正负抵消” ；时间和空间复杂度分别为 O(N)O(N) 和 O(1)O(1)。

 */

int majorityElement(int *nums, int numsSize)
{
    int ret;
    int votes = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(votes == 0)
        {
            ret = nums[i];
        }
        if(nums[i] == ret)
            votes++;
        else
            votes--;
    }
    return ret;
}

int main()
{
    int arr[] = {6,5,5};
    printf("%d\n", majorityElement(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}