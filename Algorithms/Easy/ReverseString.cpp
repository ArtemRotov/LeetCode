/*
344. Reverse String

Write a function that reverses a string. The input string
is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.
*/

class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^= s[j];
        }

        // char temp;
        // for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        // {
        //     temp = s[i];
        //     s[i] = s[j];
        //     s[j] = temp;
        // }

        // std::reverse(s.begin(), s.end());    
    }
};

