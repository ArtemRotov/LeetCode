/*
144. Binary Tree Preorder Traversal

Given the root of a binary tree, return the preorder traversal of its nodes' values.

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
    std::vector<int> preorderTraversal(TreeNode* root) 
    {
        std::vector<int> res{};
        preorder(root, res);

        return res;
    }

    void preorder(TreeNode* root, std::vector<int> &res)
    {
        if (!root)
            return;

        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
};
