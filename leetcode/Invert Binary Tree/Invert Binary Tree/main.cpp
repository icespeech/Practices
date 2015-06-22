#include "Solution.h"
#include "gtest/gtest.h"
#include <vector>
using std::vector;

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	getchar();
	return 0;
}

TEST(BasicTest, OneNodeTest)
{

	Solution solution;
	TreeNode node1(1);

	TreeNode* newRoot = solution.invertTree(&node1);

	EXPECT_EQ(node1.val, newRoot->val);
	EXPECT_EQ(&node1, newRoot);
}

TEST(BasicTest, OneRootWithLeftLeafTest)
{
	Solution solution;
	TreeNode node1(1);
	TreeNode node2(2);

	node1.left = &node2;

	TreeNode* newRoot = solution.invertTree(&node1);

	EXPECT_EQ(node1.val, newRoot->val);
	EXPECT_EQ(&node1, newRoot);

	EXPECT_EQ(nullptr, newRoot->left);

	EXPECT_EQ(node2.val, newRoot->right->val);
	EXPECT_EQ(&node2, newRoot->right);
}

TEST(BasicTest, OneRootWithRightLeafTest)
{
	Solution solution;
	TreeNode node1(1);
	TreeNode node3(2);

	node1.right = &node3;

	TreeNode* newRoot = solution.invertTree(&node1);

	EXPECT_EQ(node1.val, newRoot->val);
	EXPECT_EQ(&node1, newRoot);

	EXPECT_EQ(node3.val, newRoot->left->val);
	EXPECT_EQ(&node3, newRoot->left);

	EXPECT_EQ(nullptr, newRoot->right);
}

TEST(BasicTest, OneRootWithTwoLeavesTest)
{
	Solution solution;
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);

	node1.left = &node2;
	node1.right = &node3;

	TreeNode* newRoot = solution.invertTree(&node1);

	EXPECT_EQ(node1.val, newRoot->val);
	EXPECT_EQ(&node1, newRoot);

	EXPECT_EQ(node3.val, newRoot->left->val);
	EXPECT_EQ(&node3, newRoot->left);

	EXPECT_EQ(node2.val, newRoot->right->val);
	EXPECT_EQ(&node2, newRoot->right);
}

TEST(ThreeLayersTest, OneRootWithLeftSubTreeAndRightLeafTest)
{
	Solution solution;
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);

	node1.left = &node2;
	node1.right = &node3;

	node2.left = &node4;
	node2.right = &node5;

	TreeNode* newRoot = solution.invertTree(&node1);

	EXPECT_EQ(node1.val, newRoot->val);
	EXPECT_EQ(&node1, newRoot);

	EXPECT_EQ(node3.val, newRoot->left->val);
	EXPECT_EQ(&node3, newRoot->left);

	EXPECT_EQ(node2.val, newRoot->right->val);
	EXPECT_EQ(&node2, newRoot->right);

	EXPECT_EQ(node5.val, newRoot->right->left->val);
	EXPECT_EQ(&node5, newRoot->right->left);

	EXPECT_EQ(node4.val, newRoot->right->right->val);
	EXPECT_EQ(&node4, newRoot->right->right);
}