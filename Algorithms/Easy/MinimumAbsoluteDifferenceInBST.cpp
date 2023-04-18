/*
530. Minimum Absolute Difference in BST

Given the root of a Binary Search Tree (BST), return the minimum absolute difference 
between the values of any two different nodes in the tree.

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
    int res = INT_MAX; int val = -1;
public:
    int getMinimumDifference(TreeNode* root) 
    {
        if (root->left)
            getMinimumDifference(root->left);
        
        if (val >= 0)
            res = std::min(res, root->val - val);
        
        val = root->val;

        if (root->right)
            getMinimumDifference(root->right);
        
        return res;
    }
};
