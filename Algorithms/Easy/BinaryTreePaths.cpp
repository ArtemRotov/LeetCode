/*
257. Binary Tree Paths

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

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
    std::vector<std::string> binaryTreePaths(TreeNode* root) 
    {
        if (!root) return res;
        helper(root, "");
        return res;
    }

    void helper(TreeNode* root, std::string s)
    {
        s += std::to_string(root->val);

        if (!root->right && !root->left)
        {
            res.push_back(s);
            return;
        }

        if (root->left) helper(root->left, s + "->");
        if (root->right) helper(root->right, s + "->");
    }

private:
    std::vector<std::string> res{};
};
