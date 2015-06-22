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

/* Empty Tests */

TEST(EmptyTest, EmptyPattern)
{
	Solution sol;

	EXPECT_TRUE(sol.isMatch("", ""));
	EXPECT_FALSE(sol.isMatch("k", ""));
	EXPECT_FALSE(sol.isMatch("abc", ""));
}

TEST(EmptyTest, EmptyInputSimplePattern)
{
	Solution sol;

	EXPECT_FALSE(sol.isMatch("", "n"));
	EXPECT_FALSE(sol.isMatch("", "cba"));
}

TEST(EmptyTest, EmptyInputWildCardsPattern)
{
	Solution sol;

	EXPECT_TRUE(sol.isMatch("", "*"));
	EXPECT_FALSE(sol.isMatch("", "?"));
	EXPECT_FALSE(sol.isMatch("", "*?"));
	EXPECT_FALSE(sol.isMatch("", "?*"));
	EXPECT_TRUE(sol.isMatch("", "**"));
}

TEST(EmptyTest, EmptyInputComplicatedPattern)
{
	Solution sol;

	EXPECT_FALSE(sol.isMatch("", "*abc"));
	EXPECT_FALSE(sol.isMatch("", "?abc"));
	EXPECT_FALSE(sol.isMatch("", "*?abc"));
}


/* One Character Input Tests */

TEST(OneCharacterInputTest, OneCharacterPattern)
{
	Solution sol;
	EXPECT_TRUE(sol.isMatch("t", "t"));
	EXPECT_FALSE(sol.isMatch("t", "j"));
}

TEST(OneCharacterInputTest, ManyCharactersPattern)
{
	Solution sol;

	// Head included
	EXPECT_FALSE(sol.isMatch("t", "tuv"));
	// Tail included
	EXPECT_FALSE(sol.isMatch("t", "rst"));
	// Totally excluded
	EXPECT_FALSE(sol.isMatch("t", "ghi"));
}

TEST(OneCharacterInputTest, WildCardsPattern)
{
	Solution sol;

	EXPECT_TRUE(sol.isMatch("t", "*"));
	EXPECT_TRUE(sol.isMatch("t", "?"));

	EXPECT_TRUE(sol.isMatch("t", "*?"));
	EXPECT_TRUE(sol.isMatch("t", "?*"));
	EXPECT_TRUE(sol.isMatch("t", "**"));
	EXPECT_FALSE(sol.isMatch("t", "??"));

	EXPECT_TRUE(sol.isMatch("t", "*?*"));

}

TEST(OneCharacterInputTest, ComplicatedPattern)
{
	Solution sol;

	EXPECT_FALSE(sol.isMatch("t", "t?"));
	EXPECT_TRUE(sol.isMatch("t", "t*"));

	EXPECT_FALSE(sol.isMatch("t", "t?*"));
	EXPECT_FALSE(sol.isMatch("t", "t*?"));

	EXPECT_FALSE(sol.isMatch("t", "*?t"));
	EXPECT_FALSE(sol.isMatch("t", "?*t"));

	EXPECT_FALSE(sol.isMatch("t", "?t*"));
	EXPECT_FALSE(sol.isMatch("t", "*t?"));
	EXPECT_TRUE(sol.isMatch("t", "*t*"));
}

/* Duplicated Two Characters Input Tests */

TEST(DupTwoCharsInputTest, OneCharacterPattern)
{
	Solution sol;

	EXPECT_FALSE(sol.isMatch("tt", "t"));
	EXPECT_FALSE(sol.isMatch("tt", "j"));
}

TEST(DupTwoCharsInputTest, TwoCharactersPattern)
{
	Solution sol;

	EXPECT_TRUE(sol.isMatch("tt", "tt"));
	// Intersects
	EXPECT_FALSE(sol.isMatch("tt", "tj"));
	EXPECT_FALSE(sol.isMatch("tt", "jt"));
	// Excluded
	EXPECT_FALSE(sol.isMatch("tt", "jk"));
	EXPECT_FALSE(sol.isMatch("tt", "jj"));
}

TEST(DupTwoCharsInputTest, ManyCharactersPattern)
{
	Solution sol;

	EXPECT_FALSE(sol.isMatch("tt", "ttt"));
	EXPECT_FALSE(sol.isMatch("tt", "stt"));
	EXPECT_FALSE(sol.isMatch("tt", "ttu"));
	EXPECT_FALSE(sol.isMatch("tt", "stu"));
	EXPECT_FALSE(sol.isMatch("tt", "ghi"));
}

TEST(DupTwoCharsInputTest, WildCardsPattern)
{
	Solution sol;

	EXPECT_TRUE(sol.isMatch("tt", "*"));
	EXPECT_FALSE(sol.isMatch("tt", "?"));

	EXPECT_TRUE(sol.isMatch("tt", "*?"));
	EXPECT_TRUE(sol.isMatch("tt", "?*"));
	EXPECT_TRUE(sol.isMatch("tt", "**"));
	EXPECT_TRUE(sol.isMatch("tt", "??"));

	EXPECT_TRUE(sol.isMatch("tt", "?*?"));
	EXPECT_TRUE(sol.isMatch("tt", "*?*"));
	EXPECT_TRUE(sol.isMatch("tt", "***"));
	EXPECT_FALSE(sol.isMatch("tt", "???"));
}

