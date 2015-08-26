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
    int result = sol.divide(0, 0);

    EXPECT_EQ(INT_MAX, result);
}

TEST(SimpleTest, SimpleTest)
{
    Solution sol;
    EXPECT_EQ(123456789 / 12, sol.divide(123456789, 12));
    EXPECT_EQ(987654321 / -3, sol.divide(987654321, -3));
    EXPECT_EQ(INT_MIN / -2, sol.divide(INT_MIN, -2));
    // special case
    EXPECT_EQ(INT_MAX, sol.divide(INT_MIN, -1));
    EXPECT_EQ(-999999999 / -5, sol.divide(-999999999, -5));
    EXPECT_EQ(1004958205 / -2137325331, sol.divide(1004958205, -2137325331));
    EXPECT_EQ(-1004958205 / -2137325331, sol.divide(-1004958205, -2137325331));
    EXPECT_EQ(-1004958205 / INT_MIN, sol.divide(-1004958205, INT_MIN));
    EXPECT_EQ(0 / 5, sol.divide(0, 5));
    EXPECT_EQ(0 / 5, sol.divide(0, -5));
    EXPECT_EQ(2 / 2, sol.divide(2, 2));
}