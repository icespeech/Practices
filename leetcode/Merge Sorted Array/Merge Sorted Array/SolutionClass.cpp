#include "SolutionClass.h"

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    static vector<int> temp;

    temp.clear();

    nums1.erase(nums1.begin()+m, nums1.end());
    nums2.erase(nums2.begin()+n, nums2.end());
        
    if (n == 0) return;
    if (m == 0)
    {
        std::swap(nums1, nums2);
        return;
    }

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