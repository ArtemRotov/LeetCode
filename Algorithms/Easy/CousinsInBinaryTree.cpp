/*
993. Cousins in Binary Tree

Given the root of a binary tree with unique values and the values of two different 
nodes of the tree x and y, return true if the nodes corresponding to the values x 
and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth 
k node are at the depth k + 1.


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
    bool isCousins(TreeNode* root, int x, int y) 
    {
        if (!root || root->val == x || root->val == y)
            return false;
        
        helper(root, 0, 0, x, y);

        return xd == yd && xp != yp;
    }

    void helper(TreeNode* root, int depth, int parent, int x, int y)
    {
        if (!root || (xd && yd))
            return;
        
        if (root->val == x)
        {
            xd = depth;
            xp = parent;
        }

        if (root->val == y)
        {
            yd = depth;
            yp = parent;
        }

        helper(root->left, depth+1, root->val, x, y);
        helper(root->right, depth+1, root->val, x, y);
    }

private:

int xd, yd, xp, yp;

};
