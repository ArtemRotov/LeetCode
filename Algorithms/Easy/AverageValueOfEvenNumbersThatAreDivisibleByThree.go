/*
2455. Average Value of Even Numbers That Are Divisible by Three

Given an integer array nums of positive integers, return the average value of all even integers that are divisible by 3.

Note that the average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
*/


func averageValue(nums []int) int {
    var sum float64 = 0
    var count float64 = 0

    for i := 0; i < len(nums); i++ {
        if nums[i] % 2 == 0 {
            if nums[i] % 3 == 0 {
                sum += float64(nums[i])
                count++
            }
        }
    }
    if count == 0 {
        return 0
    }

    return int(sum / count)
}
