/*
171. Excel Sheet Column Number

Given a string columnTitle that represents the column title
as appears in an Excel sheet, return its corresponding column number.

For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
*/

class Solution {
public:
    int titleToNumber(std::string columnTitle) 
    {
        int result = 0;
        int power = columnTitle.size() - 1;

        for (const char &c : columnTitle)
        {
            result += (c - 'A' + 1) * pow(26, power--);
        }

        return result;
    }
};
