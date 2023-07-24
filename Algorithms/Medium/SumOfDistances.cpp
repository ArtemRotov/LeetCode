/*
2615. Sum of Distances

You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.

Return the array arr.
*/

class Solution {
public:
    std::vector<long long> distance(std::vector<int>& nums) 
    {
        std::vector<long long> res(nums.size());
        std::unordered_map<int, std::vector<int>> m{};

        for (int i = 0; i < nums.size(); i++)
            m[nums[i]].push_back(i);

        for (auto &p : m)
        {
            long long prev = 0;
            long long post = 0;
            for (int v : p.second) post += v;

            for (long long i = 0; i < p.second.size(); i++)
            {
                int idx = p.second[i];
                post -= idx;
                res[idx] += abs(prev - (i * idx));
                res[idx] += abs((long long)(post - ((p.second.size() - 1 - i) * idx)));
                prev += idx;
            }
        }

        return res;
    }
};
