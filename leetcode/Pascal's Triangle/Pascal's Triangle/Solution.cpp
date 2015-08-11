#include "Solution.h"

using std::vector;

vector<vector<int>> Solution::generate(int numRows)
{
    if (numRows == 0) return vector<vector<int>>();
    if (numRows == 1) return vector<vector<int>>({ { 1 } });
    if (numRows == 2) return vector<vector<int>>({ { 1 }, { 1, 1 } });

    vector<vector<int>> ret({ { 1 }, { 1, 1 } });

    for (int j = 2; j < numRows; ++j)
    {
        vector<int> tmp(1, 1);
        int previous = ret.size() - 1;
        for (int i = 1; i < ret[previous].size(); ++i)
        {
            tmp.push_back(ret[previous][i - 1] + ret[previous][i]);
        }
        tmp.push_back(1);
        ret.push_back(tmp);
    }

    return ret;
}