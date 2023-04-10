/*
872. Leaf-Similar Trees

Consider all the leaves of a binary tree, from left to right order,
the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        std::vector<int> v1 {};
        std::vector<int> v2 {};
        helper(root1, v1);
        helper(root2, v2);

        return v1 == v2;
    }

    void helper(TreeNode* root, std::vector<int> &v)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            v.push_back(root->val);
            return;
        }
        helper(root->left, v);
        helper(root->right, v);
    }
};
