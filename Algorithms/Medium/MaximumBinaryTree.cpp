/*
654. Maximum Binary Tree

You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively 
from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

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

//stack 
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums)
    {
        std::stack<TreeNode*> stk;
        for (int num : nums)
        {
            TreeNode* node = new TreeNode(num);
            while (!stk.empty() && stk.top()->val < node->val)
            {
                node->left = stk.top();
                stk.pop();
            }
            if (!stk.empty())
            {
                stk.top()->right = node;
            }
            stk.push(node);
        }

        while (stk.size() > 1)
        {
            stk.pop();
        }

        return stk.top();
    }
};
 
// brute force
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums)
    {
        auto it = std::max_element(nums.begin(), nums.end());

        if (it == nums.end())
            return nullptr;

        TreeNode* root = new TreeNode(*it);

        std::vector<int> l = (it == nums.begin()) ? std::vector<int>() : std::vector<int>(nums.begin(), it);
        std::vector<int> r(it + 1, nums.end());

        root->left = constructMaximumBinaryTree(l);
        root->right = constructMaximumBinaryTree(r);

        return root;
    }
};
