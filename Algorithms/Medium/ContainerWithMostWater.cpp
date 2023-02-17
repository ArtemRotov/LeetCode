/*
11. Container With Most Water
You are given an integer array height of length n. There are n vertical
lines drawn such that the two endpoints of the ith line are (i, 0) and
(i, height[i]).

Find two lines that together with the x-axis form a container, such that
the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(std::vector<int>& height) 
    {
        int water = 0;
        int h = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            h = std::min(height[i],height[j]);
            water = std::max(water, h * (j - i));

            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }

        return water;
    }
};
