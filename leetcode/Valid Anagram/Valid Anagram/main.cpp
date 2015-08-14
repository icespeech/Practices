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

    EXPECT_TRUE(sol.isAnagram("", ""));
}

TEST(OneCharacterTest, OneCharacterTest)
{
    Solution sol;

    EXPECT_TRUE(sol.isAnagram("a", "a"));
    EXPECT_FALSE(sol.isAnagram("a", "b"));
    EXPECT_FALSE(sol.isAnagram("a", ""));
}

TEST(LeetcodeExampleTest, LeetcodeExampleTest)
{
    Solution sol;

    EXPECT_FALSE(sol.isAnagram("rat", "cat"));
    EXPECT_TRUE(sol.isAnagram("anagram", "nagaram"));
}