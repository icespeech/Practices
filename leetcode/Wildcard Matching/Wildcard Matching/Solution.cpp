#include <vector>
#include "Solution.h"

inline bool isAllStar(string p)
{
	if (p.size() == 0)
	{
		return false;
	}

	for (auto ch : p)
	{
		if (ch != '*')
		{
			return false;
		}
	}

	return true;
}

string eliminateStars(const string& p)
{
	std::vector<char> v;
	if (p.size() == 0)
	{
		return p;
	}

	bool previousOneIsStar = false;
	for (auto ch : p)
	{
		if (ch == '*')
		{
			if (previousOneIsStar)
			{
				continue;
			}
			else
			{
				v.push_back(ch);
				previousOneIsStar = true;
			}
		}
		else
		{
			if (previousOneIsStar)
			{
				previousOneIsStar = false;
			}
			v.push_back(ch);
		}
	}

	return string(v.begin(), v.end());
}

bool recursiveMatching(string s, string p)
{
	int i = 0;
	bool starFlag = false;
	for (; i < p.size() && i < s.size(); ++i)
	{
		if (p[i] == '*')
		{
			starFlag = true;
			break;
		}
		// either p[i] is '?' or p[i] equals s[i], otherwise it's not match
		else if (p[i] == '?' || p[i] == s[i])
		{
			continue;
		}
		else
		{
			return false;
		}
	}

	if (!starFlag)	// if no '*' encountered
	{
		if (i == s.size())
		{
			if (i == p.size())
			{
				return true;
			}
			else	// all characters of s are matched, yet p still have characters
			{
				// then the remaining p characters must star to be matched
				return (isAllStar(string(&p[i], &p[p.size()])));
			}
		}
		else	// i == p.size(), all characters of p are matched
		{
			// then s should not remain any characters
			return (i == s.size());
		}
	}
	else	// p[i] is '*'
	{
		for (int j = i; j <= s.size(); ++j) // here j may equals s.size() because '*' can match an empty string
		{
			if (recursiveMatching(string(&s[j], &s[s.size()]), string(&p[i + 1], &p[p.size()])))
			{
				return true;
			}
		}
		return false;
	}
}

bool Solution::isMatch(string s, string p)
{
	p = eliminateStars(p);

	if ((p.compare(s) == 0) || (p.compare("*") == 0))
	{
		return true;
	}

	return recursiveMatching(s, p);
}