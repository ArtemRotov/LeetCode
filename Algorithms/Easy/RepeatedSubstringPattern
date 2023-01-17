/*
459. Repeated Substring Pattern

Given a string s, check if it can be constructed by taking a substring of
it and appending multiple copies of the substring together.
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        std::string substr;

        for (int i = 0; i < s.length(); ++i)
        {
            substr += s[i];
            int len = substr.length();

            int pos = len;
            int n = s.find(substr, pos);

            while (n != std::string::npos && n == pos)
            {
                pos += len;
                if (pos == s.length())
                    return true;
                n = s.find(substr, pos);
            }
        }

        return false;
    }
};
