/*
435. Non-overlapping Intervals

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
*/

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& v) 
    {
        int res = 0;
        int prev = 0;
        sort(v.begin(),v.end(), [](const std::vector<int> &a, const std::vector<int> &b){
            return a[0] < b[0];
        });

        for (size_t i = 1; i < v.size(); i++)
        {
            if (v[i][0] < v[prev][1])
            {
                res++;
                if (v[i][1] < v[prev][1]) prev = i;
            }
            else prev = i;
        }
        return res;           
    }
};
