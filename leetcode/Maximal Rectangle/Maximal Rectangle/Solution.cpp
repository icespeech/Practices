#include "Solution.h"
#include <algorithm>
using std::vector;

int Solution::maximalRectangle(vector<vector<char>>& matrix)
{
    size_t xLen = 0, yLen = 0;
    if ((yLen = matrix.size()) == 0 || (xLen = matrix[0].size()) == 0) return 0;
    
    size_t maxArea = 0, tmpArea = 0;
    vector<int> heights;
    for (int i = 0; i < xLen; ++i)
        heights.push_back(matrix[0][i] - '0');
    
    heights.push_back(-1);

    for (char c : matrix[0])
    {
        if (c == '0')
            tmpArea = 0;
        else
        {
            tmpArea++;
            if (tmpArea > maxArea) maxArea = tmpArea;
        }
    }

    if (yLen > 1)
    {
        for (int y = 1; y < yLen; ++y)
        {
            for (int x = 0; x < xLen; ++x)
            {
                if (matrix[y][x] == '0')
                    heights[x] = 0;
                else
                    heights[x]++;
            }
            if ((tmpArea = calcArea(heights)) > maxArea)
                maxArea = tmpArea;
        }
    }

    return maxArea;
}

// same as "Largest Rectangle in Histogram"
#include <stack>
#define h first
#define pos second
size_t Solution::calcArea(const vector<int>& heights)
{
    size_t xLen = heights.size();
    if (xLen == 0) return 0;
    if (xLen == 1) return heights[0];

    size_t maxArea = 0;
    std::stack<std::pair<int, size_t>> heightStack;

    heightStack.push(std::make_pair(heights[0], 0));
    for (int i = 1; i < xLen; ++i)
    {
        if (heights[i] >= heightStack.top().h)
        {
            heightStack.push(std::make_pair(heights[i], i));
        }
        else
        {
            // the equal position of this histogram bar
            int equalPos = i;
            while (!heightStack.empty() && heights[i] < heightStack.top().h)
            {
                equalPos = heightStack.top().pos;
                size_t tmpArea = heightStack.top().h * (i - heightStack.top().pos);
                if (tmpArea > maxArea)
                    maxArea = tmpArea;
                heightStack.pop();
            }
            heightStack.push(std::make_pair(heights[i], equalPos));
        }
    }

    return maxArea;
}