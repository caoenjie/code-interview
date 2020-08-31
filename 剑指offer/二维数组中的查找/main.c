/* 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:
现有矩阵 matrix 如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

给定 target = 5，返回 true。
给定 target = 20，返回 false。

限制：
0 <= n <= 1000
0 <= m <= 1000
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool findNumberIn2DArray(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    if(matrixSize == 0 || matrixColSize[0] == 0)
        return false;

    int i = 0, j = matrixColSize[0] - 1;

    while(i < matrixSize && j >= 0)
    {
        if(matrix[i][j] == target)
            return true;
        else if(matrix[i][j] > 0)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{
    int arr[5][5] =
    {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int matrixSize = 5;
    int matrixColSize[5] = {5, 5, 5, 5, 5};
    if(findNumberIn2DArray(arr, matrixSize, matrixColSize, 5))
        printf("good\n");

    return 0;
}