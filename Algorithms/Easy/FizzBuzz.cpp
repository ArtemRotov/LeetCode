/*
412. Fizz Buzz
	
Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
*/

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) 
    {
        std:vector<std::string> result(n);
        int i = 0;

        for (i = 1; i <= n; i++)
            result[i-1] = std::to_string(i);

        for (i = 2; i <= n; i+=3)
            result[i] = "Fizz";

        for (i = 4; i <= n; i+=5)
            result[i] = "Buzz";

        for (i = 14; i <= n; i+=15)
            result[i] = "FizzBuzz";
        
        return result;
    }
};
