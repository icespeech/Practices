#include "Vertex.h"

class Solution
{
public:
    int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string>& wordDict);

private:
    std::set<Vertex*> mWaitingLineSet;
    std::queue<std::pair<Vertex*, unsigned int>> mWaitingLine;
};