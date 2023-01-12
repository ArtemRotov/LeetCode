/*
593. Valid Square

Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).
*/


class Solution {
public:
    bool validSquare(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3, std::vector<int>& p4)
    {
        std::unordered_set<int> set {};

        set.insert(d2(p1,p2));
        set.insert(d2(p1,p3));
        set.insert(d2(p1,p4));
        set.insert(d2(p2,p3));
        set.insert(d2(p2,p4));
        set.insert(d2(p3,p4));

        return !set.count(0) && set.size() == 2;
    }

private:
    int d2(std::vector<int> &p1, std::vector<int> &p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};