TEST(DupTwoCharsInputTest, ComplicatedPattern)
{
	Solution sol;

	EXPECT_TRUE(sol.isMatch("tt", "t?"));
	EXPECT_TRUE(sol.isMatch("tt", "t*"));
	EXPECT_TRUE(sol.isMatch("tt", "*t"));
	EXPECT_TRUE(sol.isMatch("tt", "?t"));

	EXPECT_FALSE(sol.isMatch("tt", "?s"));
	EXPECT_FALSE(sol.isMatch("tt", "*s"));
	EXPECT_FALSE(sol.isMatch("tt", "s?"));
	EXPECT_FALSE(sol.isMatch("tt", "s*"));

	EXPECT_TRUE(sol.isMatch("tt", "t?*"));
	EXPECT_TRUE(sol.isMatch("tt", "t*?"));
	EXPECT_TRUE(sol.isMatch("tt", "t**"));
	// false
	EXPECT_FALSE(sol.isMatch("tt", "t??"));

	EXPECT_TRUE(sol.isMatch("tt", "?t*"));
	EXPECT_TRUE(sol.isMatch("tt", "*t?"));
	EXPECT_TRUE(sol.isMatch("tt", "*t*"));
	// false
	EXPECT_FALSE(sol.isMatch("tt", "?t?"));

	EXPECT_TRUE(sol.isMatch("tt", "*?t"));
	EXPECT_TRUE(sol.isMatch("tt", "?*t"));
	EXPECT_TRUE(sol.isMatch("tt", "**t"));
	// false
	EXPECT_FALSE(sol.isMatch("tt", "??t"));

	EXPECT_TRUE(sol.isMatch("tt", "*?t*"));
}

/* Many Characters Input Tests */

TEST(ManyCharInputTest, PartiallyIncludePattern)
{
	Solution sol;

	EXPECT_FALSE(sol.isMatch("test", "t"));
	EXPECT_FALSE(sol.isMatch("test", "te"));
	EXPECT_FALSE(sol.isMatch("test", "es"));
	EXPECT_FALSE(sol.isMatch("test", "st"));
	EXPECT_FALSE(sol.isMatch("test", "est"));

	EXPECT_TRUE(sol.isMatch("test", "test"));
}

TEST(ManyCharInputTest, ExcludedShorterPattern)
{
	Solution sol;

	EXPECT_FALSE(sol.isMatch("test", "v"));
	EXPECT_FALSE(sol.isMatch("test", "ca"));
	EXPECT_FALSE(sol.isMatch("test", "cave"));
}

TEST(ManyCharInputTest, LongerPattern)
{
	Solution sol;

	EXPECT_FALSE(sol.isMatch("test", "test "));
	EXPECT_FALSE(sol.isMatch("test", "teste"));
	EXPECT_FALSE(sol.isMatch("test", " test"));
	EXPECT_FALSE(sol.isMatch("test", "t est"));
	EXPECT_FALSE(sol.isMatch("test", "hahaha"));
}

TEST(ManyCharInputTest, WildCardsPattern)
{
	Solution sol;

	EXPECT_TRUE(sol.isMatch("test", "*"));
	EXPECT_FALSE(sol.isMatch("test", "?"));

	EXPECT_TRUE(sol.isMatch("test", "*?"));
	EXPECT_TRUE(sol.isMatch("test", "?*"));
	EXPECT_TRUE(sol.isMatch("test", "**"));
	EXPECT_FALSE(sol.isMatch("test", "??"));

	EXPECT_TRUE(sol.isMatch("test", "?*?"));
	EXPECT_TRUE(sol.isMatch("test", "*?*"));
	EXPECT_TRUE(sol.isMatch("test", "***"));
	EXPECT_FALSE(sol.isMatch("test", "???"));

	EXPECT_TRUE(sol.isMatch("test", "????"));
}

TEST(ManyCharInputTest, ComplicatedPattern)
{
	Solution sol;

	EXPECT_FALSE(sol.isMatch("test", "t?"));
	EXPECT_TRUE(sol.isMatch("test", "t*"));
	EXPECT_TRUE(sol.isMatch("test", "*t"));
	EXPECT_FALSE(sol.isMatch("test", "?t"));

	EXPECT_FALSE(sol.isMatch("test", "?s"));
	EXPECT_FALSE(sol.isMatch("test", "*s"));
	EXPECT_FALSE(sol.isMatch("test", "s?"));
	EXPECT_FALSE(sol.isMatch("test", "s*"));

	EXPECT_TRUE(sol.isMatch("test", "t?*"));
	EXPECT_TRUE(sol.isMatch("test", "t*?"));
	EXPECT_TRUE(sol.isMatch("test", "t**"));
	EXPECT_FALSE(sol.isMatch("test", "t??"));

	EXPECT_FALSE(sol.isMatch("test", "?t*"));
	EXPECT_FALSE(sol.isMatch("test", "*t?"));
	EXPECT_TRUE(sol.isMatch("test", "*t*"));
	EXPECT_FALSE(sol.isMatch("test", "?t?"));

	EXPECT_TRUE(sol.isMatch("test", "*?t"));
	EXPECT_TRUE(sol.isMatch("test", "?*t"));
	EXPECT_TRUE(sol.isMatch("test", "**t"));
	// false
	EXPECT_FALSE(sol.isMatch("test", "??t"));

	EXPECT_TRUE(sol.isMatch("test", "*?t*"));
	EXPECT_TRUE(sol.isMatch("test", "???t"));
	EXPECT_TRUE(sol.isMatch("test", "t???"));
	EXPECT_FALSE(sol.isMatch("test", "??t?"));
	EXPECT_TRUE(sol.isMatch("test", "??s?"));
	EXPECT_FALSE(sol.isMatch("test", "?*t?"));
}


/* Special Character Input */
TEST(OneSpecialCharInputTest, ZeroAndOneCharPattern)
{
	Solution sol;

	EXPECT_FALSE(sol.isMatch("*", ""));
	EXPECT_FALSE(sol.isMatch("*", "a"));
	EXPECT_TRUE(sol.isMatch("*", "?"));
	EXPECT_TRUE(sol.isMatch("*", "*"));
}
