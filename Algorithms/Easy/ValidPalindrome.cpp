/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads
the same forward and backward. Alphanumeric characters include letters and
numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

class Solution {
public:
    bool isPalindrome(std::string s) 
    {
        for (int i = 0, j = s.size() - 1; i < j;)
        {
            if (!std::isalnum(s[i]))
            {
                i++;
                continue;
            }
            
            if (!std::isalnum(s[j]))
            {
                j--;
                continue;
            }

            if (std::tolower(s[i++]) != std::tolower(s[j--]))
                return false;
        }
        
        return true;
    }
};
