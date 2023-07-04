/*
137. Single Number II

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

class Solution {
public:
    int singleNumber(std::vector<int>& nums) 
    {
        std::unordered_map<int,int> m{};

        for (int &v : nums) m[v]++;

        for (auto &p : m)
        {
            if (p.second == 1) return p.first;
        }

        return 0;
    }
};
