/* 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
 
限制：
0 <= 链表长度 <= 10000
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void add(struct ListNode *h, int n)
{
    struct ListNode *s = h;
    while (s->next != NULL)
        s = s->next;

    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val = n;
    p->next = NULL;
    s->next = p;

    return;
}

void show(struct ListNode *h)
{
    struct ListNode *p = h;
    p = p->next;
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    return;
}

void distroy(struct ListNode *h)
{
    while (h != NULL)
    {
        struct ListNode *p = h;
        h = h->next;
        free(p);
    }
}

int *reversePrint(struct ListNode *head, int *returnSize)
{
    if (head == NULL)
    {
        *returnSize = 0;
        return malloc(sizeof(int) * 10000);
    }
    int *arr = reversePrint(head->next, returnSize);
    arr[(*returnSize)++] = head->val;
    return arr;
}

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *pre = NULL, *cur = head->next;
    while(cur != NULL)
    {
        struct ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    struct ListNode *h = (struct ListNode *)malloc(sizeof(struct ListNode));
    h->next = pre;
    show(h);
    return pre;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = -9999;//head node
    head->next = NULL;
    for (int i = 1; i < 6; i++)
        add(head, i);
    show(head);
    printf("reverse.............\n");
    reverseList(head);
    distroy(head);
    return 0;
}
