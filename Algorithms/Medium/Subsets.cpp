/*
78. Subsets

Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Solution {
    std::vector<std::vector<int>> res{};
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        std::vector<int> v{};
        helper(nums,v,0);
        return res;
    }

    void helper(std::vector<int>& nums, std::vector<int> &v, int index)
    {
        res.push_back(v);
        for (int i = index; i < nums.size(); i++)
        {
            v.push_back(nums[i]);
            helper(nums, v, i + 1);
            v.pop_back();
        }
    }
};
