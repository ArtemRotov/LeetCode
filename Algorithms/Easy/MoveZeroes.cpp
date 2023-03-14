/*
283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while
maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) 
    {
        int count = 0;
        for(int i=0; i< nums.size(); i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
            else if(count!=0)
            {
                nums[i-count] = nums[i];
                nums[i] = 0;
            }   
        }
    }        
        // int j = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] != 0)
        //     {
        //         nums[j++] = nums[i];
        //     }
        // }

        // for (; j < nums.size(); j++)
        // {
        //     nums[j] = 0;
        // }
};
