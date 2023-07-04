/*
448. Find All Numbers Disappeared in an Array

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
*/

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) 
    {
        std::vector<bool> vec (nums.size()+1);
        std::vector<int> res{};
        
        for (int &v : nums) vec[v] = 1;

        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] == 0) res.push_back(i);
        }

        return res;
    }
};
