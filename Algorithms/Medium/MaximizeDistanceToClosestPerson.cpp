/*
849. Maximize Distance to Closest Person

You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.
*/

class Solution {
public:
    int maxDistToClosest(std::vector<int>& seats) 
    {
        int left = -1;
        int len = 0;
        int max = 0;
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 0)
            {
                len++;
                continue;
            }
            else
            {
                if (len > 0 && left == -1)
                    ;
                else
                    len = ((len - 1) / 2 ) + 1;

                left = i;
                max = std::max(len, max);
                len = 0;
            }
        }
        if (len > 0)
            max = std::max(len, max);

        return max;
    }
};
