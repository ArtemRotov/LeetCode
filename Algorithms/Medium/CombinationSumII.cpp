/*
40. Combination Sum II

Given a collection of candidate numbers (candidates) and a target number 
(target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) 
    {
        std::vector<int> v {};
        std::sort(candidates.begin(), candidates.end());

        helper(candidates, v, target, 0);

        // it so slow
        // std::sort(result.begin(), result.end());
        // result.erase(std::unique(result.begin(), result.end()), result.end());
        return result;
    }

private:
    std::vector<std::vector<int>> result {};

    void helper(std::vector<int>& candidates, std::vector<int> &v, int target, int index)
    {
        int sum = std::accumulate(v.begin(), v.end(), 0);
        if (sum >= target)
        {
            if (sum == target)
                result.push_back(v);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            // Пропускаем дубляж цифры в !этом же цикле! (а не при переходе в рекурсию)!
            if (i - 1 >= index && candidates[i - 1] == candidates[i]) continue;
            v.push_back(candidates[i]);
            helper(candidates, v, target, i + 1);
            v.pop_back();
        }
    }
};
