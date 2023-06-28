/*
383. Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
*/

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) 
    {
        std::unordered_map<char,int> s2{};
        for (char &c : magazine) s2[c]++;

        for (char &c : ransomNote)
        {
            if (s2[c] > 0) s2[c]--;
            else return false;
        }

        return true;
    }
};
