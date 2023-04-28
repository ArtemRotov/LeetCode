/*
111. Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

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
    int minDepth(TreeNode* root)
    {
        if (!root)
            return 0;
        return helper(root) + 1;
    }

    int helper(TreeNode* root, int depth = 0)
    {
        if (!root)
            return INT_MAX;
        if (!root->left && !root->right)
            return depth;

        return std::min(helper(root->left, depth + 1), helper(root->right, depth + 1));
    }
};
