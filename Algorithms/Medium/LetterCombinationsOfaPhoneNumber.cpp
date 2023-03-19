/*
17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that
the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does
not map to any letters.
*/

class Solution {
public:
    void backtrack(string& comb, string digits)
    {
        if(digits.empty())
            ans.push_back(comb);
        else 
        {
            for(const char &c:map[digits[0]-'0'])
            {
                comb += c;
                backtrack(comb,digits.substr(1));
                comb.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty()) return {};
        string comb = "";
        backtrack(comb,digits);
        return ans;
    }

    std::vector<std::string> ans;
    std::vector<std::string> map {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

};

// class Solution {
// public:
//     std::vector<std::string> letterCombinations(std::string digits) 
//     {
//         if (digits.empty()) return{};

//         const std::vector<std::string> map {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

//         std::vector<std::string> result{""};

//         for (const char &c : digits)
//         {
//             std::vector<std::string> tmp;
//             for (const char &el : map[c - '0'])
//             {
//                 for (std::string str : result)
//                     tmp.push_back(str + el);
//             }
//             result.swap(tmp);
//         }
      

//         return result;
//     }   
// };

