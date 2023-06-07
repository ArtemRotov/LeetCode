/*
2574. Left and Right Sum Differences

Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:

answer.length == nums.length.
answer[i] = |leftSum[i] - rightSum[i]|.
Where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return the array answer.
*/

class Solution {
public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) 
    {
        int rsum = std::accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0;
        for (int &v : nums)
        {
            rsum -= v;
            int res = abs(lsum - rsum);
            lsum += v;
            v = res;
        }   

        return nums;
    }
};
