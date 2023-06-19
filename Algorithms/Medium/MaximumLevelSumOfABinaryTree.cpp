/*
1161. Maximum Level Sum of a Binary Tree

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

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
    // Hashmap solution
    int maxLevelSum1(TreeNode* root)
    {
        std::unordered_map<int,int> m{};
        helper1(root, 0, m);

        int max = INT_MIN;
        int lvl = 0;
        for (const auto &p : m)
        {
            if (p.second >= max) { max = p.second; lvl = p.first; }
        }

        return lvl;
    }

    void helper1(TreeNode* root, int lvl, std::unordered_map<int,int> &m)
    {
        if (!root) return;
        lvl++;
        m[lvl]+=root->val;
        helper1(root->left, lvl, m);
        helper1(root->right, lvl, m);
    }

    // level-order traversal
    int maxLevelSum(TreeNode* root)
    {
        std::vector<TreeNode*> q {root};
        int lvl = 0, sum_lvl = INT_MIN, lvlret = 0;

        while (!q.empty())
        {
            std::vector<TreeNode*> q1;
            int sum = 0;
            ++lvl;
            for (auto node : q)
            {
                sum += node->val;
                if (node->left) q1.push_back(node->left);
                if (node->right) q1.push_back(node->right);
            }
            if (sum > sum_lvl) { sum_lvl = sum; lvlret = lvl; }
            std::swap(q,q1);
        }

        return lvlret;
    }
};
