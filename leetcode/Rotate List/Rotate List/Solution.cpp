#include "Solution.h"

ListNode* Solution::rotateRight(ListNode* head, int k)
{
    if (head == nullptr || head->next == nullptr) return head;
    if (k == 0) return head;

    ListNode* backN = head;
    ListNode* tail = head;
    ListNode* ret = nullptr;

    for (int i = 1; i <= k; ++i)
    {
        tail = tail->next;
        if (tail == nullptr)
        {
            tail = head;
            k = (k % i) + i;
        }
    }

    if (tail == nullptr) return head;
    while (tail->next != nullptr)
    {
        backN = backN->next;
        tail = tail->next;
    }
    tail->next = head;
    ret = backN->next;
    backN->next = nullptr;

    return ret;
}