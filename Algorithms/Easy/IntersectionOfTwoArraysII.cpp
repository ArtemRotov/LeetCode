/*
350. Intersection of Two Arrays II

Given two integer arrays nums1 and nums2, return an array of their
intersection. Each element in the result must appear as many times as
it shows in both arrays and you may return the result in any order.
*/

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        std::unordered_map<int,int> hash{};
        std::vector<int> result{};
        if (nums1.size() > nums2.size())
        {
            for (int &el : nums1) hash[el]++;
            for (int &el : nums2)
            {
                if (hash[el])
                { 
                    result.push_back(el);   
                    hash[el]--;
                }
            }
        }
        else
        {
            for (int &el : nums2) hash[el]++;
            for (int &el : nums1)
            {
                if (hash[el])
                { 
                    result.push_back(el);   
                    hash[el]--;
                }   
            }
        }

        return result;
    }
};
