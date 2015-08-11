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

TEST(ZeroInputTest, ZeroInputTest)
{
    Solution sol;

    ListNode n1(7), n2(8), n3(4), n4(9);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    ListNode* result = sol.rotateRight(&n1, 0);

    char resultStr[5] = { 0, 0, 0, 0, 0 };
    int i = 0;
    while (result != nullptr)
    {
        resultStr[i++] = result->val + '0';
        result = result->next;
    }

    EXPECT_STREQ(resultStr, "7849");
}

TEST(RotateFirstTest, RotateFirstTest)
{
    Solution sol;

    ListNode n1(5), n2(4), n3(3), n4(2), n5(1);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode* result = sol.rotateRight(&n1, 4);

    char resultStr[6] = { 0, 0, 0, 0, 0, 0 };
    int i = 0;
    while (result != nullptr)
    {
        resultStr[i++] = result->val + '0';
        result = result->next;
    }

    EXPECT_STREQ(resultStr, "43215");
}

TEST(RotateNTest, RotateNTest)
{
    Solution sol;

    ListNode n1(3), n2(2), n3(4), n4(1), n5(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode* result = sol.rotateRight(&n1, 3);

    char resultStr[6] = { 0, 0, 0, 0, 0, 0 };
    int i = 0;
    while (result != nullptr)
    {
        resultStr[i++] = result->val + '0';
        result = result->next;
    }

    EXPECT_STREQ(resultStr, "41632");
}

TEST(RotateLastTest, RotateLastTest)
{
    Solution sol;

    ListNode n1(7), n2(8), n3(4), n4(9);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    ListNode* result = sol.rotateRight(&n1, 1);

    char resultStr[5] = { 0, 0, 0, 0, 0 };
    int i = 0;
    while (result != nullptr)
    {
        resultStr[i++] = result->val + '0';
        result = result->next;
    }

    EXPECT_STREQ(resultStr, "9784");
}

TEST(JustEdgeTest, JustEdgeTest)
{
    Solution sol;

    ListNode n1(7), n2(8), n3(4), n4(9);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    ListNode* result = sol.rotateRight(&n1, 4);

    char resultStr[5] = { 0, 0, 0, 0, 0 };
    int i = 0;
    while (result != nullptr)
    {
        resultStr[i++] = result->val + '0';
        result = result->next;
    }

    EXPECT_STREQ(resultStr, "7849");
}

TEST(OutOfRangeTest, OutOfRangeTest)
{
    Solution sol;

    ListNode n1(7), n2(8), n3(4), n4(9);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    ListNode* result = sol.rotateRight(&n1, 6);

    char resultStr[5] = { 0, 0, 0, 0, 0 };
    int i = 0;
    while (result != nullptr)
    {
        resultStr[i++] = result->val + '0';
        result = result->next;
    }

    EXPECT_STREQ(resultStr, "4978");
}

TEST(VeryLargeTimesTest, VeryLargeTimesTest)
{
    Solution sol;

    ListNode n1(7), n2(8), n3(4), n4(9);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    ListNode* result = sol.rotateRight(&n1, 2000000001);

    char resultStr[5] = { 0, 0, 0, 0, 0 };
    int i = 0;
    while (result != nullptr)
    {
        resultStr[i++] = result->val + '0';
        result = result->next;
    }

    EXPECT_STREQ(resultStr, "9784");
}

TEST(VeryLargeTimesTest2, VeryLargeTimesTest2)
{
    Solution sol;

    ListNode n1(7), n2(8), n3(4), n4(9);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    ListNode* result = sol.rotateRight(&n1, 2000000000);

    char resultStr[5] = { 0, 0, 0, 0, 0 };
    int i = 0;
    while (result != nullptr)
    {
        resultStr[i++] = result->val + '0';
        result = result->next;
    }

    EXPECT_STREQ(resultStr, "7849");
}