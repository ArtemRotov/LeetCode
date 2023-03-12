/*
190. Reverse Bits

Reverse bits of a given 32 bits unsigned integer.
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        std::bitset<32> bs(n);
        int l{0}, r{31};
        while( l < r)
        {
            bool tmp = bs[l];
            bs[l++] = bs[r];
            bs[r--] = tmp;
        }

        return bs.to_ulong();
    }
};
