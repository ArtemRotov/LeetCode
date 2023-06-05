/*
1232. Check If It Is a Straight Line

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
*/

class Solution {
public:
    bool checkStraightLine(std::vector<std::vector<int>>& coordinates) 
    {
    const double inf = 9999999.9999999;
    double k = 0;
    double dx = coordinates[1][0] - coordinates[0][0];
    double dy = coordinates[1][1] - coordinates[0][1];
    if (dx == 0) k = inf;
    else k = double(dy/dx);

    for (int i = 0; i < coordinates.size() - 1; i++)
    {
        double newK = 0;
        dx = coordinates[i+1][0] - coordinates[i][0];
        dy = coordinates[i+1][1] - coordinates[i][1];
        if (dx == 0) newK = inf;
        else newK = dy/dx;

        if (k != newK) return false;
    }

    return true;
    }
};
