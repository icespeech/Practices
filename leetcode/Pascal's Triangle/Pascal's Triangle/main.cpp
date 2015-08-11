#include "Solution.h"
#include "gtest\gtest.h"

using std::string;

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    // pause to show the results
    getchar();
    return 0;
}

TEST(BasicTest, BasicTest)
{
    Solution sol;
    
    EXPECT_EQ(0, sol.generate(0).size());
    auto result = sol.generate(1);
    EXPECT_EQ(1, result.size());
    EXPECT_EQ(1, result[0].size());
    EXPECT_EQ(1, result[0][0]);
}

TEST(LeetcodeExampleTest, LeetcodeExampleTest)
{
    Solution sol;
    auto result = sol.generate(5);

    EXPECT_EQ(5, result.size());
    EXPECT_EQ(1, result[0].size());
    EXPECT_EQ(2, result[1].size());
    EXPECT_EQ(3, result[2].size());
    EXPECT_EQ(4, result[3].size());
    EXPECT_EQ(5, result[4].size());

    EXPECT_EQ(1, result[0][0]);

    EXPECT_EQ(1, result[1][0]);
    EXPECT_EQ(1, result[1][1]);

    EXPECT_EQ(1, result[2][0]);
    EXPECT_EQ(2, result[2][1]);
    EXPECT_EQ(1, result[2][2]);

    EXPECT_EQ(1, result[3][0]);
    EXPECT_EQ(3, result[3][1]);
    EXPECT_EQ(3, result[3][2]);
    EXPECT_EQ(1, result[3][3]);

    EXPECT_EQ(1, result[4][0]);
    EXPECT_EQ(4, result[4][1]);
    EXPECT_EQ(6, result[4][2]);
    EXPECT_EQ(4, result[4][3]);
    EXPECT_EQ(1, result[4][4]);
}