/*
692. Top K Frequent Words

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
*/

class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) 
    {
        std::unordered_map<std::string, int> m1{};

        int max = 0;
        for (const std::string &s : words)
        {
            m1[s]++;
            max = std::max(max, m1[s]);
        }
        
        std::vector<std::string> res {};

        while(k > 0 && max > 0)
        {
            std::vector<std::string> v {};

            for (const auto &p : m1)
            {
                if (p.second == max) v.push_back(p.first);
            }

            std::sort(v.begin(), v.end());

            for (const std::string &s : v)
            {
                if (k <= 0) break;
                res.push_back(s);
                k--;
            }

            max--;
        }

        return res;
    }
};
