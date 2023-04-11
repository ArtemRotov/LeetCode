/*
46. Permutations

Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.
*/

class Solution {
    std::vector<std::vector<int>> res{};
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) 
    {
        helper(nums, 0);
        return res;
    }

    void helper(std::vector<int>& nums, int idx)
    {
        if (idx == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            std::swap(nums[i], nums[idx]);
            helper(nums, idx + 1);
            std::swap(nums[i], nums[idx]);
        }
    }
    
    // std::vector<std::vector<int>> permute(std::vector<int>& nums) 
    // {
    //     std::vector<int> v{};
    //     std::unordered_map<int,int> idx{};
    //     helper(nums,v,idx);
    //     return res;
    // }

    // void helper(std::vector<int>& nums, std::vector<int>& v, std::unordered_map<int,int>& idx)
    // {
    //     if (v.size() == nums.size())
    //     {
    //         res.push_back(v);
    //         return;
    //     }
        
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (idx[i])
    //             continue;
            
    //         v.push_back(nums[i]);
    //         idx[i]++;
    //         helper(nums, v, idx);
    //         v.pop_back();
    //         idx[i]--;
    //     }
    // }
};

