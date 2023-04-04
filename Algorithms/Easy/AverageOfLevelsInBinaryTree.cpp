/*
637. Average of Levels in Binary Tree

Given the root of a binary tree, return the average value of the nodes on
each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
 
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
    std::vector<double> averageOfLevels(TreeNode* root)
    {
        std::vector<double> result{};
        std::queue<TreeNode*> q{};
        q.push(root);

        while (!q.empty())
        {
            int s = q.size();
            long sum = 0;
            for (int i = 0; i < s; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                sum += node->val;
            }
            result.push_back((double)sum / s);
        }

        return result;
    }
};
