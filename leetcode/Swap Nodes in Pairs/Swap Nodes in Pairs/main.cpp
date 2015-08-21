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
    auto result = sol.swapPairs(nullptr);

    EXPECT_EQ(nullptr, result);
}

TEST(OneNodeTest, OneNodeTest)
{
    Solution sol;
    ListNode n1(1);
    auto result = sol.swapPairs(&n1);

    EXPECT_EQ(&n1, result);
}

TEST(TwoNodesTest, TwoNodesTest)
{
    Solution sol;
    ListNode n1(1), n2(2);
    n1.next = &n2;
    auto result = sol.swapPairs(&n1);

    EXPECT_EQ(&n2, result);
    int ans[] = { 2, 1 };

    for (int i : ans)
    {
        EXPECT_EQ(result->val, i);
        result = result->next;
    }
}

TEST(ThreeNodesTest, ThreeNodesTest)
{
    Solution sol;
    ListNode n1(1), n2(2), n3(3);
    n1.next = &n2, n2.next = &n3;
    auto result = sol.swapPairs(&n1);

    EXPECT_EQ(&n2, result);
    int ans[] = { 2, 1, 3 };

    for (int i : ans)
    {
        EXPECT_EQ(result->val, i);
        result = result->next;
    }
}

TEST(LeetcodeExampleTest, LeetcodeExampleTest)
{
    Solution sol;
    ListNode n1(1), n2(2), n3(3), n4(4);
    n1.next = &n2, n2.next = &n3, n3.next = &n4;
    auto result = sol.swapPairs(&n1);

    EXPECT_EQ(&n2, result);
    int ans[] = { 2, 1, 4, 3 };

    for (int i : ans)
    {
        EXPECT_EQ(result->val, i);
        result = result->next;
    }
}