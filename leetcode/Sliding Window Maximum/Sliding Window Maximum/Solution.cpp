#include "Solution.h"
#include <algorithm>
using std::vector;

// as the hint says, use a double-ended queue to store local maximums and filter unwanted elements
// this will store the position of each local maximum
class node
{
public:
    node(int i):
        position(i),
        next(nullptr),
        prev(nullptr)
    {
    }
    int position;
    node* next;
    node* prev;
};

vector<int> Solution::maxSlidingWindow(vector<int>& nums, int k)
{
    if (nums.size() == 0) return vector<int>();
    if (k == 1) return nums;
    if (k == nums.size()) return { *std::max_element(nums.begin(), nums.end()) };

    vector<int> ret;

    node* first = new node(0);
    node *head = first, *tail = first;

    for (int i = 1; i < nums.size(); ++i)
    {
        // if i is k elements behind the current local maximum, the window is now passed the position of it
        if (head != nullptr && (i - head->position == k))
        {
            node *tmp = head;
            if (head->next != nullptr)
                head->next->prev = nullptr;
            head = head->next;
            delete tmp;
            if (head == nullptr)
                tail = head;
        }

        // filters all elements that smaller than the new incoming one, so the incoming ones will always be local maximums
        while (tail != nullptr && nums[tail->position] < nums[i])
        {
            node *tmp = tail;
            tail = tail->prev;
            delete tmp;
            if (tail == nullptr)
                head = tail;
        }
        if (tail != nullptr)
        {
            tail->next = new node(i);
            tail->next->prev = tail;
            tail = tail->next;
        }
        else head = tail = new node(i);
        
        // when i reaches the k-1 element, the first k elements (0 ~ k-1) form a window now,
        // so a local maximum element needs to be pushed into results, as every following steps
        if (i >= k - 1)
            ret.push_back(nums[head->position]);
    }
    return ret;
}