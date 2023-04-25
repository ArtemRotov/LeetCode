/*
110. Balanced Binary Tree

Given a binary tree, determine if it is  height-balanced

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
    bool isBalanced(TreeNode* root)
    {
        if (!root)
            return true;

        if (helper(root) == -1) return false;

        return true;
    }

    int helper(TreeNode* root)
    {
        if (!root)
            return 0;

        int leftDepth = helper(root->left);
        int rightDepth = helper(root->right);

        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1) return -1;

        return std::max(leftDepth, rightDepth) + 1;
    }
};
