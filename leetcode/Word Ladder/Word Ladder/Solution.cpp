#include <unordered_map>
#include <vector>
#include <set>
#include "Solution.h"
using std::string;
using std::set;

bool stringAdj(const string& a, const string& b)
{
    for (int i = 0, differ = 0; i < a.size(); ++i)
        if (a[i] != b[i] && ++differ > 1) return false;
    
    return true;
}

int Solution::ladderLength(string beginWord, string endWord, std::unordered_set<string>& wordDict)
{
    if (beginWord.size() == 0 || endWord.size() == 0 || beginWord.size() != endWord.size()) return 0;
    if (beginWord.compare(endWord) == 0) return 1;
    if (stringAdj(beginWord, endWord)) return 2;

    std::unordered_map<string, std::vector<string>> graph;

    for (const string& s : wordDict)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            string tmp = s;
            tmp[i] = '*';
            graph[tmp].push_back(s);
        }
    }

    std::unordered_set<string> visited;
    set<string> layerSetFromStart;
    set<string> layerSetFromEnd;
    set<string> tmpLayerSetFromStart;
    set<string> tmpLayerSetFromEnd;

    layerSetFromStart.insert(beginWord);
    layerSetFromEnd.insert(endWord);

    int startDepth = 1, endDepth = 0;

    while (layerSetFromStart.size() > 0 || layerSetFromEnd.size() > 0)
    {
        /*
        * start side
        */
        for (const string& curStart : layerSetFromStart)
        {
            visited.insert(curStart);
            for (int i = 0; i < curStart.size(); ++i)
            {
                string tmpS = curStart;
                tmpS[i] = '*';
                for (const string& s : graph[tmpS])
                {
                    if (visited.find(s) != visited.end())
                        continue;

                    // there is this node, and this node is in the leaf layer of the end side => found
                    if (layerSetFromEnd.find(s) != layerSetFromEnd.end())
                        return startDepth + endDepth + 1;
                    
                    tmpLayerSetFromStart.insert(s);
                }
            }
        }
        startDepth++;
        layerSetFromStart = tmpLayerSetFromStart;
        tmpLayerSetFromStart.clear();

        /*
        * end side
        */
        for (const string& curEnd : layerSetFromEnd)
        {
            visited.insert(curEnd);
            for (int i = 0; i < curEnd.size(); ++i)
            {
                string tmpE = curEnd;
                tmpE[i] = '*';
                for (const string& s : graph[tmpE])
                {
                    if (visited.find(s) != visited.end())
                        continue;

                    if (layerSetFromStart.find(s) != layerSetFromStart.end())
                        return startDepth + endDepth + 1;
                    
                    tmpLayerSetFromEnd.insert(s);
                }
            }
        }
        endDepth++;
        layerSetFromEnd = tmpLayerSetFromEnd;
        tmpLayerSetFromEnd.clear();
    }
    return 0;
}