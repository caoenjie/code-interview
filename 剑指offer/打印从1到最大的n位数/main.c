/* 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

说明：

用返回一个整数列表来代替打印
n 为正整数
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *printNumbers(int n, int *returnSize)
{
    int *numlist;
    int maxnum = pow(10.0, n) - 1;
    numlist = (int *)malloc(sizeof(int) * maxnum);
    for(int i = 0; i < maxnum; i++)
        numlist[i] = i + 1;
    *returnSize = maxnum;
    return numlist;
}

int main()
{
    int size;
    int *l = printNumbers(1, &size);
    for(int i=0; i<size; i++)
        printf("%d ", l[i]);
    return 0;
}
