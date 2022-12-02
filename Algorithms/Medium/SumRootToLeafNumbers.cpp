/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root)
    {
        return Dfs(root,0);
    }

    int Dfs (TreeNode* root, int sum)
    {
        if (!root)
            return 0;

        sum = sum * 10 + root->val;

        if (!root->left && !root->right)
            return sum;

        sum = Dfs(root->left,sum) + Dfs(root->right,sum);

        return sum;
    }
};
