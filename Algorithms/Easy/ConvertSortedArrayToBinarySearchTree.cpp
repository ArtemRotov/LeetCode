/*
108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in
ascending order, convert it to a height-balanced binary search tree.

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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) 
    {
        if (nums.size() == 0)
            return nullptr;
        
        if (nums.size() == 1)
            return new TreeNode(nums[0]);

        
        int middle = nums.size() / 2;
        std::vector<int> leftArr (nums.begin(), nums.begin() + middle);
        std::vector<int> rightArr (nums.begin() + middle + 1, nums.end());

        TreeNode* root = new TreeNode(nums[middle]);

        root->left = sortedArrayToBST(leftArr);
        root->right = sortedArrayToBST(rightArr);

        return root;
    }
};


