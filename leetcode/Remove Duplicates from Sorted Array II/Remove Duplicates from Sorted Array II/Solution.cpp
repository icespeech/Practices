#include "Solution.h"

int Solution::removeDuplicates(std::vector<int>& nums)
{
	if (nums.size() < 3)
	{
		return nums.size();
	}

	bool isDuplicated = false;
	unsigned int insertingIndex = 1;

	for (auto it = nums.begin() + 1; it != nums.end(); ++it)
	{
		if (nums[insertingIndex - 1] != *it)
		{
			nums[insertingIndex++] = *it;
			isDuplicated = false;
		}
		else
		{
			if (!isDuplicated)
			{
				nums[insertingIndex++] = *it;
				isDuplicated = true;
			}
		}
	}

	nums.erase(nums.begin()+insertingIndex, nums.end());

	return nums.size();
}