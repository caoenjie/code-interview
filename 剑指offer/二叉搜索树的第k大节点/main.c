/* 给定一棵二叉搜索树，请找出其中第k大的节点。

示例 1:
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4

示例 2:
输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4

限制：
1 ≤ k ≤ 二叉搜索树元素个数
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *create(struct TreeNode *head, int arr[], int len, int index)
{
    if(index >= len)
        return NULL;

    head = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    head->val = arr[index];
    head->left = head->right = NULL;
    head->left = create(head->left, arr, len, index*2 + 1);
    head->right = create(head->right, arr, len, index*2 + 2);
}

void show(struct TreeNode *head)
{
    if(head == NULL)
        return;
    show(head->left);
    printf("%d ", head->val);
    show(head->right);
}

void distroy(struct TreeNode *head)
{
    if(head == NULL)
        return;

    struct TreeNode *l ;
    struct TreeNode *r ;
    l = head->left;
    r = head->right;
    free(head);
    distroy(l);
    distroy(r);
}

// int *getarrry(struct TreeNode *head, int *returnSize)
// {
//     struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode*) * 1000);
//     int *arr = (int *)malloc(sizeof(int) * 10000);
//     struct TreeNode *p = head;
//     int top = -1;
//     *returnSize = 0;
//     while(p != NULL || top != -1)
//     {
//         if(p)
//         {
//             stack[++top] = p;
//             p = p->left;
//         }
//         else
//         {
//             p = stack[top--];
//             arr[(*returnSize)++] = p->val;
//             p = p->right;
//         }
//     }
//     return arr;
// }


// int kthLargest(struct TreeNode *root, int k)
// {
//     int size = 0;
//     int *arr = getarrry(root, &size);
//     return arr[size - k];
// }

int g_size;

void inorderTraversal(struct TreeNode *root, int *arr)
{
    if(root == NULL)
        return;
    inorderTraversal(root->left, arr);
    arr[g_size++] = root->val;
    inorderTraversal(root->right, arr);

}

int kthLargest(struct TreeNode *root, int k)
{
    g_size = 0;
    int *arr = (int *)malloc(sizeof(int) * 10000);
    memset(arr, 0, sizeof(arr)/sizeof(arr[0]));
    if(arr == NULL) return 0;
    inorderTraversal(root, arr);
    return arr[g_size - k];
}

int main()
{
    struct TreeNode *h;
    int arr[] = {5, 2, 6, 1, 3};
    h = create(h, arr, sizeof(arr)/sizeof(arr[0]), 0);
    show(h);
    printf("\n");
    printf("%d\n", kthLargest(h, 1));
    distroy(h);

    return 0;
}