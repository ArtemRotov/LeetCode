/*
1588. Sum of All Odd Length Subarrays
Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

A subarray is a contiguous subsequence of the array.
*/

class Solution {
public:
    int sumOddLengthSubarrays(std::vector<int>& arr) 
    {
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += ((i + 1) * (arr.size() - i) + 1) / 2 * arr[i];
        }
        return sum; 
    }
};
