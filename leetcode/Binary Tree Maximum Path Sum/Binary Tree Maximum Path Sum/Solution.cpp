#include "Solution.h"
#include <climits>

int Solution::recursiveResult(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    int rl = recursiveResult(root->left);
    int rr = recursiveResult(root->right);
    int ret;

    if (rl > 0 && rr > 0)
    {
        int tmp = root->val + rr + rl;
        if (tmp > maxSum)
            maxSum = tmp;

        return root->val + (rl > rr ? rl : rr);
    }
    else
    {
        if (rl > 0)
            ret = root->val + rl;
        else if (rr > 0)
            ret = root->val + rr;
        else
            ret = root->val;
    }

    if (ret > maxSum)
        maxSum = ret;
    return ret;
}

int Solution::maxPathSum(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    maxSum = INT_MIN;
    int result = recursiveResult(root);
    return (maxSum > result) ? maxSum: result;
}