/*
70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct
ways can you climb to the top?

*/

class Solution {
public:
    int climbStairs(int n) 
    {
        long a = 1;
        long b = 1;

        while (n--)
        {
            a = (b += a) - a;
        }

        return a;
    }
};
