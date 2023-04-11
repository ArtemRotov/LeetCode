/*
90. Subsets II

Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Solution {
    std::vector<std::vector<int>> res{};
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) 
    {
        std::vector<int> v{};
        std::sort(nums.begin(), nums.end());
        helper(nums, v, 0);
        return res;
    }

    void helper(std::vector<int>& nums, std::vector<int>& v, int index)
    {
        res.push_back(v);

        for(int i = index; i < nums.size(); i++)
        {
            if (i > 0 && i - 1 >= index && nums[i] == nums[i-1]) continue;

            v.push_back(nums[i]);
            helper(nums, v, i + 1);
            v.pop_back();
        }
    }
};
