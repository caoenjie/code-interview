/* 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3

示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false

限制：
0 <= 节点个数 <= 1000
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
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool cmp(struct TreeNode *left, struct TreeNode *right)
{
    if(left == NULL && right == NULL)
        return true;
    else if(left == NULL || right == NULL)
        return false;
    else if(left->val != right->val)
        return false;
    return cmp(left->left, right->right) && cmp(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root)
{
    if(root == NULL)
        return true;
    return cmp(root->left, root->right);
}

int main()
{

    return 0;
}