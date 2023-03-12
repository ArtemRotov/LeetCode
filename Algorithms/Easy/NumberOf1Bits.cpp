/*
191. Number of 1 Bits

Write a function that takes the binary representation of an unsigned
integer and returns the number of '1' bits it has (also known as the Hamming weight).
*/

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        /*
        
        std::bitset<32> bs(n);
        return bs.count();
        
        */

        int result = 0;
        while (n)
        {
            if (n&1)
                result++;
            n = n >> 1;
        }

        return result;
    }
};
