/*
783. Minimum Distance Between BST Nodes

Given the root of a Binary Search Tree (BST), return the minimum difference 
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
    int res = 1e6; int v = -1;
public:
    int minDiffInBST(TreeNode* root)
    {
        if (root->left)
            minDiffInBST(root->left);

        if (v >= 0)
            res = std::min(res, root->val - v);

        v = root->val;

        if (root->right)
            minDiffInBST(root->right);

        return res;
    }
};
