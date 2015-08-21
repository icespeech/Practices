#include "Solution.h"

ListNode* Solution::swapPairs(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) return head;

    ListNode *n1 = head, *n2 = head->next, *n3, *n4;
    head = n2;

    while (true)
    {
        if (nullptr == (n3 = n2->next))
        {
            n2->next = n1;
            n1->next = nullptr;
            return head;
        }
        
        if (nullptr == (n4 = n3->next))
        {
            n1->next = n3;
            n2->next = n1;
            return head;
        }
        else
        {
            n1->next = n4;
            n2->next = n1;
            n1 = n3;
            n2 = n4;
        }
    }
}