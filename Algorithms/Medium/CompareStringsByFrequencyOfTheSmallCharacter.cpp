/*
1170. Compare Strings by Frequency of the Smallest Character

Let the function f(s) be the frequency of the lexicographically smallest character in a non-empty string s.
For example, if s = "dcce" then f(s) = 2 because the lexicographically smallest character is 'c', which has
a frequency of 2.

You are given an array of strings words and another array of query strings queries. For each query queries[i],
count the number of words in words such that f(queries[i]) < f(W) for each W in words.

Return an integer array answer, where each answer[i] is the answer to the ith query.
*/

class Solution {
public:
    std::vector<int> numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words)
    {
        std::vector<int> result {};

        std::vector<int> wordsValues {};
        for (const std::string &w : words)
            wordsValues.push_back(f(w));

        for (const std::string &q : queries)
        {
            int counter = 0;
            int val = f(q);

            for (int el : wordsValues)
            {
                if (val < el)
                    counter++;
            }

            result.push_back(counter);
        }

        return result;
    }

private:
    int f2(const std::string& s)
    {
        return std::count(std::begin(s), std::end(s), *std::min_element(std::begin(s), std::end(s)));
    }

    int f(const std::string& s)
    {
        std::map<char,int> m;
        for (const char &el : s)
            m[el]++;

        return (*m.begin()).second;
    }

};
