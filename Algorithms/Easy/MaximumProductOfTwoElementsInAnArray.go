/*
1464. Maximum Product of Two Elements in an Array

Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
*/

func maxProduct(nums []int) int {
    sort.Ints(nums)
    
    return (nums[len(nums)-1] - 1) * (nums[len(nums) - 2] - 1)
}
