#include "Solution.h"
#include <stack>
#include <set>
using std::vector;

std::stack<int, vector<int>> tmpLayer;
std::set<vector<int>> ret;

void recurse(vector<int>& nums)
{
    if (nums.size() == 1)
    {
        tmpLayer.push(nums[0]);

        int* end = &tmpLayer.top() + 1;
        int* begin = end - tmpLayer.size();
        ret.insert(vector<int>(begin, end));

        tmpLayer.pop();
        return;
    }

    // use this set to prune all duplicated expansions.
    // this will significantly reduce the execution time when there are duplicated items
    std::set<int> used;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (used.find(nums[i]) != used.end())
            continue;

        used.insert(nums[i]);
        tmpLayer.push(nums[i]);
        vector<int> tmp(nums.begin(), nums.begin() + i);
        tmp.insert(tmp.end(), nums.begin() + i + 1, nums.end());

        recurse(tmp);
        tmpLayer.pop();
    }
}

vector<vector<int>> Solution::permuteUnique(vector<int>& nums)
{
    if (nums.size() == 0) return vector<vector<int>>();
    if (nums.size() == 1) return vector<vector<int>>({ { nums[0] } });
    
    std::set<int> used;

    ret.clear();
    recurse(nums);

    return vector<vector<int>>(ret.begin(), ret.end());
}