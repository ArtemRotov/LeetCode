/*
101. Symmetric Tree

Given the root of a binary tree, check whether it is a mirror
of itself (i.e., symmetric around its center).

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
    bool isSymmetric(TreeNode* root) 
    {
        if (!root)
            return true;
        
        return compareNode(root->left,root->right);
        
    }

private:
    bool compareNode(TreeNode* nodeLeft, TreeNode* nodeRight)
    {
        if (!nodeLeft && !nodeRight)
            return true;
        
        if (!nodeLeft || !nodeRight)
            return false;

        if (nodeLeft->val != nodeRight->val)
            return false;

        return compareNode(nodeLeft->left,nodeRight->right) && compareNode(nodeLeft->right,nodeRight->left);
    }
};
