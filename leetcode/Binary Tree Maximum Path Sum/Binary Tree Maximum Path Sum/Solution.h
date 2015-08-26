/**
* Definition for a binary tree node.
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
    int maxSum;
    int recursiveResult(TreeNode* root);
public:
    int maxPathSum(TreeNode* root);
};