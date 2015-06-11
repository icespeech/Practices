#include "SolutionClass.h"

int Solution::ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict)
{
    if (beginWord.compare(endWord) == 0)
    {
        return 1;
    }

    unordered_set<Vertex*> vertices;

    Vertex* start = new Vertex(beginWord, &mWaitingLine);
    vertices.insert(start);

    Vertex* end = new Vertex(endWord, &mWaitingLine);
    vertices.insert(end);

    for (auto str: wordDict)
    {
        Vertex* v = new Vertex(str, &mWaitingLine);
        vertices.insert(v);
    }

    buildGraph(vertices);

    mWaitingLine.push(std::make_pair(start, 2));
    
    while (mWaitingLine.front().second < vertices.size())
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

void Solution::buildGraph(unordered_set<Vertex*>& vertices)
{
    vector<Vertex*> verticesVector(vertices.begin(), vertices.end());

    for (int i = 0; i < verticesVector.size()-1; ++i)
    {
        for (int j = i+1; j < verticesVector.size(); ++j)
        {
            if (verticesVector[i]->adjacentTo(verticesVector[j]))
            {
                verticesVector[i]->addAdjacent(verticesVector[j]);
                verticesVector[j]->addAdjacent(verticesVector[i]);
            }
        }
    }
}