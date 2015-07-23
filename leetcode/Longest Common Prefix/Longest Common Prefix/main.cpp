#include "Solution.h"
#include "gtest\gtest.h"

using std::string;
using std::vector;

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    // pause to show the results
    getchar();
    return 0;
}

TEST(EmptyInputTest, EmptyInputTest)
{
    Solution sol;
    std::vector<string> strs;

    EXPECT_STREQ("", sol.longestCommonPrefix(strs).c_str());
}

TEST(EmptyStringTest, EmptyStringTest)
{
    Solution sol;
    std::vector<string> strs1 = { "", "" };
    std::vector<string> strs2 = { "", "", "" };
    std::vector<string> strs3 = { "", "", "", "", "", "" };

    EXPECT_STREQ("", sol.longestCommonPrefix(strs1).c_str());
    EXPECT_STREQ("", sol.longestCommonPrefix(strs2).c_str());
    EXPECT_STREQ("", sol.longestCommonPrefix(strs3).c_str());
}

TEST(SameInputTest, SameInputTest)
{
    Solution sol;
    std::vector<string> strs1 = { "a", "a" };
    std::vector<string> strs2 = { "abc", "abc" };
    std::vector<string> strs3 = { "abcdef", "abcdef", "abcdef", "abcdef", "abcdef", "abcdef", "abcdef", "abcdef" };

    EXPECT_STREQ("a", sol.longestCommonPrefix(strs1).c_str());
    EXPECT_STREQ("abc", sol.longestCommonPrefix(strs2).c_str());
    EXPECT_STREQ("abcdef", sol.longestCommonPrefix(strs3).c_str());
}

TEST(SameInputTest, SameInputTest)
{
    Solution sol;
    std::vector<string> strs1 = { "a", "a" };
    std::vector<string> strs2 = { "abc", "abc" };
    std::vector<string> strs3 = { "abcdef", "abcdef", "abcdef", "abcdef", "abcdef", "abcdef", "abcdef", "abcdef" };

    EXPECT_STREQ("a", sol.longestCommonPrefix(strs1).c_str());
    EXPECT_STREQ("abc", sol.longestCommonPrefix(strs2).c_str());
    EXPECT_STREQ("abcdef", sol.longestCommonPrefix(strs3).c_str());
}

TEST(SimpleInputTest, SameInputTest)
{
    Solution sol;
    std::vector<string> strs1 = { "a", "a" };
    std::vector<string> strs2 = { "abc", "abc" };

    EXPECT_STREQ("a", sol.longestCommonPrefix(strs1).c_str());
    EXPECT_STREQ("abc", sol.longestCommonPrefix(strs2).c_str());
}