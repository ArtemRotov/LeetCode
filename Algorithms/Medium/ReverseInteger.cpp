/*
7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer
range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

class Solution {
public:    
    int reverse(int x) 
    {
        long res = 0;
        while (x)
        {
            int tmp = res*10 + x%10;
            if (tmp/10 != res)
                return 0;
            res = tmp;
            x = x/10;
        }

        return res;
    }
};
