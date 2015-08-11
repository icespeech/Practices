#include "Solution.h"

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    ListNode* backNAnd1 = head;
    ListNode* tail = head;

    for (int i = 0; i < n; ++i)
        tail = tail->next;
    
    if (tail == nullptr)
        return head->next;

    tail = tail->next;
    while (tail != nullptr)
    {
        backNAnd1 = backNAnd1->next;
        tail = tail->next;
    }
    backNAnd1->next = backNAnd1->next->next;
    
    return head;
}