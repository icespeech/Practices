#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <utility>

using std::vector;
using std::string;
using std::pair;

class Vertex
{
public:
    Vertex(string str, std::queue<pair<Vertex*, unsigned int>>* wl):
        mStr(str),
        mAdjacentVertices(),
        mWaitingLine(wl)
    {
    }

    void addAdjacent(Vertex*);
    bool search(unsigned int, string);
    bool compare(string);
    bool adjacentTo(Vertex*);
private:
    string mStr;
    vector<Vertex*> mAdjacentVertices;
    std::queue<pair<Vertex*, unsigned int>>* mWaitingLine;
};