#include <vector>
#include <stack>
#define h first
#define pos second

using std::vector;
using std::stack;
using std::pair;

class Solution
{
public:
    int largestRectangleArea(vector<int>& height)
    {
        if (height.size() == 0) return 0;
        if (height.size() == 1) return height[0];

        // add a stop item to force the tail items to calculate
        height.push_back(-1);

        size_t maxArea = 0;
        stack<pair<int, size_t>> heightStack;

        heightStack.push(std::make_pair(height[0], 0));
        for (int i = 1; i < height.size(); ++i)
        {
            if (height[i] >= heightStack.top().h)
            {
                heightStack.push(std::make_pair(height[i], i));
            }
            else
            {
                // the equal position of this histogram bar
                int equalPos = i;
                while (!heightStack.empty() && height[i] < heightStack.top().h)
                {
                    equalPos = heightStack.top().pos;
                    size_t tmpArea = heightStack.top().h * (i - heightStack.top().pos);
                    if (tmpArea > maxArea)
                        maxArea = tmpArea;
                    heightStack.pop();
                }
                heightStack.push(std::make_pair(height[i], equalPos));
            }
        }

        return maxArea;
    }
};