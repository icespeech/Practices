#include "SolutionClass.h"
#include "gtest/gtest.h"

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	getchar();
	return 0;
}

TEST(BasicTest, MultiplyShortPositiveNumbers)
{
	Solution solution;
	EXPECT_STREQ("1", solution.multiply("1", "1").c_str());
}

TEST(BasicTest, MultiplyLongPositiveNumberWithShort)
{
    Solution solution;
    EXPECT_STREQ("135802468864197531", solution.multiply("12345678987654321", "11").c_str());
}

TEST(BasicTest, MultiplyLongPositiveNumbers)
{
    Solution solution;
    EXPECT_STREQ("1219326320073159566072245112635269", solution.multiply("12345678987654321", "98765432123456789").c_str());
}