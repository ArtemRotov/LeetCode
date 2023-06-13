/*
763. Partition Labels

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.
*/

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) 
    {
        std::vector<int> res {};
        std::unordered_map<char, int> m{};
        
        for (int i = 0; i < s.size(); i++) m[s[i]] = i;

        int target = 0;
        for (int i = 0, cnt = 1; i < s.size(); i++, cnt++)
        {
            target = std::max(target, m[s[i]]);
            if (target == i)
            {
                res.push_back(cnt);
                cnt = 0;
            }
        }
    
        return res;
    }
};
