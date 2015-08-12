#include "Stack.h"

void Stack::push(int x)
{
    // if current queue with items is rQueue
    if (current)
    {
        lQueue.push(x);
        while (!rQueue.empty())
        {
            lQueue.push(rQueue.front());
            rQueue.pop();
        }
        current = false;
    }
    else
    {
        rQueue.push(x);
        while (!lQueue.empty())
        {
            rQueue.push(lQueue.front());
            lQueue.pop();
        }
        current = true;
    }
}

void Stack::pop()
{
    if (current)
        rQueue.pop();
    else
        lQueue.pop();
}

int Stack::top()
{
    if (current)
        return rQueue.front();
    else
        return lQueue.front();
}

bool Stack::empty()
{
    return lQueue.empty() && rQueue.empty();
}