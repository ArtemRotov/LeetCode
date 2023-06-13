/*
56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) 
    {
        std::vector<std::vector<int>> res{};

        std::sort(intervals.begin(), intervals.end());

        int j = 0;
        for(int i = 0; i < intervals.size() - 1; i++)
        {
            j = i + 1;
            if (intervals[j][0] >= intervals[i][0] && intervals[j][0] <= intervals[i][1])
            {
                intervals[j][0] = intervals[i][0];
                intervals[j][1] = std::max(intervals[i][1], intervals[j][1]);
            }
            else
            {
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        }

        res.push_back({intervals[intervals.size() - 1][0], intervals[intervals.size() - 1][1]});

        return res;
    }
};
