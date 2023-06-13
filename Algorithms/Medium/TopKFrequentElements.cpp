/*
347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) 
    {
        std::unordered_map<int, std::pair<int, int>> m{};

        for (int n : nums)
        {
            m[n].first++;
            m[n].second = n;
        }

        std::vector<std::pair<int,int>> v;

        for (auto &p : m)
            v.push_back(p.second);
        
        std::sort(v.rbegin(), v.rend());

        std::vector<int> res {};
        for (int i = 0; i < k; i++) 
        {
            res.push_back(v[i].second);
        }

        return res;
    }
};
