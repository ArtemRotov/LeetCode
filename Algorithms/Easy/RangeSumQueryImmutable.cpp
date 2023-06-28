/*
303. Range Sum Query - Immutable

Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/

class NumArray {
public:
    NumArray(std::vector<int>& nums)
    {
        int sum = 0;
        for (int &v : nums)
        {
            sum += v;
            cache_sum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) 
    {
        if (left == 0) return cache_sum[right];
        else return cache_sum[right] - cache_sum[left - 1];
    }

private:
    std::vector<int> cache_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
