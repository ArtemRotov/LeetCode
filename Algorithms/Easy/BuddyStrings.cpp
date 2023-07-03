/*
859. Buddy Strings

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 */
 
class Solution {
public:
    bool buddyStrings(std::string s, std::string g) 
    {
        if (s.size() != g.size()) return false;
        if (s == g && std::set<char>(s.begin(), s.end()).size() < s.size()) return true;
        
        std::vector<int> v {};
        for (int i = 0; i < s.size(); i++) if (s[i] != g[i]) v.push_back(i);

        return v.size() == 2 && s[v[0]] == g[v[1]] && s[v[1]] == g[v[0]];
    }
};
