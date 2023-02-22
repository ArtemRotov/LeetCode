/*
2108. Find First Palindromic String in the Array

Given an array of strings words, return the first palindromic string in the array.
If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.
*/

class Solution {
public:
    //c++11
    std::string firstPalindrome(std::vector<std::string>& words) 
    {
        for (auto &w : words)
            if (std::equal(std::begin(w), std::end(w), std::rbegin(w)))
                return w;
        
        return {};
    }

    std::string firstPalindrome(std::vector<std::string>& words) 
    {
        for (auto &w : words)
            if (w == std::string(w.rbegin(), w.rend()))
                return w;
        
        return {};
    }
};
