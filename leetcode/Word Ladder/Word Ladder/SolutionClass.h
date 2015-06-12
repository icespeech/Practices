#include "Vertex.h"

using std::string;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, std::unordered_set<string>& wordDict);
private:
    void buildGraph(std::unordered_set<Vertex*>&);
    std::set<Vertex*> mWaitingLineSet;
    std::queue<std::pair<Vertex*, unsigned int>> mWaitingLine;
};