/*
113. Path Sum II

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

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
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        std::vector<std::vector<int>> res {};
        helper(res, root, targetSum);

        return res;
    }

    void helper(std::vector<std::vector<int>> &res, TreeNode* root, int target, std::vector<int> p = std::vector<int>())
    {
        if (!root) return;
    
        p.push_back(root->val);
        if (std::accumulate(p.begin(), p.end(), 0) == target && !root->left && !root->right) res.push_back(p);
        helper(res, root->left, target, p);
        helper(res, root->right, target, p);
    }
};
