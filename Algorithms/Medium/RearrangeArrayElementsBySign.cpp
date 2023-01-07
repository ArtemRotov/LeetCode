/*
2149. Rearrange Array Elements by Sign

You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:
    Every consecutive pair of integers have opposite signs.
    For all integers with the same sign, the order in which they were present in nums is preserved.
    The rearranged array begins with a positive integer.

Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
*/

class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums)
    {
        std::vector<int> result(nums.size(), 0);

        int positive = 0;
        int negative = 1;

        for(const int &el : nums)
        {
            if (el > 0)
            {
                result[positive] = el;
                positive +=2;
            }
            else
            {
                result[negative] = el;
                negative +=2;
            }
        }

        return result;
    }
};

class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums)
    {
        std::queue<int> positive{};
        std::queue<int> negative{};

        for (const int &el : nums)
        {
            if (el < 0)
                negative.push(el);
            else
                positive.push(el);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i & 1)
            {
                nums[i] = negative.front();
                negative.pop();
            }
            else
            {
                nums[i] = positive.front();
                positive.pop();
            }
        }

        return nums;
    }
};
