#include "Solution.h"
#include "gtest/gtest.h"

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    getchar();
    return 0;
}

TEST(EmptyInputTest, EmptyInputTest)
{
    Solution sol;

    EXPECT_STREQ("", sol.longestPalindrome("").c_str());
}

TEST(OneCharacterInputTest, OneCharacterInputTest)
{
    Solution sol;

    EXPECT_STREQ("a", sol.longestPalindrome("a").c_str());
}


TEST(DuplicateSubstringTest, DuplicateSubstringTest)
{
    Solution sol;

    EXPECT_STREQ("aa", sol.longestPalindrome("aa").c_str());
    EXPECT_STREQ("aa", sol.longestPalindrome("baa").c_str());
    EXPECT_STREQ("aaa", sol.longestPalindrome("aaa").c_str());
}


TEST(SimplePalindromTest, SimplePalindromTest)
{
    Solution sol;

    EXPECT_STREQ("aba", sol.longestPalindrome("aba").c_str());
    EXPECT_STREQ("abcba", sol.longestPalindrome("abcba").c_str());
    EXPECT_STREQ("abcdcba", sol.longestPalindrome("abcdcba").c_str());
}

TEST(SimplePalindromicSubstringTest, SimplePalindromicSubstringTest)
{
    Solution sol;

    EXPECT_STREQ("aba", sol.longestPalindrome("abadc").c_str());
    EXPECT_STREQ("abcba", sol.longestPalindrome("kjabcbasd").c_str());
    EXPECT_STREQ("abcdcba", sol.longestPalindrome("qabcdcba").c_str());
}

TEST(ComplicatedTest, ComplicatedTest)
{
    Solution sol;

    EXPECT_STREQ("ABCBCBA", sol.longestPalindrome("BBABCBCBA").c_str());
    EXPECT_STREQ("ACBBCA", sol.longestPalindrome("BCACBBCA").c_str());
    EXPECT_STREQ("AAAA", sol.longestPalindrome("AAAA").c_str());
    EXPECT_STREQ("XYXYXYXYXYXYXYXYXYXYXYXYXYX", sol.longestPalindrome("XYXYXYXYXYXYXYXYXYXYXYXYXYX").c_str());
    EXPECT_STREQ("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", sol.longestPalindrome("AAAAAAAAAABCAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA").c_str());
}