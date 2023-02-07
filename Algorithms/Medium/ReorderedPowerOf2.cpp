/*
869. Reordered Power of 2
You are given an integer n. We reorder the digits in any order
(including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number
is a power of two.
*/

class Solution {
public:
    bool reorderedPowerOf2(int n) 
    {
        if (n == 1) return true;
        
        std::string strN = std::to_string(n);
        std::map<char,int> charsN {};
        for (const auto &el : strN) charsN[el]++;
        
        int lenN = strN.size();

        int c = 1;
        std::vector<std::map<char,int>> chars {};

        for (int i = 0; i < 30; i++)
        {
            c = c << 1;
            std::string strC = std::to_string(c);
            if (strC.size() != lenN)
                continue;
            chars.emplace_back();
            for (const auto &el : strC) chars.back()[el]++;
        }

        for (const auto &map : chars)
        {
            if (map == charsN)
                return true;
        }

        return false;
    }
};
