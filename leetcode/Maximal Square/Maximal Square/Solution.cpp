#include "Solution.h"

inline char min(char a, char b)
{
    return a < b ? a : b;
}

int Solution::maximalSquare(std::vector<std::vector<char>>& matrix)
{
    if (matrix.size() == 0) return 0;
    char max = '0';

    for (char c : matrix[0])
        if (c == '1')
        {
            max = '1';
            break;
        }
    
    if (max == '0')
        for (auto v : matrix)
            if (v[0] == '1')
            {
                max = '1';
                break;
            }

    for (int i = 1; i < matrix.size(); ++i)
        for (int j = 1; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == '0')
                continue;

            matrix[i][j] = min(min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;
            if (matrix[i][j] > max)
                max = matrix[i][j];
        }

    return (max - '0')*(max - '0');
}