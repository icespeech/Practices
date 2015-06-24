#include "Solution.h"
using std::string;

std::pair<size_t, size_t> findPalindrome(const string& s, size_t x, size_t y)
{
    for (int i = x - 1, j = y + 1; i >= 0 && y < s.size(); --i, ++j)
    {
        if (s[i] == s[j])
        {
            x = i;
            y = j;
        }
        else break;
    }
    return  std::make_pair(x, y+1);
}

string Solution::longestPalindrome(string s)
{
    std::string tempResultString;

    if (s.size() < 2)
    {
        return s;
    }

    if (s.size() == 2)
    {
        if (s[0] == s[1])
        {
            return s;
        }
        else
        {
            return string(&s[0], &s[1]);
        }
    }

    int i = 0;
    for (; i < s.size() - 2; ++i)
    {
        if (((s.size() - i) * 2) < tempResultString.size())
        {
            break;
        }

        if (s[i] == s[i + 1])
        {
            auto p = findPalindrome(s, i, i + 1);
            string tempString(&s[p.first], &s[p.second]);
            if (tempString.size() > tempResultString.size())
            {
                tempResultString = tempString;
            }
        }
        if (s[i] == s[i + 2])
        {
            auto p = findPalindrome(s, i, i + 2);
            string tempString(&s[p.first], &s[p.second]);
            if (tempString.size() > tempResultString.size())
            {
                tempResultString = tempString;
            }
        }
    }

    // the last two characters may be the only palindromic substring
    if (s[s.size() - 2] == s[s.size() - 1])
    {
        if (tempResultString.size() < 2)
        {
            tempResultString.replace(tempResultString.begin(), tempResultString.end(), &s[s.size() - 2], &s[s.size()]);
        }
    }
    return tempResultString;
}