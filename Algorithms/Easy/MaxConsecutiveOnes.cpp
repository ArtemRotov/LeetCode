/*
485. Max Consecutive Ones

Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) 
    {
        int res = 0;
        int curr = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]) 
            {
                curr++;
                res = std::max(res, curr);
            }
            else curr = 0;
        }

        return res;
    }
};
