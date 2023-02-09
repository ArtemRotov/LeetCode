/*
2150. Find All Lonely Numbers in the Array
You are given an integer array nums. A number x is lonely when it
appears only once, and no adjacent numbers (i.e. x + 1 and x - 1) appear
in the array.

Return all lonely numbers in nums. You may return the answer in any order.
*/

class Solution {
public:
    std::vector<int> findLonely(std::vector<int>& nums) 
    {
        if (nums.size() < 2)
            return nums;
            
        std::sort(nums.begin(),nums.end());

        std::vector<int> result {};
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (i == 0)
            {
                if (!(abs(nums[i] - nums[i+1]) <= 1))
                {
                    result.push_back(nums[i]);
                    continue;
                }
            }
            else if (!(abs(nums[i] - nums[i+1]) <= 1) && !(abs(nums[i] - nums[i-1]) <= 1))
                result.push_back(nums[i]);
            
        }
        if (!(abs(nums[nums.size() - 1] - nums[nums.size() - 2]) <= 1))
            result.push_back(nums.back());

        return result;
    }
};
