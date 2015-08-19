#include "Solution.h"
#include "gtest\gtest.h"
using std::vector;

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    // pause to show the results
    getchar();
    return 0;
}

TEST(EmptyTest, EmptyTest)
{
    Solution sol;
    auto result = sol.maxSlidingWindow(vector<int>({ }), 0);

    EXPECT_EQ(0, result.size());
}

TEST(OneElementTest, OneElementTest)
{
    Solution sol;
    auto result = sol.maxSlidingWindow(vector<int>({ 3 }), 1);

    EXPECT_EQ(1, result.size());
    EXPECT_EQ(3, result[0]);
}

TEST(AllTheSameTest, AllTheSameTest)
{
    Solution sol;
    auto result = sol.maxSlidingWindow(vector<int>({ 8, 8, 8, 8, 8, 8, 8, 8 }), 4);

    EXPECT_EQ(5, result.size());
    std::vector<int> ans = { 8, 8, 8, 8, 8 };

    for (int i = 0; i < ans.size(); ++i)
    {
        EXPECT_EQ(result[i], ans[i]);
    }
}

TEST(IncreasingTest, IncreasingTest)
{
    Solution sol;
    auto result = sol.maxSlidingWindow(vector<int>({ 1, 2, 3, 4, 5, 6, 7, 8 }), 4);

    EXPECT_EQ(5, result.size());
    std::vector<int> ans = { 4, 5, 6, 7, 8 };

    for (int i = 0; i < ans.size(); ++i)
    {
        EXPECT_EQ(result[i], ans[i]);
    }
}

TEST(DecreasingTest, DecreasingTest)
{
    Solution sol;
    auto result = sol.maxSlidingWindow(vector<int>({ 8, 7, 6, 5, 4, 3, 2, 1 }), 4);

    EXPECT_EQ(5, result.size());
    std::vector<int> ans = { 8, 7, 6, 5, 4 };

    for (int i = 0; i < ans.size(); ++i)
    {
        EXPECT_EQ(result[i], ans[i]);
    }
}

TEST(LeetcodeTest, LeetcodeTest)
{
    Solution sol;
    auto result = sol.maxSlidingWindow(vector<int>({ 1, 3, -1, -3, 5, 3, 6, 7 }), 3);

    EXPECT_EQ(6, result.size());
    std::vector<int> ans = { 3, 3, 5, 5, 6, 7 };

    for (int i = 0; i < ans.size(); ++i)
    {
        EXPECT_EQ(result[i], ans[i]);
    }
}