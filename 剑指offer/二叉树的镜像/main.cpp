#include <iostream>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void create(struct TreeNode *&head, int arr[], int len, int index)
{
    if (index >= len)
        return;
    head = new TreeNode;
    head->val = arr[index];
    head->left = head->right = NULL;
    create(head->left, arr, len, index * 2 + 1);
    create(head->right, arr, len, index * 2 + 2);
}

void show(struct TreeNode *&head)
{
    if (head == NULL)
        return;
    std::cout << head->val << " ";
    show(head->left);
    show(head->right);
}

void distroy(struct TreeNode *&head)
{
    if (head == NULL)
        return;
    TreeNode *l = head->left;
    TreeNode *r = head->right;
    delete head;
    distroy(l);
    distroy(r);
}

struct TreeNode *mirrorTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    std::swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
    return root;
}

struct TreeNode *mirrorTree(struct TreeNode *root)
{
    if(root == NULL)
        return NULL;
    TreeNode *tmp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(tmp);
    return root;
}


/*

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
 */
int main()
{
    int root[] = {4, 2, 7, 1, 3, 6, 9};
    TreeNode *head;
    create(head, root, 7, 0);
    show(head);
    mirrorTree(head);
    std::cout << std::endl;
    show(head);
    distroy(head);

    return 0;
}