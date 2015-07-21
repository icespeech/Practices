#include "Solution.h"
using std::string;

bool stringAdj(const string& a, const string& b)
{
    for (int i = 0, differ = 0; i < a.size(); ++i)
        if (a[i] != b[i] && ++differ > 1) return false;
    
    return true;
}

bool setAdj(const string& str, const std::unordered_set<string> st)
{
    for (auto s : st)
        if (stringAdj(s, str)) return true;
    
    return false;
}

int Solution::ladderLength(string beginWord, string endWord, std::unordered_set<string>& wordDict)
{
    if (beginWord.size() == 0 || endWord.size() == 0 || beginWord.size() != endWord.size()) return 0;
    if (beginWord.compare(endWord) == 0) return 1;
    if (stringAdj(beginWord, endWord)) return 2;

    std::unordered_set<string> layerSetFromStart;
    std::unordered_set<string> layerSetFromEnd;
    std::unordered_set<string> tmpLayerSetFromStart;
    std::unordered_set<string> tmpLayerSetFromEnd;

    layerSetFromStart.insert(beginWord);
    layerSetFromEnd.insert(endWord);

    int startDepth = 1, endDepth = 1;

    while (layerSetFromStart.size() > 0 || layerSetFromEnd.size() > 0)
    {
        /*
        * start side
        */
        for (auto curStart : layerSetFromStart)
        {
            for (int i = 0; i < curStart.size(); ++i)
            {
                string tmpS = curStart;
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    if (c == curStart[i]) continue;

                    tmpS[i] = c;
                    // there is this node, and this node is in the leaf layer of the end side => found
                    if (layerSetFromEnd.find(tmpS) != layerSetFromEnd.end())
                        return startDepth + endDepth;

                    // there is this node in the dict
                    if (wordDict.find(tmpS) != wordDict.end())
                    {
                        tmpLayerSetFromStart.insert(tmpS);
                    }
                }
            }
        }
        startDepth++;
        layerSetFromStart = tmpLayerSetFromStart;
        tmpLayerSetFromStart.clear();

        /*
        * end side
        */
        for (auto curEnd : layerSetFromEnd)
        {
            for (int i = 0; i < curEnd.size(); ++i)
            {
                string tmpE = curEnd;
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    if (c == curEnd[i]) continue;

                    tmpE[i] = c;
                    if (layerSetFromStart.find(tmpE) != layerSetFromStart.end())
                        return startDepth + endDepth;

                    // there is this node in the dict
                    if (wordDict.find(tmpE) != wordDict.end())
                        tmpLayerSetFromEnd.insert(tmpE);
                }
            } // end for loop of every character of the word
        }

        endDepth++;
        layerSetFromEnd = tmpLayerSetFromEnd;
        tmpLayerSetFromEnd.clear();
    }
    return 0;
}
