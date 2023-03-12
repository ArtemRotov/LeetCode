/*
217. Contains Duplicate

Given an integer array nums, return true if any value appears at least
twice in the array, and return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) 
    {
        //return nums.size() > std::unordered_set<int>(nums.begin(),nums.end()).size();
        
        std::unordered_set<int> uSet{};

        for (const int &val : nums)
        {
            if (uSet.count(val))
                return true;
            uSet.insert(val);
        }

        return false;
    }
};
