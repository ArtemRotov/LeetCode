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

// O(1) space recursive solution

class Solution {
public:
    void flatten(TreeNode* root)
    {
        if (root) preOrder(root);
    }

private:
    TreeNode* head = nullptr;

    void preOrder (TreeNode* node)
    {
        if (node->right) preOrder(node->right);
        if (node->left) preOrder(node->left);
        node->left = nullptr;
        node->right = head;
        head = node;
    }
};
