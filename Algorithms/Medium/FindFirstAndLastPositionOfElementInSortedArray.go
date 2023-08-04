/*
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/

func searchRange(nums []int, target int) []int {
	if len(nums) == 1 && target == nums[0] {
		return []int{0, 0}
	}
	l := 0
	r := len(nums) - 1
	mid := -1
	for l <= r {
		mid = (l + r) / 2

		if nums[mid] < target {
			l = mid + 1
		} else if nums[mid] > target {
			r = mid - 1
		} else {
			break
		}
	}

	if mid != -1 && nums[mid] == target {
		l, r = mid, mid
		for l >= 0 && nums[l] == target {
			l--
		}
		for r < len(nums) && nums[r] == target {
			r++
		}
		l++
		r--
	} else {
		l, r = -1, -1
	}

	return []int{l, r}
}
