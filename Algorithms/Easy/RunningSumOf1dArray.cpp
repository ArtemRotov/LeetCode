/*
1480. Running Sum of 1d Array
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.
*/

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) 
    {
        int sum = 0;

        for (int &v : nums)
        {
            sum += v;
            v = sum;
        }

        return nums;
    }
};
