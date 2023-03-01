/*
1513. Number of Substrings With Only 1s

Given a binary string s, return the number of substrings with all
characters 1's. Since the answer may be too large, return it modulo 109 + 7.
*/

class Solution {
public:
    int numSub(std::string s) 
    {
        int res = 0;
        int cnt = 0;
        int mod = 1e9 + 7;
        for (const char &el : s)
        {
            cnt = (el == '1') ? cnt + 1 : 0;
            res = (res + cnt) % mod;
        }

        return res;
    }
};
