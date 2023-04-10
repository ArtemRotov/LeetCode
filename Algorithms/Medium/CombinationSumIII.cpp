
/*
216. Combination Sum III

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.

Each number is used at most once.

Return a list of all possible valid combinations. The list must not contain the same
combination twice, and the combinations may be returned in any order.
*/

class Solution {

std::vector<std::vector<int>> result{};

public:
    std::vector<std::vector<int>> combinationSum3(int k, int sum)
    {
        std::vector<int> v{};
        helper(v,k,sum);
        return result;
    }

    void helper(std::vector<int> &v, int k, int sum)
    {
        if (std::accumulate(v.begin(), v.end(), 0) == sum && v.size() == k)
        {
            result.push_back(v);
            return;
        }

        if (v.size() < k)
        {
            for (int i = v.empty() ? 1 : v.back() + 1; i < 10; i++)
            {
                v.push_back(i);
                helper(v, k, sum);
                v.pop_back();
            }
        }
    }
};
