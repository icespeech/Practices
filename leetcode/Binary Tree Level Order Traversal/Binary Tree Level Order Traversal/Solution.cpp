#include "Solution.h"
using std::vector;

vector<vector<int>> Solution::levelOrder(TreeNode* root)
{
    if (root == nullptr) return vector<vector<int>>();

    vector<vector<int>> ret;
    vector<TreeNode*> level;

    level.push_back(root);

    while (level.size() > 0)
    {
        vector<TreeNode*> tmpLevel;
        vector<int> tmpRetLevel;

        for (auto tn : level)
        {
            tmpRetLevel.push_back(tn->val);

            if (tn->left != nullptr)
                tmpLevel.push_back(tn->left);
            if (tn->right != nullptr)
                tmpLevel.push_back(tn->right);
        }
        ret.push_back(tmpRetLevel);
        level = tmpLevel;
    }

    return ret;
}