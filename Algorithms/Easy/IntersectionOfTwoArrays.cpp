/*
349. Intersection of Two Arrays

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
*/


class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> res{};

        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();)
        {
            if (res.size() && nums1[i] == res.back()) { i++; continue; }
            if (res.size() && nums2[j] == res.back()) { j++; continue; }

            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else
            {
                if (nums1[i] > nums2[j]) j++;
                else i++;
            }
        }

        return res;
    }
};
