/*
653. Two Sum IV - Input is a BST
Given the root of a binary search tree and an integer k, return true if there exist two 
elements in the BST such that their sum is equal to k, or false otherwise.

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
    bool findTarget(TreeNode* root, int k) 
    {   
        if (!root)
            return false;
        
        if (uSet.count(k - root->val))
            return true;
        uSet.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }

private:
    std::unordered_set<int> uSet{};
};
