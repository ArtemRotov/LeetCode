/*
228. Summary Ranges

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
*/

class Solution {
public:

    // Input: nums = [0,1,2,4,5,7]
    // Output: ["0->2","4->5","7"]
    std::vector<std::string> summaryRanges(std::vector<int>& nums) 
    {
        if (nums.empty()) return {};

        std::vector<std::string> res {};

        int cnt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
                if (nums[i-1]+1 == nums[i]) cnt++;
                else if (cnt > 0)
                {
                    std::string str = std::to_string(nums[i-1] - cnt);
                    str += "->";
                    str += std::to_string(nums[i-1]);
                    res.push_back(str);
                    cnt = 0;
                }
                else
                {
                    res.push_back(std::to_string(nums[i-1]));
                }
        }

        if (cnt == 0) res.push_back(std::to_string(nums.back()));
        else
        {
            std::string str = std::to_string(nums.back() - cnt);
            str += "->";
            str += std::to_string(nums.back());
            res.push_back(str);
        }

        return res;
    }
};
