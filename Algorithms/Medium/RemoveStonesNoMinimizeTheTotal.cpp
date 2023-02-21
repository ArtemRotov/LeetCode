/*
1962. Remove Stones to Minimize the Total

You are given a 0-indexed integer array piles, where piles[i] represents the
number of stones in the ith pile, and an integer k. You should apply the following
operation exactly k times:

Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
Notice that you can apply the operation on the same pile more than once.

Return the minimum possible total number of stones remaining after applying the k
operations.

floor(x) is the greatest integer that is smaller than or equal to x (i.e., rounds x down).
*/

class Solution {
public:
    int minStoneSum(std::vector<int>& piles, int k)
    {
        std::priority_queue<int> q (piles.begin(), piles.end());
        int res = std::accumulate(piles.begin(), piles.end(), 0);
        while (k > 0)
        {
            k--;
            int val = q.top();
            q.pop();
            q.push((val+1)/2);
            
            res -= val/2;
       }

       return res;
    }
};
