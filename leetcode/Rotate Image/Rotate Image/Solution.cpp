#include "Solution.h"

void Solution::rotateInPlace(std::vector<std::vector<int>>& matrix, int xyStart, int n)
{
    int *reserve = new int[n - 1];
    
    int x = xyStart, y = xyStart;
    // lower bound, upper bound
    int lBound = xyStart, uBound = xyStart + n - 1;
    // left side
    for (; y < uBound; ++y)
    {
        reserve[y - xyStart] = matrix[y][x];
        matrix[y][x] = matrix[uBound][y];
    }
    // bottom side
    for (; x < uBound; ++x)
        matrix[y][x] = matrix[uBound - (x-lBound)][uBound];
    // right side
    for (; y > lBound; --y)
        matrix[y][x] = matrix[lBound][y];
    // up side
    for (int k = 0; x > lBound; --x, ++k)
        matrix[y][x] = reserve[k];
    
    delete[] reserve;
}

void Solution::rotate(std::vector<std::vector<int>>& matrix)
{
    if (matrix.size() < 2)
        return;

    if (matrix.size() % 2 == 0)
    {
        for (int i = (matrix.size() / 2) - 1, r = 1; i >= 0; --i, ++r)
            rotateInPlace(matrix, i, r*2);
    }
    else
    {
        for (int i = ((matrix.size()-1) / 2) - 1, r = 1; i >= 0; --i, ++r)
            rotateInPlace(matrix, i, (r * 2) + 1);
    }
}