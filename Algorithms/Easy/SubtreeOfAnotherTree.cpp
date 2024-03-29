/*
572. Subtree of Another Tree

Given the roots of two binary trees root and subRoot, return true if there is a subtree 
of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of 
this node's descendants. The tree tree could also be considered as a subtree of itself.

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
    bool isSame(TreeNode* root, TreeNode* subRoot)
    {
        if ((!root && subRoot) || (root && !subRoot))
            return false;
        if (!root && !subRoot)
            return true;
        if (root->val != subRoot->val)
            return false;

        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root)
            return isSame(root, subRoot);

        bool res = isSame(root, subRoot);
        return res ? res : isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
