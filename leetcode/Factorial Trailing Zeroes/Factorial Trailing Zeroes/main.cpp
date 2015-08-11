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

TEST(BasicTest, BasicTest)
{
    Solution sol;

    EXPECT_EQ(0, sol.trailingZeroes(0));
    EXPECT_EQ(0, sol.trailingZeroes(1));
    EXPECT_EQ(6, sol.trailingZeroes(25));
    EXPECT_EQ(22, sol.trailingZeroes(99));
    EXPECT_EQ(536870902, sol.trailingZeroes(2147483647));
}