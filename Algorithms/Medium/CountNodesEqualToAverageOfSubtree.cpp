/*
2265. Count Nodes Equal to Average of Subtree

Given the root of a binary tree, return the number of nodes where the value of the node is equal 
to the average of the values in its subtree.
Note:
The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
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
    int averageOfSubtree(TreeNode* root) 
    {
        int result = 0;
        helper(root, result);
        return result;
    }

    std::pair<int,int> helper(TreeNode* root, int &res)
    {
        if (!root)
            return {0,0};
        
        std::pair<int,int> left = helper(root->left, res);
        std::pair<int,int> right = helper(root->right, res);

        int cnt = 1 + left.second + right.second;

        if ((root->val + left.first + right.first) / cnt == root->val)
            res++;
        
        return {(left.first + right.first + root->val), cnt};
    }
};
