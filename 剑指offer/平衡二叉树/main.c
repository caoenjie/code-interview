/* 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

示例 1:
给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false

限制：
1 <= 树的结点个数 <= 10000
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *create(struct TreeNode *root, int arr[], int size, int index)
{
    if (index >= size)
        return NULL;
    if (arr[index] == -1)
    {
        root = NULL;
        return NULL;
    }
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = arr[index];
    root->left = root->right = NULL;
    root->left = create(root->left, arr, size, index * 2 + 1);
    root->right = create(root->right, arr, size, index * 2 + 2);
    return root;
}

void show(struct TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->val);
    show(root->left);
    show(root->right);
}

void distroy(struct TreeNode *root)
{
    if (root == NULL)
        return;
    struct TreeNode *l = root->left;
    struct TreeNode *r = root->right;
    free(root);
    distroy(l);
    distroy(r);
}

#define MAX(a,b) (a) > (b) ? (a) : (b)
int TreeDeep(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    int leftDept = TreeDeep(root->left);
    int rightDept = TreeDeep(root->right);
    return MAX(leftDept + 1, rightDept + 1);
}

bool isBalanced(struct TreeNode *root)
{
    return !root ? true : abs(TreeDeep(root->left) - TreeDeep(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, -1, -1, 4, 4};
    struct TreeNode *root;
    root = create(root, arr, sizeof(arr) / sizeof(arr[0]), 0);
    // show(root);

    // if (isBalanced(root))
    //     printf("good\n");
    printf("%d\n", TreeDeep(root));
    distroy(root);

    return 0;
}