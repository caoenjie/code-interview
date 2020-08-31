/* 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：
“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
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
    if(head == NULL)
        return;
    printf("%d ", head->val);
    show(head->left);
    show(head->right);
}

void distroy(struct TreeNode *head)
{
    if(head == NULL)
        return;
    struct TreeNode *l, *r;
    l = head->left;
    r = head->right;
    free(head->left);
    free(head->right);
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if(root == NULL || root->val == p->val || root->val == q->val)
        return root;

    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left == NULL && right == NULL)
        return NULL;
    else if(left == NULL && right)
        return right;
    else if(right == NULL && left)
        return left;
    else
        return root;
}

int main()
{
    int arr[] = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    struct TreeNode *root;
    root = create(root, arr, sizeof(arr)/sizeof(arr[0]), 0);
    // show(root);
    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->val = 5;
    struct TreeNode *q = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    q->val = 4;
    struct TreeNode *tmp = lowestCommonAncestor(root, p, q);
    printf("%d\n", tmp->val);
    distroy(root);
    free(p);
    free(q);
    return 0;
}