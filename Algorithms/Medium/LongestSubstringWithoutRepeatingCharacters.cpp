/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int len = s.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return 1;

        std::unordered_map<char, int> uMap{};

        std::vector<int> counts {};
        int cnt = 0;

        for (int i = 0, curr= 0; i < len && curr < len; ++i)
        {
            if (uMap.count(s[i]))
            {
                i = curr;
                curr++;
                uMap.clear();
                counts.push_back(cnt);
                cnt = 0;
            }
            else
            {
                uMap[s[i]]++;
                cnt++;
            }
        }
        if (cnt)
            counts.push_back(cnt);

        return *std::max_element(counts.begin(), counts.end());
    }
};
