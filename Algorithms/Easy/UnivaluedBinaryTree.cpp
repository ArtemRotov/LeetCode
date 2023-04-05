/*
965. Univalued Binary Tree

A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued,
or false otherwise.

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
    bool isUnivalTree(TreeNode* root)
    {
        if (!root)
            return true;
        return help(root, root->val);
    }

    bool help(TreeNode* root, int value)
    {
        if (!root)
            return true;

        if (root->val != value)
            return false;

        return help(root->left, value) && help(root->right, value);
    }
};
