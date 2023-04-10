/*
77. Combinations

Given two integers n and k, return all possible combinations of k numbers
chosen from the range [1, n].

You may return the answer in any order.
*/

class Solution {
    std::vector<std::vector<int>> result{};
    
public:
    std::vector<std::vector<int>> combine(int n, int count)
    {
        std::vector<int> v {};
        helper(v, 1, n, count);
        return result;
    }

    void helper(std::vector<int> &v, int b, int n, int count)
    {
        if (v.size() == count)
        {
            result.push_back(v);
            return;
        }

        for (int i = b; i < n + 1 && v.size() < count; i++)
        {
            v.push_back(i);
            helper(v, i + 1, n, count);
            v.pop_back();
        } 
    }
};
