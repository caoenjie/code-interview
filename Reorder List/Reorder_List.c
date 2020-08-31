/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// #include <stdio.h>
// #include <stdlib.h>
// struct ListNode
// {
//     int val;
//     struct ListNode *next;
// };

// void reorderList(struct ListNode *head)
// {

// }

// int main()
// {
// }
#include <stdio.h>
#include <stdlib.h>
typedef struct Node *LinkList;

struct Node
{
    int data;
    struct Node *next;
} Node;

void list(int arr[], LinkList l, int n)
{
    int i;
    LinkList p = l, s;
    for (i = 0; i < n; i++)
    {
        s = (LinkList)malloc(sizeof(Node));
        s->data = arr[i];
        p->next = s;
        p = s;
    }
    p->next = NULL;
}

void traverse(LinkList l)
{
    LinkList p = l->next;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}
void reverse(LinkList l)
{
    // LinkList p = l->next;
    // LinkList s = NULL, q = NULL;
    // while (p != NULL)
    // {
    //     s = p->next;
    //     p->next = q;
    //     q = p;
    //     p = s;
    // }
    // LinkList h = (LinkList)malloc(sizeof(Node));
    // h->next = q;
    LinkList p = l->next;
    LinkList p1 = NULL, p2 = NULL;
    while(p != NULL)
    {
        p1 = p->next;
        p->next = p2;
        p2 = p;
        p = p1;
    }
    LinkList t = (LinkList)malloc(sizeof(Node));
    t->next = p2;
    traverse(t);
}

int main(int argc, char *argv[])
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkList head = (LinkList)malloc(sizeof(Node));
    list(arr, head, 10);
    traverse(head);
    reverse(head);
}
