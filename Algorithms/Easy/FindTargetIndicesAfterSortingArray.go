/*
2089. Find Target Indices After Sorting Array

You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.
*/

func targetIndices(nums []int, target int) []int {
    
    sort.Ints(nums)

    left := 0
    right := len(nums) - 1

    out := make([]int,0,2)

    for left < right {
        mid := (left + right) / 2

        if nums[mid] == target || nums[mid] > target {
            right = mid
        } else {
            left = mid + 1
        }
    }

    for ; left < len(nums) && nums[left] == target; left++ {
        out = append(out, left)
    }

    return out
}
