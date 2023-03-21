/*
46. Permutations

Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.
*/

class Solution {
public:
    void permute(std::vector<std::vector<int>> &result, std::vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            result.push_back(nums);
            return;
        } 
        
        for (int j = i; j < nums.size(); j++) 
        {
            std::swap(nums[i], nums[j]);
            permute(result, nums, i + 1);
            std::swap(nums[i], nums[j]);
        }
    }
    
    std::vector<std::vector<int>> permute(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> result;
        permute(result, nums, 0);
        return result;
    }
};


