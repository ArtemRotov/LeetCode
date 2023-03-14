/*
268. Missing Number

Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.
*/

class Solution {
public:
    int missingNumber(std::vector<int>& nums) 
    {
        int result = 0;
        int i = 0;

        for (const int &val : nums)
        {
            result ^= val ^ i++;
        }
        
        return result^i;
    }
};
