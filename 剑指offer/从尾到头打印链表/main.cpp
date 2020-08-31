#include <iostream>
#include <vector>
#include <stack>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    std::vector<int> reversePrint(ListNode *head);
};

std::vector<int> Solution::reversePrint(ListNode *head)
{
    std::stack<int> s;
    std::vector<int> res;
    //入栈
    while (head)
    {
        s.push(head->val);
        head = head->next;
    }
    //出栈
    while (!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

int main()
{

    return 0;
}
