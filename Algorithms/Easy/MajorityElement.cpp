/*
169. Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than
[n / 2] times. You may assume that the majority element always
exists in the array.
*/

class Solution {
public:
    int majorityElement(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());

        return nums[nums.size()/2];
    }

    //     int result = 0;
    //     std::unordered_map<int,int> umap;

    //     for (int &el : nums)
    //         umap[el]++;
        
    //     for(const auto &pair: umap)
    //     {
    //         if (pair.second > nums.size()/2)
    //         {
    //             result = pair.first;
    //             break;
    //         }
    //     }

    //     return result;
};
