/*
643. Maximum Average Subarray I
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum
average value and return this value. Any answer with a calculation error less
than 10^5 will be accepted.
*/

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) 
    {
        double result = -99999999999;
        int sum = 0;

        for (int i = 0; i < k; i++)
            sum += nums[i];
        
        result = std::max(result, (double)sum / k);

        for (int i = 0; i < nums.size() - k; i++)
        {
            sum -= nums[i];
            sum += nums[i+k];
            result = std::max(result, (double)sum / k);
        }

        return result;
    }
};
