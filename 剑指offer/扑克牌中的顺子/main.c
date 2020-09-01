/* 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

示例 1:
输入: [1,2,3,4,5]
输出: True

示例 2:
输入: [0,0,1,2,5]
输出: True

限制：
数组长度为 5 
数组的数取值为 [0, 13] .
 */

#include <stdio.h>
#include <stdbool.h>

bool isStraight(int *nums, int numsSize)
{
    int maxnum = 0;
    int minnum = 14;
    bool arr[15] = {0};
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == 0)
            continue;
        if(minnum > nums[i] && nums[i] != 0)
            minnum = nums[i];
        if(maxnum < nums[i])
            maxnum = nums[i];
        if(arr[nums[i]])
            return false;
        arr[nums[i]] = true;
    }
    return maxnum-minnum + 1 <= 5;

}

int main()
{
    // [11,8,12,8,10]
    int arr[] = {1, 2, 3, 4, 5};
    isStraight(arr, 5);

    return 0;
}