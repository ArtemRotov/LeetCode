/*
404. Sum of Left Leaves
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

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
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return (isLeft) ? root->val : 0;
        
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }

    
    // int sumOfLeftLeaves(TreeNode* root)
    // {
    //     int sum {0};

    //     helper(root, sum);

    //     return sum;
    // }

    // void helper(TreeNode* root, int &sum)
    // {
    //     if (!root)
    //         return;

    //     if (root->left && !root->left->left && !root->left->right)
    //         sum += root->left->val;

    //     helper(root->left, sum);
    //     helper(root->right, sum);
    // }
};
