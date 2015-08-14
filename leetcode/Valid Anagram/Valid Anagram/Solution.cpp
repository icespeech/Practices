#include "Solution.h"
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

bool Solution::isAnagram(string s, string t)
{
    vector<char> vs(s.begin(), s.end());
    vector<char> vt(t.begin(), t.end());

    std::sort(vs.begin(), vs.end());
    std::sort(vt.begin(), vt.end());

    return vs == vt;
}