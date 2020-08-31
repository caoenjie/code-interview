/* 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

示例:
输入: [1,2,3,4,5]
输出: [120,60,40,30,24]

提示：
所有元素乘积之和不会溢出 32 位整数
a.length <= 100000
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int *constructArr(int *a, int aSize, int *returnSize)
{
    if(aSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int *res = (int *)malloc(sizeof(int) * aSize);
    *returnSize = aSize;
    int tmp = 1;
    res[0] = 1;
    for(int i = 1; i < aSize; i++)
    {
        res[i] = res[i-1]*a[i-1];
    }
    for(int i = aSize-2; i > -1; i--)
    {
        tmp *= a[i+1];
        res[i] *= tmp;
    }
    return res;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int size = 0;
    constructArr(a, 5, &size);

    return 0;
}