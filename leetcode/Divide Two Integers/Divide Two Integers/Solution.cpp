#include "Solution.h"

int Solution::divide(int dividend, int divisor)
{
    if (divisor == 0) return INT_MAX;
    if (divisor == 1) return dividend;
    if (divisor == -1)
    {
        if (dividend == INT_MIN) return INT_MAX;
        return -dividend;
    }
    if (dividend == 0) return 0;

    int times = 1, result = 0, ret;
    int absDividend, absDivisor;

    if (divisor > 0 && dividend > 0)
        absDividend = dividend, absDivisor = divisor;
    else if (dividend < 0 && divisor < 0)
    {
        if (dividend == INT_MIN && divisor == INT_MIN)
            return 1;
        else if (dividend == INT_MIN)
        {
            absDividend = -(dividend - divisor), absDivisor = -divisor, result = 1;
        }
        else if (divisor == INT_MIN)
            return 0;
        else
            absDividend = -dividend, absDivisor = -divisor;
    }
    else if (dividend < 0)
    {
        if (dividend == INT_MIN)
            absDividend = -(dividend + divisor), absDivisor = divisor, result = 1;
        else
            absDividend = -dividend, absDivisor = divisor;
    }
    else
    {
        if (divisor == INT_MIN)
            return 0;
        else absDividend = dividend, absDivisor = -divisor;
    }

    int tmpDivisor = absDivisor;
    while (absDividend >= absDivisor)
    {
        if (absDividend < tmpDivisor)
        {
            tmpDivisor = absDivisor;
            times = 1;
        }
        absDividend -= tmpDivisor;
        tmpDivisor += tmpDivisor;
        result += times;
        times += times;
    }

    if (dividend < 0)
    {
        if (divisor < 0)
            return result;
        else
            return -result;
    }
    else
    {
        if (divisor < 0)
            return -result;
        else
            return result;
    }
}