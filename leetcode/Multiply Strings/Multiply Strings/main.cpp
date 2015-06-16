#include "SolutionClass.h"
#include "gtest/gtest.h"

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(BasicTest, MultiplyShortPositiveNumbers)
{
	Solution solution;
	EXPECT_STREQ("1", solution.multiply("1", "1").c_str());
}