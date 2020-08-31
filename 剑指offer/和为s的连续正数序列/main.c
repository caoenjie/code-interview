/* 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

示例 1：
输入：target = 9
输出：[[2,3,4],[4,5]]

示例 2：
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 
限制：
1 <= target <= 10^5 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **findContinuousSequence(int target, int *returnSize, int **returnColumnSizes)
{
    if(target/2 == 0) return NULL;
    int i = 1, j = 1, sum = 0;
    int len = target/2;
    int **arr = (int **)malloc(sizeof(int *) * (target/2));
    *returnColumnSizes = (int *)malloc(sizeof(int ) * (target/2));
    *returnSize = 0;

    while(i <= len)
    {
        if(sum < target)
        {
            sum += j;
            j++;
        }
        else if(sum > target)
        {
            sum -= i;
            i++;
        }
        else
        {
            arr[*returnSize] = (int*)malloc(sizeof(int) * (j-i));
            (*returnColumnSizes)[*returnSize] = j-i;
            for(int k = i; k < j; k++)
                arr[*returnSize][k-i] = k;
            (*returnSize)++;
            sum -= i;
            i++;
        }
    }
    return arr;
}

int main()
{
    int returnSize;
    int **returnColumnsize;
    int **arr = findContinuousSequence(9, &returnSize, returnColumnsize);

    return 0;
}