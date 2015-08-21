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

TEST(OneElementTest, OneElementTest)
{
    Solution sol;
    auto result = sol.evalRPN(vector<string>({"1"}));

    EXPECT_EQ(1, result);
}

TEST(SimpleCalculatingTest, SimpleCalculatingTest)
{
    Solution sol;
    auto result = sol.evalRPN(vector<string>({ "1", "2", "+" }));

    EXPECT_EQ(3, result);
}

TEST(LeetcodeExampleTest, LeetcodeExampleTest)
{
    Solution sol;
    auto result = sol.evalRPN(vector<string>({ "2", "1", "+", "3", "*" }));
    EXPECT_EQ(9, result);

    result = sol.evalRPN(vector<string>({ "4", "13", "5", "/", "+" }));
    EXPECT_EQ(6, result);
}