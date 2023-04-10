/*
39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list 
of all unique combinations of candidates where the chosen numbers sum to target. You may 
return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations
are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

class Solution {
    std::vector<std::vector<int>> result {};

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
    {
        std::vector<int> v {};
        helper(candidates, v, 0, target);
        return result;
    }

    void helper(std::vector<int> &cand, std::vector<int> &v, int index, int target)
    {
        int sum = std::accumulate(v.begin(), v.end(), 0);
        if (sum >= target)
        {
            if (sum == target)
                result.push_back(v);
            return;
        }

        for (int i = index; i < cand.size(); i++)
        {
            v.push_back(cand[i]);
            helper(cand, v, i, target);
            v.pop_back();
        }
    }
};
