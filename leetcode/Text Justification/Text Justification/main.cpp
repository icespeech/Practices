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

    EXPECT_EQ(0, sol.fullJustify(vector<string>(), 0).size());
}

TEST(EmptyTest, EmptyTest2)
{
    Solution sol;
    auto result = sol.fullJustify(vector<string>({ "" }), 0);

    EXPECT_EQ(1, result.size());
    EXPECT_STREQ("", result[0].c_str());
}

TEST(EmptyTest, EmptyTest3)
{
    Solution sol;
    auto result = sol.fullJustify(vector<string>({"", "", ""}), 0);

    EXPECT_EQ(3, result.size());
    EXPECT_STREQ("", result[0].c_str());
    EXPECT_STREQ("", result[1].c_str());
    EXPECT_STREQ("", result[2].c_str());
}

TEST(EmptyTest, EmptyLinesTest1)
{
    Solution sol;
    auto result = sol.fullJustify(vector<string>({ "", "" }), 2);
    EXPECT_EQ(1, result.size());
    EXPECT_STREQ("  ", result[0].c_str());
}

TEST(EmptyTest, EmptyLinesTest2)
{
    Solution sol;
    auto result = sol.fullJustify(vector<string>({ "a", "", "" }), 2);
    EXPECT_EQ(2, result.size());
    EXPECT_STREQ("a ", result[0].c_str());
    EXPECT_STREQ("  ", result[1].c_str());
}

TEST(EmptyTest, EmptyLinesTest3)
{
    Solution sol;
    auto result = sol.fullJustify(vector<string>({ "", "", "a" }), 2);
    EXPECT_EQ(2, result.size());
    EXPECT_STREQ("  ", result[0].c_str());
    EXPECT_STREQ("a ", result[1].c_str());
}

TEST(SingleCharacterTest, SingleCharacterTest)
{
    Solution sol;
    auto result = sol.fullJustify(vector<string>({ "a" }), 1);

    EXPECT_EQ(1, result.size());
    EXPECT_STREQ("a", result[0].c_str());
}

TEST(SingleWordTest, SingleWordTest)
{
    Solution sol;
    auto result = sol.fullJustify(vector<string>({ "Ha" }), 4);

    EXPECT_EQ(1, result.size());
    EXPECT_STREQ("Ha  ", result[0].c_str());
}

TEST(SingleWordTest, SingleWordTest2)
{
    Solution sol;
    auto result = sol.fullJustify(vector<string>({ "Ha" }), 2);

    EXPECT_EQ(1, result.size());
    EXPECT_STREQ("Ha", result[0].c_str());
}

TEST(ManyWordsTest, ManyWordsTest)
{
    Solution sol;
    auto result = sol.fullJustify(vector<string>({ "An", "apple", "a", "day", "keeps", "the", "doctors", "away." }), 10);

    EXPECT_EQ(5, result.size());
    EXPECT_STREQ("An apple a", result[0].c_str());
    EXPECT_STREQ("day  keeps", result[1].c_str());
    EXPECT_STREQ("the       ", result[2].c_str());
    EXPECT_STREQ("doctors   ", result[3].c_str());
    EXPECT_STREQ("away.     ", result[4].c_str());
}

TEST(LeetcodeExampleTest, LeetcodeExampleTest)
{
    Solution sol;
    auto result = sol.fullJustify(vector<string>({ "This", "is", "an", "example", "of", "text", "justification." }), 16);
    
    EXPECT_EQ(3, result.size());
    for (auto r : result)
    {
        EXPECT_EQ(16, r.size());
    }
}