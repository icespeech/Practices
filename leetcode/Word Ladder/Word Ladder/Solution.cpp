#include "Solution.h"
using std::string;

int Solution::ladderLength(string beginWord, string endWord, std::unordered_set<string>& wordDict)
{
    if (beginWord.compare(endWord) == 0)
    {
        return 1;
    }

    std::unordered_set<Vertex*> vertices;

    Vertex* start = new Vertex(beginWord, &mWaitingLineSet, &mWaitingLine);
    vertices.insert(start);

    Vertex* end = new Vertex(endWord, &mWaitingLineSet, &mWaitingLine);
    vertices.insert(end);

    for (auto str: wordDict)
    {
        if (str.compare(beginWord) == 0 || str.compare(endWord) == 0)
            continue;
        Vertex* v = new Vertex(str, &mWaitingLineSet, &mWaitingLine);

        for (auto vt : vertices)
        {
            if (v->adjacentTo(vt))
            {
                v->addAdjacent(vt);
                vt->addAdjacent(v);
            }
        }
        vertices.insert(v);
    }

    mWaitingLine.push(std::make_pair(start, 2));
    
    while (mWaitingLine.size() > 0 && mWaitingLine.front().second <= vertices.size())
    {
        if (mWaitingLine.front().first->search(mWaitingLine.front().second, endWord))
        {
            return mWaitingLine.front().second;
        }
        else
        {
            mWaitingLine.pop();
        }
    }

    // over
    for (auto v: vertices)
    {
        delete v;
    }

    return 0;
}