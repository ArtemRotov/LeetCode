/*
1302. Deepest Leaves Sum

Given the root of a binary tree, return the sum of values of its deepest leaves.

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
    int deepestLeavesSum(TreeNode* root) 
    {
        int sum = 0;
        int maxDepth = 0;
        helper(root, sum, maxDepth);
        return sum;
    }
    
    void helper(TreeNode* root,  int &sum, int &maxDepth, int depth = 0)
    {
        if (!root)
            return;
        
        helper(root->left, sum, maxDepth, depth + 1);
        helper(root->right, sum, maxDepth, depth + 1);

        if (!root->left && !root->right)
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                sum = 0;
            }
            if (depth == maxDepth)
                sum += root->val;
        }
    }
};
