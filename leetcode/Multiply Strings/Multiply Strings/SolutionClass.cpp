#include "SolutionClass.h"
#include <vector>
using std::vector;

void a2iForVector(vector<char>& aVec)
{
	for (auto it = aVec.begin(); it != aVec.end(); ++it)
		*it -= '0';
}
void i2aForVector(vector<char>& iVec)
{
	for (auto it = iVec.begin(); it != iVec.end(); ++it)
		*it += '0';
}

void multiplyByDigit(vector<char>& bigNumber, const vector<char>& num1, char multiplier, int digit)
{
	int tempDigit;
	for (int i = num1.size()-1, inserter = digit; i >= 0; --i, ++inserter)
	{
		tempDigit = multiplier * num1[i];

		// when the vector is out of digits to be added
		if (inserter == bigNumber.size())
		{
			bigNumber.push_back(tempDigit);
		}
		else
		{
			bigNumber[inserter] += tempDigit;
		}
	}

	for (int i = 0; i < bigNumber.size(); ++i)
	{
		if (bigNumber[i] >= 10)
		{
			if (i == bigNumber.size() - 1)
			{
				bigNumber.push_back(bigNumber[i] / 10);
			}
			else
			{
				bigNumber[i + 1] += bigNumber[i] / 10;
			}

			bigNumber[i] %= 10;
		}
	}
}

string Solution::multiply(string num1, string num2)
{
	// if num1 or num2 is zero, the result will be zero
	if ((num1.size() == 1 && num1[0] == '0') ||
		(num2.size() == 1 && num2[0] == '0'))
	{
		return "0";
	}

	vector<char> num1Vec(num1.begin(), num1.end());
	vector<char> num2Vec(num2.begin(), num2.end());
	a2iForVector(num1Vec);
	a2iForVector(num2Vec);

	vector<char> bigNumber(num1.size(), 0);

	for (int digit = 0, i = num2.size() - 1; i >= 0; ++digit, --i)
	{
		multiplyByDigit(bigNumber, num1Vec, num2Vec[i], digit);
	}
	
	i2aForVector(bigNumber);

	return string(bigNumber.rbegin(), bigNumber.rend());
}