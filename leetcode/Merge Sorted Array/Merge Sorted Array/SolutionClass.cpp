#include "SolutionClass.h"

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    if (n == 0) return;

    static vector<int> temp;

    auto it1 = nums1.begin();
    auto it2 = nums2.begin();

    while(it1 != nums1.end() || it2 != nums2.end())
    {
        if (it1 == nums1.end())
        {
            temp.insert(temp.end(), it2, nums2.end());
            break;
        }
        else if (it2 == nums2.end())
        {
            temp.insert(temp.end(), it1, nums1.end());
            break;
        }
        else
        {
            if(*it1 <= *it2)
            {
                temp.push_back(*it1);
                ++it1;
            }
            else
            {
                temp.push_back(*it2);
                ++it2;
            }
        }
    }

    std::swap(nums1, temp);
}