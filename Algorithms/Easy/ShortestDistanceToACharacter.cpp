821. Shortest Distance to a Character

Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] 
is the distance from index i to the closest occurrence of character c in s.

The distance between two indices i and j is abs(i - j), where abs is the absolute value function.

class Solution {
public:
    std::vector<int> shortestToChar(std::string s, char c) 
    {
        std::vector<int> charPos{};

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
                charPos.push_back(i);
        }

        std::vector<int> answ {};
        for (int i = 0; i < s.size(); i++)
        {
            answ.push_back(helper(i, charPos));
        }
        
        return answ;
    }
    
    int helper(int i, const std::vector<int> &c)
    {
        int min = 1000000;

        for (int v : c)
        {
            if (abs(v - i) < min)
                min = abs(v - i);
        }

        return min;
    }
};
