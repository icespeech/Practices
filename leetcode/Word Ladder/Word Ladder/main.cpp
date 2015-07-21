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

TEST(EmptyInputTest, EmptyInputTest)
{
	Solution sol;
	std::unordered_set<string> dict;
	EXPECT_EQ(0, sol.ladderLength("hot", "dog", dict));
}

TEST(NoPathTest, NoPathTest)
{
	Solution sol;
	std::unordered_set<string> dict = { "hit" };

	EXPECT_EQ(0, sol.ladderLength("hot", "dog", dict));
}

TEST(SimplePathTest, SimplePathTest)
{
	Solution sol;
	std::unordered_set<string> dict = { "hot", "dog", "dot" };

	EXPECT_EQ(3, sol.ladderLength("hot", "dog", dict));
}

TEST(LeetCodeExampleTest, LeetCodeExampleTest)
{
	Solution sol;
	std::unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };

	EXPECT_EQ(5, sol.ladderLength("hit", "cog", dict));
}