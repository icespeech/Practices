#include "Solution.h"
#include "gtest\gtest.h"

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

    EXPECT_EQ(0, sol.permuteUnique(std::vector<int>()).size());
}

TEST(SingleElementTest, SingleElementTest)
{
    Solution sol;

    auto result = sol.permuteUnique(std::vector<int>({ 5 }));
    EXPECT_EQ(1, result.size());
    EXPECT_EQ(1, result[0].size());
    EXPECT_EQ(5, result[0][0]);
}

TEST(TwoElementsTest, TwoElementsTest)
{
    Solution sol;

    auto result = sol.permuteUnique(std::vector<int>({ 5, 2 }));
    EXPECT_EQ(2, result.size());
    EXPECT_EQ(2, result[0].size());
    EXPECT_EQ(2, result[1].size());
    EXPECT_EQ(2, result[0][0]);
    EXPECT_EQ(5, result[0][1]);
    EXPECT_EQ(5, result[1][0]);
    EXPECT_EQ(2, result[1][1]);
}

TEST(ThreeElementsTest, ThreeElementsTest)
{
    Solution sol;

    auto result = sol.permuteUnique(std::vector<int>({ 5, 2, 8 }));
    EXPECT_EQ(6, result.size());
    EXPECT_EQ(3, result[0].size());
    EXPECT_EQ(3, result[1].size());
    EXPECT_EQ(3, result[2].size());
}

TEST(LeetcodeExampleTest, LeetcodeExampleTest)
{
    Solution sol;

    auto result = sol.permuteUnique(std::vector<int>({ 1, 1, 2 }));
    EXPECT_EQ(3, result.size());
    EXPECT_EQ(3, result[0].size());
    EXPECT_EQ(3, result[1].size());
    EXPECT_EQ(3, result[2].size());
}

TEST(LeetcodeExampleTest, LeetcodeExampleTest2)
{
    Solution sol;

    auto result = sol.permuteUnique(std::vector<int>({ 3, 3, 0, 0, 2, 3, 2 }));
    EXPECT_EQ(210, result.size());
    for (auto v : result)
    {
        EXPECT_EQ(v.size(), 7);
    }
}

TEST(LargeNumberTest, LargeNumberTest)
{
    Solution sol;

    auto result = sol.permuteUnique(std::vector<int>({ 1, 2, 2, 2, 5, 5, 7, 8, 9 }));
    EXPECT_EQ(30240, result.size());

    for (auto v : result)
    {
        EXPECT_EQ(v.size(), 9);
    }
}