/*
74. Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.	
*/

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            int l = 0;
            int r = matrix[i].size() - 1;
            if (target >= matrix[i][l] && target <= matrix[i][r])
            {
                while (l < r)
                {
                    int mid = (r - l) / 2 + l;

                    if (matrix[i][mid] == target) return true;

                    if (matrix[i][mid] > target) r = mid - 1;
                    else l = mid + 1;
                }
                if (l == r && matrix[i][l] == target) return true;
            }
        }

        return false;
    }
};
