/* 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

节点总数 <= 1000
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *create(struct TreeNode *head, int arr[], int len, int index)
{
    if (index >= len)
        return NULL;
    if (arr[index] == -1)
    {
        head = NULL;
        return NULL;
    }
    head = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    head->val = arr[index];
    head->left = head->right = NULL;
    head->left = create(head->left, arr, len, index * 2 + 1);
    head->right = create(head->right, arr, len, index * 2 + 2);
    return head;
}

void show(struct TreeNode *head)
{
    if (head == NULL)
        return;
    printf("%d ", head->val);
    show(head->left);
    show(head->right);
}

void distroy(struct TreeNode *head)
{
    if (head == NULL)
        return;
    struct TreeNode *l, *r;
    l = head->left;
    r = head->right;
    free(head->left);
    free(head->right);
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int **arr = (int *)malloc(sizeof(int) * 1000);
    struct TreeNode *queue[1000], *t;
    int level = 0;
    int l = 0, r = 0;
    queue[r++] = root;
    while(l != r)
    {
        (*returnColumnSizes)[level] = r - l;
        arr[level] = (int *)malloc(sizeof(int) * (r-l));
        for(int i = 0; i < (*returnColumnSizes)[level]; i++)
        {
            t = queue[l++];
            arr[level][i] = t->val;
            if(t->left)
                queue[r++] = t->left;
            if(t->right)
                queue[r++] = t->right;
        }
        level++;
    }
    *returnSize = level;
    return arr;
}

int main()
{
    int arr[] = {3, 9, 20, -1, -1, 15, 7};
    struct TreeNode *p = create(p, arr, sizeof(arr) / sizeof(arr[0]), 0);

    return 0;
}