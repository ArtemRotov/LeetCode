/*
2309. Greatest English Letter in Upper and Lower Case

Given a string of English letters s, return the greatest English letter which 
occurs as both a lowercase and uppercase letter in s. The returned letter should 
be in uppercase. If no such letter exists, return an empty string.

An English letter b is greater than another letter a if b appears after a in the
English alphabet.
*/

class Solution {
public:
    string greatestLetter(string s) 
    {
        std::unordered_set<int> uSet{};
        std::string str{};

        for (const char &c : s)
            uSet.insert(c);

        int max = 0;

        for (int val : uSet)
        {
            if (val >= 65 && val <= 90 && uSet.count(val + 32) && val > max)
                max = val;
        }
        
        if (max != 0) str += (char)max;

        return str;    
    }
};
