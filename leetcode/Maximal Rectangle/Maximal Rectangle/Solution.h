#include <vector>

class Solution
{
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix);
private:
    size_t calcArea(const std::vector<int>& heights);
};