/*
1022. Sum of Root To Leaf Binary Numbers

You are given the root of a binary tree where each node has a value 0 or 1.
Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

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
    int sumRootToLeaf(TreeNode* root, int val = 0) 
    {
        if (!root)
            return 0;
        
        val = val * 2 + root->val;
        
        return root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val); 
    }
};
