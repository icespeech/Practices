#include <set>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <utility>

class Vertex
{
public:
    Vertex(std::string str, std::set<Vertex*>* wlsp, std::queue<std::pair<Vertex*, unsigned int>>* wlp) :
        mStr(str),
        mAdjacentVertices(),
        mWaitingLineSetPtr(wlsp),
        mWaitingLinePtr(wlp)
    {
    }

    void addAdjacent(Vertex*);
    bool search(unsigned int, std::string);
    bool compare(std::string);
    bool adjacentTo(Vertex*);
private:
    std::string mStr;
    std::vector<Vertex*> mAdjacentVertices;
    std::set<Vertex*>* mWaitingLineSetPtr;
    std::queue<std::pair<Vertex*, unsigned int>>* mWaitingLinePtr;
};