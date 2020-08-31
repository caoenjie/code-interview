/* 统计一个数字在排序数组中出现的次数。

示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: 2

示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: 0

限制：
0 <= 数组长度 <= 50000
 */
#include <stdio.h>

// int search(int *nums, int numsSize, int target)
// {
//     if (numsSize == 0)
//     {
//         return 0;
//     }
//     int res = 0;
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[i] == target)
//             res++;
//         if (nums[i] > target)
//             return res;
//     }
//     return res;
// }

/*
 * binary search
 */
int search(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1, mid, cnt = 0;
    while (left <= right)
    {
        mid = (right + left) >> 1;
        if (nums[mid] == target)
        {
            for (int i = mid - 1; i >= 0 && nums[i] == target; i--)
            {
                cnt++;
            }
            for (int i = mid; i < numsSize && nums[i] == target; i++)
            {
                cnt++;
            }
            break;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return cnt;
}

int main()
{

    return 0;
}