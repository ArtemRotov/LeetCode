/*
501. Find Mode in Binary Search Tree

Given the root of a binary search tree (BST) with duplicates, 
return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or 
equal to the node's key.
The right subtree of a node contains only nodes with keys greater than 
or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

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
    std::vector<int> findMode(TreeNode* root) 
    {
        std::vector<int> result;

        int max = helper(root);

        for (auto &pair : uMap)
        {
            if (pair.second == max)
                result.push_back(pair.first);
        }

        return result;
    }

    int helper(TreeNode* root)
    {
        if (!root)
            return 0;
        
        uMap[root->val]++;

        return std::max(uMap[root->val], std::max(helper(root->left), helper(root->right)));
    }

private:
    std::unordered_map<int, int> uMap{};
};
