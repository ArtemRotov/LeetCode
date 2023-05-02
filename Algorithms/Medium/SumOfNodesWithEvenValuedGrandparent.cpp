/*
1315. Sum of Nodes with Even-Valued Grandparent

Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent.
If there are no nodes with an even-valued grandparent, return 0.

A grandparent of a node is the parent of its parent if it exists.
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

    int sumEvenGrandparent(TreeNode* root)
    {
        if (!root)
            return 0;

        int sum = 0;

        if (root->val % 2 == 0)
        {
            if (root->left)
            {
                if (root->left->left)
                    sum += root->left->left->val;
                if (root->left->right)
                    sum += root->left->right->val;
            }
            if (root->right)
            {
                if (root->right->left)
                    sum += root->right->left->val;
                if (root->right->right)
                    sum += root->right->right->val;
            }
        }
        
        sum += sumEvenGrandparent(root->left);
        sum += sumEvenGrandparent(root->right);
        
        return sum;
    }
};
