#include <queue>

class Stack
{
public:
    // Push element x onto stack.
    void push(int x);
    // Removes the element on top of the stack.
    void pop();
    // Get the top element.
    int top();
    // Return whether the stack is empty.
    bool empty();

private:
    // false denotes lQueue
    bool current = false;
    std::queue<int> lQueue;
    std::queue<int> rQueue;
};