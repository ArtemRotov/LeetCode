/*
1309. Decrypt String from Alphabet to Integer Mapping

You are given a string s formed by digits and '#'. We want to map s to English
lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
Return the string formed after mapping.

The test cases are generated so that a unique mapping will always exist.
*/

class Solution {
public:
    std::string freqAlphabets(std::string s)
    {
        std::string result {};

        for (int i = 0; i < s.length() ; ++i)
        {
            if (i < s.length() - 2 && s[i+2] == '#')
            {
                result += 'j' + (s[i] - '0') * 10 + s[i + 1] - '0' - 10;
                i += 2;
            }
            else
                result += 'a' - 1 + s[i] - '0';
        }

        return result;
    }
};
