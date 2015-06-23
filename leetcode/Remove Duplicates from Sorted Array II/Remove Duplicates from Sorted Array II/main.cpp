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

TEST(EmptyInputTest, EmptyInputTest)
{
	Solution sol;
	std::vector<int> v;

	EXPECT_EQ(0, sol.removeDuplicates(v));
	EXPECT_EQ(v.size(), 0);
}

TEST(OneInputTest, OneInputTest)
{
	Solution sol;
	std::vector<int> v(1, 1);

	EXPECT_EQ(1, sol.removeDuplicates(v));
	EXPECT_EQ(v.size(), 1);
	EXPECT_EQ(v[0], 1);
}

TEST(TwoInputsTest, TwoInputsTest)
{
	Solution sol;
	std::vector<int> v1 = { 1, 1 };
	std::vector<int> v2 = { 1, 2 };

	EXPECT_EQ(2, sol.removeDuplicates(v1));
	EXPECT_EQ(v1.size(), 2);
	EXPECT_EQ(v1[0], 1);
	EXPECT_EQ(v1[1], 1);

	EXPECT_EQ(2, sol.removeDuplicates(v2));
	EXPECT_EQ(v2.size(), 2);
	EXPECT_EQ(v2[0], 1);
	EXPECT_EQ(v2[1], 2);
}

TEST(ManyInputsTest, ManyInputsTest)
{
	Solution sol;
	std::vector<int> v1 = { 1, 1, 1 };
	std::vector<int> v2 = { 1, 1, 1, 2, 2, 3 };

	EXPECT_EQ(2, sol.removeDuplicates(v1));
	EXPECT_EQ(v1.size(), 2);
	EXPECT_EQ(v1[0], 1);
	EXPECT_EQ(v1[1], 1);

	EXPECT_EQ(5, sol.removeDuplicates(v2));
	EXPECT_EQ(v2.size(), 5);
	EXPECT_EQ(v2[0], 1);
	EXPECT_EQ(v2[1], 1);
	EXPECT_EQ(v2[2], 2);
	EXPECT_EQ(v2[3], 2);
	EXPECT_EQ(v2[4], 3);
}