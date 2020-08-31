/* 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的.

示例1:
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

限制：
0 <= 链表长度 <= 1000
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void create(struct ListNode *l, int arr[], int len)
{
    struct ListNode *p = l;
    for (int i = 1; i < len; i++)
    {
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->val = arr[i];
        p->next = tmp;
        tmp->next = NULL;
        p = p->next;
    }
}

void show(struct ListNode *l)
{
    struct ListNode *p = l;
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
}

void distroy(struct ListNode *l)
{
    while (l != NULL)
    {
        struct ListNode *p = l;
        l = l->next;
        free(p);
    }
}

// struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
// {
//     if (l1 == NULL)
//     {
//         return l2;
//     }
//     if (l2 == NULL)
//     {
//         return l1;
//     }

//     struct ListNode *p = NULL;
//     if (l1->val < l2->val)
//     {
//         p = l1;
//         p->next = mergeTwoLists(l1->next, l2);
//     }
//     else
//     {
//         p = l2;
//         p->next = mergeTwoLists(l1, l2->next);
//     }
//     return p;
// }

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *a = head;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            a->next = l1;
            l1 = l1->next;
        }
        else
        {
            a->next = l2;
            l2 = l2->next;
        }
        a = a->next;
    }
    if (l1 == NULL)
    {
        a->next = l2;
    }
    else
    {
        a->next = l1;
    }

    struct ListNode *p = head;
    head = head->next;
    free(p);
    return head->next;
}

int main()
{
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    struct ListNode *l1, *l2;
    //init l1
    l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->val = arr1[0];
    l1->next = NULL;
    create(l1, arr1, sizeof(arr1) / sizeof(arr1[0]));
    //init l2
    l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->val = arr2[0];
    l2->next = NULL;
    create(l2, arr2, sizeof(arr2) / sizeof(arr2[0]));

    show(l1);
    printf("\n");
    show(l2);
    printf("\n");

    struct ListNode *l = mergeTwoLists(l1, l2);
    show(l);

    // distroy(l1);
    // distroy(l2);
    distroy(l);

    return 0;
}