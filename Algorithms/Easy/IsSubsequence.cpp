/*
392. Is Subsequence

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) 
    {
        int i = 0;
        for (const char &c : t)
        {
            if (i == s.size()) return true;
            if (c == s[i]) i++;
        }

        return i == s.size();
    }
};
