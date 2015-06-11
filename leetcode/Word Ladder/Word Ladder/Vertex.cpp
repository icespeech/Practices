#include "Vertex.h"

void Vertex::addAdjacent(Vertex* adj)
{
    mAdjacentVertices.push_back(adj);
}

bool Vertex::search(unsigned int depth, string endWord)
{
    for (auto adj: mAdjacentVertices)
    {
        if (adj->compare(endWord)) // found
        {
            return true;
        }
        else
        {
            mWaitingLine->push(std::make_pair(adj, depth+1));
        }
    }
    return false;
}

bool Vertex::compare(string str)
{
    return (mStr.compare(str) == 0);
}

bool Vertex::adjacentTo(Vertex* v)
{
    int diff = 0;
    for (int i = 0;i < v->mStr.size();++i)
    {
        if (mStr[i] != v->mStr[i])
        {
            ++diff;
            if (diff > 1)
                return false;
        }
    }
    
    if (diff == 1)
        return true;

    return false;
}