#include "Solution.h"
#include <vector>
using std::string;

string Solution::addBinary(string a, string b)
{
    if (a.size() == 0) return b;
    if (b.size() == 0) return a;

    std::vector<char> ret;

    int carry = 0;
    for (auto ita = a.rbegin(), itb = b.rbegin(); ita != a.rend() || itb != b.rend();)
    {
        int ia = (ita == a.rend()) ? 0 : *ita++ - '0';
        int ib = (itb == b.rend()) ? 0 : *itb++ - '0';

        int bit = ia + ib + carry;
        carry = bit / 2;
        bit %= 2;
        
        ret.push_back(bit + '0');
    }

    if (carry == 1)
        ret.push_back('1');

    // eliminate the leading '0's
    auto it = ret.rbegin();
    while (*it == '0')
        if (++it == ret.rend())
            return "0";

    return string(it, ret.rend());
}