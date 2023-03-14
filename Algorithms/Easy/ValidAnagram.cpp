/*
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of 
a different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    bool isAnagram(std::string s, std::string t) 
    {
        std::unordered_map<char,int> uMap{};

        for (const char &c : s) uMap[c]++;

        for (const char &c : t)
        {
            if (!uMap.count(c))
                return false;
            uMap[c]--;
        }

        for (const auto &el : uMap)
        {
            if (el.second > 0)
                return false;
        }

        return true;
    }
};
