/*
5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.
*/

class Solution {
public:
    // s[i, right - 1] - включают повторяющиеся символы - "aaa"
    // пока s[left] == s[right], s[left, right] включает палиндром - "baaab"

    std::string longestPalindrome(std::string &s) 
    {
        int currLen = 0;
        int pLeft = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int right = i;
            while (right <s.size() && s[i] == s[right])
                right++;

            int left = i - 1;
            while (left >= 0 && s[left] == s[right])
            {
                left--;
                right++;
            }

            if (right - left - 1 > currLen)
            {
                currLen = right - left - 1;
                pLeft = left + 1;
            }
        }

        return s.substr(pLeft, currLen);
    }
};
