/* 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

示例 1:
输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]

示例 2:
输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
 
限制：
1 <= n <= 11
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

double *twoSum(int n, int *returnSize)
{
    int dp[15][70] = {0};

    for (int i = 1; i <= 6; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= 6 * i; j++)
        {
            for (int cur = 1; cur <= 6; cur++)
            {
                if (j - cur <= 0)
                {
                    break;
                }
                dp[i][j] += dp[i - 1][j - cur]; //第n个骰子的点数为cur，它与前n-1个筛子的点数和为某个确定的数时，共有多少种骰子点数的组合
            }
        }
    }
    int all = pow(6, n);
    int count = 0;
    double *res = (double *)malloc(sizeof(double) * (6 * n + 1));
    for (int i = n; i <= 6 * n; i++)
    { //最小点数为n个骰子全为1，最大全为6
        res[i - n] = dp[n][i] * 1.0 / all;
        count++;
    }
    *returnSize = count;
    return res;
}

int main()
{
}