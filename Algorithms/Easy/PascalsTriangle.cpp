/*
118. Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) 
    {
        std::vector<std::vector<int>> result(numRows);

        for (int i = 0; i < numRows; i++)
        {
            result[i].resize(i + 1, 1);
            
            for(int j = 1; j < i; j++)
            {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }

        return result;
    }
};
