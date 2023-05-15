/*
119. Pascal's Triangle II

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
*/

class Solution {
public:
    std::vector<int> getRow(int rowIndex) 
    {   
        if (!rowIndex)
            return {1};
        
        std::vector<std::vector<int>> res(rowIndex + 1);

        for (int i = 0; i < res.size(); i++)
        {
            res[i].resize(i + 1, 1);

            for(int j = 1; j < i; j++)
            {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }

        return res[rowIndex];
    }
};
