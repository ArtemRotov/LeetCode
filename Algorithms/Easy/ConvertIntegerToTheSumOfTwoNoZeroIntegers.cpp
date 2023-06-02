/*
1317. Convert Integer to the Sum of Two No-Zero Integers

No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.
*/

class Solution {
public:
    std::vector<int> getNoZeroIntegers(int n) 
    {
        for( int i = 1; i < n; i++ )
        {
            if( noZero( i ) && noZero( n-i ) )
            {
                return { i, n-i };
            }
        }
        return {};
    }

    bool noZero(int n)
    {
        while(n > 0)
        {
            if(n % 10 == 0) return false;
            n = n/10;
        }
        return true;
    }
};
