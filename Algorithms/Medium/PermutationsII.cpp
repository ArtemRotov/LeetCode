47. Permutations II

Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.

class Solution {
    std::vector<std::vector<int>> res{};
    
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) 
    {
        std::vector<int> v{};
        std::unordered_map<int,int> idx{};
        std::sort(nums.begin(), nums.end());
        
        helper(nums,v,idx);
        return res;
    }

    void helper(std::vector<int>& nums, std::vector<int>& v, std::unordered_map<int,int>& idx)
    {
        if (v.size() == nums.size())
        {
            res.push_back(v);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if ((i > 0 && nums[i] == nums[i-1] && idx[i-1]) || idx[i]) continue;
            
            v.push_back(nums[i]);
            idx[i]++;
            helper(nums, v, idx);
            v.pop_back();
            idx[i]--;
        }
    }

    // std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
    // {
    //     std::sort(nums.begin(), nums.end());
    //     helper(nums, 0);
    //     return res;
    // }

    // void helper(std::vector<int> nums, int idx)
    // {
    //     if (idx == nums.size())
    //     {
    //         res.push_back(nums);
    //         return;
    //     }

    //     for (int i = idx; i < nums.size(); i++)
    //     {
    //         if (nums[i] == nums[idx] && i != idx) continue;

    //         std::swap(nums[i], nums[idx]);
    //         helper(nums, idx + 1);
    //     }
    // }
};
