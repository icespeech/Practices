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

    EXPECT_EQ(0, sol.levelOrder(nullptr).size());
}

TEST(OneLevelTest, OneLevelTest)
{
    Solution sol;
    TreeNode l1(5);

    auto result = sol.levelOrder(&l1);

    EXPECT_EQ(1, result.size());
    EXPECT_EQ(1, result[0].size());
    EXPECT_EQ(5, result[0][0]);
}

TEST(LeetcodeExampleTest, LeetcodeExampleTest)
{
    Solution sol;
    TreeNode l1(3);
    TreeNode l2l(9);
    TreeNode l2r(20);
    TreeNode l3l(15);
    TreeNode l3r(7);

    l1.left = &l2l;
    l1.right = &l2r;
    l2r.left = &l3l;
    l2r.right = &l3r;

    auto result = sol.levelOrder(&l1);

    EXPECT_EQ(3, result.size());
    
    EXPECT_EQ(1, result[0].size());
    EXPECT_EQ(2, result[1].size());
    EXPECT_EQ(2, result[2].size());

    EXPECT_EQ(3, result[0][0]);
    EXPECT_EQ(9, result[1][0]);
    EXPECT_EQ(20, result[1][1]);
    EXPECT_EQ(15, result[2][0]);
    EXPECT_EQ(7, result[2][1]);
}