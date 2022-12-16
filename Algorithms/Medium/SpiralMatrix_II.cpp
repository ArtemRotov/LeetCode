class Solution {
public:
        enum Direction
    {
        RIGHT,
        DOWN,
        LEFT,
        UP
    };

    std::vector<std::vector<int>> generateMatrix(int n)
    {
        std::vector<std::vector<int>> result (n, std::vector<int>(n));

        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = right;

        Direction d = RIGHT;
        int counter = 0;

        while (left <= right && top <= bottom)
        {
            if (d == RIGHT)
            {
                for (int i = left; i <= right; ++i) result[top][i] = ++counter;
                top++;
                d = DOWN;
            }
            else if (d == DOWN)
            {
                for (int i = top; i <= bottom; ++i) result[i][right] = ++counter;
                right--;
                d = LEFT;
            }
            else if (d == LEFT)
            {
                for (int i = right; i >= left; --i) result[bottom][i] = ++counter;
                bottom --;
                d = UP;
            }
            else if (d == UP)
            {
                for (int i = bottom; i >= top ; --i) result[i][left] = ++counter;
                left ++;
                d = RIGHT;
            }
        }

        return result;
    }
};
