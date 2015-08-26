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
    auto result = sol.maxPathSum(nullptr);

    EXPECT_EQ(0, result);
}

TEST(OneNodeTest, OneNodeTest)
{
    Solution sol;
    TreeNode n1(2);
    auto result = sol.maxPathSum(&n1);

    EXPECT_EQ(2, result);
}

TEST(TwoNodesTest, TwoNodesTest)
{
    Solution sol;

    TreeNode n1(2), n2(5);
    n1.right = &n2;
    auto result = sol.maxPathSum(&n1);

    EXPECT_EQ(7, result);
}

TEST(ThreeNodesTest, ThreeNodesTest)
{
    Solution sol;

    TreeNode n1(2), n2(5), n3(1);
    n1.right = &n2;
    n1.left = &n3;
    auto result = sol.maxPathSum(&n1);

    EXPECT_EQ(8, result);
}

TEST(ComplicatedTest, ComplicatedTest)
{
    Solution sol;

    TreeNode n1(10), n2(11), n3(2),
             n4(12), n5(1), n6(3),
             n7(6), n8(4), n9(7),
             n10(5), n11(8), n12(9);
    n1.left = &n2, n1.right = &n3;
    n2.left = &n4, n2.right = &n5;
    n3.right = &n6;
    n5.left = &n7;
    n6.left = &n8, n6.right = &n9;
    n8.left = &n10, n8.right = &n11;
    n11.left = &n12;
    auto result = sol.maxPathSum(&n1);

    EXPECT_EQ(59, result);
}

TEST(NegitiveNodesTest, NegitiveNodesTest)
{
    Solution sol;

    TreeNode n1(2), n2(-1);
    n1.right = &n2;
    auto result = sol.maxPathSum(&n1);

    EXPECT_EQ(2, result);
}

TEST(NegitiveNodesTest, NegitiveNodesTest2)
{
    Solution sol;

    TreeNode n1(-2), n2(6), n3(0), n4(-6);
    n1.left = &n2;
    n2.left = &n3, n2.right = &n4;
    auto result = sol.maxPathSum(&n1);

    EXPECT_EQ(6, result);
}