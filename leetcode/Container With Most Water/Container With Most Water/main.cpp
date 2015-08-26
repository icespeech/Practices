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
    vector<int> height;
    int result = sol.maxArea(height);

    EXPECT_EQ(0, result);
}

TEST(OneElementTest, OneElementTest)
{
    Solution sol;
    vector<int> height{ 3 };
    int result = sol.maxArea(height);

    EXPECT_EQ(0, result);
}

TEST(TwoElementsTest, TwoElementsTest)
{
    Solution sol;
    vector<int> height{ 4, 6 };
    int result = sol.maxArea(height);
    EXPECT_EQ(4, result);

    vector<int> height2{ 2, 2 };
    result = sol.maxArea(height2);
    EXPECT_EQ(2, result);
}

TEST(MultipleElementsTest, MultipleElementsTest)
{
    Solution sol;
    vector<int> height{ 4, 6, 2, 1, 3, 7, 8, 5 };
    int result = sol.maxArea(height);

    EXPECT_EQ(30, result);
}

TEST(LeetcodeTestcaseTest, LeetcodeTestcaseTest)
{
    Solution sol;
    vector<int> height{ 68, 113, 143, 194, 176, 62, 158, 162, 103, 75,
                        104, 179, 189, 150, 151, 180, 76, 158, 158, 19,
                        198, 42, 119, 13, 127, 158, 193, 59, 146, 80, 41,
                        15, 193, 184, 161, 121, 198, 71, 83, 102, 146, 139,
                        33, 135, 89, 184, 115, 117, 142, 25, 136, 93, 67,
                        7, 106, 146, 165, 100, 6, 64, 180, 47, 31, 125,
                        183, 192, 46, 182, 63, 129, 36, 161, 68, 69, 96,
                        110, 54, 164, 27, 148, 189, 116, 41, 9, 123, 100,
                        155, 89, 152, 113, 153, 84, 160, 184, 9, 144, 128,
                        55, 78, 143 };
    int result = sol.maxArea(height);

    EXPECT_EQ(16560, result);
}

TEST(LeetcodeTestcaseTest2, LeetcodeTestcaseTest2)
{
    Solution sol;
    vector<int> height{ 1, 2, 1 };
    int result = sol.maxArea(height);

    EXPECT_EQ(2, result);
}