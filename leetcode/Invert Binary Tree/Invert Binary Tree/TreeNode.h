/*
* Definition for a binary tree node.
*/
struct TreeNode
{
	TreeNode(int x) :
	val(x),
	left(nullptr),
	right(nullptr)
	{
	}

	int val;
	TreeNode *left;
	TreeNode *right;
};