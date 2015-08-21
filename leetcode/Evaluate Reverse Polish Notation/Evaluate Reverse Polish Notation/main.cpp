#include "Solution.h"
#include "gtest\gtest.h"
using std::vector;
using std::string;

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
    auto result = sol.evalRPN(vector<string>());

    EXPECT_EQ(0, result);
}