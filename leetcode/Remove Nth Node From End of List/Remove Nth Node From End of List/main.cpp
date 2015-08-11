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

TEST(RemoveFirstTest, RemoveFirstTest)
{
    Solution sol;

    ListNode n1(5), n2(4), n3(3), n4(2), n5(1);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode* result = sol.removeNthFromEnd(&n1, 5);
    
    char resultStr[5] = { 0, 0, 0, 0, 0 };
    int i = 0;
    while (result != nullptr)
    {
        resultStr[i++] = result->val + '0';
        result = result->next;
    }

    EXPECT_STREQ(resultStr, "4321");
}

TEST(RemoveNthTest, RemoveNthTest)
{
    Solution sol;

    ListNode n1(3), n2(2), n3(4), n4(1), n5(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode* result = sol.removeNthFromEnd(&n1, 2);

    char resultStr[5] = { 0, 0, 0, 0, 0 };
    int i = 0;
    while (result != nullptr)
    {
        resultStr[i++] = result->val + '0';
        result = result->next;
    }

    EXPECT_STREQ(resultStr, "3246");
}

TEST(RemoveLastTest, RemoveLastTest)
{
    Solution sol;

    ListNode n1(7), n2(8), n3(4), n4(9);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    ListNode* result = sol.removeNthFromEnd(&n1, 1);
    
    char resultStr[4] = { 0, 0, 0, 0 };
    int i = 0;
    while (result != nullptr)
    {
        resultStr[i++] = result->val + '0';
        result = result->next;
    }

    EXPECT_STREQ(resultStr, "784");
}