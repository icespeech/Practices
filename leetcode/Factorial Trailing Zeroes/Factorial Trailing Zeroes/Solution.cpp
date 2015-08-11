#include "Solution.h"

int Solution::trailingZeroes(int n)
{
    size_t result = 0;
    
    // counts how many 5s in factors showed up from 1 to n
    while (n > 0)
        result += (n /= 5);
    
    return result;
}