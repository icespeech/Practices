#include "SolutionClass.h"
#include <algorithm>

void PostOrderSwapSubTrees(TreeNode* node)
{
	if (node->left == nullptr && node->right == nullptr)
		return;

	if (node->left != nullptr)
		PostOrderSwapSubTrees(node->left);

	if (node->right != nullptr)
		PostOrderSwapSubTrees(node->right);

	std::swap(node->left, node->right);
}

TreeNode* Solution::invertTree(TreeNode* root)
{
	if (root == nullptr)
		return nullptr;

	PostOrderSwapSubTrees(root);
	return root;
}