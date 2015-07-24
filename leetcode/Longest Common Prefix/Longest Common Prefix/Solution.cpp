#include "Solution.h"
using std::string;

string Solution::longestCommonPrefix(std::vector<string>& strs)
{
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];

    std::vector<char> ret;
    size_t minLength = SIZE_MAX;

    for (const string& s : strs)
    {
        if (s.size() < minLength)
            minLength = s.size();
    }

    if (minLength == 0) return "";

    for (int i = 0; i < minLength; ++i)
    {
        bool flag = true;
        for (int j = 1; j < strs.size(); ++j)
        {
            if (strs[j - 1][i] != strs[j][i])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;

        ret.push_back(strs[0][i]);
    }
    return string(ret.begin(), ret.end());
}