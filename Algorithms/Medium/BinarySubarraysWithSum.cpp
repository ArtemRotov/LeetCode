/*
930. Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.
*/

class Solution {
public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal)
    {
        std::unordered_map<int,int> uMap({{0, 1}});
        int sum = 0;
        int res = 0;
        for (int &val : nums)
        {
            sum += val;
            res += uMap[sum - goal];
            uMap[sum]++;
        }

        return res;
    }
};
