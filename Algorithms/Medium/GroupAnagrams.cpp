/*
49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) 
    {
        std::vector<std::vector<std::string>> res {};

        std::unordered_map<std::string, std::vector<std::string>> m{};
        for (std::string s : strs)
        {
            std::string str = s;
            std::sort(str.begin(), str.end());
            m[str].push_back(s);
        }

        for (auto p : m)
            res.push_back(p.second);

        return res;
    }
};
