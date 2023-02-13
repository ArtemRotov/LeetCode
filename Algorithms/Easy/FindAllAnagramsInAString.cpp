/*
438. Find All Anagrams in a String
Given two strings s and p, return an array of all the start indices
of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a
different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) 
    {   
        std::vector<int> result {};

        int lenp = p.size();
        int lens = s.size();

        if (lens < lenp)
            return result;

        std::vector<int> pmap(26,0);
        std::vector<int> smap(26,0);
        
        for (const char &el : p) pmap[el - 97]++;        
        for (int i = 0; i < lenp; i++) smap[s[i] - 97]++;
        
        if (pmap == smap)
            result.push_back(0);
        
        for (int i = 0; i < lens - lenp; i++)
        {   
            smap[s[i] - 97]--;
            smap[s[i + lenp] - 97]++;
            if (pmap == smap)
                result.push_back(i + 1);
        }

        return result;
    }
};
