/*
455. Assign Cookies
Assume you are an awesome parent and want to give your children
some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size
of a cookie that the child will be content with; and each cookie
j has a size s[j]. If s[j] >= g[i], we can assign the cookie j
to the child i, and the child i will be content. Your goal is
to maximize the number of your content children and output the
maximum number.
*/

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) 
    {
        if (s.empty())
        return 0;

        int result = 0;

        std::priority_queue<int> prQ(s.begin(), s.end());

        std::sort(g.begin(), g.end(), std::greater<>());

        for (const int el : g)
        {
            if (prQ.empty())
                break;

            if (el <= prQ.top())
            {
                result++;
                prQ.pop();
            }
        }

        return result;
    }
};
