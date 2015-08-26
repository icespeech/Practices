#include <vector>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>>& matrix);
private:
    void rotateInPlace(std::vector<std::vector<int>>&, int, int);
};