/* 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

限制：
0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    if (matrixSize == 0 || matrixColSize == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int len = matrixSize * matrixColSize[0];
    int *res = (int *)malloc(sizeof(int) * len);
    int index = 0;
    int row_up = -1, row_down = matrixSize, col_left = -1, col_right = matrixColSize[0];

    while(index < len)
    {
        //turn ——>
        for(int i = col_left+1; index < len && i < col_right; i++)
            res[index++] = matrix[row_up+1][i];

        row_up++;
        //trun ↓
        for(int i = row_up+1; index < len && i < row_down; i++)
            res[index++] = matrix[i][col_right-1];

        col_right--;

        //trun <——
        for(int i = col_right-1; index < len && i > col_left; i--)
            res[index++] = matrix[row_down-1][i];

        row_down--;

        //trun ↑
        for(int i = row_down-1; index < len && i > row_up; i--)
            res[index++] = matrix[i][col_left+1];

        col_left++;
    }
    *returnSize = index;
    return res;
}

int main()
{
    int **arr = (int **)malloc(sizeof(int *) * 3);
    for(int i = 0; i < 4; i++)
        arr[i] = (int *)malloc(sizeof(int) * 4);
    int num = 1;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
            arr[i][j] = num++;
    }
    // for(int i = 0; i < 3; i++)
    // {
    //     for(int j = 0; j < 4; j++)
    //         printf("%d ", arr[i][j]);
    // }

    int arr_col[3] = {4, 4, 4};
    int size;
    int *a = spiralOrder(arr, 3, arr_col, &size);

    // for(int i = 0; i < size; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    return 0;
}