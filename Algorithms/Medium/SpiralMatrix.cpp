class Solution {
public:

    enum DIRECTION
    {
        RIGHT,
        DOWN,
        LEFT,
        UP
    };

    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        std::vector<int> res {};
        if (matrix.empty())
            return res;

        int top = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        int left = 0;
        int direction = RIGHT;

        while (left <= right && top <= bottom)
        {
            if (direction == RIGHT)
            {
                for(int i = left; i <= right; ++i) res.push_back(matrix[top][i]);
                direction = DOWN;
                top++;
            }
            else if(direction == DOWN)
            {
                for(int i = top; i <= bottom; ++i) res.push_back(matrix[i][right]);
                direction = LEFT;
                right--;
            }
            else if(direction == LEFT)
            {
                for(int i = right; i >= left; --i) res.push_back(matrix[bottom][i]);
                direction = UP;
                bottom--;
            }
            else if(direction == UP)
            {
                for(int i = bottom; i >= top; --i) res.push_back(matrix[i][left]);
                direction = RIGHT;
                left++;
            }
        }

        return res;
    }
};
