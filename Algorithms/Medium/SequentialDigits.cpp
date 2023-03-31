/*
1291. Sequential Digits

An integer has sequential digits if and only if each digit in the number is one
more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive
that have sequential digits.
*/

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) 
    {
        std::vector<int> result {};

        int value = 0;
        for (int i = 1; i < 10; i++)
        {
            for (int j = i; j < 10 ; j++)
            {
                value = value * 10 + j;
                if (value >= low && value <= high)
                    result.push_back(value);
            }
            
            value = 0;
        }

        std::sort(result.begin(), result.end());

        return result;
    }
};
