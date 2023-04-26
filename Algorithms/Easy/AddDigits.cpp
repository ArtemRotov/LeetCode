/*
258. Add Digits
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/

class Solution {
public:

    int addDigits(int num)
    {
        while(num > 9)
        {
            int s = num;
            num = 0;
            while (s) 
            {
                num += s % 10;
                s /= 10;
            }
        }

        return num;
    }
};
