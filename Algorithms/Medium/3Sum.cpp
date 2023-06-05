/*
15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> res {};
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while(front < back)
            {
                int sum = nums[front] + nums[back];

                if (sum < target) front++;

                else if (sum > target) back--;

                else
                {
                    std::vector<int> triplet = {nums[i], nums[front], nums[back]};
                    res.push_back(triplet);

                    while (front < back && nums[front] == triplet[1]) front++;
                    while (front < back && nums[back] == triplet[2]) back--;
                }
            }

            while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }

        return res;
    }
};
