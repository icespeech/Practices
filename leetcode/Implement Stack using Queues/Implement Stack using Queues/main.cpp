#include "Stack.h"
#include "gtest\gtest.h"

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    // pause to show the results
    getchar();
    return 0;
}

TEST(SimpleTest, SimpleTest)
{
    Stack stack;

    EXPECT_TRUE(stack.empty());
    stack.push(1);
    EXPECT_EQ(1, stack.top());
    EXPECT_FALSE(stack.empty());
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(OperationsTest, OperationsTest)
{
    Stack stack;

    EXPECT_TRUE(stack.empty());
    stack.push(1);
    EXPECT_EQ(1, stack.top());
    EXPECT_FALSE(stack.empty());
    stack.pop();
    EXPECT_TRUE(stack.empty());
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(7);
    stack.push(8);
    EXPECT_FALSE(stack.empty());
    stack.pop();
    EXPECT_EQ(7, stack.top());
    stack.pop();
    stack.pop();
    EXPECT_EQ(2, stack.top());
    EXPECT_EQ(2, stack.top());
    stack.push(127);
    EXPECT_EQ(127, stack.top());
    stack.pop();
    stack.pop();
    EXPECT_EQ(1, stack.top());
    stack.pop();
    EXPECT_TRUE(stack.empty());
}