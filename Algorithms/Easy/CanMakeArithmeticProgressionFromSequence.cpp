/*
1502. Can Make Arithmetic Progression From Sequence

A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.
*/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        std::sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size() - 2; i++)
        {
            if (arr[i] - arr[i+1] != arr[i+1] - arr[i+2]) return false;
        }

        return true;
    }
};
