/*
387. First Unique Character in a String

Given a string s, find the first non-repeating character in
it and return its index. If it does not exist, return -1.
*/

class Solution {
public:
    int firstUniqChar(std::string s) 
    {
        
        std::unordered_map<char, int> hash{};

        for (int i = 0; i < s.size(); i++)
            hash[s[i]]++;

        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] == 1)
                return i;
        }

        return -1;
        
        // In case we have a large number of characters in a string and the one we
        // are looking for is at the end 
        
        // std::unordered_map<char, std::pair<int,int>> hash{};

        // int index = s.size();
        // for (int i = 0; i < s.size(); i++)
        // {
        //     hash[s[i]].first++;
        //     hash[s[i]].second = i;
        // }

        // for (const auto &pair : hash)
        // {
        //     if (pair.second.first == 1)
        //         index = std::min(index, pair.second.second);
        // }

        // return (index == s.size()) ? -1 : index;
    }
};
