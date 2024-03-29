/*
1822. Sign of the Product of an Array

There is a function signFunc(x) that returns:

1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).
*/

class Solution {
public:
    int arraySign(std::vector<int>& nums) 
    {
        int n = 1;

        for (int v : nums)
        {
            n *= signFunc(v);
        }

        return n;
    }

    int signFunc(long long num)
    {
        if (num == 0) return 0;
        if (num > 0) return 1;
        
        return -1;
    }
};
