/*
345. Reverse Vowels of a String

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
*/

class Solution {
public:
    // std::string reverseVowels(std::string &s) 
    // {
    //     std::unordered_set<char> ss {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    //     for (int i = 0, j = s.size() - 1; i < j;)
    //     {
    //         if (ss.count(s[i]) && ss.count(s[j]))
    //         {
    //             std::swap(s[i], s[j]);
    //             i++; j--;
    //             continue;
    //         }
    //         if (ss.count(s[i])) j--;
    //         else i++;
    //     }
        
    //     return s;
    // }

    std::string reverseVowels(std::string &s) 
    {
        int i = 0;
        int j = s.size() - 1;

        while (i < j)
        {
            if (!isVowel(s[i])) { i++; continue; }
            if (!isVowel(s[j])) { j--; continue; }
            std::swap(s[i], s[j]);
            i++; j--;
        }

        return s;
    }

    bool isVowel(char c)
    {
        return (
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' );
    }
};
