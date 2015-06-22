#pragma warning( disable : 4996 )

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <random>
#include <chrono>
#include "Solution.h"

const int MAX_TEST_RANDOM = 1000;

template<typename T>
bool vectorCompare(vector<T> v1, vector<T> v2)
{
    if (v1.size() != v2.size()) return false;

    for (int i = 0;i < v1.size();++i)
        if (v1[i] != v2[i]) return false;

    return true;
}

int main()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    srand(time(NULL));
    int m = rand()%MAX_TEST_RANDOM;
    int n = rand()%MAX_TEST_RANDOM;

    vector<int> cards;
    for (int i = 1;i <= MAX_TEST_RANDOM;++i)
        cards.push_back(i);

    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    vector<int> nums1(cards.begin(), cards.begin()+m);
    
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    vector<int> nums2(cards.begin(), cards.begin()+n);

    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    vector<int> ans(nums1.begin(), nums1.end());
    ans.insert(ans.end(), nums2.begin(), nums2.end());

    std::sort(ans.begin(), ans.end());

    Solution solution;
    //solution.merge(nums1, m, nums2, n);

    vector<int> mv(1, 2);
    mv.push_back(0);
    vector<int> nv(1, 1);

    solution.merge(mv, 1, nv, 1);
    std::cout << (vectorCompare(ans, nums1) ? "Match" : "Mis match");

    // halted to check the answer
    int i;
    std::cin >> i; 

    return 0;
}