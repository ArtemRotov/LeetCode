/*
326. Power of Three

Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3^x.
*/

class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        
        //return n > 0 && ((int)pow(3,19) % n == 0);
        
        if (n == 0) return false;
        
        while (n)
        {
            if (n % 3 != 0 && n != 1)
                return false;
            
            n = n / 3;
        }

        return true;
    }
};
