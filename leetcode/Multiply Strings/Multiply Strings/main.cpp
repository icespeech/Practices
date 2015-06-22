#include "Solution.h"
#include "gtest/gtest.h"

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	getchar();
	return 0;
}

TEST(BasicTest, SimpleMultiply)
{
	Solution solution;
	EXPECT_STREQ("1", solution.multiply("1", "1").c_str());
}

TEST(BasicTest, MultiplyEasyNumbers)
{
	Solution solution;
	EXPECT_STREQ("56088", solution.multiply("123", "456").c_str());
}

TEST(BasicTest, MultiplyEasyNumbersForCarries)
{
	Solution solution;
	EXPECT_STREQ("516006", solution.multiply("789", "654").c_str());
}

TEST(BigNumberTest, MultiplyLongPositiveNumberWithShort)
{
    Solution solution;
    EXPECT_STREQ("135802468864197531", solution.multiply("12345678987654321", "11").c_str());
}

TEST(BigNumberTest, MultiplyLongPositiveNumbers)
{
    Solution solution;
    EXPECT_STREQ("1219326320073159566072245112635269", solution.multiply("12345678987654321", "98765432123456789").c_str());
}

TEST(ZeroTest, MultiplyLeftZero)
{
	Solution solution;
	EXPECT_STREQ("0", solution.multiply("0", "98765432123456789").c_str());
}

TEST(ZeroTest, MultiplyRightZero)
{
	Solution solution;
	EXPECT_STREQ("0", solution.multiply("12345678987654321", "0").c_str());
}

TEST(ZeroTest, MultiplyAllZero)
{
	Solution solution;
	EXPECT_STREQ("0", solution.multiply("0", "0").c_str());
}
