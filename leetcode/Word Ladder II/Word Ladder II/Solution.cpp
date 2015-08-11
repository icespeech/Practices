#include <unordered_map>
#include <vector>
#include <set>
#include <stack>
#include "Solution.h"
using std::string;
using std::set;
using std::vector;

class node
{
public:
    node()
    {

    }
    node(const string& s) :
        name(s),
        pathes()
    {
    }
    string name;
    set<string> pathes;
};

node startNode;
node* endNode;

bool inline stringAdj(const string& a, const string& b)
{
    for (int i = 0, differ = 0; i < a.size(); ++i)
        if (a[i] != b[i] && ++differ > 1) return false;

    return true;
}

vector<vector<string>> Solution::findLadders(string beginWord, string endWord, std::unordered_set<string>& wordDict)
{
    if (beginWord.size() == 0 || endWord.size() == 0 || beginWord.size() != endWord.size()) return vector<vector<string>>();
    if (beginWord.compare(endWord) == 0) return { {beginWord} };
    if (stringAdj(beginWord, endWord)) return { { beginWord, endWord } };
    
    vector<node> nodes;
    std::unordered_map<string, std::vector<node*>> graph;

    wordDict.insert(endWord);

    // this is important. this prevents the memory addresses that being stored into the graph below to change
    nodes.reserve(wordDict.size());
    for (const string& s : wordDict)
    {
        nodes.push_back(s);
        if (s.compare(endWord) == 0)
        {
            endNode = &*(nodes.end() - 1);
        }

        for (int i = 0; i < s.size(); ++i)
        {
            string tmp = s;
            tmp[i] = '*';
            graph[tmp].push_back(&*(nodes.end()-1));
        }
    }

    std::unordered_set<string> visited;
    set<node*> layerSetFromStart;
    set<node*> tmpLayerSetFromStart;

    startNode.name = beginWord;

    layerSetFromStart.insert(&startNode);

    bool foundFlag = false;
    while (layerSetFromStart.size() > 0)
    {
        /*
        * start side
        */
        for (node* curStart : layerSetFromStart)
        {
            visited.insert(curStart->name);
            for (int i = 0; i < curStart->name.size(); ++i)
            {
                string tmpS = curStart->name;
                tmpS[i] = '*';
                for (node* s : graph[tmpS])
                {
                    if (visited.find(s->name) != visited.end())
                        continue;

                    if (s == endNode)
                        foundFlag = true;

                    if (curStart->pathes.size() == 0)
                    {
                        s->pathes.insert(curStart->name);
                    }
                    else
                    {
                        if (s->pathes.size() == 0 || !((curStart->pathes.begin()->size() + curStart->name.size()) > s->pathes.begin()->size()))
                        {
                            for (const string& str : curStart->pathes)
                            {
                                s->pathes.insert(str + curStart->name);
                            }
                        }
                    }
                    tmpLayerSetFromStart.insert(s);
                }
            }
        }
        if (foundFlag)
        {
            vector<vector<string>> ret;
            for (const string& s : endNode->pathes)
            {
                vector<string> vs;
                auto it = s.begin();
                while (it < s.end())
                {
                    vs.push_back(string(it, it + endNode->name.length()));
                    it += endNode->name.length();
                }
                vs.push_back(endNode->name);
                ret.push_back(vs);
            }
            return ret;
        }
        layerSetFromStart = tmpLayerSetFromStart;
        tmpLayerSetFromStart.clear();
    }
    return vector<vector<string>>();
}