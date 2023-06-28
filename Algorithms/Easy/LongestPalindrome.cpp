/*
409. Longest Palindrome

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
*/

class Solution {
public:
    int longestPalindrome(std::string s) 
    {
        std::unordered_map<char, int> m{};

        for (char &c : s) m[c]++;

        int sum = 0;
        bool flag = false;
        for (auto &p : m)
        {
            if (p.second % 2 && !flag)
            {
                sum+=p.second;
                flag = true;
            } else if (p.second % 2) sum += p.second - 1;
            else sum += p.second;
        }

        return sum;
    }
};


