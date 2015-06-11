#include "Vertex.h"

using std::string;
using std::unordered_set;
using std::queue;
using std::pair;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict);
private:
    void buildGraph(unordered_set<Vertex*>&);
    std::queue<pair<Vertex*, unsigned int>> mWaitingLine;
};